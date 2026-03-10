
#ifndef STRUCTS_H
# define STRUCTS_H

/* LIBRERIE NECESSARIE */

# include <mlx.h>

/* STRUTTURE DATI PER IL MOTORE RAY-CASTING */

/*
 * t_img - Immagine per il rendering
 * Usata per l'immagine principale dello schermo (double buffering)
 * e per le texture caricate da file XPM.
 */
typedef struct s_img
{
	void	*img;			// puntatore all'immagine MLX
	char	*addr;			// indirizzo dei pixel in memoria
	int		bpp;			// bits per pixel (deve essere 32 per miniLibX)
	int		line_length;	// numero di byte per riga dell'immagine
	int		byte_order;		// ordine dei byte (little/big endian)
}	t_img;

/*
 * t_keys - Stato dei tasti
 * Usato per il movimento fluido. Invece di muovere il giocatore
 * direttamente nell'handler del tasto, si impostano dei flag.
 * Nel game loop si controllano i flag e si muove il giocatore.
 */
typedef struct s_keys
{
	int	w;			// avanti (W o freccia su)
	int	s;			// indietro (S o freccia giu)
	int	a;			// spostamento laterale sinistra (A)
	int	d;			// spostamento laterale destra (D)
	int	left;		// rotazione sinistra (freccia)
	int	right;		// rotazione destra (freccia)
	int	esc;		// uscire dal gioco
}	t_keys;

/*
 * t_texture - Texture per i muri
 * Texture per i 4 lati dei muri.
 * NO=Nord(0), SO=Sud(1), WE=Ovest(2), EA=Est(3)
 */
typedef struct s_texture
{
	t_img	img;			// immagine della texture caricata
	int		width;			// larghezza (devono essere quadrati, es. 64x64)
	int		height;			// altezza
	char	*path;			// percorso del file XPM (per debug e ricaricamento)
}	t_texture;

/*
 * t_player - Giocatore
 * Rappresenta la telecamera del giocatore nel mondo 3D.
 * Il giocatore ha una posizione 2D nella mappa e un orientamento.
 *
 * Orientamenti iniziali possibili:
 * - N: dir=(0,-1), plane=(0.66,0)
 * - S: dir=(0,1), plane=(-0.66,0)
 * - E: dir=(1,0), plane=(0,0.66)
 * - W: dir=(-1,0), plane=(0,-0.66)
 */
typedef struct s_player
{
	double	pos_x;		// coordinate nella mappa (decimali, es. pos_x = 3.5)
	double	pos_y;
	double	dir_x;		// vettore di direzione (dove guarda il giocatore)
	double	dir_y;
	double	room_plane_x;	// piano della camera (determina il FOV)
	double	room_plane_y;
}	t_player;

/*
 * t_map - Mappa del gioco
 * La mappa e una griglia 2D dove ogni cella contiene:
 * - 0 = spazio vuoto (si puo camminare)
 * - 1 = muro (collisione)
 * - N, S, E, W = posizione iniziale del giocatore
 * - 2 = porta (bonus)
 * - spazio = spazio vuoto, diverso da 0 per formato file
 */
typedef struct s_map
{
	char	**grid;			// array di stringhe (ogni stringa = una riga della mappa)
	int		width;			// larghezza massima (numero di colonne)
	int		height;			// altezza (numero di righe)
	int		player_x;		// coordinate del giocatore nella griglia (int)
	int		player_y;
	char	player_dir;		// carattere che indica l'orientamento iniziale
}	t_map;

/*
 * t_game - Gioco principale
 * Struct che contiene tutto il gioco. In questo modo e facile
 * passare un solo puntatore a tutte le funzioni.
 */
typedef struct s_game
{
	void		*mlx;			// puntatore all'istanza miniLibX (mlx_init)
	void		*win;			// puntatore alla finestra (mlx_new_window)
	t_img		img;			// immagine principale per il rendering
	t_texture	textures[4];	// array delle 4 texture muri (NO, SO, WE, EA)
	t_map		map;			// struttura della mappa
	t_player	player;			// struttura del giocatore
	t_keys		keys;			// stato dei tasti
	int			floor_color;	// colore del pavimento (formato 0x00RRGGBB)
	int			ceiling_color;	// colore del soffitto

	/* TODO: Bonus (da aggiungere quando implementati):
	 * - z_buffer: array delle distanze dei muri per ogni colonna (per sprite)
	 * - sprites: array degli sprite nella mappa
	 * - num_sprites: numero di sprite
	 */
}	t_game;

#endif
