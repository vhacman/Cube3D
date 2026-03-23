/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Accede a una cella della griglia in modo sicuro.
 * Restituisce ' ' (spazio) per coordinate fuori dai limiti: questo e'
 * deliberato. Il check di chiusura mappa si basa sul fatto che qualsiasi
 * cella percorribile sul bordo avra' almeno un vicino fuori dalla griglia,
 * che trattiamo come zona aperta. In questo modo il bordo della griglia
 * e' automaticamente considerato "non-muro" senza dover gestire casi
 * speciali in check_surroundings.
 * Il check su ft_strlen e' necessario perche' le righe della mappa
 * possono avere lunghezze diverse: get_cell(game, 10, 2) su una riga
 * di 5 caratteri deve restituire ' ', non accedere a memoria casuale. */
static char	get_cell(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map.height)
		return (' ');
	if (x < 0 || x >= (int)ft_strlen(game->map.grid[y]))
		return (' ');
	return (game->map.grid[y][x]);
}

/* Verifica che tutti e 4 i vicini ortogonali di una cella percorribile
 * siano validi (non spazio e non fuori bounds).
 * Controlliamo solo le 4 direzioni cardinali, non le diagonali: nel
 * raycaster DDA il giocatore si muove ortogonalmente, quindi una mappa
 * "aperta" solo in diagonale non causa problemi di fuga dalla mappa.
 * Restituisce 1 se la mappa e' aperta in almeno una direzione, 0 se ok. */
static int	check_surroundings(t_game *game, int x, int y)
{
	if (get_cell(game, x, y - 1) == ' ')
		return (1);
	if (get_cell(game, x, y + 1) == ' ')
		return (1);
	if (get_cell(game, x - 1, y) == ' ')
		return (1);
	if (get_cell(game, x + 1, y) == ' ')
		return (1);
	return (0);
}

/* Controlla che il carattere sia uno dei simboli ammessi dal subject.
 * Usiamo ft_strchr su una stringa letterale: piu' conciso e leggibile
 * rispetto a una catena di confronti, e aggiungere un carattere richiede
 * solo di modificare la stringa.
 * Restituisce 1 se il carattere e' valido, 0 altrimenti. */
static int	is_valid_map_char(char c)
{
	return (ft_strchr("012 NSEW", c) != NULL);
}

/* Valida l'intera mappa: caratteri legali e chiusura perimetrale.
 * Scorriamo ogni cella: se il carattere non e' nella lista ammessa
 * usciamo subito con errore. Se la cella e' percorribile (giocatore
 * puo' entrarci: 0, N, S, E, W) verifichiamo che sia circondata.
 * Non controlliamo i muri ('1'): un muro che tocca il bordo o uno spazio
 * e' accettabile, purche' nessun percorso sia aperto.
 * error_exit termina il programma: non serve un return esplicito dopo,
 * ma lo manteniamo per chiarezza del flusso al lettore. */
int	validate_map(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			c = game->map.grid[y][x];
			if (!is_valid_map_char(c))
				error_exit(game, "Invalid character in map");
			if (ft_strchr("0NSEW", c) && check_surroundings(game, x, y))
				error_exit(game, "Map is not closed/surrounded by walls");
			x++;
		}
		y++;
	}
	return (0);
}
