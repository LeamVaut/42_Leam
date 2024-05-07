/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvdelga <alvdelga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:01:20 by alvdelga          #+#    #+#             */
/*   Updated: 2024/05/05 13:51:38 by alvdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*set_next_line(char *text)
{
	size_t		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free (text);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(text) - i + 1), sizeof(*text));
	if (!str)
		return (NULL);
	while (text[++i] != '\0')
		str[j++] = text[i];
	str[j] = '\0';
	free (text);
	return (str);
}

char	*get_line_on_buffer(char *text)
{
	size_t		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

char	*read_buffer(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (text);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	text[fd] = read_buffer(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	output_text = get_line_on_buffer(text[fd]);
	text[fd] = set_next_line(text[fd]);
	return (output_text);
}

/*int main()
{
	int fd = open("txt.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
 	{
 		printf("%s", a);
		free(a);
 	}

 	printf("\n%s", get_next_line(fd));
	close(fd);
     return 0;
// valgrind --leak-check=full ./a.out
}*/
/*int main(int argc, char **argv)
{
	int fd = open(argv[1], O_CREAT);
	char *result;
	printf("%d\n", fd);
	while ((result = get_next_line(fd)))
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
}*/
/*int main()
{
    int fd = open("files/txt.txt", O_CREAT);
    int fdb = open("files/txt3.txt", O_CREAT);
    int fdc = open("files/txtt.txt", O_CREAT);
    char *a;

    printf("%d\n", fd);
    printf("%d\n", fdb);
    printf("%d\n", fdc);
    // while ((a = get_next_line(fd)))
    // {
    //     printf("%s", a);
	// 	free(a);
    // }  

    printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fdb));
	printf("%s\n", get_next_line(fdc));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%u\n", get_next_line(fd));

    return 0;  
}*/