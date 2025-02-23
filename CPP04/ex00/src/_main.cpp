/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:39 by erian             #+#    #+#             */
/*   Updated: 2025/02/23 10:36:33 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	// block 1
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << "\n";
	
	// block 2
	const WrongAnimal *post = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	const WrongCat *f = new WrongCat();
	
	std::cout << k->getType() << " " << std::endl;
	std::cout << f->getType() << " " << std::endl;
	k->makeSound();
	f->makeSound();
	post->makeSound();
	
	std::cout << "\n";

	delete meta;
	delete j;
	delete i;
	std::cout << "\n";
	delete post;
	delete k;
	delete f;

	return 0;
}