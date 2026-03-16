/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 01:19:17 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/16 03:22:55 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

/* Restituisce il colore del muro in base al lato colpito.
 * TEMPORANEO: quando ci sono le texture, questa funzione
 * viene sostituita da get_texture() + get_tex_pixel().
 * side 0 = lato E/W, side 1 = lato N/S */
static int      get_wall_color(int side)
{
        if (side == 0)
                return (COLOR_GREEN);
        return (0x0000AA00);
}

/* Calcola i pixel di inizio e fine della colonna verticale del muro.
 * line_height e' inversamente proporzionale alla distanza:
 * piu' il muro e' lontano, piu' la colonna e' bassa.
 * I valori vengono clampati ai bordi dello schermo. */
static void     calc_draw_bounds(double perp_wall_dist, int *draw_start,
                                int *draw_end)
{
        int     line_height;

        line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
        *draw_start = SCREEN_HEIGHT / 2 - line_height / 2;
        if (*draw_start < 0)
                *draw_start = 0;
        *draw_end = SCREEN_HEIGHT / 2 + line_height / 2;
        if (*draw_end >= SCREEN_HEIGHT)
                *draw_end = SCREEN_HEIGHT - 1;
}

/*Disegna la colonna verticale del muro per la colonna x.
Riceve la distanza perpendicolare dal DDA e il lato colpito.
Calcola i bounds, sceglie il colore e disegna pixel per pixel. */
void    draw_wall(t_game *game, int x, double perp_wall_dist, int side)
{
        int     draw_start;
        int     draw_end;
        int     color;
        int     y;

        if (perp_wall_dist <= 0)
                perp_wall_dist = 0.0001;
        calc_draw_bounds(perp_wall_dist, &draw_start, &draw_end);
        color = get_wall_color(side);
        y = draw_start;
        while (y <= draw_end)
        {
                my_mlx_pixel_put(&game->img, x, y, color);
                y++;
        }
}
