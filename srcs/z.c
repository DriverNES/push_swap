/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:58:52 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/11 11:40:58 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void	pa(t_stacks *s)
{
	if (s->a[0] == 0)
		return ;
	s->b_top++;
	s->b[s->b_top] = s->a[s->a_top];
	s->a[s->a_top] = 0;
	s->a_top--;
	set_var(s);
	ft_putendl("pa");
}

void	pb(t_stacks *s)
{
	if (s->b[0] == 0)
		return ;
	s->a_top++;
	s->a[s->a_top] = s->b[s->b_top];
	s->b[s->b_top] = 0;
	s->b_top--;
	set_var(s);
	ft_putendl("pb");
}

void	sa(t_stacks *s)
{
	int tmp;

	if (s->a[0] == 0)
		return ;
	tmp = s->a[s->a_top];
	s->a[s->a_top] = s->a[s->a_top - 1];
	s->a[s->a_top - 1] = tmp;
	set_var(s);
	ft_putendl("sa");
}

void	sb(t_stacks *s)
{
	int tmp;

	if (s->b[0] == 0)
		return ;
	tmp = s->b[s->b_top];
	s->b[s->b_top] = s->b[s->b_top - 1];
	s->b[s->b_top - 1] = tmp;
	set_var(s);
	ft_putendl("sb");
}

void	ss(t_stacks *s)
{
	sb(s);
	sa(s);
	ft_putendl("ss");
}

void	ra(t_stacks *s)
{
	int tmp;
	int i;

	if (s->a[0] == 0)
		return ;
	i = 0;
	tmp = s->a[s->a_top];
	while (i < s->a_top)
	{
		s->a[s->a_top - i] = s->a[s->a_top - i - 1];
		i++;
	}
	s->a[0] = tmp;
	set_var(s);
	ft_putendl("ra");
}

void	rb(t_stacks *s)
{
	int tmp;
	int i;

	if (s->b[0] == 0)
		return ;
	i = 0;
	tmp = s->b[s->b_top];
	while (i < s->b_top)
	{
		s->b[s->b_top - i] = s->b[s->b_top - i - 1];
		i++;
	}
	s->b[0] = tmp;
	set_var(s);
	ft_putendl("rb");
}

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
	ft_putendl("rr");
}

void	rra(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s->a[0] == 0)
		return ;
	i = 0;
	tmp = s->a[0];
	while (i < s->a_top)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[s->a_top] = tmp;
	set_var(s);
	ft_putendl("rra");
}

void	rrb(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s->b[0] == 0)
		return ;
	i = 0;
	tmp = s->b[0];
	while (i < s->b_top)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[s->b_top] = tmp;
	set_var(s);
	ft_putendl("rrb");
}

void	rrr(t_stacks *s)
{
	ra(s);
	rb(s);
	ft_putendl("rrr");
}

void	sort_3a(t_stacks *s)
{
	if (s->a_top != 2)
		return ;
	else if (s->a[2] < s->a[0] && s->a[0] < s->a[1])
	{
		rra(s);
		sa(s);
	}
	else if (s->a[2] > s->a[1] && s->a[1] > s->a[0])
	{
		ra(s);
		sa(s);
	}
	else if (s->a[2] > s->a[1] && s->a[2] < s->a[0])
		sa(s);
	else if (s->a[2] > s->a[1] && s->a[2] > s->a[0])
		ra(s);
	else if (s->a[2] < s->a[1] && s->a[2] > s->a[0])
		rra(s);
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

int		main(int ac, char **av)
{
	int			i;
	int			count;
	t_stacks	*s;

	i = 0;
	count = 0;
	s = (t_stacks *)malloc(sizeof(t_stacks));
	if (ac == 2)
		init_one(s, av[1]);
	else
	{
		i = ac - 1;
		ft_init(s, i);
		while (count < i)
		{
			s->a[count] = ft_atoi(av[count + 1]);
			s->a_top++;
			count++;
		}
	}
	normalize(s);
	set_var(s);
//	print_tab(s, 'a');
	algo1(s);
//	print_tab(s, 'a');
	return (0);
}
