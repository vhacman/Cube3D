#include "cub3d.h"

/* Imposta la direzione e il piano camera del giocatore
 * in base al carattere di spawn (N/S/E/W).
 * Sostituisce il carattere nella griglia con '0'. */
static void	init_player(t_game *game)
{
	char	dir;

	dir = game->map.player_dir;
	game->player.pos_x = game->map.player_x + 0.5;
	game->player.pos_y = game->map.player_y + 0.5;
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	if (dir == 'N' || dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = (dir == 'N') ? -1 : 1;
		game->player.room_plane_x = (dir == 'N') ? 0.66 : -0.66;
		game->player.room_plane_y = 0;
	}
	else
	{
		game->player.dir_x = (dir == 'E') ? 1 : -1;
		game->player.dir_y = 0;
		game->player.room_plane_x = 0;
		game->player.room_plane_y = (dir == 'E') ? 0.66 : -0.66;
	}
}

/* Verifica che tutti gli elementi obbligatori siano stati parsati:
 * 4 texture e i colori di floor e ceiling. */
static void	check_elements(t_game *game)
{
	int	i;

	if (game->floor_color == -1 || game->ceiling_color == -1)
		error_exit(game, "Missing floor or ceiling color");
	i = 0;
	while (i < 4)
	{
		if (!game->textures[i].path)
			error_exit(game, "Missing texture path");
		i++;
	}
}

/* Alloca e inizializza il gioco: parsing, validazione,
 * inizializzazione mlx, finestra, immagine, texture.
 * Restituisce il puntatore a t_game. */
t_game	*init_game(char *cub_path)
{
	t_game	*game;

	game = calloc(1, sizeof(t_game));
	if (!game)
		error_exit(NULL, "Failed to allocate game struct");
	game->floor_color = -1;
	game->ceiling_color = -1;
	parse_file(game, cub_path);
	check_elements(game);
	validate_map(game);
	init_player(game);
	game->mlx = init_mlx();
	game->win = create_window(game->mlx);
	init_image(game);
	init_keys(game);
	if (load_all_textures(game))
		error_exit(game, "Failed to load textures");
	load_weapon(game);
	setup_hooks(game);
	return (game);
}

/* Punto di ingresso: controlla il numero di argomenti,
 * inizializza il gioco e avvia il loop degli eventi. */
int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_exit(NULL, "Usage: ./cub3D <map.cub>");
	game = init_game(argv[1]);
	start_loop(game);
	return (0);
}
