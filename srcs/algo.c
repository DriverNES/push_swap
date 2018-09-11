/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 07:44:39 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/11 14:04:00 by ndriver          ###   ########.fr       */
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

void	algo2(t_stacks *s)
{
	int i;

	i = 1;
	if (is_ascending(s, 'a'))
		return ;
	while (s->a_top >= 3)
	{
		while (s->a_min < s->fract * i && s->a_top >= 3)
		{
			if (s->a[s->a_top] < s->fract * i)
				pa(s);
			else
				ra(s);
		}
		if (s->a_min >= s->fract * i)
		{
			i++;
	//		print_tab(s, 'b');
		}
	}
	sort_3a(s);
	algo3(s);
}

void	algo3(t_stacks *s)
{
	while (s->b_top != -1)
	{
		if (s->b_max == s->b[s->b_top])
			pb(s);
		else if (s->b_max_index < s->b_top / 2)
			rb(s);
		else
			rrb(s);
	}
}
