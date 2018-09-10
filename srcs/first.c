/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:44:19 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/06 18:07:36 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\libft\libft.h"
#include "..\includes\push_swap.h"
#include <stdio.h>

void	ft_init(t_stacks *s, int size)
{
	int i;

	i = 0;
	s->a_top = -1;
	s->b_top = -1;
	s->a = (int *)malloc(sizeof(int) * size);
	s->b = (int *)malloc(sizeof(int) * size);
	s->masterstack = (int *)malloc(sizeof(int) * size);
	while (i <= size)
	{
		s->a[i] = 0;
		s->b[i] = 0;
		s->masterstack[i] = 0;
		i++;
	}
}

void	error(int i)
{
	ft_putnbr(i);
	ft_putchar('\n');
}

void	normalize(t_stacks *s)
{
	int i;
	int j;
	int *tmp;
	int size;

	size = s->a_top + 1;
	tmp = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		tmp[i] = s->a[i];
		s->a[i] = size;
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (tmp[i] < tmp[j])
				s->a[i]--;
	}
	free(tmp);
}

int		is_sorted(t_stacks *s)
{
	int i;
	int j;

	i = 0;
	while (i <= s->a_top)
	{
		j = i;
		while (j <= s->a_top)
		{
			if (s->a[i] < s->a[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	print_tab(t_stacks *s, char c)
{
	int		len;
	int		*tab;
	int		size;
	char	*str;

	if (c == 'a')
	{
		tab = s->a;
		size = s->a_top;
	}
	else if (c == 'b')
	{
		tab = s->b;
		size = s->b_top;
	}
	else
		return ;
	while (size >= 0)
	{
		str = ft_itoa(tab[size]);
		len = ft_strlen(str);
		write(1, str, len);
		ft_putchar('\n');
		size--;
	}
}
