/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:29:27 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/22 17:35:09 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"
#include "../headers/Colors.hpp"

#include <string>
#include <cstdlib>
#include <iostream>

static int calculate_stack(char sign, std::stack<float> &_stack);
static float operation(char sign, float left_value, float right_value);



rpn::rpn(std::string input) : _input(input), _stack() {}

rpn::~rpn() {}

rpn::rpn(const rpn &other) : _input(other._input), _stack(other._stack){}

rpn& rpn::operator =(const rpn &other) 
{
    if (this  != &other)
    {
        _input = other._input;
        _stack = other._stack;
    }
    return (*this);
}


void rpn::run_calculation()
{
    for (size_t i = 0 ; i < _input.size() ; i += 2)
    {
        if (_input.find_first_of("0123456789", i) == i)
            _stack.push((_input[i]) - 48);
        else if (_input.find_first_of("*/+-", i) == i)
        {
            if (calculate_stack(_input[i], _stack))
                return ;
        }
    }
    if (_stack.size() == 1)
        std::cout << _stack.top() << std::endl;
    else
        std::cout << "Error" << std::endl;

}

static int calculate_stack(char sign, std::stack<float> &_stack)
{
    float left_value;
    float right_value;
    float result;
    if (_stack.size() < 2)
    {
        std::cerr << "Error :Not enough elements in the _stack -> at least 2 operands" << std::endl;
        return (1);
    }
    right_value = _stack.top();
    _stack.pop();
    left_value = _stack.top();
    _stack.pop();
    if (sign  == '/' && right_value == 0)
    {
        std::cerr << "Error :Devide by 0" << std::endl;
        return (1);
    }
    result = operation(sign,(left_value), (right_value));
    _stack.push(result);
    return (0);
}

static float operation(char sign, float left_value, float right_value)
{

   // DEBUG std::cout << sign << " | " << left_value << '|' << right_value << std::endl;
    if (sign == '-')
        return ((left_value) - (right_value));
    else if (sign == '+')
        return ((left_value) + (right_value));
    else if (sign == '/')
        return ((left_value) / (right_value));
    else
        return ((left_value) * (right_value));
}

// void   rpn::empty_and_print__stack()
// {
//     for ( ; !_stack.empty() ; )
//     {
//         std::cout << (_stack.top()) << std::endl;
//         _stack.pop();
//     }
// }


