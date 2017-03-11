#pragma once

#include"BigInt.h"

BigInt::BigInt(string _number)
{
	digitsNumberInBase = 1;
	int i = 0;
	number = ConvertFromDecToBasic(ConvertToDec(_number, i));
	Trim(number);
}

vll BigInt::ConvertToDec(string number, int i)
{
	vll result;
	for (; i < number.size(); i++)
	{
		int x = (int)number[i] - '0';
		result.push_back(x);
	}
	reverse(result.begin(), result.end());
	return result;
}

pair <vll, ll> BigInt::DecDivBase(vll number)
{
	vll result;
	
	ll num = 0;
 	ll rem = 0;
	ll digit;
	for (int k = number.size() - 1;k >= 0; k--)
	{
		num *= 10;
		num += number[k];
		while (num < base)
		{
			if (k - 1 >= 0)
			{
				k--;
				num *= 10;
				num += number[k];
				result.push_back(0);
			}
			else break;
		}
		if (num < base)
		{
			if(k==0 && number[k]==num)result.push_back(0);
			reverse(result.begin(), result.end());
			pair <vll, ll> pair(result, num);
			return pair;
		}
		digit = num / base;
		rem = num % base;
		result.push_back(digit);
		num -= (digit*base);
	}
	reverse(result.begin(), result.end());
	pair <vll, ll> pair(result, num);
	return pair;
}

vll BigInt::ConvertFromDecToBasic(vll number)
{
	vll res, result;
	vll num = number;
	while (true)
	{
		pair <vll, ll> pair = DecDivBase(num);
		res.push_back(pair.second);
		num = pair.first;
		if (LessThanBase(num))
		{
			res.push_back(ConvertToDec(num));
			break;
		}
	}
	
	return res;
}

bool BigInt::LessThanBase(vll num)
{
	num = Trim(num);
	return num.size()<= digitsNumberInBase && ConvertToDec(num) < base;
}

ll BigInt::ConvertToDec(vll number)
{
	ll num = 0;
	ll deg = 1;
	for (int i = 0; i < number.size(); i++)
	{
		num += number[i] * deg;
		deg += 10;
	}
	return num;
}

vll BigInt::MultDec(vll vect, ll num)
{
	vll res;
	ll temp = 0;
	ll base = 10;
	for (int i = 0; i < vect.size(); i++)
	{
		temp = vect[i] * num + temp;
		if (temp < base)
		{
			res.push_back(temp);
			temp = 0;
		}
		else
		{
			res.push_back(temp%base);
			temp = temp / base;
		}
	}
	while (temp!=0)
		if (temp < base)
		{
			res.push_back(temp);
			temp = 0;
		}
		else
		{
			res.push_back(temp%base);
			temp = temp / base;
		}
	return res;
}

vll BigInt:: ConvertBaseToDec()
{
	vll result;
	result.push_back(0);
	BigInt arg = *this;
	int dec = 10;
	vll powBase;
	powBase.push_back(1);
	vll temp;
	temp.push_back(0);
	for (int i = 0; i < arg.number.size(); i++)
	{
		temp = MultDec(powBase, number[i]);
		powBase = MultDec(powBase, base);
		result = Plus(result, temp, 10);
	}
	return result;
}

string BigInt::ConvertBaseToDecString(){
	string result;
	BigInt arg = *this;
	vll r = arg.ConvertBaseToDec();
	for (int i = r.size() - 1; i >= 0; i--){
		result += to_string(r[i]);
	} 
	return result;
}
vll BigInt::Trim(vll res)
{
	for (int i = res.size() - 1; i>0 && res[i] == 0; i--)
	{
		res.pop_back();
	}
	return res;
}

void BigInt::trim()
{
	number = Trim(number);
}