/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:01:41 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/16 17:01:55 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include "../headers/PmergeMe.hpp"
#include "../headers/Colors.hpp"


static int input_parser(int argc, char **argv);
static void print_tab(char **argv);


int main (int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Sequence is too short" << std::endl;
        return (1);
    }
    if (input_parser(argc, argv))
        return (1);
    print_tab(argv);
    FordJ my_algo(argv);

    return (0);
}

static int input_parser(int argc, char **argv)
{
    for (int i = 1; i < argc ; i++)
    {
        if (atol(argv[i]) > UINT_MAX)
        {
            std::cout << "Overflow bitch" << std::endl;
            return (1);
        }
        if (atol(argv[i]) < 0)
        {
            std::cout << "Positive integer required" << std::endl;
            return (1);
        }
    }
    std::cout << "PARSING OK" << std::endl;
    return (0);
}

static void print_tab(char **argv)
{

    for (int i = 1; argv[i] ; i++)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl << BLUE << "ooooooooooooooooooo" << RESET << std::endl;
}
