/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:56:49 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/23 14:56:49 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <math.h>

/* RISOLUZIONE SCHERMO */

/*
 * Risoluzione della finestra di gioco.
 * Valore predefinito: 1280x720 (HD)
 * Nota: la risoluzione non e' piu' richiesta nel file .cub (2026)
 */
# define SCREEN_WIDTH		1280
# define SCREEN_HEIGHT		720

/* DIMENSIONI TEXTURE */

/*
 * Dimensioni delle texture dei muri.
 * Devono essere quadrate e preferibilmente potenze di 2.
 * Standard: 64x64
 */
# define TEXTURE_WIDTH		64
# define TEXTURE_HEIGHT		64

/* VELOCITA DI MOVIMENTO E ROTAZIONE */

/*
 * Velocita' di movimento (avanti/indietro/spostamento laterale).
 * Valori tipici: 0.03 - 0.1
 */
# define MOVE_SPEED		0.05

/*
 * Velocita' di rotazione (frecce sinistra/destra).
 * Valori tipici: 0.02 - 0.08
 */
# define ROT_SPEED		0.03

/* CODICI DEI TASTI (LINUX) */

/*
 * Keycode per Linux.
 * Nota: per macOS i valori sono diversi.
 */
# define KEY_ESC			65307
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_Z				122
# define KEY_Q				113
# define KEY_UP				65362
# define KEY_DOWN			65364
# define KEY_LEFT			65361
# define KEY_RIGHT			65363

/* EVENTI MINILIBX */

/*
 * Codici eventi per mlx_hook:
 * - KeyPress: 2 (tasto premuto)
 * - KeyRelease: 3 (tasto rilasciato)
 * - DestroyNotify: 17 (click sulla X della finestra)
 */
# define EVENT_KEY_PRESS		2
# define EVENT_KEY_RELEASE	3
# define EVENT_DESTROY_NOTIFY	17

/*
 * Maschere eventi:
 * - KeyPressMask: 1
 * - KeyReleaseMask: 2
 */
# define MASK_KEY_PRESS		1
# define MASK_KEY_RELEASE		2

/* COLORI */

/*
 * Colori nel formato 0x00RRGGBB (32 bit)
 * Creazione: (r << 16 | g << 8 | b)
 */
# define COLOR_BLACK		0x00000000
# define COLOR_WHITE		0x00FFFFFF
# define COLOR_RED			0x00FF0000
# define COLOR_GREEN		0x0000FF00
# define COLOR_BLUE			0x000000FF

/* Colori default per floor e ceiling (valori RGB) */
# define DEFAULT_FLOOR_COLOR		0x00555555
# define DEFAULT_CEILING_COLOR	0x00333333

/* VALORI SPECIALI */

/*
 * Valore "infinito" per deltaDist quando rayDir e' 0.
 * Usato nell'algoritmo DDA per evitare divisione per zero.
 */
# define INF				1e30

/*
 * Valori booleani.
 * Se libft e' disponibile, usare t_bool TRUE/FALSE
 */
# define FALSE				0
# define TRUE				1

/* INDICI TEXTURE MURI */

/*
 * Indici dell'array textures[4] in t_game.
 * Corrispondono alle direzioni: Nord, Sud, Ovest, Est
 */
# define TEX_NO				0
# define TEX_SO				1
# define TEX_WE				2
# define TEX_EA				3

/* TASTO INTERAZIONE PORTE */

# define KEY_E				101

/* MINIMAP */

# define MINIMAP_SCALE		6
# define MINIMAP_MARGIN		10
# define MINIMAP_WALL_COLOR	0x00FFFFFF
# define MINIMAP_FLOOR_COLOR	0x00444444
# define MINIMAP_DOOR_COLOR	0x00FF8800
# define MINIMAP_PLAYER_COLOR	0x00FF0000
# define MINIMAP_DIR_COLOR	0x00FFFF00

/* AGGIUNGERE ALTRE COSTANTI QUI SE NECESSARIO */

#endif
