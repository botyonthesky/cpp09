/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:05:09 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/15 12:25:36 by botyonthesk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Only one argv please, usage : \"./RPN \"calcul\" " << std::endl;
    else
    {
        std::string calcul;
        calcul = argv[1];
        RPN polishNotation(calcul);
        polishNotation.run();
    }
        
    return (0);
}