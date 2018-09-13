/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:44:19 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/13 13:35:55 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

void	ft_init(t_stacks *s, int size)
{
	int i;

	i = 0;
	s->a_top = -1;
	s->b_top = -1;
	s->size = size;
	if (size < 200)
		s->fract = size / 5;
	else
		s->fract = size / 10;
	s->a = (int *)malloc(sizeof(int) * size);
	s->b = (int *)malloc(sizeof(int) * size);
	while (i <= size)
	{
		s->a[i] = 0;
		s->b[i] = 0;
		i++;
	}
}

void	init_one(t_stacks *s, char *str)
{
	int i;
	int count;
	char **out;

	count = 0;
	out = ft_strsplit(str, ' ');
	i = ft_cntwrd(str, ' ');
	ft_init(s, i);
	while (count < i)
	{
		s->a[count] = ft_atoi(out[count]);
		s->a_top++;
		count++;
	}
	s->size = i;
	if (s->size < 200)
		s->fract = i / 5;
	else
		s->fract = i / 10;
	free(out);
}

void	error(void)
{
	ft_putendl("Error");
	exit(0);
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

void	set_var(t_stacks *s)
{
	set_min(s);
	set_max(s);
	if (check_dupes(s))
		error();
}

void	set_max(t_stacks *s)
{
	int i;

	if (s->a_top != -1)
	{
		i = 0;
		s->a_max = s->a[0];
		while (i <= s->a_top)
		{
			if (s->a[i] >= s->a_max)
			{
				s->a_max = s->a[i];
				s->a_max_index = i;
			}
			i++;
		}
	}
	if (s->b_top != -1)
	{
		i = 0;
		s->b_max = s->b[0];
		while (i <= s->b_top)
		{
			if (s->b[i] >= s->b_max)
			{
				s->b_max = s->b[i];
				s->b_max_index = i;
			}
			i++;
		}
	}
}

void	set_min(t_stacks *s)
{
	int i;

	if (s->a_top != -1)
	{
		i = 0;
		s->a_min = s->a[0];
		while (i <= s->a_top)
		{
			if (s->a[i] <= s->a_min)
			{
				s->a_min = s->a[i];
				s->a_min_index = i;
			}
			i++;
		}
	}
	if (s->b_top != -1)
	{
		i = 0;
		s->b_min = s->b[0];
		while (i <= s->b_top)
		{
			if (s->b[i] <= s->b_min)
			{
				s->b_min = s->b[i];
				s->b_min_index = i;
			}
			i++;
		}
	}
}

int		is_ascending(t_stacks *s, char c)
{
	int i;
	int j;

	i = 0;
	if (c == 'a')
	{
		while (i <= s->a_top)
		{
			j = i;
			while (j <= s->a_top)
			{
				if (s->a[i] < s->a[j])
				{
					return (0);
				}
				j++;
			}
			i++;
		}
	}
	if (c == 'b')
	{
		while (i <= s->b_top)
		{
			j = i;
			while (j <= s->b_top)
			{
				if (s->b[i] < s->b[j])
				{
					return (0);
				}
				j++;
			}
			i++;
		}
	}

	return (1);
}

int		is_descending(t_stacks *s, char c)
{
	int i;
	int j;

	i = s->a_top;
	if (c == 'a')
	{
		while (i >= 0)
		{
			j = i;
			while (j >= 0)
			{
				if (s->a[i] > s->a[j])
				{
					return (0);
				}
				j++;
			}
			i++;
		}
	}
	if (c == 'b')
	{
		while (i >= 0)
		{
			j = i;
			while (j >= 0)
			{
				if (s->b[i] > s->b[j])
				{
					return (0);
				}
				j++;
			}
			i++;
		}
	}
	return (1);
}

int		check_dupes(t_stacks *s)
{
	int i;
	int j;

	i = 0;
	while (i <= s->a_top)
	{
		j = i;
		j++;
		while (j <= s->a_top)
		{
			if (s->a[j] == s->a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_tab(t_stacks *s, char c)
{
	int		len;
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
		len = ft_strlen(str);
		write(1, str, len);
		ft_putchar('\n');
		size--;
	}
}
