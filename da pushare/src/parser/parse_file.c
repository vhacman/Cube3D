/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :++++:      */
/*                                                    +:+      .+    .+      */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Dispatcher per le righe di header: instrada verso parse_texture o
 * parse_color in base al prefisso.
 * Se la riga non corrisponde a nessun identificatore noto restituiamo 1
 * (errore): process_lines chiama questa funzione solo su righe che
 * is_header_line ha gia' validato, quindi arrivare qui con uno sconosciuto
 * indica un bug nel check di is_header_line.
 * Restituisce: 0 se ok, 1 se errore. */
static int	process_header_line(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0)
		return (parse_texture(game, line));
	if (ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(game, line));
	return (1);
}

/* Scansiona l'array di righe in due passaggi logici:
 *  1. Header: righe vuote o riconosciute da is_header_line vengono
 *     processate; il ciclo si ferma alla prima riga non-header non-vuota.
 *  2. Mappa: tutto cio' che rimane (lines + i) viene passato a parse_map.
 * Questa separazione e' necessaria perche' il formato .cub non ha un
 * separatore esplicito tra header e mappa: il cambio di tipo di riga
 * e' il segnale di confine.
 * lines viene liberato qui in tutti i percorsi (ok e errore), dato che
 * parse_map lavora su copie delle stringhe.
 * Restituisce: 0 se ok, 1 se errore. */
static int	process_lines(t_game *game, char **lines)
{
	int	i;

	i = 0;
	while (lines[i] && (lines[i][0] == '\0' || is_header_line(lines[i])))
	{
		if (lines[i][0] != '\0' && process_header_line(game, lines[i]))
		{
			free_str_array(lines);
			return (1);
		}
		i++;
	}
	if (!lines[i])
	{
		free_str_array(lines);
		error_exit(game, "No map found in file");
		return (1);
	}
	game->raw_lines = lines;
	if (parse_map(game, lines + i))
		return (1);
	free_str_array(lines);
	game->raw_lines = NULL;
	return (0);
}

/* Verifica l'estensione .cub a partire dalla fine del path.
 * Confrontiamo gli ultimi 4 caratteri invece di cercare il punto dall'inizio:
 * cosi' path come "./maps/test.cub.bak" vengono rifiutati correttamente.
 * Il check len < 5 esclude path come ".cub" (solo estensione, nessun nome).
 * Restituisce: 0 se ok, 1 se l'estensione e' sbagliata. */
static int	check_extension(t_game *game, char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
	{
		error_exit(game, "File must have .cub extension");
		return (1);
	}
	return (0);
}

/* Apre il file, delega la lettura a read_all_lines, poi chiude subito il fd.
 * Chiudiamo il fd indipendentemente dal risultato di read_all_lines per
 * non lasciare descrittori aperti in caso di errore di allocazione.
 * Restituisce: array di righe NULL-terminato, NULL se apertura o lettura
 * fallisce. */
static char	**open_and_read(t_game *game, char *path)
{
	int		fd;
	char	**lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_exit(game, "Cannot open map file");
		return (NULL);
	}
	lines = read_all_lines(fd);
	close(fd);
	if (!lines)
		error_exit(game, "Failed to read map file");
	return (lines);
}

/* Entry point del parser: controlla estensione, legge il file, processa.
 * L'ordine dei controlli rispecchia il flusso naturale: prima validare
 * l'input (estensione), poi aprire la risorsa (file), poi elaborare.
 * Ogni passo restituisce 1 su errore, evitando di procedere con dati
 * parziali che causerebbero crash o comportamenti indefiniti.
 * Restituisce: 0 se ok, 1 se errore. */
int	parse_file(t_game *game, char *cub_path)
{
	char	**lines;

	if (check_extension(game, cub_path))
		return (1);
	lines = open_and_read(game, cub_path);
	if (!lines)
		return (1);
	return (process_lines(game, lines));
}
