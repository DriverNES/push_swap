/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:58:52 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/13 12:46:11 by ndriver          ###   ########.fr       */
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

void	sort_3b(t_stacks *s)
{
	if (s->b_top != 2)
		return ;
	else if (s->b[2] < s->b[0] && s->b[0] < s->b[1])
	{
		rrb(s);
		sb(s);
	}
	else if (s->b[2] > s->b[1] && s->b[1] > s->b[0])
	{
		rb(s);
		sb(s);
	}
	else if (s->b[2] > s->b[1] && s->b[2] < s->b[0])
		sb(s);
	else if (s->b[2] > s->b[1] && s->b[2] > s->b[0])
		rb(s);
	else if (s->b[2] < s->b[1] && s->b[2] > s->b[0])
		rrb(s);
}
