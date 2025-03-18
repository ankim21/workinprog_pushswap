/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:34:13 by ankim             #+#    #+#             */
/*   Updated: 2025/03/18 18:13:53 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "LIBFT/libft.h"

static void	ft_free_array(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
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
	return ();
}

int	ft_check1(int argc, char **argv)
{
	int		i;
	int		y;

	i = 0;
	y = 1;
	if (argc < 2)
    {
        write (1, "ERROR", 6);
		return (-1);
    }
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
	return(*argv);
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

int	main(int argc, char **argv)
{
	int y;
	int x;
    char *result;
	int *num;

	y = 1;
	x = 0;
	if (argc < 2)
    {
        write (1, "ERROR", 6);
		return (-1);
    }
    num = malloc((argc - 1) * sizeof(int));
    if (argc == 2)
    {
        result = ft_printme(argc, argv);
        num [y - 1] = ft_atoi(&result[x]);
        x++;
    }
    else
    {
        num[y - 1] = ft_atoi(argv[y]);
        y++;
    }
    if (ft_checkdouble(num, argc - 1) == -1)
    {
        write (1, "ERROR", 6);
        free(num);
        return (-1);
    }
    free(num);
	return(0);
}
