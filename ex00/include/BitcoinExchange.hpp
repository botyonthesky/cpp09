/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:52:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/19 07:37:27 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>

class BitcoinExchange
{
    private:
    
        std::string                         _fileName;
        std::ifstream                       _dataBase;                     
        std::map<int, float>                _dataDate;
        
        BitcoinExchange();
        
        void            dataBase(void);
        void            dataInput(void);
        bool            checkDate(std::string& date);
        bool            isLeap(int year);
        bool            isFebValid(int year, int month, int day);
        bool            isDayValid(int month, int day);
        int             checkValue(float value);
        bool            checkFormat(std::string str);
        bool            checkDataBase(int year, int month, int day);
        void            displayResult(std::string date, float value);
        float           findResult(std::string date, float value);
        std::string     getFileName(void);
        void            setFileName(std::string fileName);
            
    public:
        
        BitcoinExchange(std::string fileName);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void            run(void);

        class dataError : public std::exception
        {
            virtual const char* what() const throw();
        };

        class badInput : public std::exception
        {
            public:
                
                badInput() {}
                virtual ~badInput() throw() {}
                void    setMessage(const std::string& msg);
                virtual const char* what() const throw();
            
            private:
                std::string _msg;
        };
};

#endif