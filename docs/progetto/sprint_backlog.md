# Sprint Backlog - cub3D

## Project: cub3D - Cyber Escape
**Team:** Gabriela (vhacman), Ilaria (iallain)
**Start Date:** 8 Marzo 2026
**Estimated Delivery:** 6 Aprile 2026

---

## Sprint 1: Setup e Preparazione ✅ COMPLETATO

### Obiettivi
- [x] Setup repository Git
- [x] Creare struttura cartelle
- [x] Studiare il subject
- [x] Creare documentazione di base

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

### Obiettivi
- [x] Studiare teoria ray-casting
- [x] Studiare MiniLibX
- [x] Creare guide di studio

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S2.1 | Studiare teoria ray-casting (DDA algorithm) | Gabriela | ✅ |
| S2.2 | Creare docs/studio/teoria_cub3D.txt | Gabriela | ✅ |
| S2.3 | Creare docs/studio/guida_studio_cub3D.txt | Gabriela | ✅ |
| S2.4 | Creare docs/studio/funzioni_esterne_teoria.txt | Gabriela | ✅ |

---

## Sprint 3: Header Files e Strutture ✅ COMPLETATO

### Obiettivi
- [x] Creare structs.h con strutture dati
- [x] Creare defines.h con costanti
- [x] Creare cub3d.h con prototipi

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S3.1 | Creare include/structs.h (t_player, t_map, t_cub, t_ray) | Gabriela | ✅ |
| S3.2 | Creare include/defines.h (costanti, colors, keys) | Gabriela | ✅ |
| S3.3 | Creare include/cub3d.h (prototipi funzioni con TODO) | Gabriela | ✅ |

---

## Sprint 4: Template File con TODO ✅ COMPLETATO

### Obiettivi
- [x] Creare template per tutti i file sorgente
- [x] Aggiungere header 42 a tutti i file
- [x] Inserire TODO comment per il lavoro da fare

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S4.1 | Creare src/events/events.c (TODO: MiniLibX init) | Ilaria | ✅ |
| S4.2 | Creare src/events/keys.c (TODO: keyboard handling) | Ilaria | ✅ |
| S4.3 | Creare src/render/render.c (TODO: main rendering) | Ilaria | ✅ |
| S4.4 | Creare src/utils/error.c (TODO: error handling) | Gabriela | ✅ |
| S4.5 | Creare src/utils/free.c (TODO: memory freeing) | Gabriela | ✅ |
| S4.6 | Creare src/utils/utils.c (TODO: utility functions) | Gabriela | ✅ |

---

## Sprint 5: Documentazione Progetto ✅ COMPLETATO

### Obiettivi
- [x] Creare documentazione completa per il progetto

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

## Prossimi Sprint: Implementazione

### Sprint 6: Parser (.cub file)
**Assegnato a:** Gabriela

- [ ] Implementare parser per textures (NO, SO, WE, EA)
- [ ] Implementare parser per colori (F, C)
- [ ] Implementare parser per mappa
- [ ] Gestione errori
- [ ] Free memory

### Sprint 7: Raycasting Engine
**Assegnato a:** Ilaria

- [ ] Implementare DDA algorithm
- [ ] Calcolo distanza muri
- [ ] Textures sui muri
- [ ] Floor/Ceiling colors

### Sprint 8: Rendering
**Assegnato a:** Ilaria

- [ ] MiniLibX init
- [ ] Game loop
- [ ] Image rendering
- [ ] Double buffering

### Sprint 9: Eventi
**Assegnato a:** Ilaria

- [ ] Keyboard input (WASD, frecce)
- [ ] Window close (ESC, X rosso)
- [ ] Mouse events (optional)

### Sprint 10: Bonus
**Assegnato a:** Team

- [ ] Wall collisions
- [ ] Minimap
- [ ] Doors
- [ ] Sprites
- [ ] Mouse rotation

---

## File Creati

### Documentazione
```
docs/
├── progetto/
│   ├── divisione_lavoro_cub3D.txt
│   ├── scaletta_cub3D_Gabriela.txt
│   ├── scaletta_ilaria.txt
│   ├── cyber_escape_storia.txt
│   ├── restrizioni_progetto.md
│   └── regole_repo_42.md
├── studio/
│   ├── teoria_cub3D.txt
│   ├── guida_studio_cub3D.txt
│   └── funzioni_esterne_teoria.txt
└── git/
    ├── guida_git.txt
    └── regole_git.txt
```

### Codice Sorgente
```
include/
├── cub3d.h
├── structs.h
└── defines.h

src/
├── events/
│   ├── events.c
│   └── keys.c
├── render/
│   └── render.c
└── utils/
    ├── error.c
    ├── free.c
    └── utils.c
```

### Mappe
```
maps/
├── test.cub
└── edge_cases_test.txt
```

---

## Note

- Todo i file sorgente hanno solo commenti TODO - nessuna implementazione
- Ogni funzione ha un commento che spiega cosa deve fare
- I TODO sono divisi tra Gabriela e Ilaria secondo divisione_lavoro_cub3D.txt

---

*Ultimo aggiornamento: 5 Marzo 2026*
