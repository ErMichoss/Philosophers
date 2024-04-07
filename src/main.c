/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:43:03 by nicgonza          #+#    #+#             */
/*   Updated: 2024/04/01 13:47:24 by nicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void    ft_check_must_eat(int argc, t_rules *rules)
{
    if (argc == 5)
        rules->must_eat = 0;
    else
        rules->must_eat = 1;
}

void    ft_checkargs(int argc, char **argv)
{
    int i;

    if (argc == 1)
        ft_error_msg("Invalid number of arguments");
    else if (argc < 5 || argc > 6)
        ft_error_msg("Invalid number of arguments");
    i = 1;
    while (argv[i] != NULL)
    {
        if (ft_isnum(argv[i]) == 1)
            ft_error_msg("Invalid type of arguments");
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_rules rules;

    ft_checkargs(argc, argv);
    ft_check_must_eat(argc, &rules);
    ft_set_parameters(argv, &rules); // it set the parameters of the rules struct
    ft_init(&rules); // it set the parameters of the philo struct;

    return (0);
}
