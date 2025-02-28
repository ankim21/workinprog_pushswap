/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:37:31 by ankim             #+#    #+#             */
/*   Updated: 2025/02/28 17:30:44 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_startcheck(int argc, char **argv)
{
	int	i;
	int y;

	i = 0;
	y = 0;
	if (argc < 2)
	{
		write(1, "fucking error", 12);
		return(1);
	}
	while (i > 0)
	{
		while (argv[i][y])
		{
			
		}
	}
}

int	ft_checkvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
	{
		i++;
	}
	if (ft_strlen(str[i]) >= 12)
		return ("ERROR");
    return(0);
}

long long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str)
		return (NULL);
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
