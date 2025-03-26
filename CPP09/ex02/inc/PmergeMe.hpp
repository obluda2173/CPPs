/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:39:43 by erian             #+#    #+#             */
/*   Updated: 2025/03/26 13:11:00 by erian            ###   ########.fr       */
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

	bool is_odd = pairUnitsNumber % 2 == 1;

	Iterator start = container.begin();
	Iterator last = start;
	std::advance(last, pairLevel * pairUnitsNumber);
	Iterator end = last;
	if (is_odd) std::advance(end, -pairLevel);

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

	// Initialize main with {b1, a1}
	main.push_back(container.begin());
	std::advance(main.back(), pairLevel - 1);
	main.push_back(container.begin());
	std::advance(main.back(), pairLevel * 2 - 1);

	for (int i = 4; i <= pairUnitsNumber; i += 2) {
		Iterator pend_it = container.begin();
		std::advance(pend_it, pairLevel * (i - 1) - 1);
		pend.push_back(pend_it);

		Iterator mainIt = container.begin();
		std::advance(mainIt, pairLevel * i - 1);
		main.push_back(mainIt);
	}

	if (is_odd) {
		Iterator oddIt = end;
		std::advance(oddIt, pairLevel - 1);
		pend.push_back(oddIt);
	}

	int prevJacobsthal = jacobsthalNumber(1);
	int insertedNumbers = 0;

	for (int k = 2;; k++) {
		int currJacobsthal = jacobsthalNumber(k);
		int jacobsthalDiff = currJacobsthal - prevJacobsthal;
		if (jacobsthalDiff > static_cast<int>(pend.size()))
			break;

		typename std::vector<Iterator>::iterator pend_it = pend.begin();
		std::advance(pend_it, jacobsthalDiff - 1);
		typename std::vector<Iterator>::iterator bound_it = main.begin();
		std::advance(bound_it, currJacobsthal + insertedNumbers);
			
		int offset = 0;
		for (int i = 0; i < jacobsthalDiff; i++) {
			if (pend_it == pend.end()) break;
		
			typename std::vector<Iterator>::iterator idx =
				std::upper_bound(main.begin(), bound_it, *pend_it, compare<Iterator>);
		
			typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
		
			pend_it = pend.erase(pend_it);  
		
			if ((inserted - main.begin()) == currJacobsthal + insertedNumbers)
				offset++;
		
			bound_it = main.begin();
			std::advance(bound_it, currJacobsthal + insertedNumbers - offset);
		}

		prevJacobsthal = currJacobsthal;
		insertedNumbers += jacobsthalDiff;
	}

	for (ssize_t i = pend.size() - 1; i >= 0; i--) {
		typename std::vector<Iterator>::iterator currPend = pend.begin();
		std::advance(currPend, i);
		typename std::vector<Iterator>::iterator currBound = main.begin();
		std::advance(currBound, main.size() - pend.size() + i + is_odd);

		typename std::vector<Iterator>::iterator idx =
			std::upper_bound(main.begin(), currBound, *currPend, compare<Iterator>);
		main.insert(idx, *currPend);
	}

	std::vector<int> copy;
	copy.reserve(container.size());

	for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); ++it) {
		Iterator pair_start = *it;
		for (int i = 0; i < pairLevel; i++) {
			Iterator temp = pair_start;
			std::advance(temp, -pairLevel + i + 1);
			copy.push_back(*temp);
		}
	}

	std::copy(copy.begin(), copy.end(), container.begin());
}