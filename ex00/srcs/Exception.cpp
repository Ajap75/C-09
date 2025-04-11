/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:50:36 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/11 18:36:15 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"



const char* BitcoinExchange::ExceptionDbFormatError::what() const throw() 
{
    return ("Coma missing or");
}

const char* BitcoinExchange::ExceptionDbFileError::what() const throw() 
{
   return ("Error: CSV file not found");
}

const char* BitcoinExchange::ExceptionInputGeneralFormatError::what() const throw() 
{
   return ("Error: General Input Format");
}
