/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:40:01 by erian             #+#    #+#             */
/*   Updated: 2025/03/26 12:58:21 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::comparisonNumber = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

long jacobsthalNumber(long n) {
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::printSequence(const std::string& msg, const std::vector<int>& vec) {
	std::cout << BLUE << msg << INDIGO;
	for (long unsigned int i = 0; i < (vec.size()); i++) {
		std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
	}
	std::cout << NC << std::endl;
}

void PmergeMe::sortAndMeasure(std::vector<int>& vec, std::deque<int>& deq) {
	std::vector<int> vecCopy = vec;
	std::deque<int> deqCopy = deq;

	printSequence("Before: ", vec);

	//vector
	PmergeMe::comparisonNumber = 0;
	clock_t startVec = clock();
	mergeInsertionSort<std::vector<int> >(vecCopy, 1);
	clock_t endVec = clock();
	double vecDuration = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;

	// deque
	PmergeMe::comparisonNumber = 0;
	clock_t startDeq = clock();
	mergeInsertionSort<std::deque<int> >(deqCopy, 1);
	clock_t endDeq = clock();
	double deqDuration = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;

	printSequence("After: ", vecCopy);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << ORANGE << vecDuration << " µs" << NC << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << ORANGE << deqDuration << " µs" << NC << std::endl;
	std::cout << MAGENTA << "Sorted in: " << comparisonNumber << " comparisons" << NC << std::endl;
}