#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef int LIDateType;
typedef struct ListNode
{
	LIDateType _data;
	struct ListNode* _next;
	struct ListNode* _prve;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;

void InitList(List* lp);
void DestoryList(List* lp);
ListNode* BuyListNode(LIDateType x);

void PushBackList(List* lp, LIDateType x);
void PushFrontList(List* lp, LIDateType x);
void PopBackList(List* lp);
void PopFrontList(List* lp);

ListNode* FindListNode(List* lp, LIDateType x);
void InsertList(ListNode* pos, LIDateType x);
void EraseList(ListNode* pos);

int SizeList(List* lp);
int EmptyList(List* lp);
void PrintList(List* lp);

