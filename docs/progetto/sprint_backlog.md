# Sprint Backlog - cub3D

## Project: cub3D - Cyber Escape
**Team:** Gabriela (vhacman), Ilaria (iallain)
**Start Date:** 8 Marzo 2026
**Estimated Delivery:** 6 Aprile 2026

---

## Sprint 1: Setup e Preparazione ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S1.1 | Inizializzare repo Git con branch (main, develop, gabriela, ilaria) | Gabriela | ✅ |
| S1.2 | Creare struttura cartelle (src/, include/, maps/, textures/, libft/, docs/) | Gabriela | ✅ |
| S1.3 | Leggere e analizzare en.subject (1).pdf | Gabriela | ✅ |
| S1.4 | Leggere correction.pdf (versione 2021) | Gabriela | ✅ |
| S1.5 | Creare divisione_lavoro_cub3D.txt | Gabriela | ✅ |

---

## Sprint 2: Teoria e Studio ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S2.1 | Studiare teoria ray-casting (DDA algorithm) | Gabriela | ✅ |
| S2.2 | Creare docs/studio/teoria_cub3D.txt | Gabriela | ✅ |
| S2.3 | Creare docs/studio/guida_studio_cub3D.txt | Gabriela | ✅ |
| S2.4 | Creare docs/studio/funzioni_esterne_teoria.txt | Gabriela | ✅ |

---

## Sprint 3: Header Files e Strutture ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S3.1 | Creare include/structs.h (t_player, t_map, t_cub, t_ray) | Gabriela | ✅ |
| S3.2 | Creare include/defines.h (costanti, colors, keys) | Gabriela | ✅ |
| S3.3 | Creare include/cub3d.h (prototipi funzioni) | Gabriela | ✅ |

---

## Sprint 4: Template File ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S4.1 | Creare src/events/events.c | Ilaria | ✅ |
| S4.2 | Creare src/events/keys.c | Ilaria | ✅ |
| S4.3 | Creare src/render/render.c | Ilaria | ✅ |
| S4.4 | Creare src/utils/error.c | Gabriela | ✅ |
| S4.5 | Creare src/utils/free.c | Gabriela | ✅ |
| S4.6 | Creare src/utils/utils.c | Gabriela | ✅ |

---

## Sprint 5: Documentazione Progetto ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S5.1 | Creare tema/background: Cyber Escape | Gabriela | ✅ |
| S5.2 | Creare docs/progetto/cyber_escape_storia.txt | Gabriela | ✅ |
| S5.3 | Creare docs/progetto/restrizioni_progetto.md | Gabriela | ✅ |
| S5.4 | Creare docs/progetto/regole_repo_42.md | Gabriela | ✅ |
| S5.5 | Creare README.md secondo regole subject | Gabriela | ✅ |
| S5.6 | Creare mappe di test (test.cub, edge_cases_test.txt) | Gabriela | ✅ |

---

## Sprint 6: Parser (.cub file) ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S6.1 | Implementare parse_file() in parse_file.c | Ilaria | ✅ |
| S6.2 | Implementare parse_texture() in parse_textures.c | Ilaria | ✅ |
| S6.3 | Implementare parse_color() in parse_colors.c | Ilaria | ✅ |
| S6.4 | Implementare parse_map() in parse_map.c | Ilaria | ✅ |
| S6.5 | Implementare validate_map() in validate_map.c | Ilaria | ✅ |

---

## Sprint 7: Raycasting Engine ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S7.1 | Implementare is_walkable() in player_move.c | Ilaria | ✅ |
| S7.2 | Implementare rotate_player() in player_move.c | Ilaria | ✅ |
| S7.3 | Implementare move_forward_back() in player_move.c | Ilaria | ✅ |
| S7.4 | Implementare move_strafe() in player_move.c | Ilaria | ✅ |
| S7.5 | Implementare move_player() in player_move.c | Ilaria | ✅ |
| S7.6 | Implementare DDA algorithm in dda.c | Ilaria | ✅ |
| S7.7 | Implementare raycast() in raycaster.c | Ilaria | ✅ |
| S7.8 | Implementare draw_wall() in draw_walls.c | Ilaria | ✅ |
| S7.9 | Implementare draw_floor_ceiling() in draw_floor_ceiling.c | Ilaria | ✅ |

---

## Sprint 8: Rendering ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S8.1 | Implementare init_mlx() in events.c | Ilaria | ✅ |
| S8.2 | Implementare create_window() in events.c | Ilaria | ✅ |
| S8.3 | Implementare init_image() in render.c | Ilaria | ✅ |
| S8.4 | Implementare my_mlx_pixel_put() in render.c | Ilaria | ✅ |
| S8.5 | Implementare clear_image() in render.c | Ilaria | ✅ |
| S8.6 | Implementare render() in render.c | Ilaria | ✅ |
| S8.7 | Implementare textures (load, get_pixel, get_tex_x) in textures.c | Ilaria | ✅ |
| S8.8 | Implementare weapon rendering in weapon.c | Ilaria | ✅ |

---

## Sprint 9: Eventi ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S9.1 | Implementare setup_hooks() in events.c | Ilaria | ✅ |
| S9.2 | Implementare start_loop() in events.c | Ilaria | ✅ |
| S9.3 | Implementare close_window() in events.c | Ilaria | ✅ |
| S9.4 | Implementare init_keys() in keys.c | Ilaria | ✅ |
| S9.5 | Implementare key_press() in keys.c | Ilaria | ✅ |
| S9.6 | Implementare key_release() in keys.c | Ilaria | ✅ |

---

## Sprint Utils: Utility Functions ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| U1 | Implementare error_exit() in error.c | Ilaria | ✅ |
| U2 | Implementare free_map() in free.c | Ilaria | ✅ |
| U3 | Implementare free_textures() in free.c | Ilaria | ✅ |
| U4 | Implementare free_main_image() in free.c | Ilaria | ✅ |
| U5 | Implementare free_game() in free.c | Ilaria | ✅ |
| U6 | Implementare free_str_array() in free.c | Ilaria | ✅ |
| U7 | Implementare safe_free() in utils.c | Ilaria | ✅ |
| U8 | Implementare create_color() in utils.c | Ilaria | ✅ |

---

## Sprint main: Entry Point ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| M1 | Implementare main() in main.c | Gabriela | ✅ |
| M2 | Implementare init_game() in main.c | Gabriela | ✅ |
| M3 | Implementare init_player() + set_player_vectors() in main.c | Gabriela | ✅ |
| M4 | Implementare check_elements() in main.c | Gabriela | ✅ |

---

## Sprint 10: Bonus ✅ COMPLETATO

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| B1 | Minimap 2D overlay (posizione + direzione giocatore) — minimap_bonus.c | Gabriela | ✅ |
| B2 | Porte apribili con tasto E (char '2' in mappa) — doors_bonus.c | Gabriela | ✅ |
| B2b | Supporto '2' in validate_map, is_walkable, dda_loop | Gabriela | ✅ |
| B3 | Separazione build: render_bonus.c e keys_bonus.c (no #ifdef in funzioni) | Gabriela | ✅ |
| B4 | Stub mouse_bonus.c per Ilaria | Gabriela | ✅ |
| B5 | Stub sprites_anim_bonus.c per Ilaria | Gabriela | ✅ |
| B6 | Makefile: SRCS_BONUS con filter-out render.c/keys.c + versioni bonus | Gabriela | ✅ |

### Task Da Completare

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| B7 | Rotazione con il mouse (mouse_bonus.c) — implementazione reale | Ilaria | ⏳ |
| B8 | Sprite animati con frame multipli (sprites_anim_bonus.c) | Ilaria | ⏳ |

---

## Sprint QA: Test e Norminette ✅ COMPLETATO (in parte)

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| QA2 | Norminette v4.1 su tutti i file — pass completo | Gabriela | ✅ |
| QA3a | Fix memory leak: create_window (mlx non liberato se window fallisce) | Gabriela | ✅ |
| QA3b | Fix memory leak: free_weapon (img.img non azzerato dopo destroy) | Gabriela | ✅ |
| QA-N1 | main.c: estratto set_player_vectors() — init_player era >25 righe | Gabriela | ✅ |
| QA-N2 | keys.c: rimosso #ifdef BONUS da corpo funzione; ripuliti commenti | Gabriela | ✅ |
| QA-N3 | render.c: rimosso #ifdef BONUS da corpo funzione; ripuliti commenti | Gabriela | ✅ |
| QA-N4 | Creato src/bonus/render_bonus.c — versione bonus di render.c | Gabriela | ✅ |
| QA-N5 | Creato src/bonus/keys_bonus.c — versione bonus di keys.c | Gabriela | ✅ |
| QA-N6 | minimap_bonus.c: inlinato fill_mm_row in draw_mm_cell (6→5 funzioni) | Gabriela | ✅ |
| QA-N7 | parser_utils.c: ridotto a 5 funzioni; creato parser_utils2.c | Gabriela | ✅ |
| QA-N8 | free.c: spostato safe_free in utils.c (era 6 funzioni, ora 5) | Gabriela | ✅ |
| QA-N9 | draw_walls/floor_ceiling/textures/weapon.c: tabs al posto degli spazi | Gabriela | ✅ |
| QA-N10 | weapon.c: rimosso carattere ~ spurio a fine file | Gabriela | ✅ |
| QA-N11 | events.c: riscritto — rimossi commenti standalone in corpi funzione | Gabriela | ✅ |
| QA-N12 | error.c, validate_map.c, dda.c, player_move.c: rimossi commenti in funzioni | Gabriela | ✅ |
| QA-N13 | player_move.c: sostituiti caratteri non-ASCII (è → e') nei commenti | Gabriela | ✅ |
| QA-N14 | utils.c: corretta doppia riga vuota; aggiunto safe_free | Gabriela | ✅ |
| QA-N15 | Makefile: aggiunto parser_utils2.c a SRCS | Gabriela | ✅ |

### Task Da Completare

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| QA1 | Compilare su Linux — zero warning/errori (make + make bonus) | Entrambe | ⏳ |
| QA4 | Test con correction sheet mandatory | Entrambe | ⏳ |
| QA5 | Test error management (argomenti sbagliati, mappa aperta, ecc.) | Entrambe | ⏳ |
| QA6 | Test stabilità (face-on-keyboard) | Entrambe | ⏳ |
| QA7 | Verifica: git clone + make funziona in cartella vuota | Gabriela | ⏳ |
| QA8 | Valgrind — conferma zero leak a runtime | Entrambe | ⏳ |

---

## Prossimi Passi — PUSH MARTEDI 24 MARZO

**SCADENZA: martedì 24 marzo 2026 — push all'80 (consegna finale)**

Ordine obbligatorio per domani:
1. Compilare su Linux — `make` e `make bonus` zero errori
2. Test rapido funzionalità base (finestra, movimento, muri, ESC)
3. Valgrind — zero leak confermato
4. Test error management essenziale
5. Push all'80

---

*Ultimo aggiornamento: 23 Marzo 2026*
