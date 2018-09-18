/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:44:39 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 09:48:49 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	algo2(t_stacks *s)
{
	int i;

	i = 1;
	if (is_sorted(s))
		return ;
	while (s->a_top >= 3)
	{
		while (s->a_min < s->fract * i && s->a_top >= 3)
		{
			if (s->a[s->a_top] <= s->fract * i && s->a[s->a_top] < s->a_max - 2)
				pfunc(s, "pb");
			else
				pfunc(s, "ra");
		}
		if (s->a_min >= s->fract * i)
			i++;
	}
	sort_3a(s);
	algo3(s);
}

void	algo3(t_stacks *s)
{
	while (s->b_top != -1)
	{
		if (s->b_max == s->b[s->b_top])
			pfunc(s, "pa");
		else if (s->b_max_index < s->b_top / 2)
			pfunc(s, "rrb");
		else
			pfunc(s, "rb");
	}
}

void	sort_3a(t_stacks *s)
{
	if (s->a_top != 2)
		return ;
	else if (s->a[2] < s->a[0] && s->a[0] < s->a[1])
	{
		pfunc(s, "rra");
		pfunc(s, "sa");
	}
	else if (s->a[2] > s->a[1] && s->a[1] > s->a[0])
	{
		pfunc(s, "ra");
		pfunc(s, "sa");
	}
	else if (s->a[2] > s->a[1] && s->a[2] < s->a[0])
		pfunc(s, "sa");
	else if (s->a[2] > s->a[1] && s->a[2] > s->a[0])
		pfunc(s, "ra");
	else if (s->a[2] < s->a[1] && s->a[2] > s->a[0])
		pfunc(s, "rra");
}
