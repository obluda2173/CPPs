/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:01:44 by erian             #+#    #+#             */
/*   Updated: 2025/03/24 19:02:48 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "_Colors.hpp"

class RPN {
	private:
		static bool isOperator(const std::string &token);
		static int performOperation(const std::string &op, int a, int b);
		
	public:
		static int evaluate(const std::string &expression);
};