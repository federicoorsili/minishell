/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:20:43 by simonegiovo       #+#    #+#             */
/*   Updated: 2021/03/15 16:56:35 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_nflag(char *s)
{
    //printf("**1:%c **2:%c **3: %c\n",s[1], s[2], s[3]);
    if (s[0] == '-' && s[1] == 'n' && (s[2] == 0 || s[2] == ' '))
        return (1);
    return 0;
}

int echo_manager(t_h *h, char *cmd, char **argv)
{
    int nflag;
    int i;

    i = 1;
    nflag = 0;
	if (!argv[1])
        ft_printf("");
	else
    {
        while(argv[i] && is_nflag(argv[i]))
        {
            i++;
            nflag++;
        }
		while (argv[i])
        {
            if(i != 1)
                ft_printf(" ");
			ft_printf("%s",argv[i]);
            i++;
        }
    }
    if(!nflag)
        ft_printf("\n");
}