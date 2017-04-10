#include"BigInt.h"




vll BigInt:: Plus(vll frst, vll scnd, ll base)
{
	vll result;
	if (frst.size() == 0) return Trim(scnd);
	if (scnd.size() == 0) return Trim(frst);
	result.resize(max(frst.size(), scnd.size()));
	ll temp = 0;
	int i = 0, j = 0;
	for (; i <frst.size() && j <scnd.size(); i++, j++)
	{
		temp = temp + frst[i] + scnd[j];
		result[i] = temp%base;
		temp /= base;
	}
	while (i <frst.size())
	{
		temp = temp + frst[i];
		result[i] = temp%base;
		temp /= base;
		i++;
	}
	while ( j <scnd.size())
	{
		temp = temp + scnd[j];
		result[j] = temp%base;
		temp /= base;
		j++;
	}
	while (temp != 0)
	{
		result.push_back(temp%base);
		temp /= base;
	}
	return Trim(result);
}

vll BigInt::Minus(vll frst, vll scnd, ll base)
{
	vll result; 
	if (frst.size() == 0) return Trim(scnd);
	if (scnd.size() == 0) return Trim(frst);
	result.resize(max(frst.size(), scnd.size()));
	int i = 0, j=0;
	ll temp = 0;
	for (; i <frst.size() && j< scnd.size(); i++, j++)
	{
		temp = frst[i] - scnd[j] - temp;
		if (temp < 0)
		{
			result[i] = temp + base;
			temp = 1;
		}
		else
		{
			result[i] = temp;
			temp = 0;
		}

	}
	while (i < frst.size())
	{
		temp = frst[i] - temp;
		if (temp < 0)
		{
			result[i] = temp + base;
			temp = 1;
		}
		else
		{
			result[i] = temp;
			temp = 0;
		}
		i++;
	}
	return Trim(result);
}

vll BigInt::Mult(vll frst, vll scnd, ll base)
{
	vll result1;
	vll result; 

	ll size = frst.size() + scnd.size() + 10;
	result.resize(size);
	for (int i = 0; i < (int)frst.size(); i++)
	{
		ll r = 0;
		for (int j = 0; j < (int)scnd.size(); j++)
		{
			result[i + j] += frst[i] * scnd[j];
		}
	}
	ll r = 0;
	for (int i = 0; i<result.size(); i++)
	{
		if (result[i] >= base)
		{
			r = result[i] / base;
			result[i] -= base * r;
			result[i + 1] += r;
		}
	}
	
	return Trim(result);
}

