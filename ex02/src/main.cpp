/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/08/19 08:29:28 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc <= 2)
        std::cerr << "Error : Need arguments ! Example usage : ./PmergeMe 3 5 9 7 4" << std::endl;
    else
    {
        try
        {
            PmergeMe pm;
            pm.addInput(argc, argv);
            pm.run(); 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}