#include"BigInt.h"

BigInt BigInt::operator <<(int a)
{
	if (a <= 0) return *this;
	BigInt res;
	trim();
	res.number.resize(a + this->number.size());
	int i = this->number.size() + a;
	while (i > a)
	{
		res.number[i - 1] = this->number[i - a - 1];
		--i;
	}

	while (i > 0)
	{
		res.number[i - 1] = 0;
		--i;
	}

	return res;
}

BigInt BigInt::operator >>(int a)
{
	if (a <= 0)
		return *this;
	if (a>number.size())
		return BigInt("0");
	BigInt res;
	res.number.resize(number.size() - a);
	for (int i = 0; i < number.size() - a; i++)
		res.number[i] = number[i + a];
	res.trim();
	return res;
}

void BigInt::operator <<=(int a){
	*this = *this << a;
}

void BigInt::operator >>=(int a){
	*this = *this >> a;
}

