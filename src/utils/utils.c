#include "cub3d.h"
/* FUNZIONI DI UTILITA */

/* Libera un array di stringhe (terminato da NULL)
 * Parametri: puntatore a array di stringhe
 * Cosa fa: libera ogni stringa e poi l'array stesso
 * Uso: libera la mappa (grid), texture paths, ecc.
 * Esempio:
 *   char **arr = {"ciao", "mondo", NULL};
 *   free_str_array(arr); */
void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

/* Libera un puntatore e lo imposta a NULL
 * Parametri: puntatore a puntatore (void**)
 * Cosa fa: libera la memoria e imposta il puntatore a NULL
 * Uso: previene use-after-free
 * Esempio:
 *   void *ptr = malloc(100);
 *   safe_free(&ptr); // ptr ora e NULL */
void	safe_free(void **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

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
