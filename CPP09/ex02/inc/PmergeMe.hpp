/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:39:43 by erian             #+#    #+#             */
/*   Updated: 2025/03/26 14:30:57 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <sys/time.h> 

#include "_Colors.hpp"

class PmergeMe {
	private:
		template <typename T> void mergeInsertionSort(T& container, int pairLevel);
		template <typename T> void swapPair(T it, int pairLevel);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe &operator=(const PmergeMe& other);
		~PmergeMe();

		static int comparisonNumber;

		void sortAndMeasure(std::vector<int>& vec, std::deque<int>& deq);
		static void printSequence(const std::string& msg, const std::vector<int>& vec);
};

long jacobsthalNumber(long n);

template <typename T>
bool compare(T lv, T rv) {
	PmergeMe::comparisonNumber++;
	return *lv < *rv;
}

template <typename T>
T next(T it, int steps) {
	std::advance(it, steps);
	return it;
}

template <typename T> 
void PmergeMe::swapPair(T it, int pairLevel) {
	T start = next(it, -pairLevel + 1);
	T end = next(start, pairLevel);
	while (start != end) {
		std::iter_swap(start, next(start, pairLevel));
		start++;
	}
}

template <typename T>
void PmergeMe::mergeInsertionSort(T& container, int pairLevel) {
    typedef typename T::iterator Iterator;

    int pairUnitsNumber = container.size() / pairLevel;
    if (pairUnitsNumber < 2)
        return;

    bool isOdd = pairUnitsNumber % 2 == 1;

    Iterator start = container.begin();
    Iterator last = start;
    std::advance(last, pairLevel * pairUnitsNumber);
    Iterator end = last;
    if (isOdd) std::advance(end, -pairLevel);

    int jump = 2 * pairLevel;
    for (Iterator it = start; it != end; std::advance(it, jump)) {
        Iterator thisPair = it;
        std::advance(thisPair, pairLevel - 1);
        Iterator nextPair = it;
        std::advance(nextPair, pairLevel * 2 - 1);

        if (compare(nextPair, thisPair))
            swapPair(thisPair, pairLevel);
    }

    mergeInsertionSort(container, pairLevel * 2);

    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    Iterator mainIt1 = container.begin();
    std::advance(mainIt1, pairLevel - 1);
    main.push_back(mainIt1);

    Iterator mainIt2 = container.begin();
    std::advance(mainIt2, pairLevel * 2 - 1);
    main.push_back(mainIt2);

    for (int i = 4; i <= pairUnitsNumber; i += 2) {
        Iterator pendIt = container.begin();
        std::advance(pendIt, pairLevel * (i - 1) - 1);
        pend.push_back(pendIt);

        Iterator mainIt = container.begin();
        std::advance(mainIt, pairLevel * i - 1);
        main.push_back(mainIt);
    }

    if (isOdd) {
        Iterator oddIt = end;
        std::advance(oddIt, pairLevel - 1);
        pend.push_back(oddIt);
    }

    for (size_t i = 0; i < pend.size(); ++i) {
        typename std::vector<Iterator>::iterator boundIt = main.begin();
        std::advance(boundIt, main.size());

        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), boundIt, pend[i], compare<Iterator>);

        main.insert(idx, pend[i]);
    }

    std::vector<int> copy;
    copy.reserve(container.size());

    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); ++it) {
        Iterator pairStart = *it;
        for (int i = 0; i < pairLevel; i++) {
            Iterator temp = pairStart;
            std::advance(temp, -pairLevel + i + 1);
            copy.push_back(*temp);
        }
    }

    std::copy(copy.begin(), copy.end(), container.begin());
}