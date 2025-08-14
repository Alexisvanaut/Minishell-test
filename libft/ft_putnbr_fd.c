/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:13:05 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/16 14:32:11 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	n;
	char	to_print;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		(void)! write(fd, "-", 1);
	}
	if (n < 10)
	{
		to_print = n + '0';
		(void)! write(fd, &to_print, 1);
		return ;
	}
	to_print = n % 10 + '0';
	ft_putnbr_fd(n / 10, fd);
	(void)! write(fd, &to_print, 1);
}

/*
int	main(int argc, char **argv)
{
	int	to_print;

	if (argc != 2)
	{
		ft_putendl_fd("Please provide a single int as argument", 1);
		return (1);
	}
	to_print = ft_atoi(argv[1]);
	ft_putnbr_fd(to_print, 1);
	return (0);
}*/
