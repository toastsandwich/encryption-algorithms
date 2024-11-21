#include <iostream>
#include <string>

class ceaser_cipher {
  private:
  int shift;

  int __shift(int ch, int base) {
    // find the value then add the base
    return (ch - base + this->shift) % 26 + base;
  }

  int __unshift(int ch, int base) {
    return (ch - base - this->shift + 26) % 26 + base;
  }

  public:
  ceaser_cipher(const int);
  const std::string encrypt(const std::string);
  const std::string decrypt(const std::string);
  ~ceaser_cipher();
};

ceaser_cipher::ceaser_cipher(const int shift) {
  this->shift = shift % 26;
}

const std::string ceaser_cipher::encrypt(const std::string plain) {
  std::string cipher = "";
  for (auto ch: plain) {
    if (std::isalpha(ch)) {
      const char base = std::isupper(ch) ? 'A' : 'a';
      const char c = __shift(ch, base);
      cipher.push_back(c);
    } else {
      cipher.push_back(ch);
    }
  }
  return cipher;
}

const std::string ceaser_cipher::decrypt(const std::string cipher) {
  std::string plain = "";
  for (auto ch: cipher) {
    if (std::isalpha(ch)) {
      const char base = std::isupper(ch) ? 'A' : 'a';
      const char c = __unshift(ch, base);
      plain.push_back(c);
    } else {
      plain.push_back(ch);
    }
  }
  return plain;
}

ceaser_cipher::~ceaser_cipher() {
  this->shift = 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: ./ceaser <your_plain_text>" << '\n';
    return 1;
  }

  const std::string plain = argv[1];

  ceaser_cipher cc = ceaser_cipher(100);

  const std::string cipher = cc.encrypt(plain);
  
  std::cout << "ceaser cipher = " << cipher << '\n';

  std::cout << "result: "
            << (cc.decrypt(cipher) == plain ? "pass" : "fail")
            << '\n';
  
  return 0;
}
