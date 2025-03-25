/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:39:43 by erian             #+#    #+#             */
/*   Updated: 2025/03/25 14:14:22 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <vector>
#include <chrono>
#include <string>
#include <sstream>
#include <iostream>
#include <sys/time.h> 

#include "_Colors.hpp"

class PmergeMe {
    private:
        void mergeInsertionSort(std::vector<int> &vec);
        void mergeInsertionSort(std::deque<int> &deq);
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe& other);
        ~PmergeMe();

        void sortAndMeasure(std::vector<int>& vec, std::deque<int>& deq);
        static void printSequence(const std::string& msg, const std::vector<int>& vec);
};