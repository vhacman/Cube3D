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

## Sprint 8: Rendering ✅ COMPLETATO (10 Marzo 2026)

### Obiettivi
- [x] MiniLibX init
- [x] Game loop
- [x] Image rendering
- [x] Double buffering

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S8.1 | Implementare init_mlx() in events.c | Ilaria | ✅ |
| S8.2 | Implementare create_window() in events.c | Ilaria | ✅ |
| S8.3 | Implementare init_image() in render.c | Ilaria | ✅ |
| S8.4 | Implementare my_mlx_pixel_put() in render.c | Ilaria | ✅ |
| S8.5 | Implementare clear_image() in render.c | Ilaria | ✅ |
| S8.6 | Implementare render() in render.c | Ilaria | ✅ |

---

## Sprint 9: Eventi ✅ COMPLETATO (10 Marzo 2026)

### Obiettivi
- [x] Keyboard input (WASD, frecce)
- [x] Window close (ESC, X rosso)
- [ ] Mouse events (optional)

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

## Sprint Utils: Utility Functions ✅ COMPLETATO (10 Marzo 2026)

### Obiettivi
- [x] Gestione errori
- [x] Memory freeing
- [x] Funzioni utili generiche

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| U1 | Implementare error_exit() in error.c | Ilaria | ✅ |
| U2 | Implementare free_map() in free.c | Ilaria | ✅ |
| U3 | Implementare free_textures() in free.c | Ilaria | ✅ |
| U4 | Implementare free_main_image() in free.c | Ilaria | ✅ |
| U5 | Implementare free_game() in free.c | Ilaria | ✅ |
| U6 | Implementare free_str_array() in utils.c | Ilaria | ✅ |
| U7 | Implementare safe_free() in utils.c | Ilaria | ✅ |
| U8 | Implementare create_color() in utils.c | Ilaria | ✅ |

---

## Sprint 7: Raycasting Engine 🚧 IN CORSO

### Obiettivi
- [ ] Implementare DDA algorithm
- [ ] Calcolo distanza muri
- [ ] Textures sui muri
- [ ] Floor/Ceiling colors
- [x] Movimento giocatore (player_move.c)

### Task Completati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S7.1 | Implementare is_walkable() in player_move.c | Ilaria | ✅ |
| S7.2 | Implementare rotate_player() in player_move.c | Ilaria | ✅ |
| S7.3 | Implementare move_forward_back() in player_move.c | Ilaria | ✅ |
| S7.4 | Implementare move_strafe() in player_move.c | Ilaria | ✅ |
| S7.5 | Implementare move_player() in player_move.c | Ilaria | ✅ |

### Task Da Completare

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S7.6 | Implementare DDA algorithm in dda.c | Ilaria | ⏳ |
| S7.7 | Implementare raycast() in raycaster.c | Ilaria | ⏳ |
| S7.8 | Implementare draw_wall() in draw_walls.c | Ilaria | ⏳ |
| S7.9 | Implementare draw_floor_ceiling() in draw_floor_ceiling.c | Ilaria | ⏳ |

---

## Sprint 6: Parser (.cub file) ⏳

### Obiettivi
- [ ] Implementare parser per textures (NO, SO, WE, EA)
- [ ] Implementare parser per colori (F, C)
- [ ] Implementare parser per mappa
- [ ] Gestione errori
- [ ] Free memory

### Task Assegnati

| ID | Task | Assegnato a | Status |
|----|------|-------------|--------|
| S6.1 | Implementare parse_file() in parse_file.c | Gabriela | ⏳ |
| S6.2 | Implementare parse_texture() in parse_textures.c | Gabriela | ⏳ |
| S6.3 | Implementare parse_color() in parse_colors.c | Gabriela | ⏳ |
| S6.4 | Implementare parse_map() in parse_map.c | Gabriela | ⏳ |
| S6.5 | Implementare validate_map() in validate_map.c | Gabriela | ⏳ |

---

## Sprint 10: Bonus ⏳

### Obiettivi
- [ ] Wall collisions
- [ ] Minimap
- [ ] Doors
- [ ] Sprites
- [ ] Mouse rotation

---

## File Creati/Modificati

### Documentazione
```
docs/
├── progetto/
│   ├── divisione_lavoro_cub3D.txt
│   ├── scaletta_cub3D_Gabriela.txt
│   ├── scaletta_ilaria.txt
│   ├── cyber_escape_storia.txt
│   ├── restrizioni_progetto.md
│   ├── regole_repo_42.md
│   └── sprint_backlog.md
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
│   ├── events.c        (init_mlx, create_window, setup_hooks, start_loop, close_window)
│   └── keys.c          (init_keys, key_press, key_release)
├── render/
│   ├── render.c        (init_image, my_mlx_pixel_put, clear_image, render)
│   ├── draw_walls.c    (TODO)
│   └── draw_floor_ceiling.c (TODO)
├── raycaster/
│   ├── raycaster.c     (TODO)
│   ├── dda.c           (TODO)
│   └── player_move.c   (is_walkable, rotate_player, move_forward_back, move_strafe, move_player)
├── parser/
│   ├── parse_file.c    (TODO)
│   ├── parse_textures.c (TODO)
│   ├── parse_colors.c  (TODO)
│   ├── parse_map.c     (TODO)
│   └── validate_map.c  (TODO)
└── utils/
    ├── error.c         (error_exit)
    ├── free.c          (free_map, free_textures, free_main_image, free_game)
    └── utils.c        (free_str_array, safe_free, create_color)
```

### Mappe
```
maps/
├── test.cub
└── edge_cases_test.txt
```

---

## Prossimi Passi

1. **Implementsare DDA algorithm** (S7.6) - Ilaria
2. **Implementare raycast()** (S7.7) - Ilaria
3. **Implementare draw_wall()** (S7.8) - Ilaria
4. **Implementare draw_floor_ceiling()** (S7.9) - Ilaria
5. **Implementare Parser** (S6) - Gabriela

---

## Note

- Il rendering e gli eventi sono funzionanti
- Mancano: DDA, raycasting, disegno muri
- Le funzioni di utilità (free_str_array, safe_free) sono generiche e riutilizzabili
- Tutto il codice e commentato per chiarezza

---

*Ultimo aggiornamento: 10 Marzo 2026*
