#include"List.h"

void Test()
{
	SL* plist=NULL;
	plist=SLInit();
	SLPushBack(plist, 1);
	SLPushBack(plist, 2);
	SLPushBack(plist, 3);
	SLPushBack(plist, 4);
	SLPushBack(plist, 5);

	SLprint(plist);

	SLPopBack(plist);
	SLPopBack(plist);

	SLprint(plist);

	SLPushFront(plist, 10);
	SLPushFront(plist, 20);
	SLPushFront(plist, 30);

	SLprint(plist);

	SLPopFront(plist);
	SLPopFront(plist);

	SLprint(plist);
}


int main() {


	Test();

	return 0;
}