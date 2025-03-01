/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:51:16 by gnicolo           #+#    #+#             */
/*   Updated: 2025/02/15 13:50:19 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static int is_delimiter(char c, const char *delim) ==
Funzione che verifica se un carattere è un delimitatore
1 se È un delimitatore
0 se Non è un delimitatore
static char *skip_delimiters(char *str, const char *delim) ==
Funzione che salta i delimitatori all'inizio della stringa
Passa oltre i delimitatori
Restituisce la stringa senza delimitatori iniziali
char *ft_strtok(char *str, const char *delim) ==
Funzione che tokenizza la stringa
Stato statico per ricordare la posizione
Se str è NULL, continuiamo da dove eravamo nella stringa precedente
Se la stringa è finita, restituiamo NULL
Saltiamo i delimitatori iniziali
Se siamo alla fine della stringa, non ci sono più token
Salviamo l'inizio del token
Cerchiamo il prossimo delimitatore
Continua fino a trovare un delimitatore
Sostituiamo il delimitatore con '\0' per terminare il token
Spostiamo il puntatore oltre il delimitatore
Restituiamo il token trovato */
static int	is_delimiter(char c, const char *delim)
{
	int	i;

	i = 0;
	while (delim[i] != '\0')
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*skip_delimiters(char *str, const char *delim)
{
	while (*str != '\0' && is_delimiter(*str, delim))
		str++;
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*input;
	char		*start;

	if (!input)
		input = NULL;
	if (str != NULL)
		input = str;
	if (input == NULL)
		return (NULL);
	input = skip_delimiters(input, delim);
	if (*input == '\0')
		return (NULL);
	start = input;
	while (*input != '\0' && !is_delimiter(*input, delim))
		input++;
	if (*input != '\0')
	{
		*input = '\0';
		input++;
	}
	return (start);
}

// int main() {
//	char str[] = "Questo è un esempio di stringa!";
//	const char *delim = " ";  // Separatore: spazio
//	char *token;

//	// Chiamata iniziale
//	token = my_strtok(str, delim);
//	while (token != NULL) {
//		printf("Token: %s\n", token);
//		token = my_strtok(NULL, delim);  // Le chiamate successive passano NULL
//	}

//	return 0;
// }