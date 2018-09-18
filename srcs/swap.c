/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:15:00 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 09:59:25 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

void	sa(t_stacks *s)
{
	int tmp;

	if (s->a_top == -1)
		error();
	tmp = s->a[s->a_top];
	s->a[s->a_top] = s->a[s->a_top - 1];
	s->a[s->a_top - 1] = tmp;
	set_var(s);
}

void	sb(t_stacks *s)
{
	int tmp;

	if (s->b_top == -1)
		error();
	tmp = s->b[s->b_top];
	s->b[s->b_top] = s->b[s->b_top - 1];
	s->b[s->b_top - 1] = tmp;
	set_var(s);
}

void	ss(t_stacks *s)
{
	sb(s);
	sa(s);
}
