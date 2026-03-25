/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Chiama mlx_init() e restituisce l'handle MLX.
 * Termina il programma se l'inizializzazione fallisce. */
void	*init_mlx(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		error_exit(NULL, "Failed to initialize miniLibX");
	return (mlx);
}

/* Crea la finestra SCREEN_WIDTH x SCREEN_HEIGHT.
 * Se mlx_new_window fallisce, distrugge il display e libera mlx
 * prima di uscire (mlx_init alloca con malloc). */
void	*create_window(void *mlx)
{
	void	*win;

	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cube3D");
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		error_exit(NULL, "Failed to create window");
	}
	return (win);
}

/* Registra le callback per: chiusura finestra, tasto premuto,
 * tasto rilasciato, e game loop (render chiamato ~60fps). */
void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, EVENT_DESTROY_NOTIFY, 0, close_window, game);
	mlx_hook(game->win, EVENT_KEY_PRESS, MASK_KEY_PRESS, key_press, game);
	mlx_hook(game->win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, key_release, game);
	mlx_loop_hook(game->mlx, render, game);
}

/* Entra nel loop degli eventi mlx. Non ritorna mai. */
void	start_loop(t_game *game)
{
	mlx_loop(game->mlx);
}

/* Libera tutta la memoria e termina il programma.
 * Chiamata al click sulla X e alla pressione di ESC. */
int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}
