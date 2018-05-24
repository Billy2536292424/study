#define _CRT_SECURE_NO_WARNINGS
#include"seqlist.h"
void InitSeqList(pSeqList ps)
{
	assert(ps);
	ps -> sz = 0;
	memset(ps->data, 0, sizeof(ps->data));
}
void PushBack(pSeqList ps, DataType d)
{
	assert(ps);
	if (ps->sz == MAX)
	{
		return;
	}
	ps->data[ps->sz] = d;
	ps->sz++;

}
void PopBack(pSeqList ps)
{
	assert(ps);
	if (ps->sz == 0 )
	{
		return;
	}
	ps->sz--;
}
void Display(const pSeqList ps)
{
	int i = 0;
	assert(ps);
	for ( i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}
void PushFront(pSeqList ps, DataType d)
{	
	assert(ps);
	if (ps->sz == MAX)
	{
		return;
	}
	memmove(ps->data + 1, ps->data, sizeof(DataType)*(ps->sz));
	/*int i = 0;
	for	( i = ps->sz; i > 0; i--)
	{
		ps->data[i] = ps->data[i - 1];

	}*/
	ps->data[0] = d;
	ps->sz++;
}
void PopFront(pSeqList ps)
{
	int i = 0;
	assert(ps);
	if (ps->sz == 0)
	{
		return;
	}
	for (i = 0; i < ps->sz-1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
	
}
int Find(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps);
	for ( i = 0; i < ps->sz; i++)
	{
		if (ps->data[i] == d)
		{
			return i;
		}
		
	}
	return -1;
}
void Insert(pSeqList ps, DataType d, int pos)
{
	int i = 0;
	assert(ps);
	if (ps->sz == MAX)
	{
		return;
	}
	for (i = ps->sz; i > pos; i--)
	{
		ps->data[i] = ps->data[i - 1];

	}
	ps-> data[pos] = d;
	ps -> sz++;
}
void Remove(pSeqList ps, DataType d)
{
	int pos = Find(ps, d);

	assert(ps);
	if (ps->sz == 0)
	{
		return;
	}
	for ( int i = pos;  i < ps->sz-1;  i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}
void RemoveAll(pSeqList ps, DataType d)
{
	int pos = 0;
	assert(ps);
	while ((pos = Find(ps, d)) != -1)
	{
		Remove(ps, d);
	}
	

}
void Reverse(pSeqList ps)
{
	DataType* left = ps->data;
	DataType* right = ps->data + ps->sz - 1;
	while (left <right)
	{
		DataType tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void Sort(pSeqList ps)
{
	int i = 0;
	int j = 0;
	assert(ps);
	for ( i = 0; i < ps->sz-1; i++)
	{
		for ( j = 0; j < ps->sz-1-i; j++)
		{
			if (ps->data[j] > ps->data[j+1])
			{
				DataType tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
}
int BinarySearch(pSeqList ps, DataType d)
{
	int left = 0;
	int right = ps->sz-1;
	
	assert(ps);
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (d == ps->data[mid])
		{
			return mid;
		}
		else if (d < ps->data[mid])
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
		
	}
	return -1;
}
