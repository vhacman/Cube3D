
//COMMENTO PER ILARIA: CONSIGLIO DI SVILUPPO






/* ============================================================================ */
/* INIZIALIZZAZIONE MINILIBX E GESTIONE FINESTRA */
/* ============================================================================ */

/* TODO: Inizializza miniLibX */
/* 
 * Cosa fa: chiamare mlx_init() per inizializzare la libreria
 * Restituisce: puntatore a void (handle miniLibX)
 */

/* TODO: Crea la finestra */
/* 
 * Parametri: puntatore mlx, larghezza, altezza, titolo
 * Cosa fa: crea una nuova finestra con mlx_new_window
 * Restituisce: puntatore alla finestra, NULL se errore
 */

/* TODO: Hook per evento chiusura finestra (click X) */
/* 
 * Parametri: puntatore finestra, evento (17 = DestroyNotify), funzione handler
 * Cosa fa: registra la funzione che chiude il gioco quando si clicca la X
 * Returns: result della chiamata mlx_hook
 */

/* TODO: Hook per game loop */
/* 
 * Parametri: puntatore mlx, funzione da chiamare ogni frame, puntatore a game
 * Cosa fa: registra la funzione di rendering chiamata continuamente da mlx_loop
 * Returns: result della chiamata mlx_loop_hook
 */

/* TODO: Avvia il loop degli eventi */
/* 
 * Parametri: puntatore mlx
 * Cosa fa: entra nel loop infinito che gestisce gli eventi e chiama le funzioni registrate
 * NON restituisce mai (il programma gira fino a quando non si chiude)
 */

/* TODO: Gestore chiusura finestra */
/* 
 * Parametri: puntatore a t_game
 * Cosa fa: libera tutta la memoria, distrugge finestra e mlx, esce con exit(0)
 * Returns: 0 (convenzione per mlx_hook)
 */
