/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:06:46 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/16 03:19:06 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* Calcola delta_dist_x e delta_dist_y: la distanza che il raggio
percorre tra due bordi di cella consecutivi sullo stesso asse.
Formula: |1 / rayDir|. Se rayDir e' 0 il raggio e' parallelo
a quell'asse e non lo intersechera' mai, quindi si usa INF. */
static void	init_delta(t_game *game, t_dda *d)
{
	if (game->player.ray_dir_x == 0)
		d->delta_dist_x = INF;
	else
		d->delta_dist_x = fabs(1.0 / game->player.ray_dir_x);
	if (game->player.ray_dir_y == 0)
		d->delta_dist_y = INF;
	else
		d->delta_dist_y = fabs(1.0 / game->player.ray_dir_y);
}

/* Calcola step e side_dist per entrambi gli assi.
 * step e' la direzione di avanzamento nella mappa (+1 o -1).
 * side_dist e' la distanza dal giocatore al primo bordo di cella
 * sull'asse corrispondente (il primo incrocio con la griglia). */
static void	init_steps(t_game *game, t_dda *d)
{
	if (game->player.ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (game->player.pos_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - game->player.pos_x) * d->delta_dist_x;
	}
	if (game->player.ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (game->player.pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - game->player.pos_y) * d->delta_dist_y;
	}
}

/* Inizializza la struct t_dda con la cella di partenza del giocatore,
 * poi delega il calcolo di delta e step alle funzioni dedicate. */
static void	init_dda(t_game *game, t_dda *d)
{
	d->map_x = (int)game->player.pos_x;
	d->map_y = (int)game->player.pos_y;
	init_delta(game, d);
	init_steps(game, d);
}

/* Avanza cella per cella lungo il raggio finche' non colpisce un muro.
 * Ad ogni passo sceglie l'asse con side_dist minore (quello che
 * raggiunge prima il bordo di cella), avanza di una cella su quell'asse
 * e aggiorna side_dist sommando delta_dist.
 * Salva hit_side: 0 = colpito lato E/W, 1 = colpito lato N/S. */
static void	dda_loop(t_game *game, t_dda *d)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			game->player.hit_side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			game->player.hit_side = 1;
		}
		if (game->map.grid[d->map_y][d->map_x] == '1')
			hit = 1;
	}
}

/* Funzione principale del DDA. Inizializza, esegue il loop,
 * salva le coordinate del muro colpito per il texture mapping
 * e restituisce la distanza perpendicolare al muro.
 * La distanza perpendicolare (non euclidea) evita il fish-eye:
 * side 0 -> side_dist_x - delta_dist_x
 * side 1 -> side_dist_y - delta_dist_y */
double	perform_dda(t_game *game, int x)
{
	t_dda	d;

	(void)x;
	init_dda(game, &d);
	dda_loop(game, &d);
	game->player.wall_map_x = d.map_x;
	game->player.wall_map_y = d.map_y;
	if (game->player.hit_side == 0)
		return (d.side_dist_x - d.delta_dist_x);
	return (d.side_dist_y - d.delta_dist_y);
}
