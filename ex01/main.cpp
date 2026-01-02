#include "RPN.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: the number of argument is not 2." << std::endl;
    return 1;
  }
  std::string str(argv[1]);
  RPN rpn;
  if (rpn.parseInput(str))
    return 0;
  else
    return 1;
}
