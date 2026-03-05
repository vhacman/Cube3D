/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:27:21 by marvin            #+#    #+#             */
/*   Updated: 2026/03/05 22:27:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* ============================================================================ */
/* STRUTTURE DATI PER IL MOTORE RAY-CASTING */
/* ============================================================================ */

/* TODO: Immagine per il rendering */
/* 
 * Usata per l'immagine principale dello schermo (double buffering)
 * e per le texture caricate da file XPM.
 * 
 * Campi da definire:
 * - img: puntatore all'immagine MLX
 * - addr: indirizzo dei pixel in memoria
 * - bpp: bits per pixel (deve essere 32 per miniLibX)
 * - line_length: numero di byte per riga dell'immagine
 * - endian: ordine dei byte (little/big endian)
 */

/* TODO: Giocatore */
/* 
 * Rappresenta la telecamera del giocatore nel mondo 3D.
 * Il giocatore ha una posizione 2D nella mappa e un orientamento.
 * 
 * Campi da definire:
 * - pos_x, pos_y: coordinate nella mappa (decimali, es. pos_x = 3.5)
 * - dir_x, dir_y: vettore di direzione (dove guarda il giocatore)
 * - plane_x, plane_y: piano della camera (determina il FOV)
 * 
 * Orientamenti iniziali possibili:
 * - N: dir=(0,-1), plane=(0.66,0)
 * - S: dir=(0,1), plane=(-0.66,0)
 * - E: dir=(1,0), plane=(0,0.66)
 * - W: dir=(-1,0), plane=(0,-0.66)
 */

/* TODO: Mappa del gioco */
/* 
 * La mappa e una griglia 2D dove ogni cella contiene:
 * - 0 = spazio vuoto (si puo camminare)
 * - 1 = muro (collisione)
 * - N, S, E, W = posizione iniziale del giocatore
 * - 2 = porta (bonus)
 * - spazio = spazio vuoto, diverso da 0 per formato file
 * 
 * Campi da definire:
 * - grid: array di stringhe (ogni stringa = una riga della mappa)
 * - width: larghezza massima (numero di colonne)
 * - height: altezza (numero di righe)
 * - player_x, player_y: coordinate del giocatore nella griglia (int)
 * - player_dir: carattere che indica l'orientamento iniziale
 */

/* TODO: Texture */
/* 
 * Texture per i 4 lati dei muri.
 * L'ordine e importante: NO=0, SO=1, WE=2, EA=3
 * 
 * Campi da definire:
 * - img: immagine della texture caricata
 * - width, height: dimensioni (devono essere quadrati, es. 64x64)
 * - addr, bpp, line_length, endian: dati pixel
 * - path: percorso del file XPM (per debug e ricaricamento)
 */

/* TODO: Stato dei tasti */
/* 
 * Usato per il movimento fluido. Invece di muovere il giocatore
 * direttamente nell'handler del tasto, si impostano dei flag.
 * Nel game loop si controllano i flag e si muove il giocatore.
 * 
 * Campi da definire (booleani):
 * - w, s: avanti/indietro
 * - a, d: strafe sinistra/destra
 * - left, right: rotazione
 * - esc: uscire dal gioco
 */

/* TODO: Gioco principale */
/* 
 * Struct che contiene tutto il gioco. In questo modo e facile
 * passare un solo puntatore a tutte le funzioni.
 * 
 * Campi da definire:
 * - mlx: puntatore all'istanza miniLibX (mlx_init)
 * - win: puntatore alla finestra (mlx_new_window)
 * - img: immagine principale per il rendering
 * - textures[4]: array delle 4 texture muri (NO, SO, WE, EA)
 * - map: struttura della mappa
 * - player: struttura del giocatore
 * - keys: stato dei tasti
 * - floor_color: colore del pavimento (formato 0x00RRGGBB)
 * - ceiling_color: colore del soffitto
 * 
 * Bonus (da aggiungere quando implementati):
 * - z_buffer: array delle distanze dei muri per ogni colonna (per sprite)
 * - sprites: array degli sprite nella mappa
 * - num_sprites: numero di sprite
 */

#endif
