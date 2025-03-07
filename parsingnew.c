/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:22:40 by ankim             #+#    #+#             */
/*   Updated: 2025/03/07 16:40:59 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

long long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str)
		return (1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (siz == 0)
		return (src_len);
	while ((i < siz - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

int	ft_wordcount(char *str, char sep)
{
	int	i;
	int	word;
	int	inword;

	i = 0;
	word = 0;
	inword = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == sep)
			inword = 0;
		else if (inword == 0)
		{
			word++;
			inword = 1;
		}
		i++;
	}
	return (word);
}

int	ft_wordlen(char *word, char sep, int i)
{
	int	len;

	len = 0;
	while (word[i] && word[i] != sep)
	{
		i++;
		len++;
	}
	return (len);
}

static void	ft_free_array(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wordcount;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	wordcount = ft_wordcount((char *)s, c);
	array = malloc(sizeof(char *) * (wordcount + 1));
	if (!array)
		return (NULL);
	while (j < wordcount && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		array[j] = malloc(sizeof(char) * (ft_wordlen((char *)s, c, i) + 1));
		if (!(array[j]))
			return (ft_free_array(array, j), NULL);
		ft_strlcpy(array[j++], &s[i], ft_wordlen((char *)s, c, i) + 1);
		i += ft_wordlen((char *)s, c, i);
	}
	array[j] = NULL;
	return (array);
}

int	ft_check1(int argc, char **argv)
{
	int		i;
	int		y;

	i = 0;
	y = 1;
	if (argc < 2)
		return (-1);
	while (y < argc)
	{
		i = 0;
		while (argv[y][i] != '\0')
		{
			if (!((argv[y][i] >= '0' && argv[y][i] <= '9') || argv[y][i] == '+'
					|| argv[y][i] == '-' || argv[y][i] == ' '))
				return (-1);
			else
			{
				write (1, &argv[y][i], 1);	
				i++;
			}
		}
		write(1, "\n", 1);
		y++;
	}
	return (0);
}

int ft_process(int argc, char **argv)
{
	int y; 
	int j;
	char **s;

	y = 1;
	j = 0;
	while (y < argc)
	{
		if (ft_strchr(argv[y], ' '))
		{
			s = ft_split(argv[y], ' ');
			j = 0;
			while (s[j] != NULL)
			{
				write(1, s[j], strlen(s[j]));
				write(1, "\n", 1);
				j++;
			}
			ft_free_array(s, j);
		}
		y++;
	}
	return (0);
}

int	ft_printme(int argc, char **argv)
{
	int	i;
	int	y;

	y = 1;
	i = 0;
	if (ft_check1(argc, argv) == 0)
	{
		ft_process(argc, argv);
	}
	else
	{
		write(1, "ERROR", 6);
		return (-1);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	ft_printme(argc, argv);
	return (0);
}