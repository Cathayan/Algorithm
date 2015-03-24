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
		if (pSmall->pNext->iValue < pBig->iValue)
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





struct LIST* Recursive_MergeSort(struct LIST* pList)
{
	if ((pList == NULL) || (pList->pNext == NULL))
		return pList;






};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

