# Restrizioni del Progetto cub3D

Questo documento elenca tutte le restrizioni del progetto cub3D in base al subject ufficiale.

---

## 1. Funzioni Esterne Autorizzate

### 1.1 Funzioni Standard C
- `open` - Apertura file
- `close` - Chiusura file
- `read` - Lettura da file descriptor
- `write` - Scrittura su file descriptor
- `printf` - Formattazione e stampa
- `malloc` - Allocazione dinamica memoria
- `free` - Liberazione memoria
- `perror` - Messaggi di errore
- `strerror` - Stringa descrizione errore
- `exit` - Terminazione programma
- `gettimeofday` - Tempo sistema

### 1.2 Libreria Math (`-lm`)
Tutte le funzioni della libreria math sono autorizzate.
Esempi comuni:
- `sin`, `cos`, `tan` - Funzioni trigonometriche
- `sqrt` - Radice quadrata
- `pow` - Potenza
- `fabs` - Valore assoluto

### 1.3 MiniLibX
Tutte le funzioni della libreria MiniLibX sono autorizzate:
- Gestione finestre
- Gestione immagini
- Gestione eventi
- Gestione colori
- Gestione pixel

### 1.4 Libft
- **Autorizzata**: SÌ
- Deve essere inclusa nella cartella `libft/` del progetto
- Il Makefile deve compilare la libreria prima del progetto

---

## 2. Funzioni NON Autorizzate

### 2.1 Qualsiasi altra funzione di libreria
- NON usare funzioni non elencate sopra
- NON usare `scanf`, `fopen`, `fread`, `fprintf`, `fclose` (usa `open`/`close`/`read`/`write`)
- NON usare `strcpy`, `strcat`, `strlen` (usa Libft)
- NON usare `atoi`, `itoa` (usa Libft)

### 2.2 Funzioni grafiche NON MiniLibX
- NON usare SDL, SFML, OpenGL, GTK, Qt
- NON usare altre librerie grafiche

---

## 3. Regole di Compilazione

### 3.1 Makefile
Il Makefile deve contenere almeno:
- `$(NAME)` - Nome eseguibile
- `all` - Compila tutto
- `clean` - Rimuove file oggetto
- `fclean` - Rimuove file oggetto + eseguibile
- `re` - Ricompila da zero
- `bonus` - Compila bonus (se presenti)

### 3.2 Flag Obbligatori
```bash
cc -Wall -Wextra -Werror
```

### 3.3 Librerie
```bash
-lmlx -lm -lXext -lX11
```

---

## 4. Regole di Norm

### 4.1 Norminette
- Il progetto deve rispettare la Norm 42
- Verificare con: `norminette -R CheckForbiddenSourceHeader .`

### 4.2 Header File
Ogni file `.c` e `.h` deve avere l'header 42:
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      ::::::::   */
/*                                                    +:+ +:+         +:     */
/*   By: nome <login@student.42.fr>                  +#++:  +#++:         */
/*                                                    +#++:  +#++:         */
/*   Created: #++#++:  ##:##:## by nome              #+#    #+#           */
/*   Updated: ###  #+# .##:##.#+  by nome            #+#    #+#           */
/*                                                                            */
/* ************************************************************************** */
```

---

## 5. Gestione Errori

### 5.1 Errori nel File .cub
- Qualsiasi errore di configurazione nel file .cub deve:
  - Terminare il programma correttamente
  - Stampare "Error\n" seguito da un messaggio di errore esplicito
  - NON causare crash o comportamenti indefiniti

### 5.2 Errori di Memoria
- Tutta la memoria heap allocata deve essere liberata correttamente
- Memory leaks non tollerati
- Usare `valgrind` per verificare: `valgrind --leak-check=full ./cub3D maps/test.cub`

---

## 6. Formato Mappe

### 6.1 Caratteri Permessi
- `0` - Spazio vuoto
- `1` - Muro
- `N` - Giocatore (inizio) - Direzione Nord
- `S` - Giocatore (inizio) - Direzione Sud
- `E` - Giocatore (inizio) - Direzione Est
- `W` - Giocatore (inizio) - Direzione Ovest

### 6.2 Elementi Mappa
La mappa deve essere:
- Chiusa/circondata da muri
- Parsata così come appare nel file
- L'ultimo elemento nel file .cub

---

## 7. Requisiti Finestra

### 7.1 Comportamento Finestra
- La finestra deve rimanere fluida durante:
  - Cambio finestra
  - Minimizzazione
  - Ridimensionamento

### 7.2 Controlli Obbligatori
- `W/A/S/D` - Movimento giocatore
- `Freccia Sinistra/Destra` - Guardare a sinistra/destra
- `ESC` - Chiudere finestra e terminare programma
- `X rosso` - Chiudere finestra e terminare programma

---

## 8. Bonus

### 8.1 Bonus Consentiti
- Collisioni con muri
- Minimap
- Porte che si aprono/chiudono
- Sprite animate
- Rotazione vista con mouse

### 8.2 Regole Bonus
- I bonus vengono valutati solo se il mandatory è perfetto
- File bonus: `_bonus.{c/h}`
- Makefile deve avere regola `bonus`

---

## 9. Risorse Utili

- [MiniLibX Manual](https://harm-smits.github.io/42docs/libs/minilibx)
- [Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [Libft](https://github.com/42-Student/Libft)

---

*Documento basato su en.subject (1).pdf - Versione 12.0*
