/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:53:18 by tmaillar          #+#    #+#             */
/*   Updated: 2024/07/12 07:15:23 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Error: could not open file" << std::endl;
    else
    {
        std::string filename = argv[1];
        try
        {
            BitcoinExchange btc(filename);
            btc.run();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    return (0);
}