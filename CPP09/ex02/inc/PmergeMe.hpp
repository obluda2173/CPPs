/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:39:43 by erian             #+#    #+#             */
/*   Updated: 2025/03/26 10:01:02 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <sys/time.h> 
#include <cmath>

#include "_Colors.hpp"

class PmergeMe {
	private:
		template <typename T> void mergeInsertionSort(T& container, int pair_level);
		template <typename T> void _swap_pair(T it, int pair_level);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe &operator=(const PmergeMe& other);
		~PmergeMe();

		static int nbr_of_comps;

		void sortAndMeasure(std::vector<int>& vec, std::deque<int>& deq);
		static void printSequence(const std::string& msg, const std::vector<int>& vec);
};

long _jacobsthal_number(long n);

template <typename T>
bool _comp(T lv, T rv) {
	PmergeMe::nbr_of_comps++;
	return *lv < *rv;
}

template <typename T>
T next(T it, int steps) {
    std::advance(it, steps);
    return it;
}

template <typename T> 
void PmergeMe::_swap_pair(T it, int pair_level) {
	T start = next(it, -pair_level + 1);
	T end = next(start, pair_level);
	while (start != end) {
		std::iter_swap(start, next(start, pair_level));
		start++;
	}
}

template <typename T>
void PmergeMe::mergeInsertionSort(T& container, int pair_level) {
	typedef typename T::iterator Iterator;

	int pair_units_nbr = container.size() / pair_level;
	if (pair_units_nbr < 2)
		return;

	bool is_odd = pair_units_nbr % 2 == 1;

	Iterator start = container.begin();
	Iterator last = start;
	std::advance(last, pair_level * pair_units_nbr);
	Iterator end = last;
	if (is_odd) std::advance(end, -pair_level);

	int jump = 2 * pair_level;
	for (Iterator it = start; it != end; std::advance(it, jump)) {
		Iterator this_pair = it;
		std::advance(this_pair, pair_level - 1);
		Iterator next_pair = it;
		std::advance(next_pair, pair_level * 2 - 1);

		if (_comp(next_pair, this_pair))
			_swap_pair(this_pair, pair_level);
	}

	mergeInsertionSort(container, pair_level * 2);

	std::vector<Iterator> main;
	std::vector<Iterator> pend;

	// Initialize main with {b1, a1}
	main.push_back(container.begin());
	std::advance(main.back(), pair_level - 1);
	main.push_back(container.begin());
	std::advance(main.back(), pair_level * 2 - 1);

	for (int i = 4; i <= pair_units_nbr; i += 2) {
		Iterator pend_it = container.begin();
		std::advance(pend_it, pair_level * (i - 1) - 1);
		pend.push_back(pend_it);

		Iterator main_it = container.begin();
		std::advance(main_it, pair_level * i - 1);
		main.push_back(main_it);
	}

	if (is_odd) {
		Iterator odd_it = end;
		std::advance(odd_it, pair_level - 1);
		pend.push_back(odd_it);
	}

	int prev_jacobsthal = _jacobsthal_number(1);
	int inserted_numbers = 0;

	for (int k = 2;; k++) {
		int curr_jacobsthal = _jacobsthal_number(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break;

		typename std::vector<Iterator>::iterator pend_it = pend.begin();
		std::advance(pend_it, jacobsthal_diff - 1);
		typename std::vector<Iterator>::iterator bound_it = main.begin();
		std::advance(bound_it, curr_jacobsthal + inserted_numbers);
			
		int offset = 0;
		for (int i = 0; i < jacobsthal_diff; i++) {
			if (pend_it == pend.end()) break;
		
			typename std::vector<Iterator>::iterator idx =
				std::upper_bound(main.begin(), bound_it, *pend_it, _comp<Iterator>);
		
			typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
		
			pend_it = pend.erase(pend_it);  
		
			if ((inserted - main.begin()) == curr_jacobsthal + inserted_numbers)
				offset++;
		
			bound_it = main.begin();
			std::advance(bound_it, curr_jacobsthal + inserted_numbers - offset);
		}

		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}

	for (ssize_t i = pend.size() - 1; i >= 0; i--) {
		typename std::vector<Iterator>::iterator curr_pend = pend.begin();
		std::advance(curr_pend, i);
		typename std::vector<Iterator>::iterator curr_bound = main.begin();
		std::advance(curr_bound, main.size() - pend.size() + i + is_odd);

		typename std::vector<Iterator>::iterator idx =
			std::upper_bound(main.begin(), curr_bound, *curr_pend, _comp<Iterator>);
		main.insert(idx, *curr_pend);
	}

	std::vector<int> copy;
	copy.reserve(container.size());

	for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); ++it) {
		Iterator pair_start = *it;
		for (int i = 0; i < pair_level; i++) {
			Iterator temp = pair_start;
			std::advance(temp, -pair_level + i + 1);
			copy.push_back(*temp);
		}
	}

	std::copy(copy.begin(), copy.end(), container.begin());
}
