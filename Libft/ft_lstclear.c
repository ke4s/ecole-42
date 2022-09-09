/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksancako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:53:45 by ksancako          #+#    #+#             */
/*   Updated: 2022/01/27 14:54:11 by ksancako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mlst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		mlst = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = mlst;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

void lstprint(void *p)
{
    printf("%s", (char *)p);
}

void del(void *p)
{
	size_t m = ft_strlen(const char *s);
	ft_bzero(void *p, size_t m);
}

int main()
{
	t_list	*lst;
	t_list	*lst1;

	lst = ft_lstnew("123");
	lst1 = ft_lstnew("1234");

	ft_lstadd_back(&lst, lst1);
	ft_lstclear(&lst, del);
	ft_lstiter(lst, lstprint);
}
*/
