/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:01:20 by alvdelga          #+#    #+#             */
/*   Updated: 2024/04/22 16:30:52 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_and_update_result(char **result, char *line)
{
	char	*tmp;

	ft_strlcpy(line, *result, (ft_strchr(*result, '\n') - *result) + 2);
	tmp = *result;
	*result = ft_strdup(ft_strchr(*result, '\n') + 1);
	free(tmp);
	return (line);
}

static char	*process_result(char **result)
{
	char	*line;

	if (ft_strchr(*result, '\n'))
	{
		line = (char *)malloc(ft_strchr(*result, '\n') - *result + 2);
		if (line == NULL)
			return (NULL);
		line = get_line_and_update_result(result, line);
	}
	else
	{
		line = (char *)malloc(ft_strlen(*result) + 1);
		if (line == NULL)
			return (NULL);
		if (line)
		{
			ft_strlcpy(line, *result, ft_strlen(*result) + 1);
			free(*result);
			*result = (NULL);
		}
	}
	return (line);
}

int	read_file(int fd, char **result, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(*result, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*result);
			*result = ft_strdup("");
			return (-1);
		}
		buffer[bytes_read] = '\0';
		tmp = *result;
		*result = ft_strjoin(*result, buffer);
		free(tmp);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*result;
	char		*line;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!result)
		result = ft_strdup("");
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read_file(fd, &result, buffer);
	free(buffer);
	if (bytes_read <= 0 && ft_strlen(result) == 0)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line = process_result(&result);
	return (line);
}

//  
// get_next_line.c get_next_line_utils.c -fsanitize=address -static-libsan
// ./a.out txt/texto.txt

//LECTURA DE FICHERO O DE STDIN
int	main(int argc, char *argv[])
{
	char *buffer;

	// Leer desde archivo si se proporciona un argumento en la línea de comandos
	if (argc == 2)
	{
		// Abrir el archivo para lectura
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}

		// Llamar a la función para leer el contenido del archivo
		while ((buffer = get_next_line(fd)) != NULL)
		{
			// Verificar si se asignó memoria correctamente
			if (buffer == NULL)
			{
				fprintf(stderr, "Fallo al asignar memoria para el buffer\n");
				break;
			}

			// Procesar la línea leída
			printf("RECIBIDO: %s\n", buffer);

			// Liberar la memoria asignada a la línea
			free(buffer);
		}

		// Cerrar el descriptor de archivo
		if (close(fd) == -1)
		{
			perror("close");
			exit(EXIT_FAILURE);
		}
	}
}
    