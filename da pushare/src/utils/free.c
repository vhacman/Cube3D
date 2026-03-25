/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:41:00 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/24 16:04:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Libera la griglia 2D e azzera tutti i campi di t_map. */
void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_str_array(map->grid);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->player_dir = 0;
}

/* Distrugge le immagini MLX e libera i path delle 4 texture.
 * Azzeriamo img.img dopo mlx_destroy_image per evitare doppio-free
 * se free_textures venisse chiamata due volte. */
void	free_textures(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img.img)
		{
			mlx_destroy_image(game->mlx, game->textures[i].img.img);
			game->textures[i].img.img = NULL;
		}
		safe_free((void **)&game->textures[i].path);
		game->textures[i].width = 0;
		game->textures[i].height = 0;
		i++;
	}
}

/* Distrugge il buffer di rendering principale. */
void	free_main_image(t_game *game)
{
	if (!game || !game->mlx || !game->img.img)
		return ;
	mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = NULL;
}

/* Libera tutto il gioco nell'ordine corretto:
 * oggetti MLX prima del contesto MLX, contesto prima di free(game).
 * get_next_line(-1) svuota il buffer statico residuo di GNL,
 * necessario quando error_exit termina prima che il file
 * sia stato letto completamente.
 * Qualsiasi chiamata successiva a free_game con lo stesso puntatore
 * e' neutralizzata dal check iniziale !game. */
void	free_game(t_game *game)
{
	if (!game)
		return ;
	get_next_line(-1);
	free_str_array(game->raw_lines);   // <-- aggiungi questa
	game->raw_lines = NULL;            // <-- e questa
	free_map(&game->map);
	free_textures(game);
	free_main_image(game);
	free_weapon(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

/* Libera un array di stringhe NULL-terminato. */
void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
