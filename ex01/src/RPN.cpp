/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:22:52 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/19 08:27:46 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string input) : _input(input)
{
}

RPN::RPN(const RPN& other) :  _input(other._input), _stack(other._stack)
{
    std::cout << "RPN copy" << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
    std::cout << "RPN copy assignment" << std::endl;
    if (this != &other)
    {
        _input = other._input;
        _stack = other._stack;
    }
    return (*this);
}

RPN::~RPN()
{
}

void    RPN::manageInput(std::string input)
{
    std::stack<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' '))
    {
        tokens.push(token);
    }
    _stack = tokens;
}

void    RPN::checkInput()
{
    std::stack<std::string> tmp;
    tmp = _stack;
    int num = 0;
    int ope = 0;
    while (!tmp.empty())
    {
        if (!checkToken(tmp.top()))
            throw WrongInput();
        if (isdigit(tmp.top()[0]))
            num++;
        if (isOpe(tmp.top()))
            ope++;
        tmp.pop();
    }
    if (ope + 1 < num)
        throw NotEnoughOpe();
    if (ope + 1 > num)
        throw TooManyOpe();
}


bool            RPN::isOpe(std::string token)
{
    if (token == "-" || token == "+" || token == "/" || token == "*")
        return (true);
    return (false);
}

bool            RPN::checkToken(std::string token)
{
    if (token.size() > 1)
        return (false);
    if (!isdigit(token[0]))
    {
        if (token[0] != '+' && token[0] != '-' && token[0] != '/' && token[0] != '*')
            return (false);
    }
    return(true);
}

int     RPN::addition(int a, int b)
{
    return (a + b);
}

int     RPN::soustraction(int a, int b)
{
    return (a - b);
}

int     RPN::multiplication(int a, int b)
{
    return (a * b);
}

int     RPN::division(int a, int b)
{
    if (b == 0)
        throw DivisionByZero();
    return (a / b);
}


void    RPN::makeCalcul(std::string input)
{
    std::stack<int> numStack;
    std::istringstream iss(input);
    std::string token;
    while (iss >> token)
    {
        if (isOpe(token))
        {
            if (numStack.size() < 2)
                throw NotEnoughOpe();
            int b = numStack.top();
            numStack.pop();    
            int a = numStack.top();
            numStack.pop();
            if (token == "+")
                numStack.push(addition(a, b));
            else if (token == "-")
                numStack.push(soustraction(a, b));
            else if (token == "/")
                numStack.push(division(a, b));
            else if (token == "*")
                numStack.push(multiplication(a, b));
        }
        else
            numStack.push(std::atoi(token.c_str()));
    }    
    std::cout << numStack.top() << std::endl;   
}

void    RPN::run()
{
    try
    {
        manageInput(_input);
        checkInput();
        makeCalcul(_input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }   
}

const char*     RPN::WrongInput::what() const throw()
{
    return ("Error : Not valid input");
}

const char*     RPN::NotEnoughOpe::what() const throw()
{
    return ("Error : There is not enough operand");
}

const char*     RPN::TooManyOpe::what() const throw()
{
    return ("Error : There is too many operand");
}

const char*     RPN::DivisionByZero::what() const throw()
{
    return ("Error : Divison by zero is impossible !");
}