/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksancako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:49:36 by ksancako          #+#    #+#             */
/*   Updated: 2022/01/27 14:49:38 by ksancako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "meryem altundal";
	size_t	n = 6;
	ft_bzero(s, n);
	printf("%s\n", s);
	return 0;
}
*/
