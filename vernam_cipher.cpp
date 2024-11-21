#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class VernamCipher {
  private:
  const std::string key;
  const int len;
  const std::string make_it_see(const char c) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << std::hex << (0xFF & c) << " ";
    return ss.str();
  }

  public:
  VernamCipher(const std::string &key) : key(key), len(key.length()){};
  const std::string encrypt(const std::string &);
  const std::string decrypt(const std::string &);
  const std::string see(const std::string &);
};

const std::string VernamCipher::encrypt(const std::string &plain) {
  std::string cipher = "";
  int idx = 0;

  for(const char &c: plain) {
    cipher.push_back(static_cast<char>(c ^ key[idx]));
    idx = (idx + 1) % len;
  }
  return cipher;
}

const std::string VernamCipher::decrypt(const std::string &cipher) {
  std::string plain = "";
  int idx = 0;

  for(const char &c: cipher) {
    plain.push_back(static_cast<char>(c ^ key[idx]));
    idx = (idx + 1) % len;
  }
  return plain;
}

const std::string VernamCipher::see(const std::string &whatisit) {
  std::string str = "";
  
  for (const char &c: whatisit) {
    str += make_it_see(c);
  }

  return str;
}

int main(const int argc, const char *argv[]) {
  if (argc != 3) {
    std::cout << "usage vc <key> <plain>" << std::endl;
    return 1;
  }

  const std::string key = argv[1];
  const std::string plain = argv[2];

  VernamCipher vc(key);
  const std::string cipher = vc.encrypt(plain);

  std::cout << "cipher text: " << vc.see(cipher) << std::endl;

  std::cout << "test "
            << (plain == vc.decrypt(cipher) ? "pass" : "fail")
            << std::endl;
}