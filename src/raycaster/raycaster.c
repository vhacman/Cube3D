/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 00:14:52 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/16 03:19:28 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* Esegue il ray-casting per un frame completo.
Per ogni colonna x da 0 a SCREEN_WIDTH-1:
 *   1. camera_x: posizione nel piano camera, da -1 (sx) a +1 (dx)
 *   2. ray_dir: direzione del raggio = dir + plane * camera_x
 *   3. perform_dda: avanza fino al muro, restituisce distanza perpendicolare
 *   4. draw_wall: disegna la colonna verticale con altezza proporzionale
 * La colonna centrale (x = SCREEN_WIDTH/2) corrisponde alla direzione
 * esatta del giocatore (camera_x = 0). */
void	raycast(t_game *game)
{
	int		x;
	double	camera_x;
	double	perp_wall_dist;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2.0 * x / (double)SCREEN_WIDTH - 1.0;
		game->player.ray_dir_x = game->player.dir_x
			+ game->player.room_plane_x * camera_x;
		game->player.ray_dir_y = game->player.dir_y
			+ game->player.room_plane_y * camera_x;
		perp_wall_dist = perform_dda(game, x);
		draw_wall(game, x, perp_wall_dist, game->player.hit_side);
		x++;
	}
}
