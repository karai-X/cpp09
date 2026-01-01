#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: could not open file." << std::endl;
  }
  std::string input_file_path = argv[1];
  BitcoinExchange btc;
  if (!btc.createDataBase("./data.csv")) {
    return 1;
  }
  if (!btc.readInput(input_file_path)) {
    return 1;
  }
  return 0;
}
