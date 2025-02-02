/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:54:47 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 19:41:49 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

using std::cerr;

// hzakharc
Harl::Harl() {
	
	_debug_texts[0] = "Why bother extracting the full path for commands in Pipex when /usr/bin/ covers 90\% of cases? If they wanted absolute paths, they shouldve just hardcoded them in the first place!";
	_debug_texts[1] = "Technically, if the environment doesn't have PWD and OLDPWD, the user probably messed something up. Not my problem. Shells dont break; users do.";
	_debug_texts[2] = "Segfault on invalid input? Well, invalid input means undefined behavior, and undefined behavior means anything can happen. So its technically working as expected.";
	
	_info_texts[0] = "In a real-world scenario, people just use absolute paths for executables. Who runs commands from /usr/local/bin/ anyway? /usr/bin/ls is basically standard.";
	_info_texts[1] = "Nobody actually types cd - in real life. And even if they do, they should just re-export PWD and OLDPWD manually. They should know better.";
	_info_texts[2] = "Memory leaks? Look, if the OS reclaims memory when the program exits, does it really matter? Id say its more of a feature than a bug.";
	
	_warning_texts[0] = "Yeah, okay, technically my minishell doesnt update PWD after cd, but come on—who even checks that? As long as you pwd after every cd, youre fine.";
	_warning_texts[1] = "I know signal handling isnt perfect, but pressing Ctrl+C three times in a row usually works. If it crashes, well… just restart it. Problem solved.";
	_warning_texts[2] =	"Maybe my heredoc implementation hangs in some cases, but honestly, who even writes multi-line input like that? Just keep it simple.";

	_error_texts[0] = "What do you mean Pipex doesnt work when the command is missing? If the user cant even type a valid command, why should my program fix their mistakes?";
	_error_texts[1] = "Youre saying unset PWD breaks cd? Well, dont unset PWD then! Why would anyone ever do that on purpose?";
	_error_texts[2] = "If my program crashes, just dont do whatever makes it crash. Problem solved. Next question.";

	std::srand(std::time(0));
}

void Harl::complain(std::string level) {

	std::string tab_of_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (tab_of_levels[i] == level) {
			(this->*(functions[i]))();
			usleep(500000);
			return ;
		}
	}
	cerr << ERROR << " Uncompatibile type";
}

void Harl::debug() {
	std::cout << ORANGE << _debug_texts[std::rand() % 4] << NC << "\n";
}
void Harl::info() {
	std::cout << YELLOW << _info_texts[std::rand() % 2] << NC << "\n";
}
void Harl::warning() {
	std::cout << GREEN << _warning_texts[std::rand() % 2] << NC << "\n";
}
void Harl::error() {
	std::cout << BLUE << _error_texts[std::rand() % 3] << NC << "\n";
}

Harl::~Harl() {}