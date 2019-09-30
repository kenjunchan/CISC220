#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
//#include "Game.hpp"
#include "TreePuzzle.hpp"

//void readandwritefile(string oldfile, string newfile);

/*	PART III QUESTION 8
 * 	There are 436 nodes in the dictionary tree
 * 	The maximum amount of comparisons needed is O(log n) + 1
 */

using namespace std;
int main() {
	//PART 1
	//string sarr[10] = {"run","tuxedo","ocelot","vast","bark","punctilios","hello","is","sibylic","go"};
	//treePuzzle(10,sarr,0);
	//FOR EXTRA CREDIT
	/*
	string sarr2[13] = {"xray","jack","superthriller","fa","noon","muddle","kindergartener","zoogeographical","window","dandelion","youthsploitation","byte","apple"};
	treePuzzle(13,sarr2 ,1);
	*/

	//PART 2
	cout << endl << "A LOT OF LEFT ROTATIONS " << endl;
	string sarr3[10] = {"a","b","c","d","e","f","g","h","i","j"};
	treePuzzle(10,sarr3,3);

	cout << endl << endl << "A LOT OF RIGHT ROTATIONS " << endl;
	string sarr4[10] = {"j","i","h","g","f","e","d","c","b","a"};
	treePuzzle(10,sarr4,3);

	cout << endl << endl << "A LOT OF RIGHT-LEFT ROTATIONS " << endl;
	string sarr5[10] = {"g","j","i","c","f","h","e","d","a","b"};
	treePuzzle(10,sarr5,3);

	cout << endl << endl << "A LOT OF LEFT-RIGHT ROTATIONS " << endl;
	string sarr6[10] = {"a","p","d","g","f","e","k","j","v","b"};
	treePuzzle(10,sarr6,3);

	//PART 3

	treePuzzle("strangeAnimalDict.txt",439);






/*
	srand(time(NULL));

	Game *game = new Game();
	game->startGame();
	*/
/*
	string x = "apple";
	string y = "apple";
	if (x != y) {
		cout <<"happy less than apple" << endl;
	}
	else {
		cout << "apple less than happy" << endl;
	}
	*/
	/*
	int k = 4;  //address is 0x382ef
	int *tmp;
	tmp = &k;
	cout << tmp << endl;
	cout << *tmp << endl;
	int *tmp2;
	tmp2 = tmp;
	int j = 10; //address is 0x28ff04
	tmp = &j;
	cout << *tmp2 << endl;

	int *tmp4;
	int tmp5[6] = {1, 2, 3, 4, 5, 6 };   // address of tmp3 is 0x84231a
	tmp4 = &tmp5[0];
	cout << tmp4 << endl;

	tmp4[3]+=2;
	cout << tmp5[3] << endl;


//	int *tmp4;
//	tmp4[0] = 1;


	// tmp is here?
	 *
	 */

/*
	void add(int *k)
	{
	   k[0] +=1;
	   k += 2;
	   ++*(k+1);
	   return;
	}
	main ()
	{
	int tmp[4] = {2,4,6,8};
	add(tmp);
	//tmp is here?
	}
*/

	/*

	int a = 8;
	cout << &a << endl;
	int *b = &a;
	cout << *b << endl;
	cout << b << endl;
	cout << &b << endl;
	a = 6;
	cout << *b << endl;
	int c = 12;
	//b = &c;
	//*b = 3;
	cout << c << endl;
	cout << a << endl;
	int **d = &b;
	cout << d << endl;
	cout << **d << endl;
	cout << *d << endl;

	BSTY *dict;
	string s = "dict.txt";


	string s2 = "temp.txt";
	readandwritefile(s,s2);
	readandwritefile("temp.txt", "temp2.txt");
	readandwritefile("temp2.txt","dict.txt");
	//


	dict= readtreefromfile(s);
	dict->printTreeio();
	cout << "How many letters? " << endl;
	int num;
	cin >> num;
	*/

}



void readandwritefile(string oldfile, string newfile) {
	string words1[28003];
	string words2[28003];
	string words3[28003];
	ifstream file(oldfile.c_str());
	for (long i = 0; i < 28003; i++) {
		file >> words1[i];
		cout << words1[i] << endl;
	}
	string w;

	for (long i = 0; i < 28004; i++) {
		if (i == 14001) {
			file >> w;
		}
		else if (i < 14001){
			file >> words2[i];
		}
		else {
			file >> words2[i-1];
		}
		cout << words2[i] << endl;
	}
	for (long i = 0; i < 28003; i++) {
		file >> words3[i];
		cout << words3[i] << endl;
	}
	file.close();

	ofstream file2(newfile.c_str());
	file2 << w << endl;
	for (int x = 0; x < 28003; x++) {
		int y = rand() % 6;
		if (y == 0) {
			file2 << words1[x] << endl;
			file2 << words2[x] << endl;
			file2 << words3[x] << endl;
		}
		else if (y == 1) {
			file2 << words1[x] << endl;
			file2 << words3[x] << endl;
			file2 << words2[x] << endl;
		}
		else if (y == 2) {
			file2 << words2[x] << endl;
			file2 << words3[x] << endl;
			file2 << words1[x] << endl;
		}
		else if (y == 3) {
			file2 << words2[x] << endl;
			file2 << words1[x] << endl;
			file2 << words3[x] << endl;
		}
		else if (y == 4) {
			file2 << words3[x] << endl;
			file2 << words1[x] << endl;
			file2 << words2[x] << endl;
		}
		else if (y == 5) {
			file2 << words3[x] << endl;
			file2 << words2[x] << endl;
			file2 << words1[x] << endl;
		}
	}
	file2.close();
	cout << "done" << endl;
}
