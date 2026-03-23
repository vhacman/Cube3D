/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:40:34 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/16 03:25:39 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Carica un file XPM come texture mlx.
 * mlx_xpm_file_to_image alloca l'immagine; mlx_get_data_addr
 * permette di leggere i pixel. Restituisce 1 se errore, 0 se ok. */
int	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img.img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img.img)
		return (1);
	tex->img.addr = mlx_get_data_addr(tex->img.img, &tex->img.bpp,
			&tex->img.line_length, &tex->img.byte_order);
	return (0);
}

/* Carica tutte e 4 le texture (NO, SO, WE, EA).
 * Indici: TEX_NO=0, TEX_SO=1, TEX_WE=2, TEX_EA=3 (definiti in defines.h).
 * Restituisce 1 al primo errore, 0 se tutte caricate. */
int	load_all_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_texture(game, &game->textures[i], game->textures[i].path))
			return (1);
		i++;
	}
	return (0);
}

/* Restituisce il puntatore alla texture corretta in base al lato colpito.
 * side 0 (E/W): ray_dir_x > 0 -> EA, altrimenti WE.
 * side 1 (N/S): ray_dir_y > 0 -> SO, altrimenti NO. */
t_texture	*get_texture(t_game *game, int side)
{
	if (side == 0)
	{
		if (game->player.ray_dir_x > 0)
			return (&game->textures[TEX_EA]);
		return (&game->textures[TEX_WE]);
	}
	if (game->player.ray_dir_y > 0)
		return (&game->textures[TEX_SO]);
	return (&game->textures[TEX_NO]);
}

/* Legge il colore di un pixel dalla texture.
 * Formula offset: y * line_length + x * (bpp / 8). */
int	get_tex_pixel(t_texture *tex, int tex_x, int tex_y)
{
	char	*pixel;

	pixel = tex->img.addr
		+ (tex_y * tex->img.line_length + tex_x * (tex->img.bpp / 8));
	return (*(int *)pixel);
}

/* Calcola tex_x: la colonna nella texture corrispondente al punto di impatto.
 * wall_x e' la parte decimale della posizione di impatto sul muro.
 * side 0 (E/W) usa pos_y, side 1 (N/S) usa pos_x. */
int	get_tex_x(t_game *game, t_texture *tex, int side, double perp_dist)
{
	double	wall_x;
	int		tex_x;

	if (side == 0)
		wall_x = game->player.pos_y
			+ perp_dist * game->player.ray_dir_y;
	else
		wall_x = game->player.pos_x
			+ perp_dist * game->player.ray_dir_x;
	wall_x -= (int)wall_x;
	tex_x = (int)(wall_x * tex->width);
	if (side == 0 && game->player.ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (side == 1 && game->player.ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
