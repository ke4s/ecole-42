/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksancako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:15:26 by ksancako          #+#    #+#             */
/*   Updated: 2022/01/27 15:15:28 by ksancako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*mlst;

	mlst = *lst;
	if (!new)
		return ;
	if (*lst == (void *)0)
		*lst = new;
	else
	{
		while (mlst->next != (void *)0)
		{
			mlst = mlst->next;
		}
		mlst->next = new;
	}
}
