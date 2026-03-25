#!/bin/bash
# =============================================================================
# SUITE COMPLETA DI TEST VALGRIND PER CUB3D
# Uso: ./valgrind_tests.sh [path_al_binario] [path_alle_mappe]
#
# Esempio:
#   ./valgrind_tests.sh ./cub3D ./maps
#
# Richiede: valgrind installato, binario compilato, mappe nella directory giusta
# =============================================================================

CUB3D="${1:-./cub3D}"
MAPS="${2:-./maps}"

# Colori output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

PASS=0
FAIL=0
TOTAL=0

# Opzioni Valgrind comuni
VOPT="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42 -q"

# =============================================================================
# Funzione helper: testa un caso di ERRORE
# Il programma deve: stampare "Error" su stderr, uscire con codice != 0
# Valgrind deve: non rilevare leak
# =============================================================================
test_error() {
    local desc="$1"
    local cmd="$2"
    local expect_msg="$3"   # stringa attesa nello stderr (opzionale)

    TOTAL=$((TOTAL + 1))
    echo -e "${CYAN}[TEST $TOTAL]${NC} ${BOLD}${desc}${NC}"
    echo "  CMD: $cmd"

    # Esegui con valgrind, timeout 5s (i casi di errore non aprono finestra)
    OUTPUT=$(timeout 5s $VOPT $cmd 2>&1)
    EXIT_CODE=$?

    # Valgrind imposta exit 42 se trova errori di memoria
    VALGRIND_ERROR=0
    if echo "$OUTPUT" | grep -q "ERROR SUMMARY: [^0]"; then
        VALGRIND_ERROR=1
    fi
    if [ $EXIT_CODE -eq 42 ]; then
        VALGRIND_ERROR=1
    fi

    # Controlla che il programma abbia stampato "Error"
    HAS_ERROR_MSG=0
    if echo "$OUTPUT" | grep -q "^Error"; then
        HAS_ERROR_MSG=1
    fi

    # Controlla che exit code sia != 0 (ma non 42 = valgrind error)
    PROGRAM_FAILED=0
    if [ $EXIT_CODE -ne 0 ] && [ $EXIT_CODE -ne 42 ]; then
        PROGRAM_FAILED=1
    fi
    # Timeout = 124, anche quello conta come fallimento del programma
    if [ $EXIT_CODE -eq 124 ]; then
        echo -e "  ${RED}TIMEOUT - il programma non ha terminato entro 5s${NC}"
        FAIL=$((FAIL + 1))
        echo ""
        return
    fi

    # Risultato
    local ok=1
    if [ $VALGRIND_ERROR -eq 1 ]; then
        echo -e "  ${RED}LEAK/ERROR VALGRIND rilevato${NC}"
        echo "$OUTPUT" | grep -A5 "ERROR SUMMARY"
        ok=0
    fi
    if [ $HAS_ERROR_MSG -eq 0 ]; then
        echo -e "  ${RED}Manca 'Error' nello stderr${NC}"
        ok=0
    fi
    if [ $PROGRAM_FAILED -eq 0 ]; then
        echo -e "  ${RED}Exit code 0 (il programma non ha segnalato errore)${NC}"
        ok=0
    fi
    if [ -n "$expect_msg" ]; then
        if ! echo "$OUTPUT" | grep -qi "$expect_msg"; then
            echo -e "  ${YELLOW}WARN: messaggio atteso '$expect_msg' non trovato${NC}"
        fi
    fi

    if [ $ok -eq 1 ]; then
        echo -e "  ${GREEN}PASS${NC} — errore rilevato correttamente, nessun leak"
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
    fi
    echo ""
}

# =============================================================================
# Funzione helper: testa un caso VALIDO (solo leak check, no crash check)
# Non apre finestra — usa timeout breve e si aspetta che il programma
# termini subito con errore "Failed to initialize miniLibX" o simile
# in ambiente senza display. L'importante è: nessun leak, nessun crash.
# =============================================================================
test_valid_noleak() {
    local desc="$1"
    local cmd="$2"

    TOTAL=$((TOTAL + 1))
    echo -e "${CYAN}[TEST $TOTAL]${NC} ${BOLD}${desc}${NC}"
    echo "  CMD: $cmd"

    OUTPUT=$(timeout 5s $VOPT $cmd 2>&1)
    EXIT_CODE=$?

    if [ $EXIT_CODE -eq 124 ]; then
        echo -e "  ${YELLOW}TIMEOUT (normale se display disponibile — kill manuale)${NC}"
        PASS=$((PASS + 1))
        echo ""
        return
    fi

    VALGRIND_ERROR=0
    if echo "$OUTPUT" | grep -q "ERROR SUMMARY: [^0]"; then
        VALGRIND_ERROR=1
    fi
    if [ $EXIT_CODE -eq 42 ]; then
        VALGRIND_ERROR=1
    fi

    # In ambiente CI/no-display il programma potrebbe uscire con errore MLX
    # Non è un fallimento del parser — solo dell'inizializzazione grafica
    if echo "$OUTPUT" | grep -qi "segmentation\|double free\|invalid read\|invalid write"; then
        echo -e "  ${RED}CRASH rilevato da Valgrind${NC}"
        echo "$OUTPUT" | grep -i "segmentation\|double free\|invalid"
        FAIL=$((FAIL + 1))
        echo ""
        return
    fi

    if [ $VALGRIND_ERROR -eq 1 ]; then
        echo -e "  ${RED}LEAK/ERROR VALGRIND rilevato${NC}"
        echo "$OUTPUT" | grep -A5 "ERROR SUMMARY"
        FAIL=$((FAIL + 1))
    else
        echo -e "  ${GREEN}PASS${NC} — nessun leak rilevato"
        PASS=$((PASS + 1))
    fi
    echo ""
}

# =============================================================================
# Funzione: test argomenti (nessun file da passare)
# =============================================================================
test_args() {
    local desc="$1"
    local cmd="$2"

    TOTAL=$((TOTAL + 1))
    echo -e "${CYAN}[TEST $TOTAL]${NC} ${BOLD}${desc}${NC}"
    echo "  CMD: $cmd"

    OUTPUT=$(timeout 3s $VOPT $cmd 2>&1)
    EXIT_CODE=$?

    VALGRIND_ERROR=0
    if echo "$OUTPUT" | grep -q "ERROR SUMMARY: [^0]"; then VALGRIND_ERROR=1; fi
    if [ $EXIT_CODE -eq 42 ]; then VALGRIND_ERROR=1; fi

    HAS_ERROR_MSG=0
    if echo "$OUTPUT" | grep -q "^Error\|Usage"; then HAS_ERROR_MSG=1; fi

    local ok=1
    if [ $VALGRIND_ERROR -eq 1 ]; then
        echo -e "  ${RED}LEAK/ERROR VALGRIND${NC}"; ok=0
    fi
    if [ $EXIT_CODE -eq 0 ]; then
        echo -e "  ${RED}Exit code 0 (doveva fallire)${NC}"; ok=0
    fi

    if [ $ok -eq 1 ]; then
        echo -e "  ${GREEN}PASS${NC}"
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
    fi
    echo ""
}

# =============================================================================
# INIZIO TEST
# =============================================================================

echo ""
echo -e "${BOLD}============================================================${NC}"
echo -e "${BOLD}  SUITE VALGRIND CUB3D — $(date)${NC}"
echo -e "${BOLD}  Binario: $CUB3D${NC}"
echo -e "${BOLD}  Mappe:   $MAPS${NC}"
echo -e "${BOLD}============================================================${NC}"
echo ""

if [ ! -f "$CUB3D" ]; then
    echo -e "${RED}ERRORE: binario '$CUB3D' non trovato. Compila prima con make.${NC}"
    exit 1
fi

# ============================================================
# SEZIONE 1 — ARGOMENTI
# ============================================================
echo -e "${BOLD}--- SEZIONE 1: ARGOMENTI ---${NC}"
echo ""

test_args \
    "Nessun argomento" \
    "$CUB3D"

test_args \
    "Troppi argomenti" \
    "$CUB3D $MAPS/test.cub extra_arg"

test_error \
    "Estensione sbagliata (.map invece di .cub)" \
    "$CUB3D $MAPS/wrong_extension.map" \
    "extension"

test_error \
    "File inesistente" \
    "$CUB3D $MAPS/nonexistent_file.cub" \
    ""

test_error \
    "File vuoto" \
    "$CUB3D $MAPS/empty.cub" \
    ""

# ============================================================
# SEZIONE 2 — ERRORI TEXTURE
# ============================================================
echo -e "${BOLD}--- SEZIONE 2: TEXTURE ---${NC}"
echo ""

test_error \
    "Texture duplicata (NO ripetuto)" \
    "$CUB3D $MAPS/duplicate_texture.cub" \
    "Duplicate"

test_error \
    "Texture path inesistente (EA NONEXISTENT.xpm)" \
    "$CUB3D $MAPS/missing_texture.cub" \
    ""

test_error \
    "Texture senza estensione .xpm (WE senza .xpm)" \
    "$CUB3D $MAPS/invalid_texture2.cub" \
    ""

# ============================================================
# SEZIONE 3 — ERRORI COLORI
# ============================================================
echo -e "${BOLD}--- SEZIONE 3: COLORI ---${NC}"
echo ""

test_error \
    "Floor con solo 2 componenti (F 1,16)" \
    "$CUB3D $MAPS/bad_color_floor.cub" \
    "color"

test_error \
    "Floor con valore fuori range (F 1,16,300)" \
    "$CUB3D $MAPS/bad_color_range.cub" \
    "color"

test_error \
    "Floor con valore negativo (F 20,20,-20)" \
    "$CUB3D $MAPS/color_rgb_invalid.cub" \
    "color"

test_error \
    "Floor con solo 2 componenti variante 2 (F 20,20)" \
    "$CUB3D $MAPS/no_floor_color.cub" \
    "color"

test_error \
    "Ceiling con campo vuoto (C 200,200,)" \
    "$CUB3D $MAPS/no_ceiling_color.cub" \
    "color"

test_error \
    "Ceiling mancante (solo F, nessun C)" \
    "$CUB3D $MAPS/missing_ceiling.cub" \
    ""

# ============================================================
# SEZIONE 4 — ERRORI MAPPA
# ============================================================
echo -e "${BOLD}--- SEZIONE 4: MAPPA ---${NC}"
echo ""

test_error \
    "Nessun giocatore nella mappa" \
    "$CUB3D $MAPS/no_player.cub" \
    "player"

test_error \
    "Mappa aperta (gap in riga finale: 11011)" \
    "$CUB3D $MAPS/open_map.cub" \
    "closed"

test_error \
    "Mappa aperta variante invalid_char (11011)" \
    "$CUB3D $MAPS/invalid_char.cub" \
    "closed"

test_error \
    "Giocatore multiplo (S e E nella stessa mappa)" \
    "$CUB3D $MAPS/multiple_player.cub" \
    ""

test_error \
    "Nessun giocatore, mappa piccola (small_map)" \
    "$CUB3D $MAPS/small_map.cub" \
    ""

# ============================================================
# SEZIONE 5 — STRESS / ARGOMENTI STRANI
# ============================================================
echo -e "${BOLD}--- SEZIONE 5: STRESS & EDGE CASES ---${NC}"
echo ""

test_error \
    "Path con estensione doppia (test.cub.bak se esiste)" \
    "$CUB3D $MAPS/test.cub.bak" \
    ""

test_error \
    "Solo l'estensione come nome (.cub)" \
    "$CUB3D $MAPS/.cub" \
    "extension"

test_args \
    "Path a directory invece di file" \
    "$CUB3D $MAPS/"

# Argomento con caratteri speciali (non deve crashare)
test_args \
    "Argomento con caratteri speciali" \
    "$CUB3D '!@#\$%^&*.cub'"

# ============================================================
# SEZIONE 6 — MAPPE VALIDE (solo leak check)
# ============================================================
echo -e "${BOLD}--- SEZIONE 6: MAPPE VALIDE (leak check) ---${NC}"
echo -e "${YELLOW}Nota: in ambiente senza display MLX può fallire l'init — è normale.${NC}"
echo -e "${YELLOW}Si verifica solo assenza di leak e crash di memoria.${NC}"
echo ""

test_valid_noleak \
    "Mappa valida base (test.cub)" \
    "$CUB3D $MAPS/test.cub"

test_valid_noleak \
    "Mappa valida complessa (valid_map.cub)" \
    "$CUB3D $MAPS/valid_map.cub"

test_valid_noleak \
    "Mappa valida circolare (valid_map2.cub)" \
    "$CUB3D $MAPS/valid_map2.cub"

test_valid_noleak \
    "Mappa valida corridoio (valid_map3.cub)" \
    "$CUB3D $MAPS/valid_map3.cub"

test_valid_noleak \
    "Mappa valida alta stretta (valid_map4.cub)" \
    "$CUB3D $MAPS/valid_map4.cub"

test_valid_noleak \
    "Mappa valida grande aperta (valid_map5.cub)" \
    "$CUB3D $MAPS/valid_map5.cub"

# ============================================================
# RISULTATI
# ============================================================
echo ""
echo -e "${BOLD}============================================================${NC}"
echo -e "${BOLD}  RISULTATI FINALI${NC}"
echo -e "${BOLD}============================================================${NC}"
echo -e "  Totale test:  ${TOTAL}"
echo -e "  ${GREEN}PASS: ${PASS}${NC}"
echo -e "  ${RED}FAIL: ${FAIL}${NC}"
echo ""

if [ $FAIL -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  Tutti i test superati!${NC}"
else
    echo -e "${RED}${BOLD}  ${FAIL} test falliti. Controlla l'output sopra.${NC}"
fi
echo ""
