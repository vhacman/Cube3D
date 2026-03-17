/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:14:40 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/17 18:14:53 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Carica l'immagine dell'arma da file XPM.
 * Restituisce 1 se errore, 0 se ok.
 */
int	load_weapon(t_game *game)
{
	game->weapon.img.img = mlx_xpm_file_to_image(game->mlx,
			"textures/weapon/weapon_idle.xpm",
			&game->weapon.width,
			&game->weapon.height);
	if (!game->weapon.img.img)
		return (1);
	return (0);
}

/*
 * Disegna l'arma fissa in basso al centro dello schermo.
 * Chiamata da render() dopo mlx_put_image_to_window.
 */
void	draw_weapon(t_game *game)
{
	int	x;
	int	y;

	if (!game->weapon.img.img)
		return ;
	x = (SCREEN_WIDTH - game->weapon.width) / 2;
	y = SCREEN_HEIGHT - game->weapon.height;
	mlx_put_image_to_window(game->mlx, game->win,
		game->weapon.img.img, x, y);
}

/*
 * Libera l'immagine dell'arma.
 * Chiamata da free_game().
 */
void	free_weapon(t_game *game)
{
	if (game->weapon.img.img)
		mlx_destroy_image(game->mlx, game->weapon.img.img);
}
