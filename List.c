#include"List.h"


//结构体初始化
SL* SLInit()
{
	SL* ps = (SL*)malloc(sizeof(SL));
	if (ps == NULL)
	{
		printf("malloc fail!\n");
		free(ps);
	}
	ps->data = -1;
	ps->next = ps;
	ps->prev = ps;
	return ps;
}
//打印
void SLprint(SL* ps)
{
	assert(ps);
	
	SL* teil=ps->next;
	assert(teil != ps);
	while (teil != ps)
	{
		printf("%d ", teil->data);
		teil = teil->next;
	}
	printf("\n");
}
//尾插
void SLPushBack(SL* ps, ListDataType data)
{
	assert(ps);
	SL* newnode = (SL*)malloc(sizeof(SL));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		free(newnode);
	}
	newnode->data = data;

	SL* teil = ps;
	teil = ps->prev;
	teil->next = newnode;
	newnode->prev = teil;
	newnode->next = ps;
	ps->prev = newnode;
}
//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->next != ps);//不能数据删完了还删
	SL* teil = ps->prev;
	SL* cur = teil->prev;
	free(teil);
	ps->prev = cur;
	cur->next = ps;
}
//头插
void SLPushFront(SL* ps, ListDataType data)
{
	assert(ps);
	SL* cur = ps->next;
	SL* newnode = (SL*)malloc(sizeof(SL));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		free(newnode);
	}
	newnode->data = data;

	ps->next = newnode;
	newnode->prev = ps;
	newnode->next = cur;
	cur->prev = newnode;
}
//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	SL* cur = ps->next;
	if (cur->next == ps)
	{
		free(cur);
		ps->next = ps;
		ps->prev = ps;
	}
	else
	{
		ps->next = cur->next;
		cur->next->prev = ps;
		free(cur);
	}
}
//销毁
void SLDestroy(SL* ps)
{
	assert(ps);
	SL* cur = ps->next;
	while (cur != ps)
	{
		SL* next = cur->next;
		free(cur);
		cur = next;
	}
	free(ps);
	ps = NULL;
}