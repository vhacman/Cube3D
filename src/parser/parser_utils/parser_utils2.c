/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/23 00:00:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Valida che la stringa rappresenti un intero non negativo senza segno.
 * Controlla carattere per carattere per evitare che ft_atoi accetti
 * valori con trattini unicode o caratteri nascosti.
 * Restituisce 1 se valida (solo cifre, non vuota), 0 altrimenti. */
int	is_valid_uint_str(char *s)
{
	if (!s || !*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/* Conta gli elementi di un array NULL-terminato.
 * Usata per verificare che ft_split restituisca esattamente 3
 * componenti RGB e per determinare l'altezza della mappa. */
int	count_str_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
