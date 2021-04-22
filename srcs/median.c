/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:41:18 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/22 23:30:44 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

/*
** check exit funct when malloc fail
*/

static int	calculate(t_list *lst, size_t posit, size_t size)
{
	int		*tab;
	int		median;
	size_t	i;

	tab = malloc(size * sizeof(int));
	if (!tab)
		exit(-1);
	i = 0;
	while (lst && i < size)
	{
		tab[i] = lst->numb;
		lst = lst->next;
		i++;
	}
	ft_sort_int_tab(tab, size);
	i = 0;
	while (i < posit)
		i++;
	median = tab[i];
	free(tab);
	return (median);
}

/*
** review this conditionals
*/

int	get_dynamic_median(t_list *lst, size_t init_size)
{
	size_t	current_size;
	size_t	posit;

	if (!lst)
		return (MIN_INT);
	current_size = ft_lstsize(lst);
	if (current_size < 0.30 * init_size)
		posit = 0.50 * current_size;
	else if (current_size < 0.50 * init_size)
		posit = 0.30 * current_size;
	else
		posit = 0.15 * current_size;
	return (calculate(lst, posit, current_size));
}

int	get_median(t_list *lst)
{
	size_t	current_size;

	if (!lst)
		return (MIN_INT);
	current_size = ft_lstsize(lst);
	return (calculate(lst, current_size / 2, current_size));
}
