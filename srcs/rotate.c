/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:13:43 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 09:59:15 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ra(t_stacks *s)
{
	int tmp;
	int i;

	if (s->a_top == -1)
		error();
	i = 0;
	tmp = s->a[s->a_top];
	while (i < s->a_top)
	{
		s->a[s->a_top - i] = s->a[s->a_top - i - 1];
		i++;
	}
	s->a[0] = tmp;
	set_var(s);
}

void	rb(t_stacks *s)
{
	int tmp;
	int i;

	if (s->b_top == -1)
		error();
	i = 0;
	tmp = s->b[s->b_top];
	while (i < s->b_top)
	{
		s->b[s->b_top - i] = s->b[s->b_top - i - 1];
		i++;
	}
	s->b[0] = tmp;
	set_var(s);
}

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
}
