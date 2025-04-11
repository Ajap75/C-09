/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:57:41 by anastruc          #+#    #+#             */
/*   Updated: 2025/04/11 18:35:45 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <exception>

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

class BitcoinExchange
{
    public :
    
    BitcoinExchange(std::string &dbFileName);
    BitcoinExchange(BitcoinExchange &other);
    BitcoinExchange& operator =(BitcoinExchange &other);
    ~BitcoinExchange();
    
    //Publics Methodes
    float   GetDailyPrice(std::string& date);
    
    
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
    //Exception 
    
    private :
    
    std::map <std::string, float>  db;
    void    LoadDbInContainer(std::istream  &db);
    BitcoinExchange();
    //Debug/Test Methods
    void PrintDb(std::map<std::string, float>);    

}; 
#endif 