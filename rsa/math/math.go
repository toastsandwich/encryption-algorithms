package math

import (
	"log"
	"time"
)

func gcd(a, b int) int {
	log.Println("called function for getting the gcd for ", a, " ", b)
	now := time.Now()
	for b != 0 {
		a, b = b, a%b
	}
	log.Println("process took ", time.Since(now), " seconds")
	return a
}

func OtherCoPrime(a int) int {
	log.Println("called function for getting the other co prime for ", a)
	now := time.Now()
	for i := (2); i < a; i++ {
		if gcd(a, i) == 1 {
			log.Println("process took ", time.Since(now), " seconds")
			return i
		}
	}
	log.Println("process took ", time.Since(now), " seconds")
	return -1
}

func ModPow(x, n, m int) int {
	log.Println("called function for modPow")
	now := time.Now()
	x = x % m
	var res int = 1
	for n > 0 {
		if n%2 == 1 {
			res = (res * x) % m
		}
		x = (x * x) % m
		n = n / 2
	}
	log.Println("process took ", time.Since(now), " seconds")
	return res
}

func ModuloInverse(a, m int) (int, bool) {
	log.Println("called modulo inverse")
	now := time.Now()
	if gcd(a, m) > 1 {
		log.Println("process took ", time.Since(now), " seconds")
		return 0, false
	}
	for i := (1); i < m; i++ {
		if (a*i)%m == 1 {
			log.Println("process took ", time.Since(now), " seconds")
			return i, true
		}
	}
	log.Println("process took ", time.Since(now), " seconds")
	return -1, false
}
