/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_anim_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by ilnassi           #+#    #+#             */
/*   Updated: 2026/03/23 00:00:00 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FILE: sprites_anim_bonus.c
** AUTORE: Ilaria (ilnassi) - da implementare
** PERCHE': Bonus opzionale: sprite con animazione a piu' frame.
**          Invece di un'immagine statica, lo sprite cicla su piu' texture XPM
**          per dare l'illusione del movimento (es. fiamma, personaggio).
**
** COME FUNZIONERA' (da implementare):
**   - Mantenere un contatore frame (es. in t_game) incrementato ogni render.
**   - Usare frame % N_FRAMES per selezionare quale texture mostrare.
**   - Caricare N texture XPM per ogni sprite animato all'avvio.
**   - Proiettare lo sprite sul piano camera come nel rendering classico
**     (trasformazione con matrice inversa, Z-buffer per occlusione muri).
**
** STATO: stub - funzione dichiarata ma non implementata.
**        Il prototipo e' in cub3d.h, richiesto dal linker per make bonus.
*/

#include "cub3d.h"

/*Stub: rendering degli sprite animati con frame multipli.
Non ancora implementata: da completare da Ilaria.
Scritta da: Ilaria (stub) */
void	render_animated_sprites(t_game *game)
{
	(void)game;
}
