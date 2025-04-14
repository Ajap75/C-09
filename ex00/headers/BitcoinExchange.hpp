/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:57:41 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/14 19:53:47 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <exception>

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

class BitcoinExchange
{
    public :
    
    BitcoinExchange(std::string &dbFileName, std::string &inputFileName);
    BitcoinExchange(BitcoinExchange &other);
    BitcoinExchange& operator =(BitcoinExchange &other);
    ~BitcoinExchange();
    
    //Publics Methodes
    void   PrintPortfolioDailyValue();
    
    
    //Nested Exception
    class ExceptionDbFormatError : public std::exception
    {
        public :
        const char* what() const throw() ;
    };

    class ExceptionDbFileError : public std::exception
    {
        public :
        const char* what() const throw() ;
    };
    
    class ExceptionInputGeneralFormatError : public std::exception
    {
        public :
        const char* what() const throw() ;
    };
    
    private :
    
    std::map <std::string, float>  db_map;
    std::vector<std::string> input_vector;

    void LoadDbInMap(std::ifstream &db_ifs);
    void LoadInputInVector(std::ifstream &input_ifs);
    bool lineParser(std::string &line , std::string &date, float &value);
    BitcoinExchange();
    //Debug/Test Methods
    void PrintDb(std::map<std::string, float>);    

}; 
#endif 