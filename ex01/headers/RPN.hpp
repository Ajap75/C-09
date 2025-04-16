/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:29:24 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/16 12:33:33 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>

#ifndef RPN_HPP
#define RPN_HPP

class rpn
{
    public :
    
    
    rpn(std::string input);
    void run_calculation();
    ~rpn();
    rpn(const rpn &other);
    rpn& operator =(const rpn &other);
    
    private :
    
    std::string _input;
    std::stack<float> stack;
    rpn();
    void    empty_and_print_stack();
};
#endif 