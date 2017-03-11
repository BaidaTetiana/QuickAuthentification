#include"Cryptograpy.h"

int main()
{
	srand(time(NULL));
	//
	BigInt c = BigInt("1301077");
	cout << PrimesGenerator::isPrime(c, 50);
	c.numberInDec = c.ConvertBaseToDec();
	c.printDec();
	system("pause");
	return 0;
}