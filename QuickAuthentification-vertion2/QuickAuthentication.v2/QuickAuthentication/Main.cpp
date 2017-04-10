#include"Cryptograpy.h"

int main()
{
	srand(time(NULL));
	srand(time(NULL));
	//FIRST
	/*string jj = "105210379657361138989466928893745150396269988033039760961753225972023273228491164549281156649207216752204549219136901167725177556453912662058142288005671054431812031526333745941241103118883593132950837977460558470925209530308235671876619643871789959089510986685852991715237396845888829755249585646639660594458";
	string uu = "7273471167771778234854767044182980436491946993852499695524171726796925721226178809455417368105678237612703";
	string vv = "50219471798820038251754532599718847140476482458549571217926265659353999889687912029514241479415293808440929";
	*/
	/*string jj = "12327843054";
	string uu = "2132311123";
	string vv = "5667678811";
	
	BigInt j = BigInt(jj);
	BigInt u = BigInt(uu);
	BigInt v = BigInt(vv);
	BigInt a = Cryptography::GCD(u, v);
	a.numberInDec = a.ConvertBaseToDec();
	a.printDec();
	cout << endl;

	BigInt n = Cryptography::firstAlpha(j, u, v);
	n.numberInDec = n.ConvertBaseToDec();
	n.printDec();

	pair<BigInt, BigInt> pq = pair<BigInt, BigInt>();
	pq = Cryptography::firstBeta(n, j, u, v);
	pq.first.numberInDec = pq.first.ConvertBaseToDec();
	pq.second.numberInDec = pq.second.ConvertBaseToDec();
	
	BigInt n1 = BigInt();
	n1 = pq.first*pq.second;
	n1.numberInDec = n1.ConvertBaseToDec();
	pq.first.printDec();
	pq.second.printDec();
	n1.printDec();
	if (n == n1) cout << "1" << endl;
	else cout << "0" << endl;*/
	// SECOND 
	
	/*string cc = "2132311123";
	string vv = "5667678811";

	
	BigInt c = BigInt(cc);
	BigInt v = BigInt(vv);
	

	vector<BigInt> n = Cryptography::secondAlpha(v,c);
	n[0].numberInDec = n[0].ConvertBaseToDec();
	n[0].printDec();

	pair<BigInt, BigInt> pq = pair<BigInt, BigInt>();
	pq = Cryptography::secondBeta(n[0], n[2], v, c);
	pq.first.numberInDec = pq.first.ConvertBaseToDec();
	pq.second.numberInDec = pq.second.ConvertBaseToDec();

	BigInt n1 = BigInt();
	n1 = pq.first*pq.second;
	n1.numberInDec = n1.ConvertBaseToDec();
	pq.first.printDec();
	pq.second.printDec();
	n1.printDec();
	if (n[0] == n1) cout << "1" << endl;
	else cout << "0" << endl;*/
	system("pause");
	return 0;
}