#include"BigInt.h"

BigInt BigInt:: operator +(const BigInt& arg)
{
	BigInt frst = *this;
	BigInt scnd = arg;
	if (frst.sign != scnd.sign)
	{
		if (frst.sign == '-')
		{
			frst.Abs();
			return scnd - frst;

		}
		else
		{
			scnd.Abs();
			return frst - scnd;
		}
	}
	BigInt result = BigInt(Plus(frst.number, scnd.number, base));
	if (frst.sign == '-') result.sign = '-';
	return result;
}

BigInt BigInt:: operator -(const BigInt& arg)
{
	BigInt result = BigInt();
	BigInt frst1 = *this;
	BigInt scnd1 = arg;
	if (frst1.sign != scnd1.sign)
	{
		if (frst1.sign == '-')
		{
			BigInt scnd2 = scnd1;
			scnd2.sign = '-';
			return frst1 + scnd2;
		}
		else
		{
			BigInt scnd2 = scnd1;
			scnd2.sign = '+';
			return frst1 + scnd1;
		}
	}
	if (frst1.sign == '-')
	{
		BigInt scnd2 = scnd1;
		BigInt frst2 = frst1;
		scnd2.sign = '+';
		frst2.sign = '+';
		return scnd2 - frst2;
	}
	BigInt frst, scnd;
	if (frst1 < scnd1){
		frst = scnd1;
		scnd = frst1;
		result.sign = '-';
	}
	else
	{
		frst = frst1;
		scnd = scnd1;
		result.sign = '+';
	}
	result.number = Minus(frst.number, scnd.number, base);
	return result;

}

BigInt BigInt:: operator *(const BigInt& arg0)
{
	BigInt result = BigInt();
	BigInt frst = *this;
	BigInt scnd = arg0;
	if (frst.sign != scnd.sign) result.sign = '-';
	if (frst.sign == '-') result.sign = '+';
	//result.number = Mult(frst.number, scnd.number, base);
	result = result.Shtrassen(frst, scnd);
	return result;
}

pair<BigInt, BigInt> DivMod(BigInt &frst, BigInt &scnd)
{
	int norm = scnd.base / (scnd.number.back() + 1);
	frst.Abs();
	scnd.Abs();
	BigInt a = frst*norm;
	BigInt b = scnd*norm;

	BigInt q, r;
	q.number.resize(a.number.size());
	r.number.resize(a.number.size());

	for (int i = a.number.size() - 1; i >= 0; i--)
	{
		r *= a.base;
		r += a.number[i];

		ll s1 = r.number.size() <= b.number.size() ? 0 : r.number[b.number.size()];
		ll s2 = r.number.size() <= b.number.size() - 1 ? 0 : r.number[b.number.size() - 1];

		ll d = (a.base * s1 + s2) / b.number.back();
		r = r - b*d;
		while (r < 0)
		{
			r = r + b;
			d--;
		}
		q.number[i] = d;
	}
	/*q.sign = frst.sign * scnd.sign;
	r.sign = frst.sign;*/
	q.trim();
	r.trim();
	r = const_cast<BigInt&>(frst)-(q*scnd);
	return make_pair(q, r / norm);
}
BigInt BigInt::operator /(const BigInt & arg0)
{

	BigInt frst = *this;
	BigInt scnd = arg0;

	BigInt result = BigInt();

	if (frst.sign != scnd.sign) result.sign = '-';
	if (frst.sign == '-') result.sign = '+';
	result = DivMod(frst, scnd).first;

	return result;

}

BigInt BigInt::operator%(const BigInt& arg0)
{
	BigInt result = BigInt();
	BigInt frst = *this;
	BigInt scnd = arg0;
	if (frst.sign != scnd.sign) result.sign = '-';
	if (frst.sign == '-') result.sign = '+';

	result = DivMod(frst, scnd).second;

	return result;
}

void BigInt::operator +=(const BigInt& arg0){
	*this  = *this + arg0;
}
void BigInt::operator -=(const BigInt& arg0){
	*this  = *this - arg0;
}

void BigInt::operator *= (const BigInt& arg0){
	*this  = *this * arg0;
}
void BigInt::operator /= (const BigInt& arg0){
	*this  = *this / arg0;
}
void BigInt::operator %= (const BigInt& arg0){
	*this  = *this % arg0;
}
void BigInt::operator ++(){
	*this  = *this + 1;
}
void BigInt::operator --(){
	*this  = *this - 1;
}

void BigInt::operator=(const BigInt& arg)
{
	sign = arg.sign;
	digitsNumberInBase = 1;
	number.resize(arg.number.size());
	for (int i = 0; i <(int)arg.number.size(); i++)
		number[i] = arg.number[i];
}