#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

class RailFence {
  private:
  const int rails;
  public:
  // construtor for RailFense
  RailFence(const int &rails) : rails(rails) {}
  const std::string encrypt(const std::string &);
  const std::string decrypt(const std::string &);
};

// create 2d vector, arrange rails conver to string
const std::string RailFence::encrypt(const std::string &plain) {
  std::vector<std::vector<char>> fence = std::vector<std::vector<char>> (rails, std::vector<char>(plain.length(), '\n'));
  std::string cipher = "";

  int row = 0;
  int step = 1;

  for (int i = 0; i < plain.length(); i++) {
    fence[row][i] = plain[i];

    if(row == 0) step = 1;
    if(row == rails - 1) step = -1;

    row += step;
  }
  
  for(const auto& row: fence) {
    for(const char& r: row) {
      if (r != '\n') {
        cipher.push_back(r);
      }
    }
  }
  return cipher;
}

const std::string RailFence::decrypt(const std::string &cipher) {
  std::string plain = "";

  std::vector<std::vector<char>> plot = std::vector<std::vector<char>> (rails, std::vector<char>(cipher.length(), '\n'));
  int row = 0;
  int step = 1;
  for (int i = 0; i < cipher.length(); i++) {
    plot[row][i] = '*';
    if(row == 0) step = 1;
    if(row == rails - 1) step = -1;

    row += step;
  }

  int idx = 0;
  for (auto& p: plot) {
    for (char& c: p) {
      if(c == '*') {
        c = cipher[idx++];
      }
    }
  }

  row = 0;
  step = 1;
  for (int i = 0; i < cipher.length(); i++) {
    plain.push_back(plot[row][i]);
    if(row == 0) step = 1;
    if(row == rails - 1) step = -1;

    row += step;
  }
  return plain;
}

int main(const int argc, const char *argv[]) {
  if(argc != 3) {
    std::cout << "usage: rc <rail> <your_message>" << std::endl;
    return 1;
  }

  const int rail = std::stoi(argv[1]);
  RailFence rc(rail); //4 rails
  
  const std::string plain = argv[2];

  const std::string cipher = rc.encrypt(plain);

  std::cout << "rail cipher: " << cipher << std::endl;

  std::cout << "test "
            << (plain == rc.decrypt(cipher) ? "pass" : "fail")
            << std::endl;
}
 