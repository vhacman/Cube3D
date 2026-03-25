/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/23 00:00:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FILE: keys_bonus.c
** AUTORE: Gabriela (vhacman)
** PERCHE': Versione bonus di keys.c - identica al mandatory ma con la
**          gestione del tasto E per aprire le porte (handle_doors).
**          Separata in file distinto: #ifdef dentro il corpo di una funzione
**          e' vietato dalla norminette. Compilata solo con make bonus.
**          Sostituisce src/events/keys.c nel build bonus.
**
** CHIAMATA DA: mlx_hook (evento KeyPress/KeyRelease), registrato in events.c.
*/

#include "cub3d.h"

/* Inizializza tutti i flag tasti a 0 (non premuto). */
void	init_keys(t_game *game)
{
	game->keys.w = 0;
	game->keys.s = 0;
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
	game->keys.esc = 0;
}

/* Gestore pressione tasto: imposta il flag corrispondente.
 * KEY_E apre la porta davanti al giocatore (bonus porte). */
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->keys.w = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->keys.s = 1;
	else if (keycode == KEY_A || keycode == KEY_Q)
		game->keys.a = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	else if (keycode == KEY_E)
		handle_doors(game);
	else if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

/* Gestore rilascio tasto: azzera il flag corrispondente. */
int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->keys.w = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->keys.s = 0;
	else if (keycode == KEY_A || keycode == KEY_Q)
		game->keys.a = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}
