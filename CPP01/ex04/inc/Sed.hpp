#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "Colors.hpp"

class Sed {
  public:
    Sed();
    ~Sed();

    void replace(std::string file, std::string to_replace, std::string replace);
};
