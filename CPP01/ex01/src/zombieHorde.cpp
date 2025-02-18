/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:08:31 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 12:11:12 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ) {
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		new(&zombies[i]) Zombie(name);
	return zombies;
}