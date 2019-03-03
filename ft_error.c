/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 23:34:11 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/02 23:48:52 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	write(1, "usage: ./fillit <FILE>\n", 23);
	exit(0);
}

void	ft_open_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_byte_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_piece_num_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}
