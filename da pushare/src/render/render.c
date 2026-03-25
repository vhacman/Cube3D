/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Crea il buffer immagine per il double buffering.
 * mlx_new_image alloca l'immagine; mlx_get_data_addr restituisce
 * il puntatore ai pixel grezzi per la scrittura diretta. */
void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
		error_exit(game, "Failed to create image");
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.byte_order);
}

/* Scrive un pixel nel buffer immagine.
 * offset = y * line_length + x * (bpp / 8). Ignora coordinate fuori schermo. */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)dst = color;
}

/* Azzera tutti i pixel del buffer (nero). */
void	clear_image(t_game *game)
{
	ft_memset(game->img.addr, 0, SCREEN_WIDTH * SCREEN_HEIGHT
		* (game->img.bpp / 8));
}

/* Rendering di un frame: muove il giocatore, pulisce il buffer,
 * disegna floor/ceiling, esegue raycasting, invia alla finestra,
 * disegna l'arma sopra. Chiamato circa 60 volte al secondo da mlx_loop_hook. */
int	render(t_game *game)
{
	move_player(game);
	clear_image(game);
	draw_floor_ceiling(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	draw_weapon(game);
	return (0);
}
