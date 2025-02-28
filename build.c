/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:55:35 by ankim             #+#    #+#             */
/*   Updated: 2025/02/28 16:47:05 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_cdnode
{
	int				data;
	struct s_cdnode	*next;
	struct s_cdnode	*prev;
}					t_cdnode;

typedef struct s_stack
{
	t_cdnode		*top;
	int				value;
}					t_stack;

t_cdnode	*new_node(int x)
{
	t_cdnode	*new;

	new = (t_cdnode *)malloc(sizeof(t_cdnode));
	if (!new)
		return (NULL);
	new->data = x;
	new->next = new;
	new->prev = new;
	return (new);
}

// t_stack	b(t_cdnode node)
// {
// 	t_stack	*a;

// 	a = (t_stack *)malloc(sizeof(t_stack));
// 	if (!a)
// 		return (NULL);
// 	a->top = NULL;
// 	a->value = 0;
// 	return (*a);
// }

int	main(int argc, char **argv)
{
	int	i;

	printf("number of args:: %d \n", argc);
	printf("prog name: %s\n", argv[0]);
	printf("Args: \n");
	for (i = 1; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	return (0);
}

// int main (void)
// {
// 	t_cdnode	*first;
// 	t_cdnode	*second;
// 	t_cdnode 	*third;

// 	first = new_node (10);
// 	second = new_node (20);
// 	third = new_node(30);

// 	first->next = second;
// 	first->prev = third;

// 	second->next = third;
// 	second->prev = first;

// 	third->next = first;
// 	third->prev = second;

// 	printf("%p, %p, %p \n", first, (void *)first->next, (void *)first->prev);
// 	printf("%p, %p, %p \n", second, (void *)second->next, (void *)second->prev);
// 	printf("%p, %p, %p \n", third, (void *)third->next, (void *)third->prev);
// 	return(0);
// }
