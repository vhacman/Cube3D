/* Inclusione dell'header principale del progetto che contiene tutti i prototipi e le strutture */
#include "cub3d.h"

/* ============================================================================ */
/* INIZIALIZZAZIONE MINILIBX E GESTIONE FINESTRA */
/* ============================================================================ */

/* Inizializza la libreria miniLibX
 * Parametri: nessuno
 * Cosa fa: chiama mlx_init() per creare la connessione con il server X/Wayland
 * Restituisce: puntatore void all'handle MLX, usato per tutte le operazioni successive
 * Errore: se la inizializzazione fallisce, termina il programma con errore */
void	*init_mlx(void)
{
	void	*mlx; /* Puntatore al contesto MLX */

	mlx = mlx_init(); /* Inizializza la connessione con il display */
	if (!mlx) /* Controlla se l'inizializzazione e fallita */
		error_exit(NULL, "Failed to initialize miniLibX"); /* Termina con errore */
	return (mlx); /* Restituisce il puntatore al contesto MLX */
}

/* Crea la finestra di gioco
 * Parametri: puntatore al contesto MLX
 * Cosa fa: crea una nuova finestra con le dimensioni definita da SCREEN_WIDTH e SCREEN_HEIGHT
 * Restituisce: puntatore alla finestra creata
 * Errore: se la creazione fallisce, distrugge il display MLX e termina */
void	*create_window(void *mlx)
{
	void	*win; /* Puntatore alla finestra */

	/* Crea finestra con larghezza, altezza e titolo "Cube3D" */
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cube3D");
	if (!win) /* Controlla se la finestra e stata creata */
	{
		mlx_destroy_display(mlx); /* Chiude la connessione al display X */
		error_exit(NULL, "Failed to create window"); /* Termina con errore */
	}
	return (win); /* Restituisce il puntatore alla finestra */
}

/* Configura tutti gli hook per gestire gli eventi
 * Parametri: puntatore a t_game (contiene mlx e win)
 * Cosa fa: registra le callback per:
 *   - Callback: funzione registrata per essere chiamata automaticamente quando succede un evento
 *   - click sulla X della finestra (chiude il gioco)
 *   - Tasto premuto (gestito da key_press)
 *   - Tasto rilasciato (gestito da key_release)
 *   - Game loop (chiamato ogni frame per il rendering)
 * 
 * Nota: 
 *   - mlx_hook e mlx_loop_hook non bloccano, registrano solo le callback
 *   - L'operatore -> (freccia) accede a un campo di una struttura tramite puntatore
 *     es: game->win e' equivalente a (*game).win */
void	setup_hooks(t_game *game)
{
	/* Hook per la chiusura della finestra (evento DestroyNotify = click sulla X) */
	mlx_hook(game->win, EVENT_DESTROY_NOTIFY, 0, close_window, game);
	/* Hook per tasto premuto (evento KeyPress) con maschera per eventi da tastiera */
	mlx_hook(game->win, EVENT_KEY_PRESS, MASK_KEY_PRESS, key_press, game);
	/* Hook per tasto rilasciato (evento KeyRelease) */
	mlx_hook(game->win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, key_release, game);
	/* Hook per il game loop: chiamato ripetutamente (circa 60fps) per il rendering */
	mlx_loop_hook(game->mlx, render, game);
}

/* Avvia il loop principale degli eventi
 * Parametri: puntatore al contesto MLX
 * Cosa fa: entra in un loop infinito che:
 *   - Gestisce gli eventi in coda (click, tasti, ecc.)
 *   - Chiama le callback registrate (render, key_press, key_release, ecc.)
 *   - Non restituisce mai fino alla chiusura del programma
 * Nota: questa funzione blocca fino a quando non si chiude la finestra */
void	start_loop(t_game *game)
{
	mlx_loop(game->mlx); /* Entra nel loop degli eventi */
}

/* Gestore dell'evento di chiusura finestra (click sulla X)
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Libera tutta la memoria allocata (mappa, texture, immagini, strutture)
 *   - Chiude la finestra e il contesto MLX
 *   - Termina il programma con exit(0)
 * Restituisce: 0 (richiesto dalla convenzione di mlx_hook)
 * Nota: viene chiamata anche quando si preme ESC */
int	close_window(t_game *game)
{
	free_game(game); /* Libera tutta la memoria del gioco */
	exit(0); /* Termina il programma con successo */
	return (0); /* Ritorna 0 per convenzione (mai raggiunto) */
}
