#include <cctype>
#include <iostream>
#include <map>
#include <string>

class MonoAlphabeticCipher {
public:
  MonoAlphabeticCipher(const std::string&);
  const std::string encrypt(const std::string&);
  const std::string decrypt(const std::string&);
private:
  std::map<char, char> encryption_map;
  std::map<char, char> decryption_map;
  const char get_encryption_char(const char ch) {
    return encryption_map[ch];
  }
  const char get_decryption_char(const char ch) {
    return decryption_map[ch];
  }
};

MonoAlphabeticCipher::MonoAlphabeticCipher(const std::string &key) {
  for (int i = 0; i < 26; i++) {
    encryption_map['a' + i] = std::tolower(key[i]);
    decryption_map[std::tolower(key[i])] = 'a' + i;
  }
}

const std::string MonoAlphabeticCipher::encrypt(const std::string &plain) {
  std::string cipher = "";
  for (char c: plain) {
    if (std::isalpha(c)) {
      const char ch = get_encryption_char(std::tolower(c));
      cipher += (std::isupper(c) ? std::toupper(ch) : ch);
    } else {
      cipher += c;
    }
  } 
  return cipher;
}

const std::string MonoAlphabeticCipher::decrypt(const std::string &cipher) {
  std::string plain = "";
  for (char c: cipher) {
    if (std::isalpha(c)) {
      const char ch = get_decryption_char(std::tolower(c));
      plain += (std::isupper(c) ? std::toupper(ch) : ch);
    } else {
      plain += c;
    }
  }
  return plain;
}

int main() {
  const std::string key = "QAZWSXEDCRFVTGBYHNUJMIKOLP";
  const std::string plain = "sample_text_is_heRe";
  MonoAlphabeticCipher mc(key);
  const std::string cipher = mc.encrypt(plain);
  const std::string message = mc.decrypt(cipher);
  std::cout << "original: " << plain << std::endl;
  std::cout << "encrypt: " << cipher << std::endl;
  std::cout << "decrypt: " << message << std::endl;
  return 0;
}
