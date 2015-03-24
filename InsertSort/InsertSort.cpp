// InsertSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct LIST
{
	struct LIST* pNext;
	int iValue;
};

struct LIST* InsertSort(struct LIST* pList)
{
	if ((pList == NULL) || (pList->pNext == NULL))
	{
		return pList;
	}

	struct LIST* pHead = NULL, *pNoSortItor = NULL;

	while ((pNoSortItor = pList) != NULL)
	{
		pList = pList->pNext;
		if ((pHead == NULL) || (pNoSortItor->iValue < pHead->iValue))
		{
			pNoSortItor->pNext = pHead;
			pHead = pNoSortItor;
		}
		else
		{
			struct LIST* pSortItor = pHead;
			while (pSortItor != NULL)
			{
				if ((pSortItor->pNext == NULL) ||
					(pNoSortItor->iValue < pSortItor->pNext->iValue))
				{
					pNoSortItor->pNext = pSortItor->pNext;
					pSortItor->pNext = pNoSortItor;
					break;
				}
				pSortItor = pSortItor->pNext;
			}
		}
	}
	return pHead;
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

