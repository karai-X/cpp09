#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  this->db_ = other.db_;
  return *this;
}

bool BitcoinExchange::createDataBase(std::string csv_file_path) {
  std::ifstream file(csv_file_path.c_str());
  std::string line;
  std::string date;
  std::string rate_str;
  double rate;
  if (file.is_open()) {
    std::getline(file, line);
    while (std::getline(file, line)) {
      std::istringstream iss(line);
      std::getline(iss, date, ',');
      date = trimSpace(date);
      std::getline(iss, rate_str, ',');
      std::stringstream rate_ss(rate_str);
      if (rate_ss >> rate) {
        db_[date] = rate;
      }
    }
  } else {
    std::cout << "Error: could not open file." << std::endl;
    return false;
  }
  return true;
}

std::string BitcoinExchange::trimSpace(std::string &str) {
  size_t start = str.find_first_not_of(" \t");
  if (start == std::string::npos)
    return "";
  size_t end = str.find_last_not_of(" \t");
  return str.substr(start, end - start + 1);
}

bool BitcoinExchange::validateDate(std::string date_str) {
  if (date_str.length() != 10 || date_str[4] != '-' || date_str[7] != '-') {
    return false;
  }
  char *endptr;
  long val = strtol(date_str.c_str(), &endptr, 10);
  if (endptr != &(date_str[4]) || val < 2009) {
    return false;
  }
  std::string date_str_sub = date_str.substr(5);
  val = strtol(date_str_sub.c_str(), &endptr, 10);
  if (endptr != &(date_str_sub[2]) || val < 1 || val > 12) {
    return false;
  }
  date_str_sub = date_str.substr(8);
  val = strtol(date_str_sub.c_str(), &endptr, 10);
  if (endptr != &(date_str_sub[2]) || val < 1 || val > 31) {
    std::cout << val << std::endl;
    return false;
  }
  return true;
}

bool BitcoinExchange::readInput(std::string input_file_path) {
  std::ifstream file(input_file_path.c_str());
  std::string line;
  std::string date;
  std::string value_str;
  float value;
  if (file.is_open()) {
    std::getline(file, line);
    while (std::getline(file, line)) {
      std::istringstream iss(line);
      std::getline(iss, date, '|');
      date = trimSpace(date);
      if (validateDate(date) == false) {
        std::cout << "Error: bad input => " << date << std::endl;
        continue;
      }
      std::getline(iss, value_str, '|');
      std::stringstream value_ss(value_str);
      if (value_ss >> value) {
        if (value < 0) {
          std::cout << "Error: not a positive number." << std::endl;
          continue;
        }
        if (value > 1000) {
          std::cout << "Error: too large a number." << std::endl;
          continue;
        }
        std::map<std::string, double>::iterator it = db_.lower_bound(date);
        if (it != db_.end() && it->first == date) {
          std::cout << date << " => " << value << " = " << value * it->second
                    << std::endl;
        } else if (it != db_.begin()) {
          it--;
          std::cout << date << " => " << value << " = " << value * it->second
                    << std::endl;
        } else {
          std::cout << "Error: bit coin had not been cretated => " << date
                    << std::endl;
        }
      } else {
        std::cout << "Error: value is invalid." << std::endl;
      }
    }
  } else {
    std::cout << "Error: could not open file." << std::endl;
    return false;
  }
  return true;
}
