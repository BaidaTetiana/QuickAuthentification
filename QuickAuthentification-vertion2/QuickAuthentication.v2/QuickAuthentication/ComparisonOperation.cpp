#include"BigInt.h"

bool BigInt::operator==(const BigInt& arg0) const
{
	return !(*this < arg0) && !(arg0 < *this);
}

bool BigInt::operator <(const BigInt& arg0) const
{
	BigInt frst = *this;
	BigInt scnd = arg0;
	frst.trim();
	scnd.trim();
	if (frst.sign<scnd.sign) return true;
	if (frst.sign>scnd.sign) return false;
	if (frst.sign == -1 && scnd.sign == -1){
		if (frst.number.size() < scnd.number.size()) return false;
		if (frst.number.size() > scnd.number.size()) return true;
		for (int i = frst.number.size() - 1; i >= 0; i--){
			if (frst.number[i] < scnd.number[i]) return false;
			if (frst.number[i] > scnd.number[i]) return true;
		}
	}
	if (frst.sign == 1 && scnd.sign == 1){
		if (frst.number.size() < scnd.number.size()) return true;
		if (frst.number.size() > scnd.number.size()) return false;
		for (int i = frst.number.size() - 1; i >= 0; i--){
			if (frst.number[i] < scnd.number[i]) return true;
			if (frst.number[i] > scnd.number[i]) return false;
		}
	}
	return false;
}

bool BigInt::operator >(const BigInt& arg0) const
{
	return arg0 < *this;
}

bool BigInt:: operator!=(const BigInt& arg0) const
{
	return !(*this == arg0);
}

bool BigInt::operator<= (const BigInt& arg0) const
{
	return !(arg0 < *this);
}

bool BigInt::operator>= (const BigInt& arg0) const
{
	return !(arg0 > *this);
}