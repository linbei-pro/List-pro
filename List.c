#include"List.h"


//�ṹ���ʼ��
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
//��ӡ
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
//β��
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
//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->next != ps);//��������ɾ���˻�ɾ
	SL* teil = ps->prev;
	SL* cur = teil->prev;
	free(teil);
	ps->prev = cur;
	cur->next = ps;
}
//ͷ��
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
//ͷɾ
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
//����
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