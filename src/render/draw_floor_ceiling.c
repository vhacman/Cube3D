/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:16:17 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/16 03:21:25 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Riempie la meta' superiore dello schermo con il colore del soffitto.
 * game->ceiling_color e' impostato dal parser dalla riga C nel .cub. */
static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&game->img, x, y, game->ceiling_color);
			x++;
		}
		y++;
	}
}

/* Riempie la meta' inferiore dello schermo con il colore del pavimento.
 * game->floor_color e' impostato dal parser dalla riga F nel .cub. */
static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&game->img, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}

/* Disegna pavimento e soffitto per il frame corrente.
 * Chiamata prima del raycasting cosi' i muri vengono disegnati sopra. */
void	draw_floor_ceiling(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
