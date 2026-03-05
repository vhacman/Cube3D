/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:27:31 by marvin            #+#    #+#             */
/*   Updated: 2026/03/05 22:27:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* ============================================================================ */
/* COSTANTI E CONFIGURAZIONE DEL GIOCO */
/* ============================================================================ */

/* TODO: Risoluzione dello schermo */
/* 
 * Valori suggeriti:
 * - 1920x1080 (full HD)
 * - 1280x720 (HD)
 * - 800x600 (classico, piu veloce)
 * - 640x480 (minimo, molto veloce)
 */

/* TODO: Definire la risoluzione orizzontale */

/* TODO: Definire la risoluzione verticale */


/* TODO: Dimensioni delle texture */
/* 
 * Le texture devono essere quadrate. Valori comuni:
 * - 64x64 (standard, veloce)
 * - 128x128 (dettaglio maggiore)
 * - 512x512 (massimo dettaglio, piu lento)
 * 
 * NOTA: devono essere potenze di 2 per alcune operazioni bitwise
 */

/* TODO: Definire la larghezza texture */

/* TODO: Definire l'altezza texture */


/* TODO: Velocita di movimento e rotazione */
/* 
 * Valori tipici:
 * - move_speed: 0.03 - 0.1 (0.05 e un buon punto di partenza)
 * - rot_speed: 0.02 - 0.08 (0.03 e un buon punto di partenza)
 * 
 * Valori piu alti = movimento piu veloce
 */

/* TODO: Definire la velocita di movimento (avanti/indietro/strafe) */

/* TODO: Definire la velocita di rotazione (frecce sinistra/destra) */


/* TODO: Codici dei tasti (Linux) */
/* 
 * Questi sono i keycode per Linux. Per macOS sono diversi.
 * Se il gioco non risponde ai tasti, verificare che i codici siano corretti.
 * 
 * Valori standard Linux:
 * - ESC: 65307
 * - W: 119, A: 97, S: 115, D: 100
 * - Z: 122, Q: 113 (versione francese ZQSD)
 * - Freccia SU: 65362, GIU: 65364, SX: 65361, DX: 65363
 */

/* TODO: Definire il codice del tasto ESC (uscita) */

/* TODO: Definire il codice del tasto W (avanti) */

/* TODO: Definire il codice del tasto A (strafe sinistra) */

/* TODO: Definire il codice del tasto S (indietro) */

/* TODO: Definire il codice del tasto D (strafe destra) */

/* TODO: Definire il codice del tasto Z (avanti, versione ZQSD) */

/* TODO: Definire il codice del tasto Q (strafe sinistra, versione ZQSD) */

/* TODO: Definire il codice della freccia SU (avanti) */

/* TODO: Definire il codice della freccia GIU (indietro) */

/* TODO: Definire il codice della freccia SX (rotazione sinistra) */

/* TODO: Definire il codice della freccia DX (rotazione destra) */


/* TODO: Eventi miniLibX */
/* 
 * Codici degli eventi per mlx_hook:
 * - KeyPress: 2
 * - KeyRelease: 3
 * - DestroyNotify: 17 (click sulla X della finestra)
 * 
 * Maschere (usate nel secondo parametro di mlx_hook):
 * - KeyPressMask: 1L<<0
 * - KeyReleaseMask: 1L<<1
 */

/* TODO: Definire l'evento tasto premuto */

/* TODO: Definire l'evento tasto rilasciato */

/* TODO: Definire l'evento chiusura finestra (click X) */

/* TODO: Definire la maschera per KeyPress */

/* TODO: Definire la maschera per KeyRelease */


/* TODO: Colori */
/* 
 * I colori sono nel formato 0x00RRGGBB (32 bit)
 * - Rosso: (255 << 16)
 * - Verde: (255 << 8)
 * - Blu: 255
 * 
 * Creazione colore: (r << 16 | g << 8 | b)
 */

/* TODO: Definire il colore nero (muro base se nessuna texture) */

/* TODO: Definire il colore bianco */

/* TODO: Definire il colore rosso */

/* TODO: Definire il colore verde */

/* TODO: Definire il colore blu */


/* TODO: Valori speciali */
/* 
 * Usati per indicare errori o stati speciali
 */

/* TODO: Definire un valore infinito (per deltaDist quando rayDir e 0) */

/* TODO: Definire il valore booleano falso */

/* TODO: Definire il valore booleano vero */


/* ============================================================================ */
/* AGGIUNGERE ALTRE COSTANTI QUI SE NECESSARIO */
/* ============================================================================ */

#endif
