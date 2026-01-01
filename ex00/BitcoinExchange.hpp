#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, double> db_;
  std::string trimSpace(std::string &str);

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();
  bool createDataBase(std::string csv_file_path);
  bool readInput(std::string input_file_path);
  bool validateDate(std::string date_str);
};

#endif
