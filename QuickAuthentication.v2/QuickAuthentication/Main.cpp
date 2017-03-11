#include"Cryptograpy.h"

int main()
{
	srand(time(NULL));
	srand(time(NULL));
	/*string jj = "105210379657361138989466928893745150396269988033039760961753225972023273228491164549281156649207216752204549219136901167725177556453912662058142288005671054431812031526333745941241103118883593132950837977460558470925209530308235671876619643871789959089510986685852991715237396845888829755249585646639660594458";
	string uu = "72734711677717782348541028931755378075660957186652180363275871006993345239116703277873458234166323835854992031373621017142798510016863271934918957662551399910363322615032924468965381288859762689622888921436653696267665436248767044182980436491946993852499695524171726796925721226178809455417368105678237612703";
	string vv = "50219471798820038251754885543767166452172886252605657626283595317064724846653639153136276235293776959710267529317111092765355663460884311433573366020744962116110635346240814481296675880769676913772395907648839792742890718841232599718847140476482458549571217926265659353999889687912029514241479415293808440929";*/
	string jj = "12327843054";
	string uu = "2132311123";
	string vv = "5667678811";

	BigInt j = BigInt(jj);
	BigInt u = BigInt(uu);
	BigInt v = BigInt(vv);

	BigInt h = BigInt("148985121611280691719542368512");
	BigInt h1 = h;
	for (int i = 1; h == h1 || j != 0; i++){
		h1 = h1 - u;
		h1.numberInDec = h1.ConvertBaseToDec();
		h1.printDec();
		j = h1%v;
		j.numberInDec = j.ConvertBaseToDec();
		j.printDec();
	}
	//BigInt n = Cryptography::firstAlpha(j, u, v);
	//n.numberInDec = n.ConvertBaseToDec();
	//n.printDec();

	//pair<BigInt, BigInt> pq = pair<BigInt, BigInt>();
	//pq = Cryptography::firstBeta(n, j, u, v);
	//pq.first.numberInDec = pq.first.ConvertBaseToDec();
	//pq.second.numberInDec = pq.second.ConvertBaseToDec();
	//
	//BigInt n1 = BigInt();
	//n1 = pq.first*pq.second;
	//n1.numberInDec = n1.ConvertBaseToDec();
	//pq.first.printDec();
	//pq.second.printDec();
	//n1.printDec();
	//if (n == n1) cout << "1" << endl;
	//else cout << "0" << endl;*/
	//BigInt a = BigInt("124");
	//BigInt b = BigInt("3");
	//BigInt n = BigInt("7");

	////BigInt c = c.BitPowModN(a,b,n);
	//BigInt c = BigInt("1993");
	////BigInt d = d.PowModN(a, b, n);
	//
	//

	//cout << PrimesGenerator::isPrime(c, 20) << endl;
	//c.numberInDec = c.ConvertBaseToDec();
	//c.printDec();
	////d.numberInDec = d.ConvertBaseToDec();
	////d.printDec();
	/////*BigInt a = BigInt("0");
	////int b = 0;
	////if (a < b) cout << "<" << endl;
	////if (a > b) cout << ">" << endl;
	////if (a <= b) cout << "<=" << endl;
	////if (a >= b) cout << ">=" << endl;
	////if (a == b) cout << "==" << endl;*/
	system("pause");
	return 0;
}