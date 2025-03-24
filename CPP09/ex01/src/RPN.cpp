/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:01:40 by erian             #+#    #+#             */
/*   Updated: 2025/03/24 19:36:36 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(const std::string &token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int performOperation(const std::string &op, int a, int b) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0)
			throw std::runtime_error("Error: Division by zero");
		return a / b;
	}
	throw std::runtime_error("Error: Invalid operator");
}

int evaluate(const std::string &expression) {
	std::stack<int> stack;
	std::istringstream tokens(expression);
	std::string token;

	while (tokens >> token) {
		if (isdigit(token[0]) && token.size() == 1) {
			stack.push(token[0] - '0');
		}
		else if (isOperator(token)) {
			if (stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands");

			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			stack.push(performOperation(token, a, b));
		}
		else {
			throw std::runtime_error("Error");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error: Too many operands left");

	return stack.top();
}