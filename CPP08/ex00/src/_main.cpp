/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/22 18:07:30 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NotFoundException::what() const throw() {
	return "Value not found in container";
}

int main() {
	try {
		int arr1[] = {10, 20, 30, 40, 50};
		std::vector<int> vec(arr1, arr1 + 5);
		int arr2[] = {5, 15, 25, 35, 45};
		std::list<int> lst(arr2, arr2 + 5);
		
		std::cout << "Found: " << *easyfind(vec, 30) << std::endl;
		std::cout << "Found: " << *easyfind(lst, 25) << std::endl;
		std::cout << "Found: " << *easyfind(vec, 100) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}