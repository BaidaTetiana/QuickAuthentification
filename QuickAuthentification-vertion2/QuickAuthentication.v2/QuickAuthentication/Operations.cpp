#include"BigInt.h"
#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

void BigInt:: Abs() 
{
	sign = 1;

}

BigInt BigInt::PowModN(BigInt a, BigInt k, BigInt n)
{
	BigInt A = a, b = BigInt("1");

	if (k == 0) return b;
	if (k.number[0] == 1) b = a;


	for (ll i = 1; i < k.number.size(); i++) {
		A = A * A % n;
		if (k.number[i]) b = A*b % n;
	}

	return b;
}


BigInt BigInt::PowN(BigInt a, BigInt N)
{
	if (N.number.size() == 1 && N.number[0] == 0)
	{
		BigInt b = BigInt();
		b.number.push_back(1);
		return b;
	}
	if (N % 2 == 1)
		return PowN(a, N - 1)* a;
	else {
		BigInt b = PowN(a, N / 2);
		return b*b;
	}
}

BigInt BigInt::Shtrassen(BigInt a, BigInt b)
{
	ll start = clock();
	BigInt res = BigInt("0");
	ll two = 2;
	//int size = max(a.number.size(), b.number.size());
	while (two < a.number.size())
		two = two * 2;
	while (a.number.size() < two)
		a.number.push_back(0);
	two = 2;
	while (two < b.number.size())
		two = two * 2;
	while (b.number.size() < two)
		b.number.push_back(0);
	fft_multiply(a.number, b.number, res.number);
	ll carry = 0;
	for (int i = 0; i < res.number.size(); i++)
	{
		res.number[i] += carry;
		carry = res.number[i] / base;
		res.number[i] -= carry*base;
	}
	res.trim();

	ll finish = clock();
	return res;

}



void BigInt::fft(vc &a, bool invert)
{
	int n = (int)a.size();
	if (n == 1)  return;

	vc a0(n / 2), a1(n / 2);
	for (int i = 0, j = 0; i<n; i += 2, ++j)
	{
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	double ang = 2 * M_PI / n * (invert ? -1 : 1);
	complex<double> w(1), wn(cos(ang), sin(ang));
	for (int i = 0; i<n / 2; ++i)
	{
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert)
		{
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

void BigInt::fft_multiply(const vector<ll> a, const vector<ll>  b, vector<ll>  &res) {
	vc fa(a.begin(), a.end()), fb(b.begin(), b.end());
	ll n = 1;
	while (n < max(a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n); fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (ll i = 0; i<n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	for (ll i = 0; i<n; ++i)
		res[i] = (ll)(fa[i].real() + 0.5);
}

BigInt BigInt::BitPowN(BigInt a, BigInt N){
	BigInt result = BigInt("1");
	while (N > 0){
		if (N % 2 != 0){
			result*= a;
			N-=1;//N--;
		}
		else
		{
			a *= a;
			N >>= 1;
		}
	}
	return result;
}
BigInt BigInt::BitPowModN(BigInt a, BigInt b, BigInt N){
	BigInt result = BigInt("1");
	while (b > 0){
		if (b % 2 != 0){
			result = ((result%N)*(a%N)) % N;
			b -= 1;// b--;
		}
		else
		{
			a = ((a%N)*(a%N)) % N;
			b >>= 1;
		}
	}
	return result;
}