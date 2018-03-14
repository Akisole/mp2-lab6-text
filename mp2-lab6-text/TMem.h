#include <string.h>
#include <iostream>
class TLink;
class TText;

struct TMem {
	TLink *pFirst, *pLast, *pFree;
};

class TLink {
public:
	char str[80];
	TLink *pNext, *pDown;
	static TMem mem;

	TLink (char *s = NULL, TLink *pN = NULL, TLink *pD = NULL) {
		pNext=pN;
		pDown=pD;
		if(s==NULL)
			str[0] = '\0';
		else strcpy_s(str,s);
	}
	~TLink(){}

	void* operator new (size_t s) {
		TLink *tmp=mem.pFree;
		if (mem.pFree!=NULL)
			mem.pFree = mem.pFree->pNext;
		return tmp;
	}
	void operator delete (void* p) {
		TLink *tmp = (TLink*)p;
		tmp->pNext = mem.pFirst;
		mem.pFree=tmp;
	}

	static void InitMem (int s); 
	static void MemClean(TText& t);
	static void PrintFree();
};