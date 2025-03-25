/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:40:01 by erian             #+#    #+#             */
/*   Updated: 2025/03/25 19:29:11 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::nbr_of_comps = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

long _jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

void PmergeMe::printSequence(const std::string& msg, const std::vector<int>& vec) {
	std::cout << BLUE << msg << INDIGO;
	for (long unsigned int i = 0; i < (vec.size()); i++) {
		std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
	}
	std::cout << NC << std::endl;
}

long getMicroseconds() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}

void PmergeMe::sortAndMeasure(std::vector<int>& vec, std::deque<int>& deq) {
	std::vector<int> vecCopy = vec;
	std::deque<int> deqCopy = deq;

	printSequence("Before: ", vec);

	// vector
	PmergeMe::nbr_of_comps = 0;
	long startVec = getMicroseconds();
	mergeInsertionSort<std::vector<int> >(vecCopy, 1);
	long endVec = getMicroseconds();
	long vecDuration = endVec - startVec;

	// deque
	PmergeMe::nbr_of_comps = 0;
	long startDeq = getMicroseconds();
	mergeInsertionSort<std::deque<int> >(deqCopy, 1);
	long endDeq = getMicroseconds();
	long deqDuration = endDeq - startDeq;

	printSequence("After: ", vecCopy);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << ORANGE << vecDuration << " µs" << NC << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << ORANGE << deqDuration << " µs" << NC << std::endl;
}