/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:58:52 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 11:31:21 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	func(t_stacks *a, char *funct)
{
	if (!ft_strcmp(funct, "pa"))
		pa(a);
	else if (!ft_strcmp(funct, "pb"))
		pb(a);
	else if (!ft_strcmp(funct, "sa"))
		sa(a);
	else if (!ft_strcmp(funct, "sb"))
		sb(a);
	else if (!ft_strcmp(funct, "ss"))
		ss(a);
	else if (!ft_strcmp(funct, "ra"))
		ra(a);
	else if (!ft_strcmp(funct, "rb"))
		rb(a);
	else if (!ft_strcmp(funct, "rr"))
		rr(a);
	else if (!ft_strcmp(funct, "rra"))
		rra(a);
	else if (!ft_strcmp(funct, "rrb"))
		rrb(a);
	else if (!ft_strcmp(funct, "rrr"))
		rrr(a);
	else
		error();
}

void	pfunc(t_stacks *s, char *funct)
{
	func(s, funct);
	ft_putendl(funct);
}

void	pb(t_stacks *s)
{
	if (s->a_top == -1)
		error();
	s->b_top++;
	s->b[s->b_top] = s->a[s->a_top];
	s->a[s->a_top] = 0;
	s->a_top--;
	set_var(s);
}

void	pa(t_stacks *s)
{
	if (s->b_top == -1)
		error();
	s->a_top++;
	s->a[s->a_top] = s->b[s->b_top];
	s->b[s->b_top] = 0;
	s->b_top--;
	set_var(s);
}

void	print_tab(t_stacks *s, char c)
{
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
		ft_putendl(str);
		size--;
	}
	free(str);
	free(tab);
}
