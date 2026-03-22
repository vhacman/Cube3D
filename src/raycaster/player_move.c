/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:51:13 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/22 15:01:55 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Controlla se una cella della mappa è percorribile (non è un muro)
Parametri: puntatore a t_game, coordinate x e y nella mappa
Restituisce: 1 se è percorribile, 0 se è un muro
Nota: controlla anche che le coordinate siano dentro i limiti della mappa */
int	is_walkable(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= game->map.width || map_y < 0
		|| map_y >= game->map.height)
		return (0);
	if (game->map.grid[map_y][map_x] == '1')
		return (0);
	return (1);
}

/*Ruota il giocatore a sinistra o destra
Parametri: puntatore a t_game
Cosa fa:
- Ruota il vettore direzione del giocatore
- Ruota new_dir_x = dir_x * cos(rot) - dir_y * sin(rot)
new_dir_y = dir_x * sin(rot) + dir_y * cos(rot) */
void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.room_plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	game->player.room_plane_x = game->player.room_plane_x * cos(rot_speed)
		- game->player.room_plane_y * sin(rot_speed);
	game->player.room_plane_y = old_plane_x * sin(rot_speed)
		+ game->player.room_plane_y * cos(rot_speed);
}

/*Parametri: puntatore a t_game, direzione (1 = avanti, -1 = indietro)
Cosa fa:
 - Calcola la nuova posizione
 - Controlla le collisioni con i muri
 - Aggiorna la posizione solo se è percorribile
Formula: new_pos = old_pos + direction_vector * move_speed */
void	move_forward_back(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED * direction;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED * direction;
	if (is_walkable(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_walkable(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

/* Muove il giocatore lateralmente (strafe)
Parametri: puntatore a t_game, direzione (-1 = sinistra, 1 = destra)
Cosa fa:
- Calcola il vettore perpendicolare alla direzione (per lo spostamento laterale)
- Si sposta perpendicularmente alla direzione corrente
 Formula vettore perpendicolare: (dir_y, -dir_x) o (-dir_y, dir_x) */
void	move_strafe(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED * direction;
	new_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED * direction;
	if (is_walkable(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (is_walkable(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

/* Muove il giocatore in base ai tasti premuti
 Parametri: puntatore a t_game
 Cosa fa:
- Controlla i flag dei tasti (impostati da key_press/key_release)
- A/D: spostamento laterale
- Frecce: rotazione sinistra/destra
Nota: questa funzione viene chiamata ogni frame (60 volte al secondo)
in modo da avere un movimento fluido */
void	move_player(t_game *game)
{
	if (game->keys.w)
		move_forward_back(game, 1);
	if (game->keys.s)
		move_forward_back(game, -1);
	if (game->keys.a)
		move_strafe(game, -1);
	if (game->keys.d)
		move_strafe(game, 1);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
}
