/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:05:14 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/15 12:05:42 by botyonthesk      ###   ########.fr       */
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

RPN::RPN(const RPN& other)
{
    std::cout << "RPN copy" << std::endl;
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    std::cout << "RPN copy assignment" << std::endl;
    if (this != &other)
        *this = other;
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


void        RPN::printStack(void)
{
    std::stack<std::string> tmp;
    tmp = _stack;
    while (!tmp.empty())
    {
        std::cout << tmp.top() << " ";
        tmp.pop();
    }
    std::cout << std::endl;
}

void    RPN::checkInput(void)
{
    
    std::stack<std::string> tmp;
    tmp = _stack;
    while (!tmp.empty())
    {
        std::string token;
        token = tmp.top();
        if (token.size() > 1)
            throw WrongInput();
        if (!checkToken(token))
            throw WrongInput();
        tmp.pop();
}
}

bool            RPN::checkToken(std::string token)
{
    if (!isdigit(token[0]))
    {
        if (token[0] != '+' || token[0] != '-' || token[0] != '/' || token[0] != '*')
            return (false);
    }
    return(true);
}

const char*     RPN::WrongInput::what() const throw()
{
    return ("Error");
}
// void    RPN::checkOperand(std::string calcul)
// {
//     (void)calcul;
// }

void    RPN::run(void)
{
    try
    {
        manageInput(_input);
        printStack();
        checkInput();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
}