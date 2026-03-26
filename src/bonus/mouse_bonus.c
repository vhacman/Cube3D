/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/23 00:00:00 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FILE: mouse_bonus.c
** AUTORE: Ilaria (ilnassi) - da implementare
** PERCHE': Bonus opzionale: rotazione del punto di vista con il mouse.
**          Muovendo il mouse a sinistra/destra il giocatore ruota come con
**          le frecce, ma in modo piu' naturale e preciso.
**
** COME FUNZIONERA' (da implementare):
**   - Registrare mlx_hook con evento MotionNotify (evento 6) in events.c.
**   - Calcolare il delta_x tra la posizione corrente e il centro della finestra.
**   - Usare quel delta per chiamare rotate_player() con velocita' proporzionale.
**   - Riportare il cursore al centro ogni frame
**     per evitare che esca dalla finestra.
**
** STATO: stub — funzione dichiarata ma non implementata.
**        Il prototipo e' in cub3d.h, richiesto dal linker per make bonus.
*/

#include "cub3d.h"

/*Stub: rotazione del punto di vista con il mouse.
Parametri: x, y = coordinate correnti del cursore, game = puntatore al gioco.
Non ancora implementata: da completare da Ilaria.
Scritta da: Ilaria (stub) */
int	mouse_move(int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	(void)game;
	return (0);
}
