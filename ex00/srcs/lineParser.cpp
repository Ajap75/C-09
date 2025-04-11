/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineParser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:29:54 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/11 18:48:58 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

bool lineParser(std::string line)
{
    size_t pipe;
    std::string date;
    std::string value;
    
    pipe = line.find("|");
    if (pipe == std::string::npos)
    {
        std::cout << "Error: No '|'" << std::endl;
        return(false);
    }
    date = line.substr(0, pipe);
    value = line.substr(pipe);
    
}