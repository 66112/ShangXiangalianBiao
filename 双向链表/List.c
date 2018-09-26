#include "List.h"
void InitList(List* lp)
{
	assert(lp);
	lp->_head = BuyListNode(0);
	lp->_head->_next = lp->_head;
	lp->_head->_prve = lp->_head;
}

void DestoryList(List* lp)
{
	assert(lp);
	while (lp->_head->_next != lp->_head)
	{
		ListNode* del = lp->_head->_next;
		lp->_head->_next = del->_next;
		free(del);
	}
	free(lp->_head);
}

ListNode* BuyListNode(LIDateType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prve = NULL;
	return newNode;
}

void PushBackList(List* lp, LIDateType x)
{
	assert(lp);
	InsertList(lp->_head, x);
}
void PushFrontList(List* lp, LIDateType x)
{
	assert(lp);
	InsertList(lp->_head->_next, x);
}
void PopBackList(List* lp)
{
	assert(lp);
	EraseList(lp->_head->_prve);
}
void PopFrontList(List* lp)
{
	assert(lp);
	EraseList(lp->_head->_next);
}

ListNode* FindListNode(List* lp, LIDateType x)
{
	assert(lp);
	ListNode* cur = lp->_head->_next;
	if (cur == lp->_head)
	{
		printf("链表为空！\n");
		return NULL;
	}
	while (cur!=lp->_head)
	{
		if (cur->_data == x)
		{
			printf("找到了！\n");
			return cur;
		}
		cur = cur->_next;
	}
	printf("没找到！\n");
	return NULL;
}

void InsertList(ListNode* pos, LIDateType x)
{
	assert(pos);
	ListNode* newNode = BuyListNode(x);
	ListNode* flag = pos->_prve;
	flag->_next = newNode;
	newNode->_prve = flag;
	newNode->_next = pos;
	pos->_prve = newNode;
}
void EraseList(ListNode* pos)
{
	assert(pos);
	if (pos->_next == pos)
	{
		printf("头节点不能删！\n");
		return;
	}
	ListNode* flag = pos->_prve;
	flag->_next = pos->_next;
	pos->_next->_prve = flag;
	free(pos);
}

int SizeList(List* lp)
{
	assert(lp);
	int count = 0;
	ListNode* cur = lp->_head->_next;
	while (cur != lp->_head)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
int EmptyList(List* lp)
{
	assert(lp);
	while (lp->_head->_next != lp->_head)
	{
		ListNode* del = lp->_head->_next;
		lp->_head->_next = del->_next;
		free(del);
	}
	return 1;
}
void PrintList(List* lp)
{
	assert(lp);
	ListNode* cur = lp->_head->_next;
	while (cur != lp->_head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("结束\n");
}

void test()
{
	List lp;
	InitList(&lp);
	PushFrontList(&lp, 3);
	PushFrontList(&lp, 4);
	PushFrontList(&lp, 5);
	PushBackList(&lp, 2);
	PushBackList(&lp, 1);
	PushBackList(&lp, 0);
	//printf("%d\n", SizeList(&lp));
	//printf("%d\n", EmptyList(&lp));
	//InsertList(FindListNode(&lp,5), 8);
	//EraseList(FindListNode(&lp,9));

	PrintList(&lp);
	DestoryList(&lp);
}
int main()
{
	test();
	return 0;
}
