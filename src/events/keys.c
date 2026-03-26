/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusione dell'header principale del progetto */
#include "cub3d.h"

/* Inizializza lo stato di tutti i tasti a "non premuto".
 * I flag sono usati per il movimento fluido: il movimento effettivo
 * avviene nel game loop, non direttamente alla pressione del tasto. */
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

/* Gestore del tasto premuto: imposta a 1 il flag del tasto corrispondente.
 * Se viene premuto ESC, chiude direttamente il gioco.
 * Restituisce 0 per convenzione richiesta da mlx_hook. */
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
	else if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

/* Gestore del tasto rilasciato: imposta a 0 il flag del tasto.
 * Restituisce 0 per convenzione richiesta da mlx_hook. */
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
