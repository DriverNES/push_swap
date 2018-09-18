/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndriver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:33:38 by ndriver           #+#    #+#             */
/*   Updated: 2018/09/18 11:36:32 by ndriver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			*masterstack;
	int			size;
	int			fract;
	int			a_top;
	int			b_top;
	int			a_max;
	int			b_max;
	int			a_min;
	int			b_min;
	int			a_max_index;
	int			b_max_index;
	int			a_min_index;
	int			b_min_index;

}				t_stacks;

void			ft_init(t_stacks *s, int size);
void			error(void);
void			normalize(t_stacks *s);
int				is_sorted(t_stacks *s);
void			print_tab(t_stacks *s, char c);
void			init_one(t_stacks *s, char *str);
void			set_a(t_stacks *s);
void			set_b(t_stacks *s);
void			set_var(t_stacks *s);
void			algo1(t_stacks *s);
void			pa(t_stacks *s);
void			pb(t_stacks *s);
void			ra(t_stacks *s);
void			rb(t_stacks *s);
void			rra(t_stacks *s);
void			rrb(t_stacks *s);
void			rr(t_stacks *s);
void			rrr(t_stacks *s);
void			sa(t_stacks *s);
void			sb(t_stacks *s);
void			ss(t_stacks *s);
void			func(t_stacks *a, char *funct);
void			pfunc(t_stacks *a, char *funct);
int				check_dupes(t_stacks *s);
void			algo2(t_stacks *s);
void			sort_3a(t_stacks *s);
void			algo3(t_stacks *s);
void			set_one(t_stacks *s, char *str, char *comp, int i);
void			checker(t_stacks *s);

#endif
