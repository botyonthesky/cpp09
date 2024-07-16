/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:59 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/16 11:18:16 by botyonthesk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

std::vector<int>    addInput(int argc, char **argv)
{
    std::vector<int>  vect;
    for (int i = 1; i < argc; i++)
    {
        int num = std::atoi(argv[i]);
        vect.push_back(num);
    }
    return (vect);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "Need arguments ! Example usage : ./PmergeMe 3 5 9 7 4" << std::endl;
    else
    {
        std::vector<int> vect;
        vect = addInput(argc, argv);
        PmergeMe pm(vect);
        pm.run();
    }
    return (0);
}