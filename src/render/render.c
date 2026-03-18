#include "cub3d.h"

/* ============================================================================ */
/* RENDERING PRINCIPALE */
/* ============================================================================ */

/* Crea l'immagine per il rendering
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Alloca una nuova immagine con mlx_new_image
 *   - Ottiene l'indirizzo dei pixel con mlx_get_data_addr
 *   - Memorizza in game->img
 * Nota: questa immagine serve come buffer per il double buffering */
void	init_image(t_game *game)
{
	/* Alloca nuova immagine con le dimensioni dello schermo */
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
		error_exit(game, "Failed to create image");
	/* Ottiene l'indirizzo dei pixel in memoria */
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.byte_order);
}

/* Funzione per scrivere un pixel nell'immagine
 * Parametri: puntatore a t_img, coordinate x, y, colore
 * Cosa calcola:
 *   - offset = y * line_length + x * (bpp / 8)
 *   - scrive il colore a (addr + offset)
 * Nota: gestisce i casi x,y fuori dai limiti */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	/* Controlla che le coordinate siano dentro i limiti dello schermo */
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	/* Calcola l'offset: riga * lunghezza_riga + colonna * byte_per_pixel */
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	/* Scrive il colore (formato little-endian: BGR) */
	*(int *)dst = color;
}

/* Pulisce l'immagine
 * Parametri: puntatore a t_game
 * Cosa fa: mette a 0 tutti i byte dell'immagine (nero trasparente)
 * Alternativa: disegna direttamente floor e ceiling senza pulire prima */
void	clear_image(t_game *game)
{
	/* Inizializza l'indirizzo dell'immagine a 0 (nero) */
	ft_memset(game->img.addr, 0, SCREEN_WIDTH * SCREEN_HEIGHT
		* (game->img.bpp / 8));
}

/* Rendering di un frame
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Pulisce l'immagine
 *   - Disegna floor e ceiling (draw_floor_ceiling)
 *   - Esegue raycasting (raycast in raycaster.c)
 *   - Muove il giocatore in base ai tasti premuti (move_player)
 *   - Mette l'immagine nella finestra con mlx_put_image_to_window
 * Nota: questa funzione viene chiamata ripetutamente da mlx_loop_hook (circa 60fps) */
int	render(t_game *game)
{
	/* Muove il giocatore in base ai tasti premuti */
	move_player(game);
	/* Pulisce l'immagine */
	clear_image(game);
	/* Disegna floor e ceiling */
	draw_floor_ceiling(game);
	/* Esegue il raycasting per disegnare i muri */
	raycast(game);
	/* Mette l'immagine nella finestra */
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	/* Disegna l'arma sopra la scena */
	draw_weapon(game);
	return (0);
}
