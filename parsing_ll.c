/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:24:44 by ankim             #+#    #+#             */
/*   Updated: 2025/03/14 17:19:24 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void ft_append(nodeptr **head_ref, int data)
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

void ft_display(nodeptr *head)
{
	int x;
	nodeptr *current;

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
	return;
}

int ft_delete (nodeptr **head_ref, int value)
{
	if (*head_ref == NULL)
		return (0);
	nodeptr *current = *head_ref;
	nodeptr *delete = NULL;
	while (delete == NULL && current->next != *head_ref)
	{
		if (current->data == value)
		{
			delete = current;
			break;
		}
		current = current->next;
	}
	if (delete == NULL && current->data == value)
		delete = current;
	if (delete == NULL) //if value was not on the list, delete == NULL
		return (0);
	if (delete-> next== delete)
		{
			free(delete);
			*head_ref = NULL;
			return (1);
		}
	delete->prev->next = delete->next; //links prev node to next node;
	delete->next->prev = delete->prev; // links next node to prev node;
	if (delete == *head_ref)
		*head_ref = delete->next;
	free(delete);
	return (1);	
}

void	ft_freelist(nodeptr **head_ref)
{
	nodeptr *current;
	nodeptr *next;
	nodeptr *last; 

	if (*head_ref == NULL)
		return;
	current = *head_ref; 
	last = (*head_ref)->prev;
	last->next = NULL;
	(*head_ref)->prev = NULL;
	while (current != NULL)
	{
		next = current->next; // save next before freeing
		free(current);
		current = next; // move to the next node
	}
	*head_ref = NULL;
	return;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (NULL);
	
}