package key

import (
	"fmt"
	"log"
	"time"

	"github.com/toastsandwich/rsa/math"
)

type PrivateKey struct {
	d int //modulo inverse of e
	n int // p * q
}

func GeneratePrivateKey(p PublicKey) (PrivateKey, error) {
	log.Println("generating private key from give public key")
	now := time.Now()
	var d int
	var ok bool
	if d, ok = math.ModuloInverse(p.e, p.toientFunction); !ok {
		return PrivateKey{}, fmt.Errorf("modulo inverse not available")
	}
	log.Println("process took ", time.Since(now), " seconds")
	return PrivateKey{
		d: d,
		n: p.n,
	}, nil
}

func (p PrivateKey) String() string {
	return fmt.Sprintf("PrivateKey<d: %d, n: %d>", p.d, p.n)
}

func (p PrivateKey) Decrypt(data int) int {
	log.Println("decrypting data")
	now := time.Now()
	m := math.ModPow(data, p.d, p.n)
	log.Println("process took ", time.Since(now), " seconds")
	return m
}
