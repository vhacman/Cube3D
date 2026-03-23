/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:56:34 by vhacman           #+#    #+#             */
/*   Updated: 2026/03/23 15:01:08 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FILE: doors_bonus.c
** AUTORE: Gabriela (vhacman)
** PERCHE': Bonus richiesto dal subject: porte che il giocatore puo' aprire.
**          Le porte sono celle con carattere '2' nella griglia della mappa.
**          Prima del bonus, '2' non era un carattere valido: abbiamo aggiunto
**          il supporto in validate_map.c, player_move.c e dda.c.
**
** COME FUNZIONA:
**   - Il tasto E (KEY_E = 101) viene intercettato in key_press() (keys.c).
**   - key_press() chiama handle_doors() direttamente alla pressione del tasto.
**   - handle_doors() calcola la cella di fronte al giocatore usando
**     pos_x + dir_x (intero) come indice nella griglia.
**   - Se quella cella e' '2' (porta chiusa), la sostituisce con '0':
**     da quel momento il DDA e is_walkable non la trattano piu' come muro.
**   - La modifica e' permanente per tutta la sessione (la porta rimane aperta).
**
** MODIFICHE COLLEGATE IN ALTRI FILE (tutte di Gabriela, 23/03/2026):
**   - include/defines.h: aggiunto KEY_E 101 e MINIMAP_DOOR_COLOR
**   - src/parser/validate_map.c: '2' aggiunto ai caratteri validi
**   - src/raycaster/player_move.c: is_walkable() tratta '2' come muro
**   - src/raycaster/dda.c: dda_loop() si ferma su '2' come su '1'
**   - src/events/keys.c: aggiunta gestione KEY_E in key_press()
**
** CHIAMATA DA: key_press() in src/events/keys.c, alla pressione del tasto E.
*/

#include "cub3d.h"

/*Calcola le coordinate della cella direttamente di fronte al giocatore.
Usa pos_x + dir_x e pos_y + dir_y (troncati a int) come indice nella griglia.
Verifica i limiti della mappa prima di accedere alla griglia.
Restituisce un puntatore al carattere nella griglia, o NULL se fuori bounds.
Separata in funzione per mantenere handle_doors pulita e sotto 25 righe.
Scritta da: Gabriela */
static char	*get_front_cell(t_game *game)
{
	int	door_x;
	int	door_y;

	door_x = (int)(game->player.pos_x + game->player.dir_x);
	door_y = (int)(game->player.pos_y + game->player.dir_y);
	if (door_y < 0 || door_y >= game->map.height)
		return (NULL);
	if (door_x < 0 || door_x >= (int)ft_strlen(game->map.grid[door_y]))
		return (NULL);
	return (&game->map.grid[door_y][door_x]);
}

/*Gestisce l'apertura della porta di fronte al giocatore (tasto E).
Se la cella frontale e' '2' (porta chiusa), la sostituisce con '0'.
Da quel momento e' trattata come pavimento da is_walkable e dal DDA:
il giocatore puo' attraversarla e i raggi ci passano sopra senza fermarsi.
Scritta da: Gabriela */
void	handle_doors(t_game *game)
{
	char	*cell;

	cell = get_front_cell(game);
	if (!cell)
		return ;
	if (*cell == '2')
		*cell = '0';
}
