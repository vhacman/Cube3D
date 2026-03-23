/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/23 00:00:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FILE: render_bonus.c
** AUTORE: Gabriela (vhacman)
** PERCHE': Versione bonus di render.c - identica al mandatory ma con la
**          chiamata a render_minimap() inserita dopo raycast() e prima di
**          mlx_put_image_to_window. Separata in file distinto per rispettare
**          la norminette: #ifdef dentro il corpo di una funzione e' vietato.
**          Compilata solo con make bonus (obj_bonus/, flag -DBONUS).
**          Sostituisce src/render/render.c nel build bonus.
**
** CHIAMATA DA: mlx_loop_hook (tramite setup_hooks), ogni frame.
*/

#include "cub3d.h"

/* Crea l'immagine per il rendering (double buffering). */
void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
		error_exit(game, "Failed to create image");
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.byte_order);
}

/* Scrive un pixel nell'immagine al buffer con bounds check. */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)dst = color;
}

/* Azzera tutti i pixel dell'immagine (nero). */
void	clear_image(t_game *game)
{
	ft_memset(game->img.addr, 0, SCREEN_WIDTH * SCREEN_HEIGHT
		* (game->img.bpp / 8));
}

/* Rendering bonus: include render_minimap dopo raycast. */
int	render(t_game *game)
{
	move_player(game);
	clear_image(game);
	draw_floor_ceiling(game);
	raycast(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	draw_weapon(game);
	return (0);
}
