
/* ============================================================================ */
/* GESTIONE ERRORI */
/* ============================================================================ */

/* TODO: Stampa errore e esci */
/* 
 * Parametri: 
 *   - game: puntatore a t_game (puo essere NULL se errore prima dell'allocazione)
 *   - message: stringa con il messaggio di errore
 * 
 * Cosa fa:
 *   - Stampa "Error\n" su stderr (write(2, "Error\n", 6))
 *   - Stampa il messaggio di errore su stderr
 *   - Se game != NULL: libera tutta la memoria con free_all
 *   - Esce dal programma con exit(1)
 * 
 * Note: questa funzione viene chiamata quando qualcosa va storto nel parsing
 * o in altre parti del gioco. Deve liberare la memoria per evitare leak.
 */
