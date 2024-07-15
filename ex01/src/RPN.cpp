/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:05:14 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/15 16:51:53 by botyonthesk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN()
{
    std::cout << "RPN default constructor" <<std::endl;
}

RPN::RPN(std::string input) : _input(input)
{
    std::cout << "RPN cosntructor" << std::endl;
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
    std::cout << "RPN destructor" << std::endl;
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

void    RPN::checkInput(void)
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

void    RPN::run(void)
{
    try
    {
        manageInput(_input);
        checkInput();
        makeCalcul(_input);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
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