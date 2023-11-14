/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheres <sonheres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:05:49 by sonheres          #+#    #+#             */
/*   Updated: 2023/11/09 10:11:19 by sonheres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

/* Crea una subcadena. 
Devuelve un puntero de la subcadena desde la posición 'start'.
Creo una variable size_t 'strlength' para guardar longitud de 's'.
Así no tengo llamar tantas veces a ft_strlen.
Primero excluye errores para devolver UNA CADENA VACÍA '\0', no NULL.
Si 'start' = punto inicio, que es mayor que la longitud de s, 
si la longitud de s es 0, o la longitud final de la subcadena, 
devolverá un único byte '\0' en la posición 0.
Y reserva memoria para 1 byte ->'substr = (char *)malloc (sizeof(char) * 1)'.
Si falla la reserva de memoria devuelve NULL. Si no, devuelve solo 
el fin de cadena. "0" = '\0'
Después comprueba que la longitud total 'len' no sobrepase la longitud
total de 's'. 'if (start + len > strlength) -> len = strlength - start'.
Asignamos memoria a la nueva subcadena + 1 ('\0').
Si falla la reserva de memoria devuelve NULL.
Entra en un while siempre que el contador de la nueva subcadena -> 'substr[i]'
sea menor que la nueva longitud y siempre que el contador de la cadena
origen -> s[j] no sea '\0'.
Avanza en paralelo en las dos cadenas. Finalmente añade '\0'.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;
	size_t	strlength;

	strlength = ft_strlen(s);
	if (start >= strlength || strlength == 0 || len == 0)
	{
		substr = (char *)malloc (sizeof(char) * 1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > strlength)
		len = strlength - start;
	substr = (char *) malloc (sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && s[j] != '\0')
		substr[i++] = s[j++];
	substr[i] = '\0';
	return (substr);
}

/* int	main(void)
{
	char			*s = "HOLA";

	printf("Subcadena: %s\n", ft_substr(s, 4, 0));
	return (0);
} */