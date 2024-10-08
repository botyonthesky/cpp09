/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:49 by tmaillar          #+#    #+#             */
/*   Updated: 2024/09/05 07:03:42 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include <climits>
#include <sys/time.h>

class PmergeMe
{
    private:
    
                std::vector<int>    _firstArrV;
                std::vector<int>    _secondArrV;
                std::deque<int>     _firstArrD;
                std::deque<int>     _secondArrD;
    

				long				checkInput(std::string input);
                void                algoVector(void);
                void                algoDeque(void);

                void                printVector(void);
                void                printDeque(void);
                
                void                mergeInsertionSortV(int first, int second);
                void                insertionSortV(int first, int last);
                void                vectorMerge(int first, int mid, int last);
                void                vectorMergeLoop(int first, int size1, int size2);
                
                void                mergeInsertionSortD(int first, int second);
                void                insertionSortD(int first, int second);
                void                dequeMerge(int first, int mid, int second);
                void                dequeMergeLoop(int first, int size1, int size2);

                void                printInfoVector(void);
                void                printInfoDeque(void);
        
    public:

                PmergeMe();
                PmergeMe(const PmergeMe& other);
                PmergeMe& operator=(const PmergeMe& other);
                ~PmergeMe();


                std::vector<int>    vect;
                std::deque<int>     deque;

                double              timeVector;
                double              timeDeque;
                double              timeInput;

                void                addInput(int argc, char **argv);
                void                run(void);
                
                class  NotPositiveNumber : public std::exception
                {
                    virtual const char* what() const throw();  
                };
                
                class NotInt : public std::exception
                {
                    virtual const char* what() const throw();
                };

				class WrongInput : public std::exception
				{
					virtual const char* what() const throw();
				};

};

#endif