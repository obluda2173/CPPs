/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:21:42 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 12:34:20 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "_Colors.hpp"

template<typename T>
void swap(T& a, T& b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T& a, T& b) {
    return (a < b) ? a : b;
}

template<typename T>
T max(T& a, T& b) {
    return (a > b) ? a : b;
}