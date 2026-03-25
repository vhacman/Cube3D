/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:51:13 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/22 15:01:55 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Controlla se una cella della mappa e' percorribile (non e' un muro).
 * Restituisce 1 se percorribile, 0 se muro o fuori dai limiti. */
int	is_walkable(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->map.width || map_y < 0
		|| map_y >= game->map.height)
		return (0);
	if (game->map.grid[map_y][map_x] == '1'
		|| game->map.grid[map_y][map_x] == '2')
		return (0);
	return (1);
}

/* Ruota il giocatore applicando la matrice di rotazione 2D al vettore
 * direzione e al piano camera. rot_speed negativo = sinistra. */
void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.room_plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	game->player.room_plane_x = game->player.room_plane_x * cos(rot_speed)
		- game->player.room_plane_y * sin(rot_speed);
	game->player.room_plane_y = old_plane_x * sin(rot_speed)
		+ game->player.room_plane_y * cos(rot_speed);
}

/* Muove avanti (direction=1) o indietro (direction=-1).
 * Calcola la nuova posizione e la applica asse per asse
 * solo se e' percorribile (collision sliding). */
void	move_forward_back(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED * direction;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED * direction;
	if (is_walkable(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_walkable(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

/* Spostamento laterale (strafe). direction=-1 = sinistra, 1 = destra.
 * Vettore perpendicolare: (dir_y, -dir_x). */
void	move_strafe(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED * direction;
	new_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED * direction;
	if (is_walkable(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_walkable(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

/* Applica il movimento ogni frame in base ai flag tasti.
 * W/S = avanti/indietro, A/D = strafe, frecce = rotazione. */
void	move_player(t_game *game)
{
	if (game->keys.w)
		move_forward_back(game, 1);
	if (game->keys.s)
		move_forward_back(game, -1);
	if (game->keys.a)
		move_strafe(game, -1);
	if (game->keys.d)
		move_strafe(game, 1);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
}
