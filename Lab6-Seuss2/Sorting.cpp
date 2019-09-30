/*
 * Part 3 Question and Answers
 *
 * 1. Because the array of predictions is an array of addresses which point to the NodeT classes made and inserted into
 * the AVL Tree.
 *
 * 2. Both methods use the Binary Search Algorithm
 *
 *
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
#include <sstream>

#include "Sorting.hpp"
#include "wordInfo.hpp"

Sorting::Sorting(){

}

void Sorting::insertionSort(wordInfo *arr[], int len){
	int i, n;
	wordInfo *key;
	   for (i = 1; i < len; i++)
	   {
	       key = arr[i];
	       n = i-1;
	       while (n >= 0 && arr[n]->ct < key->ct)
	       {
	           arr[n+1] = arr[n];
	           n = n-1;
	       }
	       arr[n+1] = key;
	   }
}

void Sorting::selectionSort(wordInfo *arr[],int len){
	wordInfo *temp;
	int minPosition;
	for (int i=0; i < len-1; i++)
	{
		minPosition = i;
		for (int j=i+1; j < len; j++)
		{
			if (arr[j]->ct > arr[minPosition]->ct)
			minPosition=j;
		}
		if (arr[minPosition]->ct != arr[i]->ct)
		{
			temp = arr[i];
			arr[i] = arr[minPosition];
			arr[minPosition] = temp;
		}
	}
}

void Sorting::quickSort(wordInfo *arr[], int beg, int end){
	if(end - beg > 0){
		int pivotPoint = partition(arr, beg, end);
		quickSort(arr, beg, pivotPoint-1);
		quickSort(arr, pivotPoint+1, end);
	}
}

int Sorting::partition(wordInfo *arr[], int beg, int end){
	srand(time(NULL));
	int pivotPoint = beg + rand() % (end - beg);
	int n = beg;
	wordInfo *tmp;
	int p = arr[pivotPoint]->ct;
	tmp = arr[pivotPoint];
	arr[pivotPoint] = arr[end];
	arr[end] = tmp;
	for(int i = beg; i < end; i++) {
		if(arr[i]->ct >= p) {
			tmp = arr[n];
			arr[n] = arr[i];
			arr[i] = tmp;
			n++;
		}
	}
	tmp = arr[n];
	arr[n] = arr[end];
	arr[end] = tmp;
	return n;
}

void Sorting::mergeSort(wordInfo *arr[],int l1,int l2){
	if(l2 - l1 > 0){
		int m = l1 + (l2-l1)/2;
		mergeSort(arr, l1, m);
		mergeSort(arr, m+1, l2);
		merge(arr, l1, m, l2);
	}
}

void Sorting::merge(wordInfo *arr[], int l, int m, int r){
	int i, n, k;
	int x = m - l + 1;
	int y = r - m;
	wordInfo *leftArr[x], *rightArr[y];
	for(i = 0; i < x; i++){
		leftArr[i] = arr[l + i];
	}
	for(n = 0; n < y; n++){
	rightArr[n] = arr[m + n + 1];
	}
	i = 0;
	n = 0;
	k = l;
	while(i < x && n < y){
		if(leftArr[i]->ct >= rightArr[n]->ct) {
			arr[k] = leftArr[i];
			i++;
		}
		else{
			arr[k] = rightArr[n];
			n++;
		}
		k++;
	}
	while(i < x){
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while(n < y){
		arr[k] = rightArr[n];
		n++;
		k++;
	}
}
