// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct LIST
{
	struct LIST* pNext;
	int iValue;
};


struct LIST* CombineList(struct LIST* pA, struct LIST* pB)
{
	struct LIST* pSmall = (pA->iValue < pB->iValue) ? pA : pB;
	struct LIST* pBig = (pA->iValue < pB->iValue) ? pB : pA;
	while ((pSmall != NULL) && (pBig != NULL))
	{
		if ((pSmall->pNext == NULL))
		{
			pSmall->pNext = pBig;
			break;
		}
		else if (pSmall->pNext->iValue < pBig->iValue)
		{
			pSmall = pSmall->pNext;
		}
		else
		{
			struct LIST* pTemp = pSmall->pNext;
			pSmall->pNext = pBig;
			pSmall = pBig;
			pBig = pTemp;
		}
	}

	return ((pA->iValue < pB->iValue) ? pA : pB);
};

struct LIST* SplitSort(struct LIST* pList, int count)
{
	if (count <= 1)
		return pList;
	struct LIST* p1stHalfEnd = pList;
	int half_count = 1;
	while (half_count++ < count/2)
	{
		p1stHalfEnd = p1stHalfEnd->pNext;
	}
	struct LIST* p2ndHalfBegin = p1stHalfEnd->pNext;
	p1stHalfEnd->pNext = NULL;
	SplitSort(pList, count/2);
	SplitSort(p2ndHalfBegin, (count - count / 2));
	return(CombineList(pList, p2ndHalfBegin));
};

struct LIST* Recursive_MergeSort(struct LIST* pList)
{
	if ((pList == NULL) || (pList->pNext == NULL))
		return pList;
	int count = 1;
	struct LIST* pTemp = pList;
	while ((pTemp = pTemp->pNext) != NULL)
	{
		count++;
	}
	return(SplitSort(pList, count));
};

struct LIST* Non_Recursive_MergeSort(struct LIST* pList)
{
	if ((pList == NULL) || (pList->pNext == NULL))
		return pList;
	struct LIST *pTemp = pList, *pHead = pList;
	int count = 1, step = 1;
	while ((pTemp = pTemp->pNext) != NULL)
	{
		count++;
	}

	while (step < count)
	{


		step *= 2;
	}

	return pHead;
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
};

