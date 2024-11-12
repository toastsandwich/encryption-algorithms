package key

import (
	"fmt"
	"log"
	"time"

	"github.com/toastsandwich/rsa/math"
)

type PublicKey struct {
	n              int //
	toientFunction int // euler toient function
	e              int // modulus of encryption
}

func NewPublicKey(p, q int) PublicKey {
	log.Println("generating public key")
	now := time.Now()
	tf := (p - 1) * (q - 1)
	log.Println("process took ", time.Since(now), " seconds")
	return PublicKey{
		n:              p * q,
		toientFunction: tf,
		e:              (math.OtherCoPrime(tf)),
	}
}

func (p PublicKey) String() string {
	return fmt.Sprintf("PublicKey<e: %d, n: %d>", p.e, p.n)
}

func (p PublicKey) Encrypt(data int) int {
	log.Println("encrypting data")
	now := time.Now()
	m := math.ModPow(data, p.e, p.n)
	log.Println("process took ", time.Since(now), " seconds")
	return m
}
