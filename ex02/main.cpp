#include "PMergeMe.hpp"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cerr << "Error: no argument" << std::endl;
    return 1;
  }
  PmergeMe pmerge;
  try {
	pmerge = PmergeMe(argv);
  } catch (...) {
    std::cerr << "Error: invalid input" << std::endl;
    return 1;
  }
  std::cout << "Before:";
  pmerge.printVec();
}
