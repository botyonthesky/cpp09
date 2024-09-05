/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:23:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/30 10:32:27 by tmaillar         ###   ########.fr       */
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
                
                void    checkInput(void);
                void    manageInput(std::string input);
                void    makeCalcul(std::string input);
                bool    checkToken(std::string token);
                bool    isOpe(std::string token);

                int     addition(int a, int b);
                int     soustraction(int a, int b);
                int     multiplication(int a, int b);
                int     division(int a, int b);

    public:
    
                RPN(std::string input);
                RPN(const RPN& other);
                RPN& operator=(const RPN& other);
                ~RPN();

                void    run(void);
                
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