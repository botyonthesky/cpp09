/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:49:16 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/16 13:50:15 by botyonthesk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> vect) : _vect(vect)
{
    std::cout << "PmergeMe default constructor" << std::endl;
}
PmergeMe::PmergeMe(PmergeMe& other)
{
    std::cout << "PmergeMe copy" << std::endl;   
    *this = other;
}
PmergeMe& PmergeMe::operator=(PmergeMe& other)
{
    std::cout << "PmergeMe copy assignment" << std::endl;
    if (this != &other)
    {
        *this = other;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe destructor" << std::endl;
}


void    PmergeMe::setVector(std::vector<int> vect)
{
    _vect = vect;
}
void    PmergeMe::printVector()
{
    for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); it++)
    {
        std::cout << *it << " ";
    }   
}
void    PmergeMe::algoStepOne()
{
    int size = _vect.size();
    int j;
    int curr;
    for (int i = 1; i < size; i++)
    {
        curr = _vect[i];
        j = i - 1;
        while (j >= 0)
        {
            if (curr < _vect[j])
            {
                _vect[j + 1] = _vect[j];
                _vect[j] = curr;
            }
            else
            {
                break;
            }
            j--;
        }
        
    }
    printVector();
}

void    PmergeMe::run(void)
{
    std::cout << "Before: ";
    printVector();
    std::cout << std::endl;
    algoStepOne();
}