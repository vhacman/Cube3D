
#ifndef CUB3D_H
# define CUB3D_H

/* INCLUDES */

# include <mlx.h>
# include "../libft/includes/libft.h"
# include "structs.h"
# include "defines.h"

/* PROTOTIPI DELLE FUNZIONI */

/* 
 * FUNZIONI DI INIZIALIZZAZIONE
 */

/*
 * Inizializza il gioco
 * Parametri: percorso del file .cub da leggere
 * Cosa fa: alloca t_game, inizializza mlx, parsing file, carica 
 * texture, inizializza mappa e giocatore
 * Restituisce: puntatore a t_game, NULL se errore
 * File: src/main.c
 */
t_game	*init_game(char *cub_path);

/* 
 * FUNZIONI DI PARSING
 */

/*
 * Parsa l'intero file .cub
 * Parametri: puntatore a t_game, percorso del file .cub
 * Cosa fa: apre e legge il file riga per riga, identifica elementi, valida e memorizza
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_file.
 */
int		parse_file(t_game *game, char *cub_path);

/*
 * Parsa le texture dei muri
 * Parametri: puntatore a t_game, riga del file .cub
 * Cosa fa: estrae identificatore e percorso XPM, verifica esistenza, memorizza in textures[4]
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_textures.c
 */
int		parse_texture(t_game *game, char *line);

/*
 * Parsa i colori
 * Parametri: puntatore a t_game, riga del file .cub
 * Cosa fa: estrae identificatore F/C, estrae RGB, valida range 0-255, converte in colore
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_colors.c
 */
int		parse_color(t_game *game, char *line);

/*
 * Parsa la mappa
 * Parametri: puntatore a t_game, array di righe
 * Cosa fa: legge righe successive, costruisce griglia 2D, trova posizione giocatore
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_map.c
 */
int		parse_map(t_game *game, char **lines);

/*
 * Valida la mappa
 * Parametri: puntatore a t_game
 * Cosa fa: controlla mappa chiusa, esattamente un giocatore, caratteri validi
 * Restituisce: 0 se valida, 1 se non valida
 * File: src/parser/validate_map.c
 */
int		validate_map(t_game *game);

/* 
 * FUNZIONI DI RAY-CASTING
 */

/*
 * Esegue il ray-casting per un frame
 * Parametri: puntatore a t_game
 * Cosa fa: per ogni colonna x, calcola direzione raggio, esegue DDA, disegna striscia
 * File: src/raycaster/raycaster.c
 */
void	raycast(t_game *game);

/*
 * Algoritmo DDA
 * Parametri: puntatore a t_game, indice colonna x
 * Cosa fa: calcola deltaDist, sideDist, loop fino a muro, restituisce distanza perpendicolare
 * Restituisce: distanza perpendicolare al muro
 * File: src/raycaster/dda.c
 */
double	perform_dda(t_game *game, int x);

/*
 * Muove il giocatore
 * Parametri: puntatore a t_game
 * Cosa fa: controlla flag tasti, muove avanti/indietro/spostamento laterale, ruota, controlla collisioni
 * File: src/raycaster/player_move.c
 */
void	move_player(t_game *game);

/* 
 * FUNZIONI DI RENDERING
 */

/*
 * Rendering principale
 * Parametri: puntatore a t_game
 * Cosa fa: pulisce immagine, esegue ray-casting, gestisce sprite, mette immagine in finestra
 * File: src/render/render.c
 */
int		render(t_game *game);

/*
 * Disegna le colonne dei muri
 * Parametri: puntatore a t_game, indice colonna x, distanza, lato
 * Cosa fa: calcola altezza colonna, punto iniziale/finale, seleziona texture, applica
 * File: src/render/draw_walls.c
 */
void	draw_wall(t_game *game, int x, double perp_wall_dist, int side);

/*
 * Disegna pavimento e soffitto
 * Parametri: puntatore a t_game
 * Cosa fa: riempie meta superiore con ceiling_color, meta inferiore con floor_color
 * File: src/render/draw_floor_ceiling.c
 */
void	draw_floor_ceiling(t_game *game);

/*
 * Carica una texture
 * Parametri: puntatore a miniLibX, percorso file XPM, puntatori per width e height
 * Cosa fa: carica file XPM, ottiene indirizzo pixel, memorizza dimensioni
 * Restituisce: puntatore a t_img, NULL se errore
 * File: src/render/textures.c
 */
t_img	*load_texture(void *mlx, char *path, int *width, int *height);

/*
 * Rendering degli sprite
 * Parametri: puntatore a t_game
 * Cosa fa: calcola distanza sprite, ordina per distanza, disegna se davanti al muro
 * File: src/render/sprites.c
 */
void	render_sprites(t_game *game);

/* 
 * FUNZIONI DI EVENTI
 */

/*
 * Gestore del click sulla X
 * Parametri: puntatore a t_game
 * Cosa fa: libera memoria, esce con exit(0)
 * Restituisce: 0 (convenzione mlx_hook)
 * File: src/events/events.c
 */
int		close_window(t_game *game);

/*
 * Gestore del tasto premuto
 * Parametri: codice del tasto, puntatore a t_game
 * Cosa fa: imposta flag corrispondente, se ESC chiude gioco
 * Restituisce: 0
 * File: src/events/keys.c
 */
int		key_press(int keycode, t_game *game);

/*
 * Gestore del tasto rilasciato
 * Parametri: codice del tasto, puntatore a t_game
 * Cosa fa: azzera flag corrispondente
 * Restituisce: 0
 * File: src/events/keys.c
 */
int		key_release(int keycode, t_game *game);

/* 
 * FUNZIONI DI UTILITA
 */

/*
 * Stampa errore e esci
 * Parametri: puntatore a t_game (puo essere NULL), messaggio di errore
 * Cosa fa: stampa Error su stderr, stampa messaggio, libera memoria, esce con exit(1)
 * File: src/utils/error.c
 */
void	error_exit(t_game *game, char *message);

/*
 * Libera tutta la memoria
 * Parametri: puntatore a t_game
 * Cosa fa: libera mappa, path texture, immagini, finestra, mlx
 * File: src/utils/free.c
 */
void	free_game(t_game *game);

/*
 * Crea un colore
 * Parametri: componenti red, green, blue (0-255)
 * Restituisce: colore nel formato 0x00RRGGBB
 * File: src/utils/color_utils.c
 */
int		create_color(int r, int g, int b);

/* 
 * FUNZIONI BONUS
 */

/*
 * Rendering minimappa
 * File: src/bonus/minimap_bonus.c
 */
void	render_minimap(t_game *game);

/*
 * Gestione porte
 * File: src/bonus/doors_bonus.c
 */
void	handle_doors(t_game *game);

/*
 * Rotazione con il mouse
 * File: src/bonus/mouse_bonus.c
 */
int		mouse_move(int x, int y, t_game *game);

/*
 * Sprite animato
 * File: src/bonus/sprites_anim_bonus.c
 */
void	render_animated_sprites(t_game *game);

#endif
