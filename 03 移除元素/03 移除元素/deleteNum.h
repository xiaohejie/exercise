#pragma once 
#include <iostream>
#include "assert.h"
using namespace std;

typedef struct DelList {
	int* a;
	int size;		//有效数据的大小
	int capacity;	//容量
}DL , DelList;

void deleteInit(DL* nums);
void deletePrint(DL* nums);
void SeqListCheckCapacity(DL* nums);


void deleteNum(DL* nums , int x);