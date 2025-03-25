/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:40:01 by erian             #+#    #+#             */
/*   Updated: 2025/03/25 15:55:42 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertionSort(std::vector<int>& vec) {
	if (vec.size() < 2)
		return;

	size_t mid = vec.size() / 2;
	std::vector<int> left(vec.begin(), vec.begin() + mid);
	std::vector<int> right(vec.begin() + mid, vec.end());

	mergeInsertionSort(left);
	mergeInsertionSort(right);

	std::vector<int>::iterator l = left.begin();
	std::vector<int>::iterator r = right.begin();
	std::vector<int>::iterator v = vec.begin();

	while (l != left.end() && r != right.end()) {
		if (*l < *r) {
			*v = *l;
			++l;
		} else {
			*v = *r;
			++r;
		}
		++v;
	}

	while (l != left.end()) {
		*v = *l;
		++l;
		++v;
	}

	while (r != right.end()) {
		*v = *r;
		++r;
		++v;
	}
}

void PmergeMe::mergeInsertionSort(std::deque<int>& deq) {
	if (deq.size() < 2)
		return;

	size_t mid = deq.size() / 2;
	std::deque<int> left(deq.begin(), deq.begin() + mid);
	std::deque<int> right(deq.begin() + mid, deq.end());

	mergeInsertionSort(left);
	mergeInsertionSort(right);

	std::deque<int>::iterator l = left.begin();
	std::deque<int>::iterator r = right.begin();
	std::deque<int>::iterator v = deq.begin();

	while (l != left.end() && r != right.end()) {
		if (*l < *r) {
			*v = *l;
			++l;
		} else {
			*v = *r;
			++r;
		}
		++v;
	}

	while (l != left.end()) {
		*v = *l;
		++l;
		++v;
	}

	while (r != right.end()) {
		*v = *r;
		++r;
		++v;
	}
}

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
	long startVec = getMicroseconds();
	mergeInsertionSort(vecCopy);
	long endVec = getMicroseconds();
	long vecDuration = endVec - startVec;

	// deque
	long startDeq = getMicroseconds();
	mergeInsertionSort(deqCopy);
	long endDeq = getMicroseconds();
	long deqDuration = endDeq - startDeq;

	printSequence("After: ", vecCopy);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << ORANGE << vecDuration << " µs" << NC << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << ORANGE << deqDuration << " µs" << NC << std::endl;
}