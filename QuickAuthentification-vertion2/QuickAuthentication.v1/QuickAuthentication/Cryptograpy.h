#pragma once

#include"PrimesGenerator.h"

class Cryptography{
public:
	static BigInt euclid(BigInt a, BigInt b, BigInt &x, BigInt &y);
	static BigInt GCD(BigInt a, BigInt b);
	static BigInt inverseElement(BigInt a, BigInt n);
	static BigInt firstAlpha(BigInt j, BigInt u, BigInt v);
	static vector<BigInt> secondAlpha(BigInt v, BigInt c);
	static pair<BigInt, BigInt> firstBeta(BigInt n, BigInt j, BigInt u, BigInt v);
	static pair<BigInt, BigInt> secondBeta(BigInt n1, BigInt N, BigInt v, BigInt c);
};

