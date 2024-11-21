#include <iostream>
#include <vector>

#include "helper.h"

int main(const int argc, const char *argv[]) {
  key::PublicKey pb(7, 1009);
  auto cipher = pb.Encrypt(9);
  std::cout << "cipher: " << cipher << std::endl;

  if (argc != 2) {
    std::cerr << "usage: rsa <message>" << std::endl;
    return 1;
  }

  const std::string message = argv[1];
  std::vector<unsigned long long> message_vec;

  for (const auto c: message) {
    auto m = static_cast<unsigned long long>(c);
    message_vec.push_back(m);
  }

  std::vector<unsigned long long> encrypted;
  for (const auto &m: message_vec) {
    const auto e = pb.Encrypt(m);
    encrypted.push_back(e);
  }

  for(const auto &e: encrypted) {
    std::cout << (e) << " ";
  } std::cout << std::endl;

  key::PrivateKey pk(&pb);
  auto mssg = pk.Decrypt(cipher);
  std::cout << "message: " << mssg << std::endl;
  
  std::vector<unsigned long long> plain;
  for (const auto &e: encrypted) { 
    const auto m = pk.Decrypt(e);
    plain.push_back(m);
  }

  for(const auto &e: plain) {
    std::cout << static_cast<char>(e);
  } std::cout << std::endl;

  return 0;
}
