/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:00:39 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/15 12:20:32 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"
#include "../headers/Colors.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// Patrsing note : I decided that a month cannot exceed 12, a day is betweem 1 - 31 regardeless yhe month (february).
// No specification for the value of the year as soon as the format is correct XXXX(digit).
int main (int argc, char **argv)
{

    std::string dbPath;
    std::string inputPath;

    if (argc == 1)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    
    dbPath.assign("srcs/data.csv");
    inputPath.assign(argv[1]);
    
    try
    {
        BitcoinExchange bitcoinExchange(dbPath, inputPath);
        bitcoinExchange.PrintPortfolioDailyValue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}



