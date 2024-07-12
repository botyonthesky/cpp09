/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:52:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/12 07:27:16 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <algorithm>
#include <map>

class BitcoinExchange
{
    private:
    
        std::string                         _fileName;
        std::ifstream                       _dataBase;                     
        std::map<std::string, float>        _dataDate;
            
    public:
        
        BitcoinExchange(std::string fileName);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void            run(void);
        void            dataBase(void);
        void            dataInput(std::string fileName);
        bool            checkDate(std::string& date);
        
        std::string     getFileName(void);
        void            setFileName(std::string fileName);


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