/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:05:17 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/15 16:42:41 by botyonthesk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <algorithm>


class RPN
{
    private:
        
                std::string                 _input;
                std::stack<std::string>     _stack;  
                RPN();

    public:
    
                RPN(std::string input);
                RPN(const RPN& other);
                RPN& operator=(const RPN& other);
                ~RPN();

                void    run(void);
                void    manageInput(std::string input);
                bool    checkToken(std::string token);
                void    checkInput(void);
                bool    isOpe(std::string token);
                void    makeCalcul(std::string input);
                int     addition(int a, int b);
                int     soustraction(int a, int b);
                int     multiplication(int a, int b);
                int     division(int a, int b);

                
                class WrongInput : public std::exception
                {
                        virtual const char* what() const throw();             
                };

                class TooManyOpe : public std::exception
                {
                        virtual const char* what() const throw();             
                };

                class NotEnoughOpe : public std::exception
                {
                        virtual const char* what() const throw();                   
                };

                class DivisionByZero : public std::exception
                {
                        virtual const char* what() const throw();
                };
};

#endif