/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:00:39 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/14 15:48:41 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"
#include "../headers/Colors.hpp"
#include "../headers/Functions.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main (int argc, char **argv)
{
    std::string dbPath;
    std::string line;

    dbPath = "srcs/data.csv";
    
    if (argc == 1)
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }
    
    BitcoinExchange bitcoinExchange(dbPath);
    
    std::ifstream InputFile(argv[1]);
    if (!InputFile.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }
    for( ; getline(InputFile, line) ; )
    {
        if (!lineParser(line));
            continue;
        bitcoinExchange.GetDailyPrice(line);
    }
    return (0);
}



