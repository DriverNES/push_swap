/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:01:41 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 09:52:09 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	set_a(t_stacks *s)
{
	int i;

	if (s->a_top != -1)
	{
		i = 0;
		s->a_max = s->a[0];
		s->a_min = s->a[0];
		while (i <= s->a_top)
		{
			if (s->a[i] >= s->a_max)
			{
				s->a_max = s->a[i];
				s->a_max_index = i;
			}
			if (s->a[i] <= s->a_min)
			{
				s->a_min = s->a[i];
				s->a_min_index = i;
			}
			i++;
		}
	}
}

void	set_b(t_stacks *s)
{
	int i;

	if (s->b_top != -1)
	{
		i = 0;
		s->b_max = s->b[0];
		s->b_min = s->b[0];
		while (i <= s->b_top)
		{
			if (s->b[i] >= s->b_max)
			{
				s->b_max = s->b[i];
				s->b_max_index = i;
			}
			if (s->b[i] <= s->b_min)
			{
				s->b_min = s->b[i];
				s->b_min_index = i;
			}
			i++;
		}
	}
}

void	set_var(t_stacks *s)
{
	set_a(s);
	set_b(s);
	if (check_dupes(s))
		error();
}
