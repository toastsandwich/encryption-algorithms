#include "helper.h"

unsigned long long math::gcd(unsigned long long p, unsigned long long q) {
  while(q > 0) {
    // a, b = b, a % b;
    auto t = q;
    q = p % q;
    p = t;
  }
  return p;
}

unsigned long long math::coprime(unsigned long long n) {
  unsigned long long i = 2;
  for (; i < n; i++) {
    if (gcd(n, i) == 1) {
      return i; //other co prime
    }
  }
  return 0; // no co prime is found
}

unsigned long long math::pow(unsigned long long x, unsigned long long n, unsigned long long m) {
  x = x % m;
  unsigned long long result = 1;
  while (n > 0) {
    if (n & 1 == 1) {
      result = (result * x) % m;
    }
    x = (x * x) % m;
    n /= 2;
  }
  return result;
}

unsigned long long math::mod_inverse(unsigned long long a, unsigned long long m) {
  // check if the gcd(a, m) == 1 then only mod inv exists
  if (gcd(a, m) > 1) {
    return 0; // mod inv not posible
  }

  unsigned long long i = 1;
  for (; i < m; i++) {
    if((a * i) % m == 1) {
      return i;
    } 
  }

  return 0;
}