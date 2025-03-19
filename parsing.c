/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:34:13 by ankim             #+#    #+#             */
/*   Updated: 2025/03/19 17:58:39 by ankim            ###   ########.fr       */
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

int	ft_wordcount2(char *str, char sep)
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

char **ft_process(char **str)
{
	int y; 
	int j;
	char **s;

	y = 1;
	j = 0;
		if (ft_strchr(str[1], ' '))
		{
			s = ft_split(str[1], ' ');
			if (!s)
				return (NULL);
			while (s[j] != NULL)
			{
				write(1, s[j], ft_strlen(s[j]));
				write(1, "\n", 1);
				j++;
			}
		}
	return(s);
}

int	*ft_tilps(char **s)
{
	int	i;
	int count;
	int *array;

	i = 0;
	count = 0;
	while (s[count])
	{
		count++;
	}
	array = malloc (sizeof(int *) * count);
	if (!array)
		return (NULL);
	while (i < count)
	{
		array[i] = ft_atoi(s[i]);
		i++;
	}
	return(array);
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

// char**	ft_writeme(int argc, char **argv)
// {
// 	int	y;
// 	int i;

// 	y = 1;
// 	i = 0;
// 	while (y < argc)
// 	{
// 		while (argv[y][i])
// 		{
// 			write (1, &argv[y][i], 1);
// 			i++;
// 		}
// 		write (1, "\n", 1);
// 		i = 0;
// 		y++;
// 	}
// 	return(argv + 1);
// }

char**	ft_printme(int argc, char **argv)
{
	int check_results;
	
	check_results = ft_check1(argc, argv);
	if (argc == 2)
	{
		if (check_results == -1)
			write(1, "ERROR\n", 6);
		else
			return (ft_process(argv));
	}
	else
	{
		if (check_results == -1)
			write(1, "ERROR\n", 6);
		else if (check_results == 0)
			return(argv + 1);
	}
	return(NULL);
}

// int	ft_checkdouble(int *nums, int size)
// {
// 	int i;
// 	int j;

// 	j = 0;
// 	i = j + 1;
// 	while (j < size - 1)
// 	{
// 		while (i < size)
// 		{
// 			if (nums[j] == nums[i])
// 				return (-1);
// 			i++;
// 		}
// 		j++;
// 		i = j + 1;
// 	}
// 	return (0);
// }

void printstack(t_node *stack_a)
{
	t_node *current;
	
	current = stack_a;
	while (1)
	{
		printf("%d \n", current->data);
		current = current->next;
		if (current == stack_a)
			break ;
	}
}

int add_node (int data, t_node **headnode)
{
	t_node *new;
	t_node *previous;

	previous = (*headnode)->prev;
	new = malloc (sizeof(t_node));
	if (!new)
		return (-1);
	new->data = data;
	new->next = *headnode;
	new->prev = previous;
	previous->next = new;
	(*headnode)->prev = new; 
	return (0);
}

int	create_headnode(int data, t_node **headnode)
{
	*headnode = malloc(sizeof(t_node));
	if (!*headnode)
		return (-1);
	(*headnode)->data = data;
	(*headnode)->prev = *headnode;
	(*headnode)->next = *headnode;
	return (0);
}

int create_stack (int data, t_node **stack_a)
{
	if (!*stack_a)
		return (create_headnode(data, stack_a));
	else 
		return (add_node(data, stack_a));
}

int	main(int argc, char **argv)
{
    char **result;
	int *num;
	int size;
	int i;
	t_node *stack_a;

	stack_a = NULL;
	i = 0;
	if (argc < 2)
    {
        write (1, "ERROR", 6);
		return (-1);
    }
	result = ft_printme(argc, argv);
	if (!result)
		return (-1);
	if (argc == 2)
    {
		size = ft_wordcount2(argv[1], ' ');	
		num = ft_tilps(result);
		if (!num)
		{
			if (argc == 2)
				ft_free_array(result, size);
			return (-1);
		}
		if (create_stack(ft_atoi(num[i]), &stack_a) == -1)
			return (-1);
		i++;
    }
	else
	{
		while (i < argc - 1)
		{
			if (create_stack(ft_atoi(result[i]), &stack_a) == -1)
				return(-1);
			i++;
		}
		printstack(stack_a);
	}
	// if (ft_checkdouble(num, size) == -1)
    // {
    //     write (1, "ERROR", 6);
    //     free(num);
	// 	if (result)
	// 		ft_free_array(result, size);
    //     return (-1);
    // }
	free(num);
	return(0);
}
