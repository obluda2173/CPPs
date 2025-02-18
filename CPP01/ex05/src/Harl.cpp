/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:54:47 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 16:19:53 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Level get_level(const std::string& level_str) {
    if (level_str == "DEBUG") return DEBUG;
    if (level_str == "INFO") return INFO;
    if (level_str == "WARNING") return WARNING;
    if (level_str == "ERROR") return ERROR;
    return UNKNOWN;
}

Harl::Harl() {
    _texts[DEBUG][0] = "Why bother extracting the full path for commands in Pipex when /usr/bin/ covers 90\% of cases? It is not even mentioned in the subject!";
    _texts[DEBUG][1] = "Technically, if the environment doesn't have PWD and OLDPWD, the user probably messed something up. Not my problem. Shells don't break; users do.";
    _texts[DEBUG][2] = "Segfault on invalid input? Well, invalid input means undefined behavior, and undefined behavior means anything can happen. So it's technically working as expected.";

    _texts[INFO][0] = "In a real-world scenario, people just use absolute paths for executables. Who runs commands from /usr/local/bin/ anyway? /usr/bin/ls is basically standard.";
    _texts[INFO][1] = "Nobody actually types cd - in real life. And even if they do, they should just re-export PWD and OLDPWD manually. They should know better.";
    _texts[INFO][2] = "Memory leaks? Look, if the OS reclaims memory when the program exits, does it really matter? I'd say it's more of a feature than a bug.";

    _texts[WARNING][0] = "Yeah, okay, technically my minishell doesn't update PWD after cd, but come on—who even checks that? As long as you pwd after every cd, you're fine.";
    _texts[WARNING][1] = "I know signal handling isn't perfect, but pressing Ctrl+C three times in a row usually works. If it crashes, well… just restart it. Problem solved.";
	_texts[WARNING][2] = "Maybe my heredoc implementation hangs in some cases, but honestly, who even writes multi-line input like that? Just keep it simple.";


    _texts[ERROR][0] = "What do you mean Pipex doesn't work when the command is missing? If the user can't even type a valid command, why should my program fix their mistakes?";
    _texts[ERROR][1] = "You're saying unset PWD breaks cd? Well, don't unset PWD then! Why would anyone ever do that on purpose?";
    _texts[ERROR][2] = "If my program crashes, just don't do whatever makes it crash. Problem solved. Next question.";

	std::srand(std::time(0));
}

void Harl::complain( std::string level_str ) {
	Level level = get_level(level_str);

	switch (level) {
		case DEBUG:
			debug();
			break;
		case INFO:
			info();
			break;
		case WARNING:
			warning();
			break;
		case ERROR:
			error();
			break;
		default:
			std::cerr << RED << "Error: Unrecognized complaint level: " << level_str << NC << std::endl;
			break;
	}

	usleep(777777);
}

void Harl::debug() {
	std::cout << DARK_ORANGE << _texts[DEBUG][std::rand() % 3] << NC << "\n";
}

void Harl::info() {
	std::cout << DARK_YELLOW << _texts[INFO][std::rand() % 3] << NC << "\n";
}

void Harl::warning() {
	std::cout << DARK_GREEN << _texts[WARNING][std::rand() % 3] << NC << "\n";
}

void Harl::error() {
	std::cout << DARK_BLUE << _texts[ERROR][std::rand() % 3] << NC << "\n";
}

Harl::~Harl() {}