/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:13:15 by siferrar          #+#    #+#             */
/*   Updated: 2020/08/22 18:00:29 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	init_keys(t_brain *b)
{
	int i;

	i = 0;
	b->keys = ft_calloc(10, sizeof(int));
	while (i < 10)
		b->keys[i++] = -1;
}

int		is_key_pressed(t_brain *b, int key)
{
	int i;

	i = 0;
	while (i < 10 && key != -1)
	{
		if (b->keys[i] == key)
			return (i);
		i++;
	}
	return (-1);
}

int		add_key_pressed(t_brain *b, int key)
{
	int i;

	i = 0;
	while (b->keys[i] != -1 && i < 10)
		i++;
	if (i < 10)
	{
		b->keys[i] = key;
		return (1);
	}
	return (0);
}

int		del_key_pressed(t_brain *b, int key)
{
	int i;

	i = 0;
	if (b->keys == NULL || key == -1)
		return (1);
	while (b->keys[i] != key && i < 6)
		i++;
	if (i < 6 && b->keys[i] == key)
	{
		b->keys[i] = -1;
		return (1);
	}
	return (0);
}
