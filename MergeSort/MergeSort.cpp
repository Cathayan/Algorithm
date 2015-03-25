// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct LIST
{
	struct LIST* pNext;
	int iValue;
};


struct LIST* Combine2List(struct LIST* pA, struct LIST* pB)
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
	return(Combine2List(pList, p2ndHalfBegin));
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

inline struct LIST* Walk_List(struct LIST* pBegin, int count)
{
	while (count--)
	{
		pBegin = pBegin->pNext;
	}
	return pBegin;
};

void CombineContinualList(struct LIST* pDummyHeader, int len1st, int len2nd)
{
	struct LIST* p1stBegin = pDummyHeader->pNext;
	struct LIST* p1stEnd = Walk_List(pDummyHeader, len1st);
	struct LIST* p2ndBegin = p1stEnd->pNext;
	struct LIST* p2ndEnd = Walk_List(p1stEnd, len2nd);
	struct LIST* pItemAfter = p2ndEnd->pNext;
	struct LIST *pSmall, *pBig;
	int *pLenSmall, *pLenBig;
	if (p1stBegin->iValue < p2ndBegin->iValue)
	{
		pSmall = p1stBegin;
		pBig = p2ndBegin;
		pLenSmall = &len1st;
		pLenBig = &len2nd;
	}
	else
	{
		pDummyHeader->pNext = p2ndBegin;
		pSmall = p2ndBegin;
		pBig = p1stBegin;
		pLenSmall = &len2nd;
		pLenBig = &len1st;
	}

	while ((*pLenSmall) && (*pLenBig))
	{
		if (*pLenSmall == 1)
		{
			pSmall->pNext = pBig;
			*pLenSmall = 0;
			break;
		}
		else if (pSmall->pNext->iValue < pBig->iValue)
		{
			pSmall = pSmall->pNext;
			(*pLenSmall)--;
		}
		else
		{
			struct LIST* pTemp = pSmall->pNext;
			int* pLenTemp = pLenSmall;
			pSmall->pNext = pBig;
			pSmall = pBig;
			pBig = pTemp;
			pLenSmall = pLenBig;
			pLenBig = pLenSmall;
			(*pLenBig)--;
		}

	}

	if (pItemAfter != p2ndEnd->pNext)
	{
		struct LIST* pFinal = Walk_List(pDummyHeader, (len1st + len2nd));
		pFinal->pNext = pItemAfter;
	}
}



struct LIST* Non_Recursive_MergeSort(struct LIST* pList)
{
	if ((pList == NULL) || (pList->pNext == NULL))
		return pList;
	struct LIST dummyHead;
	
	struct LIST *pTemp = pList, *pHead = &dummyHead, *p1stHalf = pHead, *p2ndHalf = pHead;
	int total_count = 1, step = 1;
	while ((pTemp = pTemp->pNext) != NULL)
	{
		total_count++;
	}

	dummyHead.pNext = pList;
	while (step < total_count)
	{
		for (int i = 0; (i*step) < total_count; i +=2)
		{
			if ((i + 1) * step >= total_count)
			{
				break;
			}
			else
			{
				int len1st = step;
				int len2nd = ((i + 2) * step < total_count) ? step : (total_count - (i + 1)*step);
				CombineContinualList(pHead, len1st, len2nd);
				pHead = Walk_List(pHead, (len1st + len2nd));
			}

		}
		step *= 2;
	}

	return dummyHead.pNext;
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
};

