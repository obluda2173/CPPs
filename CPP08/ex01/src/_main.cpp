/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/22 18:22:37 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void testBasicSpan() {
	std::cout << "=== Test 1: Basic Span Functionality ===" << std::endl;
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << BLUE << "Shortest Span: " << sp.shortestSpan() << NC << std::endl;
	std::cout << RED << "Longest Span: " << sp.longestSpan() << NC << std::endl;
}

void testEdgeCases() {
	std::cout << "\n=== Test 2: Edge Cases ===" << std::endl;

	try {
		Span sp(1);
		sp.addNumber(42);
		std::cout << MAGENTA << "Attempting to find a span with only one number..." << NC << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught Exception: " << ERROR << e.what() << NC << std::endl;
	}

	try {
		Span sp(3);
		std::cout << VIOLET << "Attempting to find a span with an empty Span..." << NC << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught Exception: " << ERROR << e.what() << NC << std::endl;
	}

	try {
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << INDIGO << "Trying to add another number to a full Span..." << NC << std::endl;
		sp.addNumber(4);
	} catch (const std::exception& e) {
		std::cerr << "Caught Exception: " << ERROR << e.what() << NC << std::endl;
	}
}

void testBulkInsertion() {
	std::cout << "\n=== Test 3: Bulk Insertion ===" << std::endl;

	Span sp(10);
	std::vector<int> numbers;

	for (int i = 1; i <= 7; i++) {
		numbers.push_back(i * 10);
	}

	sp.addNumbers(numbers.begin(), numbers.end());

	std::cout << BLUE << "Shortest Span: " << sp.shortestSpan() << NC << std::endl;
	std::cout << RED << "Longest Span: " << sp.longestSpan() << NC << std::endl;
}

void testLargeDataset() {
	std::cout << "\n=== Test 4: Large Dataset ===" << std::endl;

	Span sp(10000);
	for (int i = 0; i < 10000; i++) {
		sp.addNumber(i * 3);
	}

	std::cout << BLUE << "Shortest Span: " << sp.shortestSpan() << NC << std::endl;
	std::cout << RED << "Longest Span: " << sp.longestSpan() << NC << std::endl;
}

int main() {
	testBasicSpan();
	testEdgeCases();
	testBulkInsertion();
	testLargeDataset();

	return 0;
}