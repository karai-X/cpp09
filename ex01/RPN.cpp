#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) {
  st_ = other.st_;
  return *this;
}

bool RPN::handleInput(std::string input) {
  if (input == "+" || input == "-" || input == "/" || input == "*") {
    if (st_.size() < 2)
      return false;
    long b = st_.top();
    st_.pop();
    long a = st_.top();
    st_.pop();
    if (input == "+")
      st_.push(a + b);
    if (input == "-")
      st_.push(a - b);
    if (input == "*")
      st_.push(a * b);
    if (input == "/")
      st_.push(a / b);
  } else {
    int num;
    std::stringstream conv(input);
    if (conv >> num) {
      st_.push(static_cast<long>(num));
    } else
      return false;
  }
  return true;
}

bool RPN::parseInput(std::string input) {
  std::stringstream ss(input);
  std::string token;
  while (ss >> token)
    if (!handleInput(token)) {
      std::cerr << "Error" << std::endl;
      return false;
    }
  if (st_.size() != 1) {
    std::cerr << "Error" << std::endl;
    return false;
  }
  std::cout << st_.top() << std::endl;
  return true;
}
