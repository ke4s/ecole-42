/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksancako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:00:03 by ksancako          #+#    #+#             */
/*   Updated: 2022/01/27 15:00:04 by ksancako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stddef.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;

	if ((!dst && !src) || !n)
		return (dst);
	a = dst;
	while (n--)
	{
		*(char *)a = *(char *)src;
		a++;
		src++;
	}
	return (dst);
}
