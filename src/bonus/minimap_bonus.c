/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/23 00:00:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FILE: minimap_bonus.c
** AUTORE: Gabriela (vhacman)
** PERCHE': Bonus: visualizzare una mappa 2D in overlay sulla scena 3D.
**          La minimap viene disegnata sul buffer immagine prima di
**          inviarlo alla finestra, cosi' appare sopra il rendering 3D.
**          Ogni cella e' un quadrato MINIMAP_SCALE x MINIMAP_SCALE pixel.
**          Il giocatore e' un punto rosso con direzione gialla.
** CHIAMATA DA: render() in src/bonus/render_bonus.c, ogni frame.
*/

#include "cub3d.h"

/* Disegna una cella come quadrato MINIMAP_SCALE x MINIMAP_SCALE pixel.
 * px/py = angolo in alto a sinistra nel buffer schermo. */
static void	draw_mm_cell(t_game *g, int mx, int my, int color)
{
	int	px;
	int	py;
	int	x;
	int	y;

	px = MINIMAP_MARGIN + mx * MINIMAP_SCALE;
	py = MINIMAP_MARGIN + my * MINIMAP_SCALE;
	y = py;
	while (y < py + MINIMAP_SCALE)
	{
		x = px;
		while (x < px + MINIMAP_SCALE)
		{
			my_mlx_pixel_put(&g->img, x, y, color);
			x++;
		}
		y++;
	}
}

/* Restituisce il colore minimap per un carattere della griglia.
 * '1' = muro (bianco), '2' = porta chiusa (arancio), altro = pavimento. */
static int	get_mm_color(char c)
{
	if (c == '1')
		return (MINIMAP_WALL_COLOR);
	if (c == '2')
		return (MINIMAP_DOOR_COLOR);
	return (MINIMAP_FLOOR_COLOR);
}

/* Disegna tutte le celle della mappa nella minimap.
 * Scorre la griglia riga per riga; si ferma al '\0' di ogni riga
 * perche' le righe possono avere lunghezze diverse. */
static void	draw_mm_grid(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			draw_mm_cell(game, x, y, get_mm_color(game->map.grid[y][x]));
			x++;
		}
		y++;
	}
}

/* Disegna il giocatore sulla minimap: quadrato rosso 2x2 alla posizione
 * corrente, piu' un segmento giallo lungo MINIMAP_SCALE nella direzione
 * di sguardo (vettore dir_x/dir_y scalato per MINIMAP_SCALE). */
static void	draw_mm_player(t_game *game)
{
	int	px;
	int	py;
	int	i;

	px = MINIMAP_MARGIN + (int)(game->player.pos_x * MINIMAP_SCALE);
	py = MINIMAP_MARGIN + (int)(game->player.pos_y * MINIMAP_SCALE);
	my_mlx_pixel_put(&game->img, px, py, MINIMAP_PLAYER_COLOR);
	my_mlx_pixel_put(&game->img, px + 1, py, MINIMAP_PLAYER_COLOR);
	my_mlx_pixel_put(&game->img, px, py + 1, MINIMAP_PLAYER_COLOR);
	my_mlx_pixel_put(&game->img, px + 1, py + 1, MINIMAP_PLAYER_COLOR);
	i = 1;
	while (i <= MINIMAP_SCALE)
	{
		my_mlx_pixel_put(&game->img,
			px + (int)(game->player.dir_x * i),
			py + (int)(game->player.dir_y * i),
			MINIMAP_DIR_COLOR);
		i++;
	}
}

/* Punto di ingresso della minimap: disegna griglia poi giocatore sopra. */
void	render_minimap(t_game *game)
{
	draw_mm_grid(game);
	draw_mm_player(game);
}
