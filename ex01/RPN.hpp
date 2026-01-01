#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
private:
  std::stack<long> st_;
  bool handleInput(std::string input);

public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();
  bool parseInput(std::string input);
};

#endif
