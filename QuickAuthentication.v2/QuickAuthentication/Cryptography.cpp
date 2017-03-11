#include"Cryptograpy.h"

BigInt Cryptography::firstAlpha(BigInt j, BigInt u, BigInt v){
	BigInt fr = BigInt("0");
	BigInt p = PrimesGenerator::generatePrime(fr, v);
	BigInt c = (j * v) / p;
	c+=1;
	while (GCD(c, v) != 1){
		p = PrimesGenerator::generatePrime(fr, v);
		c = (j * v) / p + 1;
	}
	BigInt q = c*u + v;
	for (int i = 2; !PrimesGenerator::isPrime(q, 20); i++){
		q = c*u + v*i;
	}
	return p*q;
}

vector<BigInt> Cryptography::secondAlpha(BigInt v, BigInt c){
	BigInt fr = BigInt("0");
	BigInt p1 = PrimesGenerator::generatePrime(fr, v);
	BigInt q1 = PrimesGenerator::generatePrime(fr, v);
	BigInt p2 = PrimesGenerator::generatePrime(v*v, v*v * 2);
	BigInt r = inverseElement(c, v) * inverseElement(p2, v) * inverseElement(q1, v);
	BigInt q2 = r + v;
	for (int i = 2; !PrimesGenerator::isPrime(q2, 50); i++){
		q2 = r + v*i;
	}
	vector<BigInt> res;
	res.push_back(p1*q1);
	res.push_back(p2*q2);
	res.push_back(res[0] * res[1]);
	return res;
}
pair<BigInt, BigInt> Cryptography::firstBeta(BigInt n, BigInt j, BigInt u, BigInt v){
	BigInt n1 = n;
	BigInt l1 = BigInt("0");
	BigInt l2 = BigInt("0");
	for (int i = 1; n == n1 || n1%v != 0; i++){
		n1 -= u;
		l1 = i;
	}
	l2 = n1 / v;
	BigInt p = GCD(n, l1 + j*v);
	BigInt q = n / p;
	pair<BigInt, BigInt> pr(p, q);
	return pr;
}
pair<BigInt, BigInt> Cryptography::secondBeta(BigInt n1, BigInt N, BigInt v, BigInt c){
	pair<BigInt, BigInt> res;
	res.first = ((c%v)*(N%v)) % v;
	res.second = n1 / res.first;
	return res;
}


BigInt Cryptography::euclid(BigInt a, BigInt b, BigInt &x, BigInt &y){
	if (b == BigInt("0")){
		x = 1;
		y = 0;
		return a;
	}
	BigInt x1 = BigInt();
	BigInt y1 = BigInt();
	BigInt d = BigInt(euclid(b, a%b, x1, y1));
	x = y1;
	y = x1 - (a / b)*y1;
	return d;
}

BigInt Cryptography::GCD(BigInt a, BigInt b){
	if (b == 0) return a;
	else return GCD(b, a%b);
}

BigInt Cryptography::inverseElement(BigInt a, BigInt n){
	BigInt x = BigInt();
	BigInt y = BigInt();
	BigInt d = BigInt(euclid(a, n, x, y));
	BigInt r = BigInt("-1");
	if (d != 1) return r;
	x = (x%n + n) % n;
	return x;
}

