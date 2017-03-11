#include"BigInt.h"

BigInt BigInt::operator+(ll arg)
{
	BigInt argB;
	argB = arg;
	BigInt res;
	res = *this + argB;
	return res;
}

BigInt BigInt::operator-(ll arg)
{
	BigInt argB;
	argB = arg;
	BigInt res;

	res = *this - argB;
	return res;

}
BigInt BigInt::operator*(ll arg)
{
	BigInt argB;
	argB = arg;
	BigInt res;

	res = *this * argB;
	return res;
}
BigInt BigInt::operator/(ll arg)
{
	BigInt res;
	res = *this;
	if (arg < 0)
		res.sign = res.sign == '+' ? '-': '+', arg = -arg;
	for (int i = (int)res.number.size() - 1, rem = 0; i >= 0; --i) {
		long long cur = res.number[i] + rem * base;
		res.number[i] = (int)(cur / arg);
		rem = (int)(cur % arg);
	}
	Trim(res.number);

	return res;
}

ll BigInt::operator%(ll arg)
{
	if (arg < 0)
		arg = -arg;
	int m = 0;
	for (int i = number.size() - 1; i >= 0; --i)
		m = (number[i] + m * (long long)base) % arg;
	return m;
}

void BigInt::operator%=(ll arg)
{
	BigInt argB;
	argB = arg;
	*this = *this % argB;
}

void BigInt::operator+=(ll arg)
{
	BigInt argB = BigInt();
	argB = arg;
	*this = *this + argB;

}
void BigInt::operator-=(ll arg)
{
	BigInt argB;
	argB = arg;
	*this = *this - argB;

}

void BigInt::operator*=(ll arg)
{
	BigInt argB;
	argB = arg;
	*this = *this * argB;
}

void BigInt::operator/=(ll arg)
{
	BigInt argB;
	argB = arg;
	*this = *this / argB;
}

void BigInt::operator=(ll value)
{
	number.clear();
	sign = '+';
	if (value < 0)
	{
		sign = '-';
		value = -value;
	}
	for (; value>0; value = value / base)
	{
		number.push_back(value%base);
		if (value == 1){
			break;
		}
	}
	if (value == 0){
		number.push_back(0);
	}
}