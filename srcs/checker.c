/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:55:39 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/13 13:38:58 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int		main(int ac, char **av)
{
	t_stacks	s;
	char		**line;
	int			count;
	int		i;
	char		*temp;

	count = 0;
	line = malloc(10);
	*line = malloc(10);
//	ft_putendl(ft_itoa(ft_atoi(av[0])));
	if (ac == 2)
		init_one(&s, av[1]);
	else
	{
		i = ac - 1;
		ft_init(&s, i);
		while (count < s.size)
		{
			temp = ft_itoa(ft_atoi(av[i]));
			if (ft_strequ(av[i], temp))
			{
				s.a[count] = ft_atoi(av[i]);
				s.a_top++;
				count++;
				i--;
			}
			else
				error();
			free(temp);
		}
	}
	normalize(&s);
	if (check_dupes(&s))
		error();
	while (get_next_line(0, line) > 0)
		func(&s, *line);
	if (is_ascending(&s, 'a'))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	print_tab(&s, 'a');
	exit(0);
}
