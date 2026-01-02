#include "PMergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(char *argv[]) {
  int num;
  size_t i = 1;
  while (argv[i]) {
    std::string str(argv[i]);
    std::stringstream ss(str);
    ss >> num;
    if ((ss.fail()))
      throw std::exception();
    ss >> std::ws;
    if (!ss.eof())
      throw std::exception();
    if (num < 0)
      throw std::exception();
    vec_.push_back(num);
    deq_.push_back(num);
    i += 1;
  }
}

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  vec_ = other.vec_;
  return *this;
}

void PmergeMe::printVec() {
  for (std::vector<int>::iterator it = vec_.begin(); it != vec_.end(); it++) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

// bool PmergeMe::handleInput(std::string input) {
//   if (input == "+" || input == "-" || input == "/" || input == "*") {
//     if (st_.size() < 2)
//       return false;
//     long b = st_.top();
//     st_.pop();
//     long a = st_.top();
//     st_.pop();
//     if (input == "+")
//       st_.push(a + b);
//     if (input == "-")
//       st_.push(a - b);
//     if (input == "*")
//       st_.push(a * b);
//     if (input == "/")
//       st_.push(a / b);
//   } else {
//     int num;
//     std::stringstream conv(input);
//     if (conv >> num) {
//       st_.push(static_cast<long>(num));
//     } else
//       return false;
//   }
//   return true;
// }

// bool PmergeMe::parseInput(std::string input) {
//   std::stringstream ss(input);
//   std::string token;
//   while (ss >> token)
//     if (!handleInput(token)) {
//       std::cerr << "Error" << std::endl;
//       return false;
//     }
//   if (st_.size() != 1) {
//     std::cerr << "Error" << std::endl;
//     return false;
//   }
//   std::cout << st_.top() << std::endl;
//   return true;
// }
