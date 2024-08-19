/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:53:18 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/19 07:35:45 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Error: Only one argv. Usage: ./btc <input_file>" << std::endl;
    else
    {
        std::string filename = argv[1];
        BitcoinExchange btc(filename);
        btc.run();
    }
    return (0);
}