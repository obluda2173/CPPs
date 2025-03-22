/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:40:38 by erian             #+#    #+#             */
/*   Updated: 2025/03/22 18:10:11 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <exception>

#include "_Colors.hpp"

class Span {
	private:
		// attributes
		unsigned int _maxSize;
		std::vector<int> _numbers;
		Span();

	public:
		// OCF
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		// methods
		void addNumber(int number);
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end) {
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw std::overflow_error("Span is full");
			_numbers.insert(_numbers.end(), begin, end);
		}
		int shortestSpan() const;
		int longestSpan() const;
};