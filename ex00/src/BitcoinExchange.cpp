/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:53:06 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/12 07:41:04 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName)
{
    std::cout << "Bitcoin Exchange constructor" << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    std::cout << "Bitcoin Exchange copy" << std::endl;
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    std::cout << "Bitcoin Exchange copy assignment" << std::endl;
    if (this != &other)
        *this = other;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Bitcoin Exchange destructor" << std::endl;
}

std::string BitcoinExchange::getFileName(void)
{
    return (_fileName);
}

void        BitcoinExchange::setFileName(std::string fileName)
{
    _fileName = fileName;
}

const char* BitcoinExchange::dataError::what() const throw()
{
    return ("Error on opening the file data.csv");
}
const char* BitcoinExchange::badInput::what() const throw()
{
    return (_msg.c_str());
}
void        BitcoinExchange::badInput::setMessage(const std::string& msg)
{
    _msg = msg;
}

void        BitcoinExchange::run(void)
{
    dataBase();
    dataInput(_fileName);
    // for(std::map<std::string, float>::iterator it = _dataDate.begin(); it != _dataDate.end(); it++)
    // {
    //     std::cout << it->first << " -> " << it->second << std::endl;
    // }
    // for(std::map<std::string, float>::iterator it = _dataInput.begin(); it != _dataInput.end(); it++)
    // {
    //     std::cout << it->first << " -> " << it->second << std::endl;
    // }
}
bool        BitcoinExchange::checkDate(std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    std::string syear = date.substr(0, 4);
    std::string smonth = date.substr(5, 2);
    std::string sday = date.substr(8, 2);
    int year = atoi(syear.c_str());
    int month = atoi(smonth.c_str());
    int day = atoi(sday.c_str());
    if (year < 2009 || year > 2022)
        return (false);
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    
    return (true);
}

void        BitcoinExchange::dataInput(std::string fileName)
{
    (void)fileName;
    std::cout << "Input data" << std::endl;
    std::ifstream input;
    input.open(_fileName.c_str());
    if (!input)
        throw dataError();
    else
    {
        size_t sepa;
        std::string line;
        char *end;
        while(std::getline(input, line))
        {
            
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
            sepa = line.find("|");
            if (line == "date|value")
                continue ;
            if (sepa != std::string::npos)
            {
                std::string date = line.substr(0, sepa);
                std::cout << date << std::endl;
                if (!checkDate(date))
                {
                    badInput ex;
                    ex.setMessage("Error: bad input => " + date);
                    throw ex;
                }
                std::string values = line.substr(sepa + 1);
                std::cout << values << std::endl;
                float value = std::strtof(values.c_str(), &end);
                std::cout << value << std::endl;
                // _dataInput[date] = value;
                
            }
        }
    }
}

void        BitcoinExchange::dataBase()
{
    _dataBase.open("data.csv");
    if (!_dataBase)
        throw dataError();
    else
    {
        size_t sepa;
        std::string line;
        char* end;
        while(std::getline(_dataBase, line))
        {
            sepa = line.find(",");
            if (sepa != std::string::npos)
            {
                std::string date = line.substr(0, sepa);
                std::string values = line.substr(sepa + 1);
                float value = std::strtof(values.c_str(), &end);
                // std::cout << date << std::endl;
                _dataDate.insert(std::make_pair(date, value));
            }
        }
        // for(std::map<std::string, std::string>::iterator it = _dataDate.begin(); it != _dataDate.end(); it++)
        // {
        //     std::cout << it->first << " -> " << it->second << std::endl;
        // }
    }
}