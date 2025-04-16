/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:12 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/16 12:50:27 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>
#include "../headers/RPN.hpp"


static int input_parser(char *input);



int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    if (input_parser(argv[1]))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    rpn my_calculator(argv[1]);
    my_calculator.run_calculation();
} 






int input_parser(char *input)
{
    std::string input_string;
    
    input_string.assign(input);
    
    if(input_string.size() < 5)
        return (1);
    
    //Parse characters "*/-+0123456789"
    for(size_t i = 0; i < input_string.size() ; i += 2)
    {
        if (input_string.find_first_of("*/-+0123456789", i) != i)
            return (1);
    }
    
    //Parse spaces
    for(size_t i = 1; i < input_string.size() ; i += 2)
    {
        if (input_string.find_first_of(" ", i) != i)
            return (1);
    }
    return (0);
}

//./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
//42
//$> ./RPN "7 7 * 7 -"
//42
//$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
//0
//$> ./RPN "(1 + 1)"
//Error
