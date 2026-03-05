
/* ============================================================================ */
/* LIBERAZIONE MEMORIA */
/* ============================================================================ */

/* TODO: Libera la mappa */
/* 
 * Parametri: puntatore a t_map
 * Cosa fa:
 *   - Libera ogni riga della mappa (free(grid[i]) per ogni i)
 *   - Libera l'array delle righe (free(grid))
 *   - Azzera width e height
 */

/* TODO: Libera le texture */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Per ogni texture in game->textures:
 *     - Se l'immagine esiste: mlx_destroy_image(mlx, texture.img)
 *     - Se il path esiste: free(path)
 *   - Azzera width e height a 0
 */

/* TODO: Libera l'immagine principale */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Se game->img.img esiste: mlx_destroy_image(game->mlx, game->img.img)
 */

/* TODO: Libera tutto e chiudi */
/* 
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
 * prima di distruggere il contesto MLX.
 */
