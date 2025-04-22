/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:01:41 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/22 16:54:29 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include "../headers/PmergeMe.hpp"
#include "../headers/Colors.hpp"


static int input_parser(int argc, char **argv);
// static void print_tab(char **argv);


int main (int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Sequence is too short" << std::endl;
        return (1);
    }
    if (input_parser(argc, argv))
        return (1);
    
    FordJ my_algo(argv);
    my_algo.sort_using_list();
    my_algo.sort_using_deque();
    

    my_algo.print_algo_results();
    return (0);
    // List is faster in this situation, become during the process, the insert part, o(n) move all the following element in a deque, 
    // whereas in a list, just a couple pointers are modified.
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
    return (0);
}

// static void print_tab(char **argv)
// {

//     for (int i = 1; argv[i] ; i++)
//     {
//         std::cout << argv[i] << " ";
//     }
//     std::cout << std::endl << BLUE << "ooooooooooooooooooo" << RESET << std::endl;
// }

