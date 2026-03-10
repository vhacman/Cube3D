#include "cub3d.h"

/* ============================================================================ */
/* LIBERAZIONE MEMORIA */
/* ============================================================================ */

/* Libera la mappa
 * Parametri: puntatore a t_map
 * Cosa fa:
 *   - Libera ogni riga della mappa (free(grid[i]) per ogni i)
 *   - Libera l'array delle righe (free(grid))
 *   - Azzera width e height */
void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_str_array(map->grid); /* Libera tutte le righe e l'array */
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

/* Libera le texture
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Per ogni texture in game->textures:
 *     - Se l'immagine esiste: mlx_destroy_image(mlx, texture.img)
 *     - Se il path esiste: free(path)
 *   - Azzera width e height a 0 */
void	free_textures(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img.img)
			mlx_destroy_image(game->mlx, game->textures[i].img.img);
		/*
			- game->textures[i].path è char * (puntatore semplice)
			- &game->textures[i].path è char ** (puntatore a puntatore)
			- (void **)&game->textures[i].path cast a void ** per passarlo a safe_free
 		*/
		safe_free((void **)&game->textures[i].path);
		game->textures[i].width = 0;
		game->textures[i].height = 0;
		i++;
	}
}

/* Libera l'immagine principale
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Se game->img.img esiste: mlx_destroy_image(game->mlx, game->img.img) */
void	free_main_image(t_game *game)
{
	if (!game || !game->mlx || !game->img.img)
		return ;
	mlx_destroy_image(game->mlx, game->img.img);
}

/* Libera tutto e chiudi
 * Parametri: puntatore a t_game
 * Cosa fa (in ordine):
 *   - Libera la mappa (libera grid)
 *   - Libera le texture
 *   - Libera l'immagine principale
 *   - Se la finestra esiste: mlx_destroy_window(game->mlx, game->win)
 *   - Se mlx esiste: mlx_destroy_display(game->mlx) (solo Linux)
 *   - Libera la struttura game stessa (free(game))
 * 
 * Note: l'ordine e importante! Bisogna distruggere gli oggetti MLX
 * prima di distruggere il contesto MLX. */
void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(&game->map);
	free_textures(game);
	free_main_image(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
