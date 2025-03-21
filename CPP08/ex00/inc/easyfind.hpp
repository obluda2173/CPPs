/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:20:09 by erian             #+#    #+#             */
/*   Updated: 2025/03/21 18:25:39 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

#include "_Colors.hpp"

template <typename T>
void easyfind(T& t, int i) {
    if (std::find(t.begin(), t.end(), i) != t.end())
        
}
