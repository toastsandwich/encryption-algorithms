#include "helper.h"

using namespace key;

PublicKey::PublicKey(const unsigned long long p, const unsigned long long q) {
  this->n = p * q;
  this->tf = (p - 1) * (q - 1);
  this->e = math::coprime(tf);
}

const unsigned long long PublicKey::Encrypt(const unsigned long long m) {
  return math::pow(m, e, n) % n;
}

const unsigned long long PublicKey::get_n() {
  return this->n;
}

const unsigned long long PublicKey::get_e() {
  return this->e;
}

const unsigned long long PublicKey::get_tf() {
  return this->tf;
}
