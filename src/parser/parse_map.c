/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :++++:      */
/*                                                    :::      ::::::::   */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Costruisce la griglia 2D della mappa come array di stringhe indipendenti.
 * Duplichiamo ogni riga invece di tenere puntatori nell'array lines originale
 * perche' lines verra' liberato subito dopo in process_lines.
 * Teniamo traccia del width come lunghezza massima tra tutte le righe:
 * le righe della mappa possono avere lunghezze diverse (le aree con spazi
 * a destra spesso vengono troncate nei file .cub), quindi non possiamo
 * assumere che siano tutte uguali.
 * calloc garantisce che grid[height] sia NULL: necessario per i cicli
 * che iterano fino a NULL.
 * Restituisce: 0 se ok, 1 se malloc fallisce. */
static int	build_grid(t_game *game, char **lines, int height)
{
	int	i;
	int	len;

	game->map.grid = calloc(height + 1, sizeof(char *));
	if (!game->map.grid)
		return (1);
	game->map.height = height;
	game->map.width = 0;
	i = 0;
	while (i < height)
	{
		trim_newline(lines[i]);
		game->map.grid[i] = ft_strdup(lines[i]);
		if (!game->map.grid[i])
			return (1);
		len = ft_strlen(game->map.grid[i]);
		if (len > game->map.width)
			game->map.width = len;
		i++;
	}
	game->map.grid[height] = NULL;
	return (0);
}

/* Cerca nella griglia gia' costruita il carattere di spawn del giocatore
 * (N/S/E/W) e salva la posizione e la direzione in map.
 * La ricerca avviene DOPO build_grid e non durante: a questo punto
 * abbiamo la griglia completa e possiamo lavorare su di essa in modo
 * indipendente.
 * Salviamo coordinate intere (celle) qui; main o init_game le convertira'
 * in coordinate floating-point per il raycaster (centro della cella).
 * Non azzeriamo il carattere nella griglia: validate_map deve poterlo
 * riconoscere come cella percorribile.
 * Restituisce: 0 se trovato, 1 se nessuno spawn presente. */
static int	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (ft_strchr("NSEW", game->map.grid[i][j]))
			{
				game->map.player_x = j;
				game->map.player_y = i;
				game->map.player_dir = game->map.grid[i][j];
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/* Parsa la sezione mappa: conta le righe, costruisce la griglia, trova
 * il giocatore. L'ordine e' importante: build_grid deve completarsi
 * prima di find_player, e find_player prima di validate_map (chiamata
 * esternamente da parse_file dopo che parse_map ritorna 0).
 * count_str_array conta solo le righe non-NULL: se lines e' un array
 * vuoto (solo terminatore) height sara' 0 e usciamo subito.
 * Restituisce: 0 se ok, 1 se errore. */
int	parse_map(t_game *game, char **lines)
{
	int	height;

	height = count_str_array(lines);
	if (height == 0)
	{
		error_exit(game, "Empty map");
		return (1);
	}
	if (build_grid(game, lines, height))
	{
		error_exit(game, "Failed to build map grid");
		return (1);
	}
	if (find_player(game))
	{
		error_exit(game, "No player start position (N/S/E/W) in map");
		return (1);
	}
	return (0);
}
