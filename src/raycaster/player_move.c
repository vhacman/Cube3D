#include "cub3d.h"

/* ============================================================================ */
/* MOVIMENTO DEL GIOCATORE */
/* ============================================================================ */

/* Controlla se una cella della mappa è percorribile (non è un muro)
 * Parametri: puntatore a t_game, coordinate x e y nella mappa
 * Restituisce: 1 se è percorribile, 0 se è un muro
 * Nota: controlla anche che le coordinate siano dentro i limiti della mappa */
int	is_walkable(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	/* Converte le coordinate float in indici della mappa (int) */
	map_x = (int)x;
	map_y = (int)y;
	/* Controlla che sia dentro i limiti della mappa */
	if (map_x < 0 || map_x >= game->map.width || map_y < 0
		|| map_y >= game->map.height)
		return (0);
	/* Controlla che non sia un muro ('1') */
	if (game->map.grid[map_y][map_x] == '1')
		return (0);
	return (1);
}

/* Ruota il giocatore a sinistra o destra
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Ruota il vettore direzione del giocatore
 *   - Ruota il piano della camera (determina il FOV)
 * Formula: rotazione di una matrice 2D:
 *   new_dir_x = dir_x * cos(rot) - dir_y * sin(rot)
 *   new_dir_y = dir_x * sin(rot) + dir_y * cos(rot) */
void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	/* Salva i valori vecchi prima della rotazione */
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.room_plane_x;
	/* Ruota il vettore direzione */
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	/* Ruota il piano della camera */
	game->player.room_plane_x = game->player.room_plane_x * cos(rot_speed)
		- game->player.room_plane_y * sin(rot_speed);
	game->player.room_plane_y = old_plane_x * sin(rot_speed)
		+ game->player.room_plane_y * cos(rot_speed);
}

/* Muove il giocatore avanti o indietro
 * Parametri: puntatore a t_game, direzione (1 = avanti, -1 = indietro)
 * Cosa fa:
 *   - Calcola la nuova posizione
 *   - Controlla le collisioni con i muri
 *   - Aggiorna la posizione solo se è percorribile
 * Formula: new_pos = old_pos + direction_vector * move_speed */
void	move_forward_back(t_game *game, int direction)
{
	double	new_x;
	double	new_y;
	/* Calcola la nuova posizione moltiplicando per direction (1 o -1) */
	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED * direction;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED * direction;
	/* Controlla la collisione sull'asse X (movimento laterale del giocatore) */
	if (is_walkable(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	/* Controlla la collisione sull'asse Y */
	if (is_walkable(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

/* Muove il giocatore lateralmente (strafe)
 * Parametri: puntatore a t_game, direzione (-1 = sinistra, 1 = destra)
 * Cosa fa:
 *   - Calcola il vettore perpendicolare alla direzione (per lo spostamento laterale)
 *   - Si sposta perpendicularmente alla direzione corrente
 * Formula vettore perpendicolare: (dir_y, -dir_x) o (-dir_y, dir_x) */
void	move_strafe(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	/* Il vettore perpendicolare si ottiene scambiando e negando le coordinate:
	 * perpendicolare = (dir_y, -dir_x) per movimento a sinistra
	 * perpendicolare = (-dir_y, dir_x) per movimento a destra */
	new_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED * direction;
	new_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED * direction;
	/* Controlla la collisione sull'asse X */
	if (is_walkable(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	/* Controlla la collisione sull'asse Y */
	if (is_walkable(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

/* Muove il giocatore in base ai tasti premuti
 * Parametri: puntatore a t_game
 * Cosa fa:
 *   - Controlla i flag dei tasti (impostati da key_press/key_release)
 *   - W/S: movimento avanti/indietro
 *   - A/D: spostamento laterale
 *   - Frecce: rotazione sinistra/destra
 * Nota: questa funzione viene chiamata ogni frame (60 volte al secondo)
 * in modo da avere un movimento fluido */
void	move_player(t_game *game)
{
	/* Movimento avanti (W o freccia SU) */
	if (game->keys.w)
		move_forward_back(game, 1);
	/* Movimento indietro (S o freccia GIU) */
	if (game->keys.s)
		move_forward_back(game, -1);
	/* Spostamento laterale a sinistra (A o Q) */
	if (game->keys.a)
		move_strafe(game, -1);
	/* Spostamento laterale a destra (D) */
	if (game->keys.d)
		move_strafe(game, 1);
	/* Rotazione a sinistra (freccia SINISTRA) */
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
	/* Rotazione a destra (freccia DESTRA) */
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
}
