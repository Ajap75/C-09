/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:29:27 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/16 13:06:48 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"
#include "../headers/Colors.hpp"

#include <string>
#include <cstdlib>
#include <iostream>

static void calculate_stack(char sign, std::stack<float> &stack);
static float operation(char sign, float left_value, float right_value);



rpn::rpn(std::string input) : _input(input){}

rpn::~rpn() {}

rpn::rpn(const rpn &other) : _input(other._input) {}

rpn& rpn::operator =(const rpn &other) 
{
    if (this  != &other)
    {
        _input = other._input;
    }
    return (*this);
}


void rpn::run_calculation()
{
    for (size_t i = 0 ; i < _input.size() ; i += 2)
    {
        if (_input.find_first_of("0123456789", i) == i)
            stack.push((_input[i]) - 48);
        else if (_input.find_first_of("*/+-", i) == i)
            calculate_stack(_input[i], stack);
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
        std::cout << "Error" << std::endl;

}

static void calculate_stack(char sign, std::stack<float> &stack)
{
    float left_value;
    float right_value;
    float result;
    if (stack.size() < 2)
        std::cerr << "Not enough elements in the stack -> at least 2 operands" << std::endl;

    right_value = stack.top();
    stack.pop();
    left_value = stack.top();
    stack.pop();
    result = operation(sign,(left_value), (right_value));
    stack.push(result);
}

static float operation(char sign, float left_value, float right_value)
{

   // DEBUG std::cout << sign << " | " << left_value << '|' << right_value << std::endl;
    if (sign == '-')
        return ((left_value) - (right_value));
    else if (sign == '+')
        return ((left_value) + (right_value));
    else if (sign == '/' && right_value != '0')
        return ((left_value) / (right_value));
    else
        return ((left_value) * (right_value));
}

// void   rpn::empty_and_print_stack()
// {
//     for ( ; !stack.empty() ; )
//     {
//         std::cout << (stack.top()) << std::endl;
//         stack.pop();
//     }
// }


