#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>

class PmergeMe {
private:
  std::vector<int> vec_;
  std::deque<int> deq_;

public:
  PmergeMe();
  PmergeMe(char *argv[]);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();
  void printVec();
};

#endif
