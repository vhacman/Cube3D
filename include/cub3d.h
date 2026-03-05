/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:27:38 by marvin            #+#    #+#             */
/*   Updated: 2026/03/05 22:27:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ============================================================================ */
/* PROTOTIPI DELLE FUNZIONI */
/* ============================================================================ */

/* 
 * ============================================================================
 * FUNZIONI DI INIZIALIZZAZIONE
 * ============================================================================
 */

/* TODO: Inizializza il gioco */
/* 
 * Parametri: percorso del file .cub da leggere
 * Cosa fa: alloca t_game, inizializza mlx, parsing file, carica texture, inizializza mappa e giocatore
 * Restituisce: puntatore a t_game, NULL se errore
 * File: src/main.c (o creare init_game.c)
 */

/* 
 * ============================================================================
 * FUNZIONI DI PARSING
 * ============================================================================
 */

/* TODO: Parsa l'intero file .cub */
/* 
 * Parametri: puntatore a t_game, percorso del file .cub
 * Cosa fa: apre e legge il file riga per riga, identifica elementi, valida e memorizza
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_file.c
 */

/* TODO: Parsa le texture dei muri */
/* 
 * Parametri: puntatore a t_game, riga del file .cub
 * Cosa fa: estrae identificatore e percorso XPM, verifica esistenza, memorizza in textures[4]
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_textures.c
 */

/* TODO: Parsa i colori */
/* 
 * Parametri: puntatore a t_game, riga del file .cub
 * Cosa fa: estrae identificatore F/C, estrae RGB, valida range 0-255, converte in colore
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_colors.c
 */

/* TODO: Parsa la mappa */
/* 
 * Parametri: puntatore a t_game, array di righe
 * Cosa fa: legge righe successive, costruisce griglia 2D, trova posizione giocatore
 * Restituisce: 0 se ok, 1 se errore
 * File: src/parser/parse_map.c
 */

/* TODO: Valida la mappa */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: controlla mappa chiusa, esattamente un giocatore, caratteri validi
 * Restituisce: 0 se valida, 1 se non valida
 * File: src/parser/validate_map.c
 */

/* 
 * ============================================================================
 * FUNZIONI DI RAY-CASTING
 * ============================================================================
 */

/* TODO: Esegue il ray-casting per un frame */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: per ogni colonna x, calcola direzione raggio, esegue DDA, disegna striscia
 * File: src/raycaster/raycaster.c
 */

/* TODO: Algoritmo DDA */
/* 
 * Parametri: puntatore a t_game, indice colonna x
 * Cosa fa: calcola deltaDist, sideDist, loop fino a muro, restituisce distanza perpendicolare
 * Restituisce: distanza perpendicolare al muro
 * File: src/raycaster/dda.c
 */

/* TODO: Muove il giocatore */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: controlla flag tasti, muove avanti/indietro/strafe, ruota, controlla collisioni
 * File: src/raycaster/player_move.c
 */

/* 
 * ============================================================================
 * FUNZIONI DI RENDERING
 * ============================================================================
 */

/* TODO: Rendering principale */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: pulisce immagine, esegue ray-casting, gestisce sprite, mette immagine in finestra
 * File: src/render/render.c
 */

/* TODO: Disegna le colonne dei muri */
/* 
 * Parametri: puntatore a t_game, indice colonna x, distanza, lato
 * Cosa fa: calcola altezza colonna, punto iniziale/finale, seleziona texture, applica
 * File: src/render/draw_walls.c
 */

/* TODO: Disegna pavimento e soffitto */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: riempie meta superiore con ceiling_color, meta inferiore con floor_color
 * File: src/render/draw_floor_ceiling.c
 */

/* TODO: Carica una texture */
/* 
 * Parametri: puntatore a miniLibX, percorso file XPM, puntatori per width e height
 * Cosa fa: carica file XPM, ottiene indirizzo pixel, memorizza dimensioni
 * Restituisce: puntatore a t_img, NULL se errore
 * File: src/render/textures.c
 */

/* TODO: Rendering degli sprite */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: calcola distanza sprite, ordina per distanza, disegna se davanti al muro
 * File: src/render/sprites.c
 */

/* 
 * ============================================================================
 * FUNZIONI DI EVENTI
 * ============================================================================
 */

/* TODO: Gestore del click sulla X */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: libera memoria, esce con exit(0)
 * Restituisce: 0 (convenzione mlx_hook)
 * File: src/events/events.c
 */

/* TODO: Gestore del tasto premuto */
/* 
 * Parametri: codice del tasto, puntatore a t_game
 * Cosa fa: imposta flag corrispondente, se ESC chiude gioco
 * Restituisce: 0
 * File: src/events/keys.c
 */

/* TODO: Gestore del tasto rilasciato */
/* 
 * Parametri: codice del tasto, puntatore a t_game
 * Cosa fa: azzera flag corrispondente
 * Restituisce: 0
 * File: src/events/keys.c
 */

/* 
 * ============================================================================
 * FUNZIONI DI UTILITA
 * ============================================================================
 */

/* TODO: Stampa errore e esci */
/* 
 * Parametri: puntatore a t_game (puo essere NULL), messaggio di errore
 * Cosa fa: stampa Error su stderr, stampa messaggio, libera memoria, esce con exit(1)
 * File: src/utils/error.c
 */

/* TODO: Libera tutta la memoria */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: libera mappa, path texture, immagini, finestra, mlx
 * File: src/utils/free.c
 */

/* TODO: Crea un colore */
/* 
 * Parametri: componenti red, green, blue (0-255)
 * Restituisce: colore nel formato 0x00RRGGBB
 * File: src/utils/utils.c (o creare color_utils.c)
 */

/* 
 * ============================================================================
 * FUNZIONI BONUS
 * ============================================================================
 */

/* TODO: Rendering minimappa */
/* File: src/bonus/minimap_bonus.c */

/* TODO: Gestione porte */
/* File: src/bonus/doors_bonus.c */

/* TODO: Rotazione con il mouse */
/* File: src/bonus/mouse_bonus.c */

/* TODO: Sprite animato */
/* File: src/bonus/sprites_anim_bonus.c */

#endif
