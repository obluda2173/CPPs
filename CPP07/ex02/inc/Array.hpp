/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:21:42 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 14:27:34 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdlib.h>

#include "_Colors.hpp"

template<typename T>
class Array {
	private:
		// attributes
		T* _array;
		unsigned int _size;

	public:
		// OCF
		Array() : _array(new T), _size(0) {};
		Array(unsigned int n) : _array(new T[n]), _size(n) {};
		Array(const Array& other) : _array(new T[other.size()]), _size(other.size()) {
			for (size_t i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		Array& operator=(const Array& other) {
			delete [] _array;
			_array = new T[other.size()];
			_size = other.size();
			for (size_t i = 0; i < _size; i++)
				_array[i] = other._array[i];
			return *this;
		}
		T& operator[](unsigned int index) const {
			if (index >= _size)
				throw std::exception();
			return _array[index];
		}
		~Array() {
			delete [] _array;
		}

		// methods
		size_t size() const {
			return _size;
		}
};