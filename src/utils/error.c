#include "cub3d.h"

/* ============================================================================ */
/* GESTIONE ERRORI */
/* ============================================================================ */

/* Stampa un messaggio di errore e termina il programma
 * Parametri: 
 *   - game: puntatore a t_game (puo essere NULL se errore prima dell'allocazione)
 *   - message: stringa con il messaggio di errore
 * 
 * Cosa fa:
 *   - Stampa "Error\n" su stderr
 *   - Stampa il messaggio di errore su stderr
 *   - Se game != NULL: libera tutta la memoria
 *   - Esce dal programma con exit(1)
 * 
 * Nota: non restituisce mai, il programma termina sempre */
void	error_exit(t_game *game, char *message)
{
	/* Stampa "Error\n" su stderr */
	write(2, "Error\n", 6);
	/* Stampa il messaggio di errore su stderr solo se non e NULL */
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	/* Se il gioco e stato allocato, libera la memoria */
	if (game)
		free_game(game);
	/* Termina il programma con codice di errore */
	exit(1);
}
