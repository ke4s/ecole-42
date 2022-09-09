/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksancako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:49:59 by ksancako          #+#    #+#             */
/*   Updated: 2022/01/27 14:50:00 by ksancako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;	

	str = (void *) malloc(size * count);
	if (!str)
		return (0);
	ft_memset(str, 0, (size * count));
	return (str);
}
/*
#include <stdio.h>
int main()
{
	size_t a = 5;
	size_t b = 4;

	printf("%s \n", ft_calloc(a, b));
	return 0;
}*/
