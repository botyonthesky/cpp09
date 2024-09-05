/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:53:06 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/30 09:35:00 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName)
{
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
    {
        this->_fileName = other._fileName;
        this->_dataDate = other._dataDate;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void        BitcoinExchange::run(void)
{
    try
    {
        dataBase();
        dataInput();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
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
            if (line == "date,exchange_rate")
                continue;
            sepa = line.find(",");
            if (sepa != std::string::npos)
            {
                std::string date = line.substr(0, sepa);
                std::string values = line.substr(sepa + 1);
                float value = std::strtof(values.c_str(), &end);
                date.erase(std::remove_if(date.begin(), date.end(), std::bind2nd(std::equal_to<char>(), '-')), date.end());
                int datei = atoi(date.c_str());
                _dataDate.insert(std::make_pair(datei, value));
            }
        }
        _dataBase.close();
    }
}

void        BitcoinExchange::dataInput()
{
    std::ifstream input;
    input.open(_fileName.c_str());
    if (!input)
        throw dataError();
    else
    {
        size_t sepa = 0;
        std::string line;
        handleInput(input, line, sepa);
    }
}

void        BitcoinExchange::handleInput(std::ifstream& input, std::string& line, size_t sepa)
{
    while(std::getline(input, line))
    {
        if (line == "date | value")
            continue ;
        try
        {
            if (!checkFormat(line))
            {
                badInput ex;
                ex.setMessage("Error: bad input => " + line);
                std::cout << "";
                throw ex;
            }
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
            sepa = line.find("|");
            if (sepa != std::string::npos)
            {
                std::string date = line.substr(0, sepa);
                if (!checkDate(date))
                {
                    badInput ex;
                    ex.setMessage("Error: bad input => " + date);
                    throw ex;
                }
                handleAndDisplay(line, date, sepa);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    input.close();
}

void        BitcoinExchange::handleAndDisplay(std::string& line, std::string& date, size_t sepa)
{
    std::string svalue = line.substr(sepa + 1, std::string::npos);
    char *end;
    float value = std::strtof(svalue.c_str(), &end);
    handleValue(value);
    displayResult(date, value);   
}
void        BitcoinExchange::handleValue(float value)
{
    if (checkValue(value) == 1)
    {
        badInput ex;
        ex.setMessage("Error : not a positive number.");
        throw ex;
    }
    if (checkValue(value) == 2)
    {
        badInput ex;
        ex.setMessage("Error : too large number.");
        throw ex;
    }
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
    if (!checkDataBase(year, month, day))
        return (false);
    if (!isFebValid(year, month, day))
        return (false);
    if (!isDayValid(month, day))
        return (false);
    return (true);
}

bool        BitcoinExchange::checkDataBase(int year, int month, int day)
{   
    if (month < 1 || month > 12)
        return (false);
    if (year == 2009 && month == 01 && day < 2)
        return (false);
    return (true);
}
bool        BitcoinExchange::isDayValid(int month, int day)
{
    if (month > 0 && month < 8)
    {
        if (month % 2 == 0 && (day < 1 || day > 30))
            return (false);
        else if (day < 1 || day > 31)
            return (false);
    }
    else if (month > 7 && month < 13)
    {
        if (month % 2 == 1 && (day < 1 || day > 30))
            return (false);
        else if (day < 1 || day > 31)
            return (false);
    }
    return (true);
}


bool        BitcoinExchange::isFebValid(int year, int month, int day)
{
    if (isLeap(year) && month == 2 && (day < 1 || day > 29))
        return (false);
    if (!isLeap(year) && month == 2 && (day < 1 || day > 28))
        return (false);
    return (true);
}

bool        BitcoinExchange::isLeap(int year)
{
    if (year % 4 == 0) 
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return (true);
            else 
                return (false);
        }
        else 
            return (true);
    }
    else 
        return (false);
}

int         BitcoinExchange::checkValue(float value)
{
    if (value > 1000)
        return (2);
    if (value < 0)
        return (1);
    return (0);
}

bool        BitcoinExchange::checkFormat(std::string str)
{
    if (str[4] != '-' || str[7] != '-')
        return (false);
    if (str[10] != ' ' || str[11] != '|' || str[12] != ' ')
        return (false);
    if (!isdigit(str[13]) && str[13] != '-' && str[13] != '+')
        return (false);
    if ((str[13] == '-' || str[13] == '+') && !isdigit(str[14]))
        return (false);
    return (true);
}


float       BitcoinExchange::findResult(std::string date, float value)
{
    float result = 0;
    date.erase(std::remove_if(date.begin(), date.end(), std::bind2nd(std::equal_to<char>(), '-')), date.end());
    int datei = atoi(date.c_str());
    for(std::map<int, float>::iterator it = _dataDate.begin(); it != _dataDate.end(); it++)
    {
        if (it->first == datei)
        {
            result = value * it->second;
            return (result);
        }
        else if (it->first > datei)
        {
            it--;
            result = value * it->second;
            return (result);
        }
    }
    std::map<int, float>::iterator it = _dataDate.end();
    it--;
    result = value * it->second;
    return (result);
}


void        BitcoinExchange::displayResult(std::string date, float value)
{
    float result = findResult(date, value);
    std::cout << date << " => " << value << " = " << result << std::endl;
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