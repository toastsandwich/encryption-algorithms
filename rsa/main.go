package main

import (
	"fmt"
	"log"
	"time"

	"github.com/toastsandwich/rsa/key"
)

func main() {
	fmt.Println("starting process to encrypt and decrypt data")
	now := time.Now()
	pubKey := key.NewPublicKey(7, 101)
	fmt.Println(pubKey.String())
	data := 98
	fmt.Println("plain data:", data)
	cipher := pubKey.Encrypt(data)
	fmt.Println("cipher data:", cipher)

	pvtKey, err := key.GeneratePrivateKey(pubKey)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(pvtKey.String())
	plain := pvtKey.Decrypt(cipher)
	fmt.Println("plain:", plain)
	fmt.Println("total time taken", time.Since(now), "seconds")
}
