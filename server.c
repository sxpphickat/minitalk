/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:40:09 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/25 14:34:12 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>

void sig_handler(int signum);
int	bin_to_dec(const char *bin);

int	main(void)
{
	int		pid;
//	struct	sigaction act;

	signal(SIGUSR1, *sig_handler);
	signal(SIGUSR2, *sig_handler);
	pid = getpid();
	ft_printf("pid: %i\n", pid);

	while (1)
		pause();
	return (0);
}

void sig_handler(int signum)
{
	static char	*byte;
	static int	i;

	if (i == 0)
	{
		byte = malloc(sizeof(char) * 9);
		byte[8] = '\0';
	}
	if (signum == SIGUSR1)
		byte[i++] = '1';
	else if (signum == SIGUSR2)
		byte[i++] = '0';
	if (i == 8)
	{
		ft_putchar_fd(bin_to_dec(byte), 1);
		free(byte);
		i = 0;
	}
	return ;
}

int	bin_to_dec(const char *bin)
{
	int	dec;
	int	i;
	int	rem;
	int	pow;

	pow = 1;
	rem = 0;
	dec = 0;
	i = 7;
	while (i >= 0)
	{
		rem = bin[i] - 48;
		dec = dec + rem * pow;
		pow = pow * 2;
		i--;
	}
	return (dec);
}
