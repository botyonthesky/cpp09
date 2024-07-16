/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botyonthesky <botyonthesky@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:38 by botyonthesk       #+#    #+#             */
/*   Updated: 2024/07/16 13:07:48 by botyonthesk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe
{
    private:
    
        std::vector<int>    _vect;
        
    public:
    
        PmergeMe(std::vector<int> vect);
        PmergeMe(PmergeMe& other);
        PmergeMe& operator=(PmergeMe& other);
        ~PmergeMe();

        void    run(void);

        void    setVector(std::vector<int> vect);
        void    printVector(void);
        void    algoStepOne(void);

};




#endif