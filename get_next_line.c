/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:04:15 by moouahab          #+#    #+#             */
/*   Updated: 2023/11/23 01:29:39 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			nbyte;
	static char	*temp;

	nbyte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (nbyte > 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
			return (free(buffer), NULL);
		buffer[nbyte] = 0;
		temp = ft_strjoin(temp, buffer);
		if (is_n(temp))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&temp));
}
