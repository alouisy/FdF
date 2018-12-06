/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:28:37 by alouisy-          #+#    #+#             */
/*   Updated: 2016/12/12 22:28:40 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_line	*make_list(int fd)
{
	t_line	*list;

	list = (t_line *)malloc(sizeof(t_line));
	if (list)
	{
		list->line = ft_strnew(0);
		list->fd = fd;
		list->next = NULL;
	}
	return (list);
}

static t_line	*goto_fd(t_line *begin_list, int fd)
{
	t_line	*list;
	t_line	*tmp;

	list = begin_list;
	while (list != NULL && list->fd != fd)
	{
		tmp = list;
		list = list->next;
	}
	if (list == NULL)
	{
		list = tmp;
		tmp = make_list(fd);
		list->next = tmp;
		return (tmp);
	}
	else
		return (list);
}

static int		find_n(char *buff, t_line *list, char **line)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		len;

	s1 = ft_strjoin(list->line, buff);
	free(list->line);
	if (ft_strchr(s1, '\n') != NULL)
	{
		len = (int)(ft_strchr(s1, '\n') - s1);
		s2 = ft_strsub(s1, 0, len);
		s3 = ft_strsub(s1, len + 1, ft_strlen(s1) - len + 1);
		list->line = s3;
		*line = s2;
		free(s1);
		return (1);
	}
	else
		list->line = s1;
	return (0);
}

static int		fct_read(char **line, t_line *list)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		gl;

	gl = 0;
	if (find_n("", list, line) == 1)
		return (1);
	while (gl != 1 && (ret = read(list->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		gl = find_n(buff, list, line);
	}
	if (gl == 1)
		return (1);
	else if (ret == 0 && ft_strlen(list->line) > 0)
	{
		*line = ft_strdup(list->line);
		ft_strclr(list->line);
		return (1);
	}
	else if (ret == 0)
		return (0);
	else
		return (-1);
}

int				get_next_line(const int fd, char **line)
{
	int				res;
	static t_line	*begin_list = NULL;
	t_line			*list;

	if (begin_list == NULL)
		begin_list = make_list(fd);
	list = goto_fd(begin_list, fd);
	res = fct_read(line, list);
	return (res);
}
