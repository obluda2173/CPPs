/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:39 by erian             #+#    #+#             */
/*   Updated: 2025/02/23 10:50:27 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal *animals[SIZE];
	
	for(int i = 0; i < SIZE; i++) {
		animals[i] = (i % 2) ? (AAnimal*) new Cat() : (AAnimal*) new Dog();
		std::cout << "\n";
	}
	
	for(int i = 0; i < SIZE; i++) {
		delete animals[i];
		std::cout << "\n";
	}
	
	Cat cat_00;
    Dog dog_00;
	
	(cat_00.getBrain())->getIdeas()[0] = "random asian";
	std::cout << YELLOW << "cat_00 thinks about " << (cat_00.getBrain())->getIdeas()[0] << "\n" << NC;

	Cat cat_01(cat_00);
	std::cout << YELLOW << "cat_01 (clone of cat_00 with address: " << cat_01.getBrain() << ") thinks about " << (cat_01.getBrain())->getIdeas()[0] << "\n" << NC;

	Cat cat_02 = cat_01;
	std::cout << YELLOW << "cat_02 (clone of cat_01 with address: " << cat_02.getBrain() << ") thinks about " << (cat_02.getBrain())->getIdeas()[0] << "\n" << NC;

	(dog_00.getBrain())->getIdeas()[0] = "specific asian";
	std::cout << YELLOW << "dog_00 thinks about " << (dog_00.getBrain())->getIdeas()[0] << "\n" << NC;

	return 0;
}