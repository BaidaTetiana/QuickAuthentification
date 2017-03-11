#pragma once
#include"Defines.h"
// jfiughaer;ogiureoiguqwo;iqgu4[o8ug

class BigInt
{
public:
	BigInt(){
		digitsNumberInBase = 1;
		sign = '+';
	};
	BigInt(string number);
	BigInt(vll num)
	{
		digitsNumberInBase = 1;
		sign = '+';
		number = num;
	}
	~BigInt(){};

	void print()
	{
		for (int i = number.size()-1; i >= 0; i--)
		{
			cout << number[i];
		}
		cout << endl;
	}
	void printDec()
	{
		for (int i = numberInDec.size() - 1; i >= 0; i--)
		{
			cout << numberInDec[i];
		}
		cout << endl;
	}

	//Convertation help function
	pair <vll, ll> DecDivBase(vll number);
	vll ConvertToDec(string number, int i);
	vll ConvertFromDecToBasic(vll number);
	bool LessThanBase(vll number);
	ll ConvertToDec(vll number);
	vll MultDec(vll vect, ll num);
	vll ConvertBaseToDec();
	string ConvertBaseToDecString();
	static vll Trim(vll result);
	void trim();
	static void  fft(vc &a, bool invert);
	static void fft_multiply(const vector<ll>  a, const vector<ll>  b, vector<ll>  &res);
	//


	// basic operations 
	BigInt operator +(const BigInt&);
	BigInt operator -(const BigInt&);
	BigInt operator *(const BigInt&);
	BigInt operator /(const BigInt&);
	BigInt operator %(const BigInt&);
	void operator=(const BigInt& arg);
	void operator +=(const BigInt&);
	void operator -=(const BigInt&);
	void operator *= (const BigInt&);
	void operator /= (const BigInt&);
	void operator %= (const BigInt&);
	void operator ++();
	void operator --();
	void Abs();
	static BigInt PowModN(BigInt a, BigInt k, BigInt n);
	BigInt PowN(BigInt a, BigInt N);
	static BigInt BitPowN(BigInt a, BigInt N);
	static BigInt BitPowModN(BigInt a, BigInt b, BigInt N);
	static BigInt Shtrassen(BigInt a, BigInt b);
	BigInt operator <<(int a);
	BigInt operator >>(int a);
	void operator <<=(int a);
	void operator >>=(int a);
	//

	//comparison operation
	bool operator >(const BigInt&) const;
	bool operator >=(const BigInt&) const;
	bool operator <(const BigInt&) const;
	bool operator <=(const BigInt&) const;
	bool operator ==(const BigInt&)const;
	bool operator !=(const BigInt&)const;
	//

	//Operations with small numbers
	BigInt operator+(ll arg);
	BigInt operator-(ll arg);
	BigInt operator*(ll arg);
	BigInt operator/(ll arg);
	ll operator%(ll arg);
	void operator+=(ll arg);
	void operator-=(ll arg);
	void operator*=(ll arg);
	void operator/=(ll arg);
	void operator%=(ll arg);
	void operator=(ll value);

	//

	// Comparation operations with small numbers
	bool operator >(ll a) const;
	bool operator >=(ll a) const;
	bool operator <(ll a) const;
	bool operator <=(ll a) const;
	bool operator ==(ll a) const;
	bool operator !=(ll a) const;
	//
	vll numberInDec;
	
private:
	
	static const int base = 2;
	int digitsNumberInBase ;
	char sign;
	vll number;

	static vll Plus(vll frst, vll scnd, ll base);
	static vll Minus(vll frst, vll scnd, ll base);
	static vll Mult(vll frst, vll scnd, ll base);
	
	friend pair<BigInt, BigInt> DivMod( BigInt &arg1,  BigInt &arg2);

};



