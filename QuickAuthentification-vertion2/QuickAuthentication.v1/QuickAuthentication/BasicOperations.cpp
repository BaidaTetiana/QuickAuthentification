#include"BigInt.h"

BigInt BigInt:: operator +(const BigInt& arg)
{
	BigInt frst = *this;
	BigInt scnd = arg;
	frst.trim();
	scnd.trim();
	BigInt result = BigInt(Plus(frst.number, scnd.number, base));
	return result;
}

BigInt BigInt:: operator -(const BigInt& arg)
{
	BigInt result = BigInt();
	BigInt frst = *this;
	BigInt scnd = arg;
	frst.trim();
	scnd.trim();
	result.number = Minus(frst.number, scnd.number, base);
	return result;

}

BigInt BigInt:: operator *(const BigInt& arg0)
{
	BigInt result = BigInt();
	BigInt frst = *this;
	BigInt scnd = arg0;
	frst.trim();
	scnd.trim();
	//result.number = Mult(frst.number, scnd.number, base);
	result = result.Shtrassen(frst, scnd);
	return result;
}

pair<BigInt, BigInt> DivMod(BigInt &frst, BigInt &scnd)
{
	frst.trim();
	scnd.trim();
	int norm = scnd.base / (scnd.number.back() + 1);
	//frst.Abs();
	//scnd.Abs();
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
	q.trim();
	r.trim();
	r = const_cast<BigInt&>(frst)-(q*scnd);
	return make_pair(q, r / norm);
}
BigInt BigInt::operator /(const BigInt & arg0)
{
	BigInt frst = *this;
	BigInt scnd = arg0;
	frst.trim();
	scnd.trim();
	BigInt result = BigInt();
	result = DivMod(frst, scnd).first;
	return result;

}

BigInt BigInt::operator%(const BigInt& arg0)
{
	BigInt result = BigInt();
	BigInt frst = *this;
	BigInt scnd = arg0;
	frst.trim();
	scnd.trim();
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
	digitsNumberInBase = 1;
	number.resize(arg.number.size());
	for (int i = 0; i <(int)arg.number.size(); i++)
		number[i] = arg.number[i];
	Trim(number);
}