/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:57:23 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/14 15:43:37 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

BitcoinExchange::BitcoinExchange(std::string &dbFileName)
{
    std::ifstream db(dbFileName.c_str());
    if (!db.is_open())
    {
        std::cout << "Error: CSV file not found" << std::endl;
        throw(BitcoinExchange::ExceptionDbFileError());
    }
    LoadDbInContainer(db);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other) : db(other.db) {}
BitcoinExchange& BitcoinExchange::operator =(BitcoinExchange &other)
{
    if (this != &other)
    {
        db = other.db;
    }
    return (*this);
}

void BitcoinExchange::LoadDbInContainer(std::istream &dbFile)
{
    std::string line;
    size_t comma;
    std::string date;
    std::string btcRate;

    while (std::getline(dbFile, line))
    {
        comma = line.find(',');
        if (comma == std::string::npos)
            throw(BitcoinExchange::ExceptionDbFormatError());
        date = line.substr(0, comma);
        btcRate = line.substr(comma + 1);
        db[date] = std::atof(btcRate.c_str()); 
    }
    PrintDb(db);
    return ;
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






