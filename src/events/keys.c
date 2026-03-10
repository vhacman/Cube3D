/* Inclusione dell'header principale del progetto */
#include "cub3d.h"

/* GESTIONE TASTIERA */

/* Inizializza lo stato di tutti i tasti a "non premuto"
 * Parametri: puntatore a t_game
 * Cosa fa: imposta tutti i flag dei tasti a 0 (false)
 * Nota: chiamata all'avvio del gioco per assicurarsi che nessun tasto sia premuto
 * I flag sono usati per il movimento fluido: non muoviamo il giocatore
 * direttamente quando viene premuto un tasto, ma impostiamo il flag.
 * Il movimento effettivo avviene nel game loop. */
void	init_keys(t_game *game)
{
	game->keys.w = 0;      /* Tasto W (avanti) non premuto */
	game->keys.s = 0;      /* Tasto S (indietro) non premuto */
	game->keys.a = 0;      /* Tasto A (spostamento a sinistra) non premuto */
	game->keys.d = 0;      /* Tasto D (spostamento a destra) non premuto */
	game->keys.left = 0;   /* Freccia sinistra (rotazione) non premuta */
	game->keys.right = 0;  /* Freccia destra (rotazione) non premuta */
	game->keys.esc = 0;   /* Tasto ESC (uscita) non premuto */
}

/* Gestore del tasto premuto
 * Parametri: keycode (codice del tasto premuto), puntatore a t_game
 * Cosa fa: imposta a 1 (true) il flag del tasto corrispondente
 * Se viene premuto ESC, chiude direttamente il gioco
 * Restituisce: 0 (convenzione richiesta da mlx_hook)
 * Nota: questa funzione viene chiamata UNA SOLA VOLTA per ogni pressione */
int	key_press(int keycode, t_game *game)
{
	/* Se viene premuto W o freccia SU: muovi il giocatore avanti */
	if (keycode == KEY_W || keycode == KEY_UP)
		game->keys.w = 1;
	/* Se viene premuto S o freccia GIU: muovi il giocatore indietro */
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->keys.s = 1;
	/* Se viene premuto A o Q (versione ZQSD): spostamento laterale sinistro */
	else if (keycode == KEY_A || keycode == KEY_Q)
		game->keys.a = 1;
	/* Se viene premuto D: spostamento laterale destro */
	else if (keycode == KEY_D)
		game->keys.d = 1;
	/* Se viene premuta freccia SINISTRA: rotazione verso sinistra */
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	/* Se viene premuta freccia DESTRA: rotazione verso destra */
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	/* Se viene premuto ESC: chiudi il gioco */
	else if (keycode == KEY_ESC)
		close_window(game);
	return (0); /* Restituisce 0 per convenzione */
}

/* Gestore del tasto rilasciato
 * Parametri: keycode (codice del tasto rilasciato), puntatore a t_game
 * Cosa fa: imposta a 0 (false) il flag del tasto corrispondente
 * Questo ferma il movimento/rotazione del giocatore
 * Restituisce: 0 (convenzione richiesta da mlx_hook)
 * Nota: questa funzione viene chiamata UNA SOLA VOLTA per ogni rilascio */
int	key_release(int keycode, t_game *game)
{
	/* Se viene rilasciato W o freccia SU: ferma il movimento avanti */
	if (keycode == KEY_W || keycode == KEY_UP)
		game->keys.w = 0;
	/* Se viene rilasciato S o freccia GIU: ferma il movimento indietro */
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->keys.s = 0;
	/* Se viene rilasciato A o Q: ferma lo spostamento a sinistra */
	else if (keycode == KEY_A || keycode == KEY_Q)
		game->keys.a = 0;
	/* Se viene rilasciato D: ferma lo spostamento a destra */
	else if (keycode == KEY_D)
		game->keys.d = 0;
	/* Se viene rilasciata freccia SINISTRA: ferma la rotazione a sinistra */
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	/* Se viene rilasciata freccia DESTRA: ferma la rotazione a destra */
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0); /* Restituisce 0 per convenzione */
}
