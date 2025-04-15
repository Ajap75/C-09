/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:29:27 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/15 19:01:36 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"
#include "../headers/Colors.hpp"

#include <string>
#include <cstdlib>
#include <iostream>

static void calculate_stack(char sign, std::stack<char> &stack);
static int operation(char sign, char left_value, char right_value);



rpn::rpn(std::string input)
{
    (void) input;
    // for (size_t i = 0 ; i < input.size() ; i += 2)
    // {
    //     stack.push(input[i]);
    // }
    // empty_and_print_stack();
}

// rpn::~rpn() {}

// rpn::rpn(const rpn &other) {}
// rpn& rpn::operator =(const rpn &other) {}


void rpn::run_calculation(std::string input)
{
    for (size_t i = 0 ; i < input.size() ; i += 2)
    {
        if (input.find_first_of("0123456789", i) == i)
            stack.push(input[i]);
        else if (input.find_first_of("*/+-", i) == i)
            calculate_stack(input[i], stack);
    }
    std::cout << static_cast<int>(stack.top()) << std::endl;
}

static void calculate_stack(char sign, std::stack<char> &stack)
{
    char left_value;
    char right_value;
    int result;
    if (stack.size() < 2)
        std::cout << "Not enough elements in the stack -> at least 2 operands" << std::endl;

    for ( ; stack.size() != 1 ; )
    {
        right_value = stack.top();
        stack.pop();
        left_value = stack.top();
        stack.pop();
        // std::cout << left_value <<  " "  << sign << " " << right_value << " = " << operation(sign, left_value, right_value);
        // std::cout << (static_cast<int>(operation(sign, left_value, right_value))) << std::endl;
        result = operation(sign,(left_value), (right_value));
        std::cout << RED << result << RESET << std::endl;
        stack.push(result);
        // std::cout << RED <<(stack.top()) << RESET << std::endl;
    }
}

static int operation(char sign, char left_value, char right_value)
{
    int lv = left_value - 48;
    int rv = right_value - 48;
    
    std::cout << sign << lv << '|' << rv << std::endl;
    if (sign == '-')
        return ((lv) - (rv));
    else if (sign == '+')
        return ((lv) + (rv));
    else if (sign == '/' && rv != '0')
        return ((lv) / (rv));
    else
        return ((lv) * (rv));
}

void   rpn::empty_and_print_stack()
{
    for ( ; !stack.empty() ; )
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}
