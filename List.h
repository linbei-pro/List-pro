#pragma once
//˫���ͷѭ������
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ListDataType;

//�ṹ�嶨��
typedef struct List 
{
	ListDataType data;
	struct List* prev;
	struct List* next;
}SL;
//�ṹ���ʼ��
SL* SLInit();
//��ӡ
void SLprint(SL* ps);
//β��
void SLPushBack(SL* ps, ListDataType data);
//βɾ
void SLPopBack(SL* ps);
//ͷ��
void SLPushFront(SL* ps, ListDataType data);
//ͷɾ
void SLPopFront(SL* ps);
//����
void SLDestroy(SL* ps);