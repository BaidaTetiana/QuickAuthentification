#pragma once

#include"BigInt.h"

class PrimesGenerator{
	static vector<int> primes;
	static vector<BigInt> Primes;
	static vector<int> eratosphen();
public:
	static bool hasSmallPrimes(BigInt N);
	static bool MillerRabinTest(BigInt N, int t);
	static BigInt generatePrime(BigInt from, BigInt to);
	static void writePrimesToFile();
	static bool isPrime(BigInt n, int t);
	static string generateNumber(BigInt from, BigInt to);
	static int toInt(char a);
	static char toChar(int a);
};