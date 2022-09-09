/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksancako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:49:00 by ksancako          #+#    #+#             */
/*   Updated: 2022/01/27 14:49:15 by ksancako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(long long int n)
{
	if (n < -2147483648)
		return (0);
	if (n > 2147483647)
		return (-1);
	return ((int)n);
}

int	ft_atoi(const char *str)
{
	long long int	i;
	long long int	s;
	long long int	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0') * s;
		i++;
	}
	return (check(res));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fonk(void);

int main(void)
{
    char cdizi[40];

    strcpy(cdizi, "9999999999999999999999999 ");
    printf("Karakter dizisi: %s Int değer: %d\n 
bizimki: %d\n", cdizi, atoi(cdizi), ft_atoi(cdizi));

    strcpy(cdizi, "-9999999999999999999999999");
    printf("Karakter dizisi: %s Int değer: %d\n 
bizimki: %d\n", cdizi, atoi(cdizi), ft_atoi(cdizi));
    return 0;
}
*/
