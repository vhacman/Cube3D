#include "cub3d.h"


/* Crea un colore nel formato miniLibX
 * Parametri:
 *   - red: componente rossa (0-255)
 *   - green: componente verde (0-255)
 *   - blue: componente blu (0-255)
 * 
 * Cosa fa:
 *   - Combina le tre componenti in un intero a 32 bit
 *   - Formato: 0x00RRGGBB
 * 
 * Calcolo:
 *   - (red << 16) | (green << 8) | blue
 * 
 * Esempi:
 *   - Nero: create_color(0, 0, 0) = 0x00000000
 *   - Bianco: create_color(255, 255, 255) = 0x00FFFFFF
 *   - Rosso: create_color(255, 0, 0) = 0x00FF0000
 *   - Verde: create_color(0, 255, 0) = 0x0000FF00
 *   - Blu: create_color(0, 0, 255) = 0x0000FF00
 */
int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
