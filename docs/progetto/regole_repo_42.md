# Guida Push Repository 42 - cub3D

Questo documento spiega cosa pushare nella repository di 42, la struttura delle cartelle e come separare mandatory e bonus.

---

## 1. Struttura Directory (DA PUSHARE)

```
Cube3D/
├── Makefile              # obbligatorio
├── cub3D                 # eseguibile (dopo make)
├── include/              # header files
│   ├── cub3d.h
│   ├── structs.h
│   ├── defines.h
│   └── (altri .h)
├── src/                  # codice sorgente
│   ├── main.c
│   ├── parser/
│   │   ├── parser.c
│   │   ├── map_parser.c
│   │   └── textures.c
│   ├── raycasting/
│   │   ├── raycasting.c
│   │   ├── dda.c
│   │   └── wall_calc.c
│   ├── render/
│   │   ├── render.c
│   │   └── draw.c
│   ├── events/
│   │   ├── events.c
│   │   └── keys.c
│   └── utils/
│       ├── error.c
│       ├── free.c
│       └── utils.c
├── libft/                # libreria libft
│   ├── Makefile
│   ├── libft.h
│   └── src/
│       ├── ft_*.c
│       └── (altri .c)
└── maps/                 # mappe di test
    └── test.cub
```

---

## 2. File OBBLIGATORI da PUSHARE

### 2.1 Root
- ✅ `Makefile` - Compila tutto con regole: `all`, `clean`, `fclean`, `re`, `bonus`
- ✅ `cub3D` - Esegubile (generato da make)

### 2.2 Header Files
- ✅ `include/cub3d.h` - Header principale
- ✅ `include/structs.h` - Strutture dati
- ✅ `include/defines.h` - Costanti

### 2.3 Source Files
- ✅ `src/main.c` - Entry point
- ✅ `src/parser/` - Parsing file .cub
- ✅ `src/raycasting/` - Algoritmo raycasting
- ✅ `src/render/` - Rendering finestra
- ✅ `src/events/` - Gestione input
- ✅ `src/utils/` - Funzioni utility

### 2.4 Libreria
- ✅ `libft/` - Copia della libft completa

### 2.5 Mappe
- ✅ `maps/test.cub` - Mappa di test valida

---

## 3. File NON da PUSHARE

### 3.1 File Generati automaticamente
- ❌ `*.o` - File oggetto
- ❌ `cub3D` - Eseguibile (ricompilato da make)
- ❌ `.DS_Store` - File macOS
- ❌ `*~` - File backup

### 3.2 File di Test Personali
- ❌ `test_persianal*.c`
- ❌ `maps/altro_test.cub` (se non funziona)

### 3.3 Documentazione
- ❌ `docs/` - NON pushare (solo per voi)
- ❌ `README.md` (opzionale, può esserci)

### 3.4 Cache e Config
- ❌ `.norminette/` - Cache norminette
- ❌ `*.mlx` - File MiniLibX precompilati

---

## 4. Makefile Obbligatorio

Il Makefile DEVE contenere:

```makefile
NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Sorgenti
SRCS = src/main.c src/parser/parser.c ...

# Header
HEADERS = -I include -I libft/include

# Librerie
LIBFT = libft/libft.a
LIBM = -lm
MLX = -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(HEADERS) $(LIBFT) $(LIBM) $(MLX) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

bonus:
	# Compila bonus se presenti

.PHONY: all clean fclean re bonus
```

---

## 5. Mandatory vs Bonus

### 5.1 Mandatory (Obbligatorio)

Il gioco base DEVE includere:

- ✅ Finestra con rendering raycasting
- ✅ Movimento W/A/S/D
- ✅ Rotazione con frecce sinistra/destra
- ✅ Chiusura con ESC e X rosso
- ✅ Parsing file .cub
- ✅ Textures sui muri (4 direzioni)
- ✅ Colori floor e ceiling
- ✅ Gestione errori

**File naming:** solo `.c` e `.h` standard

### 5.2 Bonus (Opzionale)

**Regola del subject:** I bonus DEVONO essere in file `_bonus.{c/h}` (obbligatorio!)

```
src/
├── main.c              # Mandatory
├── parser/
│   └── parser.c        # Mandatory
├── raycasting/
│   └── raycasting.c    # Mandatory
├── bonus/              # Tutti i bonus nella stessa cartella
    ├── minimap_bonus.c     # File _bonus.c - OBBLIGATORIO!
    ├── collision_bonus.c  # File _bonus.c
    ├── door_bonus.c        # File _bonus.c
    └── sprite_bonus.c     # File _bonus.c
```

**Regole bonus (dal subject):**
- **OBBLIGATORIO**: File nominati `_bonus.{c/h}`
- Mandatory e bonus NELLA STESSA repo
- Makefile: regola `bonus` compila tutto
- Valutati SOLO se mandatory perfetto

**Bonus disponibili:**
- ✅ Wall collisions (rimbalzo sui muri)
- ✅ Minimap (miniatura della mappa)
- ✅ Porte che si aprono/chiudono
- ✅ Sprite animate
- ✅ Rotazione con mouse

### 5.3 Come Separare

**Opzione A: File Separati (Consigliata)**
```
src/
├── main.c           #Solo mandatory
├── mandatory/
│   ├── parser/
│   ├── raycasting/
│   └── render/
└── bonus/
    ├── minimap.c    #File _bonus.c
    └── collision.c  #File _bonus.c
```

**Opzione B: #ifdef**
```c
// In main.c
#ifdef BONUS
    // codice bonus
#endif
```

---

## 6. Norme 42 da Rispettare

### 6.1 Header File Obbligatorio

Ogni `.c` e `.h` DEVE avere:

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :::      ::::::::   */
/*                                                    +:+ +:+         +:     */
/*   By: login <login@student.42.fr>                  +#++:  +#++:         */
/*                                                    +#++:  +#++:         */
/*   Created: #### ##:##:## by login                  #+#    #+#           */
/*   Updated: ###  #+#+ .##:##.#+  by login          #+#    #+#           */
/*                                                                            */
/* ************************************************************************** */
```

### 6.2 Regole Norminette

```bash
norminette -R CheckForbiddenSourceHeader .
```

- NO tabs, solo spazi (4 spazi)
- MAX 25 linee per funzione (difficile ma si può fare)
- MAX 80 colonne
- NO più di 4 variabili per funzione
- NO file > 1000 righe

---

## 7. Check Pre-Push

Prima di pushare, eseguire:

```bash
# 1. Compila tutto?
make re

# 2. Norminette OK?
norminette -R CheckForbiddenSourceHeader .

# 3. No memory leaks?
valgrind --leak-check=full ./cub3D maps/test.cub

# 4. Esegui e test
./cub3D maps/test.cub
```

---

## 8. Git - Cosa Pushare

### 8.1 Branch Consigliato
- Pushare su branch personale, poi merge su `main` o `develop`

```bash
git add .
git commit -m "Implementazione parser e raycasting"
git push origin gabriela
```

### 8.2 NON Pushare
```bash
# NON fare mai:
git add *.o
git add cub3D
git add .DS_Store
```

---

## 9. README Consigliato

Creare `README.md` nella root:

```markdown
# cub3D

This project has been created as part of the 42 curriculum by <login>.

## Description
Realistic 3D maze using raycasting (Wolfenstein 3D style).

## Controls
- W/A/S/D: Move
- Left/Right Arrow: Rotate view
- ESC: Quit

## Compilation
```bash
make
./cub3D maps/test.cub
```

## Bonus
- Minimap
- Wall collisions
- Doors

## Resources
- [Lodev Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
```

---

## 10. Riepilogo Finale

| Cosa | Pushare | Note |
|------|---------|------|
| Makefile | ✅ SÌ | Obbligatorio |
| src/*.c | ✅ SÌ | Solo codice funzionante |
| include/*.h | ✅ SÌ | Header con norm |
| libft/ | ✅ SÌ | Copia completa |
| maps/test.cub | ✅ SÌ | Almeno una mappa |
| docs/ | ❌ NO | Solo per voi |
| *.o | ❌ NO | Ignorare |
| cub3D | ❌ NO | Generato da make |
| file test personali | ❌ NO | Ignorare |

---

*Documento per il team Gabriela + Ilaria*
