#ifndef __SEQLIST_H__ 
#define __SEQLIST_H__ 

#include<stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 10 

typedef int DataType; 

typedef struct SeqList 
{ 
DataType data[MAX]; 
int sz; 
}SeqList, *pSeqList; 

void InitSeqList(pSeqList ps); 
void PushBack(pSeqList ps, DataType d); 
void PopBack(pSeqList ps); 
void Display(const pSeqList ps); 
void PushFront(pSeqList ps, DataType d); 
void PopFront(pSeqList ps); 
int Find(pSeqList ps, DataType d); 
void Insert(pSeqList ps, DataType d, int pos); 
void Remove(pSeqList ps, DataType d); 
void RemoveAll(pSeqList ps, DataType d); 
void Reverse(pSeqList ps); 
void Sort(pSeqList ps); 
int BinarySearch(pSeqList ps, DataType d); 
#endif //__SEQLIST_H__ 

