
//COMMENTO PER ILARIA: CONSIGLIO DI SVILUPPO



/* ============================================================================ */
/* GESTIONE TASTIERA */
/* ============================================================================ */

/* TODO: Inizializza stato tasti */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: azzera tutti i flag in game->keys (tutti a 0 = non premuti)
 */

/* TODO: Gestore tasto premuto */
/* 
 * Parametri: keycode (codice del tasto), puntatore a t_game
 * Cosa fa:
 *   - Se W o freccia SU: imposta game->keys.w = 1
 *   - Se S o freccia GIU: imposta game->keys.s = 1
 *   - Se A o Q: imposta game->keys.a = 1
 *   - Se D: imposta game->keys.d = 1
 *   - Se freccia SX: imposta game->keys.left = 1
 *   - Se freccia DX: imposta game->keys.right = 1
 *   - Se ESC: chiude il gioco (chiama close_window)
 * Returns: 0 (convenzione per mlx_hook)
 */

/* TODO: Gestore tasto rilasciato */
/* 
 * Parametri: keycode (codice del tasto), puntatore a t_game
 * Cosa fa:
 *   - Se W o freccia SU: imposta game->keys.w = 0
 *   - Se S o freccia GIU: imposta game->keys.s = 0
 *   - Se A o Q: imposta game->keys.a = 0
 *   - Se D: imposta game->keys.d = 0
 *   - Se freccia SX: imposta game->keys.left = 0
 *   - Se freccia DX: imposta game->keys.right = 0
 * Returns: 0 (convenzione per mlx_hook)
 */
