/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:03:14 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/01 17:48:05 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage_msg(void)
{
	ft_putendl("usage: ./fillit [input_file]");
	exit(1);
}

void	error_msg(void)
{
	ft_putendl("error");
	exit(1);
}
