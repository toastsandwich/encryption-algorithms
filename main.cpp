#include <iostream>

#include "helper.h"

int main() {
  key::PublicKey pb(7, 11);
  auto cipher = pb.Encrypt(9);
  std::cout << "cipher: " << cipher << std::endl;
  key::PrivateKey pk(&pb);
  auto message = pk.Decrypt(cipher);
  std::cout << "message: " << message << std::endl;
  return 0;
}