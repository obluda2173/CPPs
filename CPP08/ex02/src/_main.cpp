/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:53:26 by erian             #+#    #+#             */
/*   Updated: 2025/03/22 14:49:40 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void testMutantStack() {
	std::cout << "=== Testing MutantStack ===" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterating through MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;
}

void testListComparison() {
	std::cout << "\n=== Testing std::list for comparison ===" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top element: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size after pop: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Iterating through std::list:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;
}

int main() {
	testMutantStack();
	testListComparison();
	return 0;
}