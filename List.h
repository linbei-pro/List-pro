#pragma once
//双向带头循环链表
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ListDataType;

//结构体定义
typedef struct List 
{
	ListDataType data;
	struct List* prev;
	struct List* next;
}SL;
//结构体初始化
SL* SLInit();
//打印
void SLprint(SL* ps);
//尾插
void SLPushBack(SL* ps, ListDataType data);
//尾删
void SLPopBack(SL* ps);
//头插
void SLPushFront(SL* ps, ListDataType data);
//头删
void SLPopFront(SL* ps);
//销毁
void SLDestroy(SL* ps);