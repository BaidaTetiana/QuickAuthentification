#include"BigInt.h"

bool BigInt::operator >(ll a) const
{
	BigInt a1 = BigInt();
	a1 = a;
	return *this > a1;
}
bool BigInt::operator >=(ll a) const
{
	BigInt a1 = BigInt();
	a1 = a;
	return *this >= a1;
}
bool BigInt::operator <(ll a) const
{
	BigInt a1 = BigInt();
	a1 = a;
	return *this < a1;
}
bool BigInt::operator <=(ll a) const
{
	BigInt a1 = BigInt();
	a1 = a;
	return *this <= a1;
}
bool BigInt::operator ==(ll a)const
{
	BigInt a1 = BigInt();
	a1 = a;
	return *this == a1;
}
bool BigInt::operator !=(ll a)const
{
	BigInt a1 = BigInt();
	a1 = a;
	return *this != a1;
}
