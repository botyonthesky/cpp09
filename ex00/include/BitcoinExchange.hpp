/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:52:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/30 09:40:25 by tmaillar         ###   ########.fr       */
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
    
                std::map<int, float>                _dataDate;
                std::ifstream                       _dataBase;
                std::string                         _fileName;
                
                BitcoinExchange();
                
                void            dataBase(void);
                void            dataInput(void);
                void            handleInput(std::ifstream& input, std::string& line, size_t sepa);
                void            handleAndDisplay(std::string& line, std::string& date, size_t sepa);
                void            handleValue(float value);
                
                bool            isLeap(int year);
                bool            isFebValid(int year, int month, int day);
                bool            isDayValid(int month, int day);                
                
                bool            checkFormat(std::string str);
                bool            checkDate(std::string& date);
                bool            checkDataBase(int year, int month, int day);
                int             checkValue(float value);
                
                float           findResult(std::string date, float value);
                void            displayResult(std::string date, float value);
                
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