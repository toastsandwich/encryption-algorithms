#include "helper.h"

using namespace key;

PrivateKey::PrivateKey(PublicKey *pub): public_key(pub), n(pub->get_n()) {
  this->d = math::mod_inverse(pub->get_e(), pub->get_tf());

}

const unsigned long long PrivateKey::Decrypt(const unsigned long long c) {
  return math::pow(c, d, n) % n;
}