/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Functions.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:30:52 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/14 20:01:27 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef PARSING_FUNCTIONS_HPP
#define PARSING_FUNCTIONS_HPP

bool lineParser(std::string line);
bool is_number(std::string elem);
bool is_in_range(int month, int day);
int date_parser(std::string date);
bool value_parser(float value_float);
std::string    trim_space(std::string string);

#endif




