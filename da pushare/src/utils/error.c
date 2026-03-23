/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:41:00 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/23 13:41:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	write(2, "Error\n", 6);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	if (game)
		free_game(game);
	exit(1);
}
