/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:22:40 by ankim             #+#    #+#             */
/*   Updated: 2025/03/13 19:32:24 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} nodeptr;

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
	return(array);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char *ft_process(int argc, char **argv)
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
			if (!s)
				return (NULL);
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
	return (NULL);
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

			i++;
		}
		y++;
	}
	return (0);
}

char*	ft_writeme(int argc, char **argv)
{
	int	y;
	int i;

	y = 1;
	i = 0;
	while (y < argc)
	{
		while (argv[y][i])
		{
			write (1, &argv[y][i], 1);
			i++;
		}
		write (1, "\n", 1);
		i = 0;
		y++;
	}
	return(NULL);
}

char*	ft_printme(int argc, char **argv)
{
	int check_results;
	
	check_results = ft_check1(argc, argv);
	if (argc == 2)
	{
		if (check_results == -1)
			write(1, "ERROR\n", 6);
		else
			return (ft_process(argc, argv));
	}
	else
	{
		if (check_results == -1)
			write(1, "ERROR\n", 6);
		else if (check_results == 0)
			return(ft_writeme(argc, argv));
	}
}

int	ft_checkdouble(int *nums, int size)
{
	int i;
	int j;

	j = 0;
	i = j + 1;
	
	while (j < size - 1)
	{
		while (i < size)
		{
			if (nums[j] == nums[i])
				return (-1);
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

nodeptr	*create_node(int x)
{
	nodeptr	*new;

	new = (nodeptr *)malloc(sizeof(nodeptr));
	if (!new)
		return (NULL);
	new->data = x;
	new->next = new;
	new->prev = new;
	return (new);
}

void *append(nodeptr **head_ref, int data)
{
	nodeptr *new = create_node(data);
	if (*head_ref == NULL)
	{
		*head_ref = new;
		new->next = new;
		new->prev = new;
		return;
	}
	nodeptr *last = (*head_ref)->prev;
	new->next = *head_ref;
	new->prev = last;
	last->next = new;
	(*head_ref)->prev = new;
	return;
}

void ft_display(nodeptr head)
{
	int x;
	nodeptr current;

	x = 0;
	if (!head)
	{
		printf("List is empty \n");
		return;
	}
	current = head;
	while (current != head)
		{
			printf("%d", current->data);
			current = current->next;
		}
	printf("\n");
	
}

int	main(int argc, char **argv)
{
	int y;
	int i;
	char *results;
	int	*num;
	int x;
	int final;

	y = 1;
	i = 0;
	x = 0;
	num = malloc(sizeof(int) * (argc - 1));
	if (!num)
		return (-1);
	results = malloc(sizeof(char*) * (ft_strlen(results)));
	if (!results)
		return (-1);
	if (argc < 2)
		return (-1);
	while (y < argc)
	{
		results = ft_printme(argc, argv);
		while (results[i])
		{
			num[x] = ft_atoi(&results[i]);
			x++;
			i++;
			free(results);
		}
	}
	final = ft_checkdouble(num, argc - 1);
	free(num);
	return(final);
}
