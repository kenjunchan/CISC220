#include <iostream>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string>

#include "hashNode.hpp"
#include "hashMap.hpp"
#include "MakeSeuss.hpp"

using namespace std;
int main(){
	srand(time(NULL));
	makeSeuss Seuss = makeSeuss("DrSeuss.txt","output1.txt",true,true);
	makeSeuss Seuss2 = makeSeuss("DrSeuss.txt","output2.txt",true,false);
	makeSeuss Seuss3 = makeSeuss("DrSeuss.txt","output3.txt",false,true);
	makeSeuss Seuss4 = makeSeuss("DrSeuss.txt","output4.txt",false,false);
	hashMap *m1 = new hashMap (true,true);
	m1->addKeyValue("panda","express");
	m1->addKeyValue("pineapple","juice");
	m1->addKeyValue("panda","bowl");
	m1->addKeyValue("grape","juice");
	m1->addKeyValue("orange","black");
	m1->addKeyValue("panda","zoo");
	m1->addKeyValue("orange","red");
	m1->addKeyValue("orange","blue");
	m1->addKeyValue("orange","brown");
	m1->printMap();

	return 0;
}
