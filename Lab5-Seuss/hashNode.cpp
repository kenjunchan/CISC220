#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

using namespace std;
#include "hashNode.hpp"

hashNode::hashNode(){
	srand(time(NULL));
	keyword = "";
	valuesSize = 0;
	currSize = 0;
	values = NULL;
}

hashNode::hashNode(string s){
	srand(time(NULL));
	keyword = s;
	valuesSize = 11;
	currSize = 0;
	values = new string[valuesSize];
}

hashNode::hashNode(string s, string v){
	srand(time(NULL));
	keyword = s;
	valuesSize = 3;
	currSize = 1;
	values = new string[valuesSize];
	values[currSize - 1] = v;
}

void hashNode::addValue(string v){
	if(currSize + 1 > valuesSize){
		dblArray();
	}
	currSize++;
	values[currSize - 1] = v;

}

void hashNode::dblArray(){
	int newSize = valuesSize * 2;
	string *newArr = new string[newSize];
	for(int i = 0; i < currSize; i++){
		newArr[i] = values[i];
	}
	values = newArr;
	valuesSize = newSize;
}

string hashNode::getRandValue(){
	if(currSize != 0){
		return values[(rand() % (currSize))];
	}
	else
		return "";
}

void hashNode::printArray(){
	for(int i = 0; i < valuesSize; i++){
		if(i != (valuesSize - 1))
			cout << values[i] << ", ";
		else
			cout << values[i];
	}
}
