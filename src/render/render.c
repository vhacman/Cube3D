
//COMMENTO PER ILARIA: CONSIGLIO DI SVILUPPO



/* ============================================================================ */
/* RENDERING PRINCIPALE */
/* ============================================================================ */

/* TODO: Crea l'immagine per il rendering */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Alloca una nuova immagine con mlx_new_image
 *   - Ottiene l'indirizzo dei pixel con mlx_get_data_addr
 *   - Memorizza in game->img
 */

/* TODO: Funzione per scrivere un pixel */
/* 
 * Parametri: puntatore a t_img, coordinate x, y, colore
 * Cosa calcola:
 *   - offset = y * line_length + x * (bpp / 8)
 *   - scrive il colore a (addr + offset)
 * Note: deve gestire i casi x,y fuori dai limiti
 */

/* TODO: Pulisce l'immagine */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: mette a 0 tutti i byte dell'immagine (nero trasparente)
 * Alternativa: disegna direttamente floor e ceiling senza pulire prima
 */

/* TODO: Rendering di un frame */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Pulisce l'immagine
 *   - Disegna floor e ceiling (draw_floor_ceiling)
 *   - Esegue raycasting (raycast in raycaster.c)
 *   - Mette l'immagine nella finestra con mlx_put_image_to_window
 * Note: questa funzione viene chiamata ripetutamente da mlx_loop_hook
 */
