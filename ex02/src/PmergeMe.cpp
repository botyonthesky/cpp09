/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:29:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/09/03 08:28:37by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    std::cout << "PmergeMe copy" << std::endl;   
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    std::cout << "PmergeMe copy assignment" << std::endl;
    if (this != &other)
    {
        this->vect = other.vect;
        this->deque = other.deque;
        this->timeDeque = other.timeDeque;
        this->timeVector = other.timeVector;
        this->timeInput = other.timeInput;
        this->_firstArrD = other._firstArrD;
        this->_secondArrD = other._secondArrD;
        this->_firstArrV = other._firstArrV;
        this->_secondArrV = other._secondArrV;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}




void    PmergeMe::vectorMerge(int first, int mid, int second)
{
    int size1 = mid - first + 1;
    int size2 = second - mid;
    _firstArrV.resize(size1);
    _secondArrV.resize(size2);

    for (int i = 0; i < size1; i++)
        _firstArrV[i] = vect[first + i];
    for (int j = 0; j < size2; j++)
        _secondArrV[j] = vect[mid + 1 + j];
    vectorMergeLoop(first, size1, size2);
}
void    PmergeMe::vectorMergeLoop(int first, int size1, int size2)
{
    int i = 0;
    int j = 0;
    int k = first;
    while (i < size1 && j < size2)
    {
        if (_firstArrV[i] <= _secondArrV[j])
        {
            vect[k] = _firstArrV[i];
            i++;
        }
        else
        {
            vect[k] = _secondArrV[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        vect[k] = _firstArrV[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        vect[k] = _secondArrV[j];
        j++;
        k++;
    }
}

void   PmergeMe::mergeInsertionSortV(int first, int second)
{
    if (first < second)
    {
        if (second - first <= 2)
            insertionSortV(first, second);
        else
        {
            int mid = first + (second - first) / 2;
            mergeInsertionSortV(first, mid);
            mergeInsertionSortV(mid + 1, second);
            vectorMerge(first, mid, second);
        }
    }
}

void        PmergeMe::insertionSortV(int first, int last)
{
    for (int i = first + 1; i <= last; i++)
    {
        int curr = vect[i];
        int j = i - 1;
        while (j >= first && vect[j] > curr)
        {
            vect[j + 1] = vect[j];
            j--;
        }
        vect[j + 1] = curr;   
    }
}

void    PmergeMe::algoVector()
{
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    mergeInsertionSortV(0, vect.size() - 1);
    gettimeofday(&end, 0);
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1e6 + msec;
    timeVector = timer + timeInput;
}

void     PmergeMe::dequeMerge(int first, int mid, int second)
{
    int size1 = mid - first + 1;
    int size2 = second - mid;
    _firstArrD.resize(size1);
    _secondArrD.resize(size2);
    for (int i = 0; i < size1; i++)
        _firstArrD[i] = deque[first + i];
    for (int j = 0; j < size2; j++)
        _secondArrD[j] = deque[mid + 1 + j];
    dequeMergeLoop(first, size1, size2);
}

void    PmergeMe::dequeMergeLoop(int first, int size1, int size2)
{
    int i = 0;
    int j = 0;
    int k = first;
    while (i < size1 && j < size2)
    {
        if (_firstArrD[i] <= _secondArrD[j])
        {
            deque[k] = _firstArrD[i];
            i++;
        }
        else
        {
            deque[k] = _secondArrD[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        deque[k] = _firstArrD[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        deque[k] = _secondArrD[j];
        j++;
        k++;
    }
}   

void     PmergeMe::insertionSortD(int first, int second)
{
    for (int i = first + 1; i <= second; i++)
    {
        int curr = deque[i];
        int j = i - 1;
        while (j >= first && deque[j] > curr)
        {
            deque[j + 1] = deque[j];
            j--;
        }
        deque[j + 1] = curr;   
    }
}

void     PmergeMe::mergeInsertionSortD(int first, int second)
{
    if (first < second)
    {
        if (second - first <= 2)
            insertionSortD(first, second);
        else
        {
            int mid = first + (second - first) / 2;
            mergeInsertionSortD(first, mid);
            mergeInsertionSortD(mid + 1, second);
            dequeMerge(first, mid, second);
        }
    }
}

void    PmergeMe::algoDeque()
{
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    mergeInsertionSortD(0, deque.size() - 1);
    gettimeofday(&end, 0);
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = (sec * 1e6) + msec;
    timeDeque = timeInput + timer;
}
long	PmergeMe::checkInput(std::string input)
{
	char *end;
	for (size_t i = 0; i < input.size();)
	{
		if (input[i] != '-' && input[i] != '+')
		{
			if (!std::isdigit(input[i]))
				throw WrongInput();
			i++;
		}
		else	
			i++;
	}
	long num = std::strtol(input.c_str(), &end, 10);
	if (*end != '\0' || num < 0)
		throw NotPositiveNumber();
	if (num > INT_MAX)
		throw NotInt();
	return (num);
}

void    PmergeMe::addInput(int argc, char **argv)
{
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    for (int i = 1; i < argc; i++)
    {
		long num = checkInput(argv[i]);
        vect.push_back(static_cast<int>(num));
        deque.push_back(static_cast<int>(num));
    }
    gettimeofday(&end, 0);
    long sec = end.tv_sec - begin.tv_sec;
    long msec = end.tv_usec - begin.tv_usec;
    double timer = sec * 1e6 + msec;
    timeInput = timer;
}

void    PmergeMe::run()
{
    std::cout << "Before: ";
    printVector();
    algoVector();
    algoDeque();
    std::cout << "After: ";
    printDeque();
    printInfoVector();
    printInfoDeque();
}

void    PmergeMe::printVector()
{
    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    {
        std::cout << *it << " ";
    } 
    std::cout << std::endl;  
}

void    PmergeMe::printInfoVector()
{
    std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : ";
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << timeVector << " us)" << std::endl; 
}
void    PmergeMe::printDeque()
{
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printInfoDeque()
{
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : ";
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << timeDeque << " us)" << std::endl; 
}

const char*     PmergeMe::NotPositiveNumber::what() const throw()
{
    return ("Error : Value must be positive !");
}

const char*     PmergeMe::NotInt::what() const throw()
{
    return ("Error : Value must not exceed INT MAX !");
}

const char*		PmergeMe::WrongInput::what() const throw()
{
	return ("Error : Wrong Input");
}
