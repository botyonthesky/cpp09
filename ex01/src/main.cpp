/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:23:06 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/30 10:47:38 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Only one argv please, usage : \"./RPN \"calcul\" " << std::endl;
    else
    {
        RPN polishNotation(argv[1]);
        polishNotation.run();
    }
    return (0);
}