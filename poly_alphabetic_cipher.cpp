#include <iostream>
#include <string>

class PolyAlphabeticCipher {
  private:
  const std::string key;
  const int length;
  
  public:
  PolyAlphabeticCipher(const std::string &key): key(key), length(key.length()) {};
  const std::string encrypt(const std::string &);
  const std::string decrypt(const std::string &);
};

const std::string PolyAlphabeticCipher::encrypt(const std::string &plain) {
  std::string cipher = "";
  int index = 0;
  for (char c: plain) {
    if (std::isalpha(c)) {
      const char base = std::isupper(c) ? 'A' : 'a';
      const int shift = std::toupper(key[index]) - 'A';
      const char e_ch = (c - base + shift) % 26 + base;
      cipher.push_back(e_ch);
      index = (index + 1) % length;
    } else {
      cipher.push_back(c);
    }
  }
  return cipher;
}

const std::string PolyAlphabeticCipher::decrypt(const std::string &cipher) {
  std::string plain = "";
  int index = 0;  
  for (char c: cipher) {
    if (std::isalpha(c)) {
      const char base = std::isupper(c) ? 'A' : 'a';
      const int shift = std::toupper(key[index]) - 'A';
      const char e_ch = (c - base - shift + 26) % 26 + base;
      plain.push_back(e_ch);
      index = (index + 1) % length;
    } else {
      plain.push_back(c);
    }
  }
  return plain;
} 

int main() {
  // Create a PolyAlphabeticCipher instance with a key
  PolyAlphabeticCipher cipher("KEYWORD");

  // Define a list of plain texts to test
  std::string plaintexts[] = {
      "Hello, World!",
      "PolyAlphabetic Cipher!",
      "This is a test.",
      "C++ Encryption!"
  };

  // Test encryption and decryption for each plaintext
  for (const auto &plain : plaintexts) {
    std::string encrypted = cipher.encrypt(plain);
    std::string decrypted = cipher.decrypt(encrypted);
    
    std::cout << "Plaintext: " << plain << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl << std::endl;
  }

  return 0;
}