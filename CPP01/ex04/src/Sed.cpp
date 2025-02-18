/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:37:15 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 15:04:51 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed() {}

void Sed::replace( std::string file, std::string to_replace, std::string replacement ) {
    std::ifstream input(file.c_str());
    if (!input.is_open()) {
        std::cerr << ERROR << "Error: could not open file '" << file << "'" << NC << std::endl;
        return;
    }

    std::string buffer((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    input.close();

    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = buffer.find(to_replace, start)) != std::string::npos) {
        result.append(buffer, start, pos - start);
        result += replacement;
        start = pos + to_replace.length();
    }
    result.append(buffer, start, std::string::npos);

    std::string outputFile = file + ".replace";
    std::ofstream output(outputFile.c_str());
    if (!output.is_open()) {
        std::cerr << ERROR << "Error: could not create output file '" << outputFile << "'" << NC << std::endl;
        return;
    }

    output << result;
    output.close();
}

Sed::~Sed() {}