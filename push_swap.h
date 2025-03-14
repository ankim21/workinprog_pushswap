/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:32:14 by ankim             #+#    #+#             */
/*   Updated: 2025/03/14 17:18:01 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "LIBFT/libft.h"
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

char	**ft_split(char const *s, char c);
long long	ft_atoi(char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlen(const char *s);
char *ft_process(int argc, char **argv);
int	ft_check1(int argc, char **argv);
char*	ft_writeme(int argc, char **argv);
char*	ft_printme(int argc, char **argv);
int	ft_checkdouble(int *nums, int size);
nodeptr	*create_node(int x);
void ft_append(nodeptr **head_ref, int data);
void ft_display(nodeptr *head);
int ft_delete (nodeptr **head_ref, int value);
void ft_freelist(nodeptr **head_ref);

#endif