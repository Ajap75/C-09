/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineParser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:29:54 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/14 16:44:28 by anastruc         ###   ########.fr       */
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
        std::cout << "Error: bad input => No '|'" << std::endl;
        return(true);
    }
    date = line.substr(0, pipe);
    if (date_parser(date));
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return(true);
    }
    value = line.substr(pipe);
    if (value_parser(value))
        return (true);
    return (false);
}

int date_parser(std::string date)
{
    std::string year;
    std::string month;
    std::string day;

    if (date.size() != 10 || date[4] != '-' || date[7] != '7')
        return (1);

    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    
    if (!is_number(year) || !is_number(month) || !is_number(day))
        return (1);
        
    std::cout << year << '-' << month << '-' << day << std::endl;
    int year_int = atoi(year.c_str());
    int month_int = atoi(month.c_str());
    int day_int = atoi(day.c_str());
    
    if (!is_in_range(month_int, day_int))
        return (1);
    return (0);
}

bool is_number(std::string elem)
{
    for (int i = 0; i < elem.size() ; i++)
        if (!isdigit(elem[i]))
            return (false);
    return(true);
}

bool is_in_range(int month, int day)
{
    if (month < 1 || month > 12)
        return (false);
    else if (day < 1 || day > 31)
        return (false);
    else 
        return (true);
}

bool value_parser(std::string value)
{
    float value_float = atof(value.c_str());
    if (value_float < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return(true);
    }
    if (value_float > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return(true);
    }
}