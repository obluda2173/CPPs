/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:21:42 by erian             #+#    #+#             */
/*   Updated: 2025/03/21 13:47:29 by erian            ###   ########.fr       */
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
		T* _data;
		unsigned int _size;

	public:
		// OCF
		Array() : _data(NULL), _size(0) {}
		Array(unsigned int n) : _size(n) {
			_data = new T[n]();
		}
		Array(const Array& other) : _size(other._size) {
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
		}
		Array& operator=(const Array& other) {
			if (this == &other)
				return *this;
	
			delete[] _data;
	
			_size = other._size;
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
	
			return *this;
		}
		~Array() {
			delete[] _data;
		}
	
		// operators
		T& operator[](unsigned int index) {
			// std::out_of_range is chosen for a reason
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}
		const T& operator[](unsigned int index) const {
			// std::out_of_range is chosen for a reason
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}
		
		// methods
		unsigned int size() const {
			return _size;
		}
};
	