/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :++++:      */
/*                                                    +:+      .+    .+      */
/*   By: vhacman <vhacman@student.42roma.it>        #+#    #+#             */
/*                                                #+#    #+#             */
/*   Created: 2026/03/23 13:41:00 by vhacman         #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Converte le 3 stringhe R/G/B in un colore packed a 32 bit.
 * Validiamo con is_valid_uint_str PRIMA di chiamare ft_atoi:
 * ft_atoi non distingue "-0" da "0" ne' segnala overflow, quindi
 * conviene rifiutare subito qualsiasi stringa che non sia cifre pure.
 * Il check rgb[i] > 255 cattura valori come "256" o "999".
 * Restituisce il colore packed (>= 0), -1 se un campo non e' valido. */
static int	parts_to_color(char **parts)
{
	int	rgb[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!is_valid_uint_str(parts[i]))
			return (-1);
		rgb[i] = ft_atoi(parts[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
		i++;
	}
	return (create_color(rgb[0], rgb[1], rgb[2]));
}

/* Estrae e valida la stringa "R,G,B" che segue l'identificatore (F/C).
 * Usiamo ft_split(',') per separare i componenti: piu' robusto di sscanf
 * che non e' nelle funzioni permesse.
 * Il check !parts[3] rifiuta "255,0,0,0" (4 componenti): ft_split con
 * la virgola come delimitatore restituisce NULL nel quarto slot se sono
 * esattamente 3 valori. Se uno dei primi tre e' NULL siamo sotto i 3
 * valori attesi: anche questo e' errore.
 * free_str_array libera l'array di ft_split prima di restituire.
 * Restituisce il colore packed (>= 0), -1 se il formato e' sbagliato. */
static int	extract_color(char *line)
{
	char	**parts;
	char	*rgb_str;
	int		color;

	rgb_str = skip_whitespace(line + 2);
	trim_newline(rgb_str);
	parts = ft_split(rgb_str, ',');
	if (!parts)
		return (-1);
	color = -1;
	if (parts[0] && parts[1] && parts[2] && !parts[3])
		color = parts_to_color(parts);
	free_str_array(parts);
	return (color);
}

/* Parsa una riga di colore (F = floor, C = ceiling) e salva in t_game.
 * Usiamo -1 come sentinel "non impostato": il nero puro (0x000000) e'
 * un colore legittimo, quindi non possiamo usare 0 come valore di default.
 * La struct e' azzerata da calloc all'avvio, quindi inizializziamo
 * esplicitamente floor_color e ceiling_color a -1 in init_game.
 * Controlliamo il duplicato prima di parsare il valore per la stessa
 * ragione di parse_texture: evitare lavoro inutile su input errato.
 * Restituisce: 0 se ok, 1 se errore. */
int	parse_color(t_game *game, char *line)
{
	int	*target;
	int	color;

	if (line[0] == 'F')
		target = &game->floor_color;
	else
		target = &game->ceiling_color;
	if (*target != -1)
	{
		error_exit(game, "Duplicate color definition");
		return (1);
	}
	color = extract_color(line);
	if (color == -1)
	{
		error_exit(game, "Invalid color format (expected R,G,B with 0-255)");
		return (1);
	}
	*target = color;
	return (0);
}
