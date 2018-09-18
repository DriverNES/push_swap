/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:14:14 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 09:59:40 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

void	rra(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s->a_top == -1)
		error();
	i = 0;
	tmp = s->a[0];
	while (i < s->a_top)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->a_top] = tmp;
	set_var(s);
}

void	rrb(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s->b_top == -1)
		error();
	i = 0;
	tmp = s->b[0];
	while (i < s->b_top)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->b_top] = tmp;
	set_var(s);
}

void	rrr(t_stacks *s)
{
	ra(s);
	rb(s);
}
