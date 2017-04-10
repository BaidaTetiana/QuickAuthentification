#include"PrimesGenerator.h"
vector<int> PrimesGenerator::primes;

bool PrimesGenerator::hasSmallPrimes(BigInt N){
	if (primes.size() == 0) primes = eratosphen();
	for (int i = 0; i < primes.size(); i++){
		if (N%primes[i] == 0) return false;
	}
	return true;
}

bool PrimesGenerator::MillerRabinTest(BigInt N, int t){
	if (N % 2 == 0) return false;
	BigInt r = BigInt();
	r = N - 1;
	BigInt s = BigInt("0");
	while (r % 2 == 0){
		r /= 2;
		s ++;
	}
	BigInt y = BigInt("0");
	while (t--){
		BigInt a = BigInt(to_string(rand()));
		y = BigInt::BitPowModN(a, r, N);
		if (y != 1 && y != N - 1){
			for (BigInt j = BigInt("1"); j < s-1 && y != N - 1; j++){
				y = (y*y) % N;
				if (y == 1) return false;
				if (y == N - 1) continue;
				return false;
			}
		}

	}
	return true;
}

BigInt PrimesGenerator::generatePrime(BigInt from, BigInt to){
	string st = generateNumber(from, to);
	BigInt rnd1 = BigInt(st);
	BigInt rnd2 = rnd1 +1;
	while (true){
		if (rnd1 >= from && isPrime(rnd1, 50)) return rnd1;
		if (rnd2 <= to && isPrime(rnd2, 50)) return rnd2;
		if(rnd1 >= from) rnd1--;
		if(rnd2 <= to) rnd2++;
	}
	return rnd1;
}

void PrimesGenerator::writePrimesToFile(){
	ofstream file("primes1.txt");
	if (!file){
		cout << "File doesn't exist!" << endl;
		return;
	}
	BigInt tw = BigInt("2");
	BigInt a = BigInt("512");
	BigInt b = BigInt("1024");
	BigInt from = BigInt::BitPowN(tw, b);
	BigInt to = BigInt::BitPowN(tw, a);
	int counter = 0;
	string r;
	for (BigInt i = from; i > to ; i--){
		if (isPrime(i, 50)) {
			r = i.ConvertBaseToDecString();
			file << r;
			file << endl;
			cout << r;
			cout << endl;
			counter++;
		}
	}
}

bool PrimesGenerator::isPrime(BigInt n, int t){
	return hasSmallPrimes(n) && MillerRabinTest(n, 50);
}

vector<int> PrimesGenerator::eratosphen(){
	int n = 1000;
	vector<char> prime(n + 1, true);
	vector<int>result;
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; ++i)
		if (prime[i])
			if (i * i <= n)
				for (int j = i*i; j <= n; j += i)
					prime[j] = false;
	for (int i = 2; i < prime.size(); i++){
		if (prime[i]) result.push_back(i);
	}
	return result;
}

string PrimesGenerator::generateNumber(BigInt from, BigInt to){
	from.trim();
	string fr = from.ConvertBaseToDecString();
	string t = to.ConvertBaseToDecString();
	string result;
	bool fl = false;
	int sz;
	if (fr == "0"){
		sz = rand() % 3;
		result.resize(t.size() - sz);
		for (int i = 0; i < result.size(); i++){
			if (t.size() != result.size()){
				if (i == 0) result[i] = toChar(rand() % 9) + 1;
				else result[i] = toChar(rand() % 10);
			}
			else{
				if (i == 0)	{
					result[i] = toChar(rand() % (toInt(t[i]) + 1));
					result[i] = result[i] == '0' ? '1' : result[i];
				}
				else{
					if (result[0] == t[0]) result[i] = toChar(rand() % (toInt(t[i]) + 1));
					else result[i] = toChar(rand() % 10);
				}
			}				
		}
	}
	else{
		if (fr.size() == t.size()) sz = 0;
		else sz = rand()%2;
		result.resize(t.size() - sz);
		for (int i = 0; i < result.size(); i++){
			if (sz == 1){
				result[i] = toChar(rand() % (10 - toInt(fr[i])) + toInt(fr[i]));
				if (i == 0) result[i] = result[i] == '0' ? '1' : result[i];
			}
			else{
				if (t[i] == fr[i]){
					result[i] = t[i];
					fl = true;
				}
				else{
					if (t.size() == fr.size()){
						if (fl == true || i == 0) result[i] = toChar(toInt(fr[i]) + rand() % (toInt(t[i]) - toInt(fr[i]) + 1));
						else result[i] = toChar(rand() % (10));
						fl = false;
					}
					else{
						result[i] = toChar(rand() % (toInt(t[i]) + 1));
						if (i == 0) result[i] = result[i] == '0' ? '1' : result[i];
					}
				}
				
			}
		}
	}
	return result;
}

int PrimesGenerator::toInt(char a){
	return a - '0';
}
char PrimesGenerator::toChar(int a){
	return (char)(a + '0');
}