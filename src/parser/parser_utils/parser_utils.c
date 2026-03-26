/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Implementa un realloc manuale: alloca un nuovo array di (count+2) puntatori,
 * copia le righe gia' raccolte, poi aggiunge la nuova riga in fondo.
 * Usiamo calloc cosi' il terminatore NULL e' gia' presente nell'ultimo slot.
 * realloc non e' nelle funzioni consentite dal progetto 42, quindi questa
 * e' l'unica strada.
 * In caso di fallimento libera sia line che lines per evitare leak nella
 * catena di chiamate di read_all_lines. */
static char	**append_line(char **lines, char *line, int count)
{
	char	**tmp;

	tmp = calloc(count + 2, sizeof(char *));
	if (!tmp)
	{
		free(line);
		free_str_array(lines);
		return (NULL);
	}
	if (lines)
		ft_memcpy(tmp, lines, sizeof(char *) * count);
	if (lines)
		free(lines);
	tmp[count] = line;
	return (tmp);
}

/* Legge il file riga per riga con get_next_line e accumula il risultato
 * in un array NULL-terminato.
 * Non conosciamo il numero di righe a priori, quindi cresciamo l'array
 * dinamicamente a ogni iterazione tramite append_line.
 * Se append_line fallisce, il cleanup e' gia' avvenuto al suo interno:
 * basta restituire NULL. */
char	**read_all_lines(int fd)
{
	char	**lines;
	char	*line;
	int		count;

	lines = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines = append_line(lines, line, count++);
		if (!lines)
			return (NULL);
		line = get_next_line(fd);
	}
	return (lines);
}

/* Riconosce le righe di configurazione (header) del file .cub.
 * Usiamo ft_strncmp con prefisso + spazio ("NO ", "F ", ...) invece di
 * confrontare solo le lettere: cosi' una riga "NORTH" non viene scambiata
 * per "NO". Lo spazio e' parte del formato specificato dal subject.
 * Restituisce 1 se la riga e' un header, 0 altrimenti. */
int	is_header_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

/* Avanza il puntatore oltre spazi e tab iniziali senza allocare nulla.
 * Utile dopo aver identificato il tipo di riga (es. "NO ") per isolare
 * il valore che segue, che puo' avere spazi extra di padding. */
char	*skip_whitespace(char *line)
{
	if (!line)
		return (NULL);
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

/* Rimuove il '\n' finale che get_next_line lascia nella stringa.
 * Operiamo in-place: nessuna allocazione necessaria.
 * Tutte le funzioni di parsing chiamano questa prima di usare la riga,
 * cosi' non dobbiamo gestire il newline nei confronti o nei path. */
void	trim_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}
