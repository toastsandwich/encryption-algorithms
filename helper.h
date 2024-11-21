#pragma once

namespace key {
  class PublicKey {
    private:
    unsigned long long n;  // modulus of encryption
    unsigned long long e;
    unsigned long long tf; // torient function
    public:
    PublicKey(const unsigned long long, const unsigned long long);
    const unsigned long long Encrypt(const unsigned long long);
    const unsigned long long get_n();
    const unsigned long long get_e();
    const unsigned long long get_tf();
  };

  class PrivateKey {
    private:
    PublicKey *public_key;
    unsigned long long d;
    unsigned long long n;

    public:
    PrivateKey(PublicKey *);
    const unsigned long long Decrypt(const unsigned long long);
  };
}

namespace math {
  // to calculate pow with modulus
  unsigned long long pow(unsigned long long, unsigned long long, unsigned long long);
  // to calculate modular inverse
  unsigned long long mod_inverse(unsigned long long, unsigned long long);
  // to calculate gcd
  unsigned long long gcd(unsigned long long, unsigned long long);
  // calculate other co prime
  unsigned long long coprime(unsigned long long);
}