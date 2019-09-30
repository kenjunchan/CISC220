#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#include "hashMap.hpp"

hashMap::hashMap(bool hash1, bool coll1){
	first = "";
	h1 = hash1;
	c1 = coll1;
	collisionct1 = 0;
	collisionct2 = 0;
	numKeys = 0;
	mapSize = 101;
	map = new hashNode*[mapSize];
	for(int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
}

void hashMap::addKeyValue(string k, string v){
	if(numKeys == 0)
		first = k;
	int hashValue = 0;
	bool keyAdded = false;
	if(h1==true)
		hashValue = calcHash(k);
	else
		hashValue = calcHash2(k);
	while(keyAdded == false){
		if(map[hashValue]==NULL){
			map[hashValue] = new hashNode(k,v);
			keyAdded = true;
			numKeys++;

		}
		else if(map[hashValue]!=NULL){
			if(k==map[hashValue]->keyword){
				map[hashValue]->addValue(v);
				keyAdded = true;
			}
			if(c1){
				hashValue = collHash1(hashValue,mapSize,k);
				collisionct1++;
			}
			else{
				hashValue = collHash2(hashValue,mapSize,k);
				collisionct1++;
			}
		}
	}
	if(numKeys >= mapSize*.7)
		reHash();
}

void hashMap::reHash(){
	if(numKeys >= (mapSize*.7)){
		int newMapSize = getClosestPrime(mapSize*2);
		hashNode **newMap = new hashNode*[newMapSize];
		for(int i = 0; i < newMapSize; i++){
			newMap[i] = NULL;
		}
		hashNode **oldMap = map;
		int oldMapSize = mapSize;
		map = newMap;
		mapSize = newMapSize;
		numKeys = 0;
		for(int i = 0; i < oldMapSize; i++){
			if(oldMap[i]!=NULL){
				for(int j = 0; j<oldMap[i]->currSize; j++){
					addKeyValue(oldMap[i]->keyword,oldMap[i]->values[j]);
				}
			}
		}
	}
}

int hashMap::getIndex(string k){
	int index = 0;
	if(h1==true)
		index = calcHash(k);
	else
		index = calcHash2(k);
	if(map[index]->keyword==k)
		return index;
	else{
		collisionct1++;
		if(c1){
			return collHash1(index, mapSize, k);
		}
		else{
			return collHash2(index, mapSize, k);
		}
	}
}
int hashMap::findKey(string k){
	int index = 0;
	if(h1==true)
		index = calcHash(k);
	else
		index = calcHash2(k);
	if(map[index]->keyword==k)
		return index;
	if(c1==true)
		return collHash1(index,mapSize,k);
	else
		return collHash2(index,mapSize,k);

	return -1;
}
int hashMap::getClosestPrime(int n){
	bool isPrime = true;
	while(isPrime){
		for(int i = 2; i <= n/2; i++){
			if(n % i == 0){
				isPrime = false;
				break;
			}
		}
		n++;
	}
	return n;
}
int hashMap::calcHash(string k){
	int h = 0;
	for(int i = 0; i < k.length(); i++){
		h += int(k.at(i));
	}
	h = h % mapSize;
	return h;
}

int hashMap::collHash1(int h, int i, string k){
	//Linear Probing
	while(map[h] != NULL && map[h]->keyword!=k){
		h++;
		if(h >= i){
			h = 0;
		}
	}
	return h;
}
int hashMap::calcHash2(string k){
	int h = 0;
	for(int i = 0; i < k.length(); i++){
		collisionct2++;
		h += int(k.at(i)) * 3;
	}
	h = h % mapSize;
	return h;
}

int hashMap::collHash2(int h,int i,string k){
	//Quadratic Probing
	int x = h;
	int ct = 0;
	while (map[x] != NULL && k != map[x]->keyword){
		collisionct2++;
		ct++;
		x = (h+(ct*ct))%i;
	}
	return x;
}

void hashMap::printMap(){
	cout << "PRINTING HASH MAP" << endl;
	cout << "HASHMAP SIZE: " << mapSize << endl;
	cout << "NUMBER OF KEYS: " << numKeys << endl;
	cout << "COLLISION COUNT: ";
	if(c1){
		cout << collisionct1 << endl;
	}
	if(!c1){
		cout << collisionct2 << endl;
	}
	for(int i = 0; i < mapSize; i++){
		cout << i << ": ";
		if(map[i]!=NULL){
			cout << "KEYWORD: " << map[i]->keyword << " VALUES: ";
			map[i]->printArray();
		}
		else
			cout << "NULL";
		cout << endl;
	}
}
