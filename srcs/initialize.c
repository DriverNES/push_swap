/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:51:37 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 09:57:52 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_init(t_stacks *s, int size)
{
	int i;

	i = 0;
	s->a_top = -1;
	s->b_top = -1;
	s->size = size;
	set_var(s);
	if (size < 200)
		s->fract = size / 5;
	else
		s->fract = size / 10;
	if (s->fract == 0)
		s->fract = 1;
	s->a = (int *)malloc(sizeof(int) * size + 4);
	s->b = (int *)malloc(sizeof(int) * size + 4);
	while (i <= size)
	{
		s->a[i] = 0;
		s->b[i] = 0;
		i++;
	}
}

void	init_one(t_stacks *s, char *str)
{
	int		i;
	int		count;
	char	**out;
	char	*temp;

	count = 0;
	out = ft_strsplit(str, ' ');
	i = ft_cntwrd(str, ' ');
	ft_init(s, i);
	s->size = i;
	if (s->size < 200)
		s->fract = i / 5;
	else
		s->fract = i / 10;
	if (s->fract == 0)
		s->fract = 1;
	while (count < s->size)
	{
		temp = ft_itoa(ft_atoi(out[i - 1]));
		set_one(s, temp, out[i - 1], count);
		i--;
		count++;
		free(temp);
	}
	free(out);
}

void	set_one(t_stacks *s, char *str, char *comp, int i)
{
	if (ft_strequ(comp, str))
	{
		s->a[i] = ft_atoi(comp);
		s->a_top++;
	}
	else
		error();
}

void	normalize(t_stacks *s)
{
	int i;
	int j;
	int *tmp;
	int size;

	size = s->a_top + 1;
	tmp = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		tmp[i] = s->a[i];
		s->a[i] = size;
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (tmp[i] < tmp[j])
				s->a[i]--;
	}
	free(tmp);
	set_var(s);
}

void	error(void)
{
	ft_putendl("Error");
	exit(0);
}
