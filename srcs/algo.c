/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:44:39 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/11 11:40:56 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	algo1(t_stacks *s)
{
	int i;
	int x;

	i = s->a_top;
	if (is_ascending(s, 'a'))
		return ;
	while (s->a_top >= 1)
	{
		if (s->a_min_index < s->a_top / 2)
			x = 1;
		while (s->a_min_index != s->a_top)
		{
			if (x == 1)
			{
				rra(s);
				if (s->a_min_index == s->a_top)
					break;
			}
			else
			{
				ra(s);
				if (s->a_min_index == s->a_top)
					break;
			}
		}
		if (is_ascending(s, 'a'))
			break;
		pa(s);
	}
	while (s->a_top != i)
	{
		pb(s);
	}
}
