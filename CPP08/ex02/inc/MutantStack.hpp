/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:29:14 by erian             #+#    #+#             */
/*   Updated: 2025/03/22 14:47:58 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <list>
#include <deque>
#include <iterator>
#include <iostream>

#include <_Colors.hpp>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		// OCF
		MutantStack() {}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}

		// Define iterator types from std::deque<T>
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// Iterator access functions
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};