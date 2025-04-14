/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:57:23 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/14 21:14:37 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"
#include "../headers/Parsing_Functions.hpp"
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

BitcoinExchange::BitcoinExchange(std::string &dbFileName, std::string &inputFileName)
{
    std::ifstream db_ifs(dbFileName.c_str());
    if (!db_ifs.is_open())
    {
        std::cout << "Error: CSV file not found" << std::endl;
        throw(BitcoinExchange::ExceptionDbFileError());
    }
    std::ifstream input_ifs(inputFileName.c_str());
    if (!input_ifs.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        throw(BitcoinExchange::ExceptionDbFileError());
    }
    LoadDbInMap(db_ifs);
    LoadInputInVector(input_ifs);
}


void BitcoinExchange::LoadDbInMap(std::ifstream &db_ifs)
{
    std::string line;
    size_t comma;
    std::string date;
    std::string btcRate;
    
    while (std::getline(db_ifs, line))
    {
        comma = line.find(',');
        if (comma == std::string::npos)
        throw(BitcoinExchange::ExceptionDbFormatError());
        date = line.substr(0, comma);
        btcRate = line.substr(comma + 1);
        db_map[date] = std::atof(btcRate.c_str()); 
    }
    // PrintDb(db);
    return ;
}

void BitcoinExchange::LoadInputInVector(std::ifstream &input_ifs)
{
    std::string line;
    for( ; getline(input_ifs, line) ;)
        input_vector.push_back(line);  
}

bool BitcoinExchange::lineParser(std::string &line , std::string &date, float &value_float)
{
    size_t pipe;
    std::string value;
    
    pipe = line.find("|");
    if (pipe == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return(true);
    }
    date = trim_space(line.substr(0, pipe));
    if (date_parser(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return(true);
    }
    value = trim_space(line.substr(pipe + 1));
    value_float = atof(value.c_str());
    if (value_parser(value_float))
        return (true);
    return (false);
}


void   BitcoinExchange::PrintPortfolioDailyValue()
{
    std::string date;
    float value_float;
    std::vector<std::string>::iterator it_input = input_vector.begin();
    
    it_input++; // pass the first line (title);
    for( ; it_input != input_vector.end() ; ++it_input)
    {
        if (!lineParser(*it_input, date, value_float))
        {
            if (db_map.find(date) == db_map.end())    
                std::cout << "Pas trouve" << date <<  " => " << value_float << " = " << db_map.lower_bound(date)->second * value_float << std::endl;
            else
                std::cout << "OK" << date <<  " => " << value_float << " = " << db_map.find(date)->second * value_float << std::endl;
        }
    }
        
}

void BitcoinExchange::PrintDb(std::map<std::string, float> db)
{
    std::map<std::string, float>::iterator it;
    it = db.begin();
    while (it != db.end())
    {
        if (it != db.begin())
        std::cout << "Date : " << it->first << " | Rate : " << it->second << "$" << std::endl;
        ++it;
    }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other) : db_map(other.db_map) {}

BitcoinExchange& BitcoinExchange::operator =(BitcoinExchange &other)
{
    if (this != &other)
    {
        db_map = other.db_map;
    }
    return (*this);
}





