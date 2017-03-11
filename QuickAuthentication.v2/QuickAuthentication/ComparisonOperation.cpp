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
	if (frst.number.size() == 0 && scnd.number.size() == 0) return false;
	if (frst.sign == '-')
	{
		if (scnd.sign == frst.sign)
		{
			if (scnd.number.size() > frst.number.size()) return false;
			if (scnd.number.size() < frst.number.size()) return true;
			for (int i = scnd.number.size()-1; i >=0; i--)
			{
				if (frst.number[i] > scnd.number[i]) return true;
				if (frst.number[i] < scnd.number[i]) return false;
			}
		}
		else return true;
	}
	else
	{
		if (scnd.sign == frst.sign)
		{
			if (scnd.number.size() > frst.number.size()) return true;
			if (scnd.number.size() < frst.number.size()) return false;
			for (int i = scnd.number.size()-1; i >= 0; i--)
			{
				if (frst.number[i] < scnd.number[i]) return true;
				if (frst.number[i] > scnd.number[i]) return false;
			}
		}
		else return false;
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
