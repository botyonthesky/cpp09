/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:05:17 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/15 11:54:08 by botyonthesk      ###   ########.fr       */
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
                void    printStack(void);
                bool    checkToken(std::string token);
                void    checkInput(void);
                
                class WrongInput : public std::exception
                {
                        virtual const char* what() const throw();             
                };

        //     void    checkOperand(std::string calcul);

};







#endif