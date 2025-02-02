#include "Sed.hpp"

using std::cerr;
using std::endl;

int main(int ac, char **av) {
  
  if (ac != 4) {
    cerr << ERROR << " wrong number of arguments!!! " << NC << endl;
    return 1;
  }
  else {
    Sed sed;
    std::string file = av[1];
    std::string to_replace = av[2];
    std::string replace = av[2];
    sed.replace(file, to_replace, replace);
  }
  return 0;
}
