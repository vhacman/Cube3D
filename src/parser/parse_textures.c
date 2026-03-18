#include "cub3d.h"

/* Mappa il prefisso della riga all'indice costante della texture.
 * Usiamo strncmp("XX ", 3) e non strcmp: la riga contiene il path dopo
 * lo spazio, quindi confrontare tutta la stringa fallirebbe sempre.
 * Restituisce TEX_NO/SO/WE/EA (0-3), -1 se identificatore sconosciuto. */
static int	get_tex_index(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (TEX_NO);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (TEX_SO);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (TEX_WE);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (TEX_EA);
	return (-1);
}

/* Isola il path XPM che segue l'identificatore a due lettere + spazio.
 * skip_whitespace gestisce eventuali spazi extra tra identificatore e path,
 * trim_newline rimuove il '\n' lasciato da get_next_line.
 * Se dopo lo skip rimane una stringa vuota il path e' assente: errore.
 * Restituisce: copia allocata del path, NULL se vuoto o malloc fallisce. */
static char	*extract_path(char *line)
{
	char	*path;

	path = skip_whitespace(line + 3);
	trim_newline(path);
	if (*path == '\0')
		return (NULL);
	return (ft_strdup(path));
}

/* Parsa una riga di texture e salva il path in game->textures[idx].path.
 * Controlliamo idx < 0 per identificatori non validi (es. "NE ./foo.xpm").
 * Controlliamo il duplicato PRIMA di estrarre il path: risparmia
 * un'allocazione inutile se la texture e' gia' stata definita.
 * textures[idx].path == NULL e' il sentinel "non ancora impostato",
 * in quanto calloc azzera tutta la struct t_game all'avvio.
 * Restituisce: 0 se ok, 1 se errore (error_exit e' gia' stato chiamato). */
int	parse_texture(t_game *game, char *line)
{
	int		idx;
	char	*path;

	idx = get_tex_index(line);
	if (idx < 0)
	{
		error_exit(game, "Unknown texture identifier");
		return (1);
	}
	if (game->textures[idx].path)
	{
		error_exit(game, "Duplicate texture definition");
		return (1);
	}
	path = extract_path(line);
	if (!path)
	{
		error_exit(game, "Missing or empty texture path");
		return (1);
	}
	game->textures[idx].path = path;
	return (0);
}
