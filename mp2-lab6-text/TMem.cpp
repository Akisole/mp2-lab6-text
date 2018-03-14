#include "TText.h"

 void TLink::InitMem (int s){
		mem.pFirst = (TLink*)new char[sizeof(TLink)*s];
		mem.pFree = mem.pFirst;
		mem.pLast = mem.pFirst + (s-1);
		TLink *tmp = mem.pFree;
		for (int i=0; i<s-1; i++) {
			tmp->pNext = tmp+1;
			strcpy_s(tmp->str, "free");
			tmp++;
		}
		mem.pLast->pNext = NULL;
		strcpy_s(mem.pLast->str, "free");
	}

 void TLink::MemClean(TText& t) {
		for(t.Reset(); !t.IsEnd(); t.GoNext())
			strcat(t.GetCurr()->str, "*");
		TLink *tmp=mem.pFree;
		for( ; tmp!=NULL; tmp=tmp->pNext)
			strcpy(tmp->str, "*");
		for(tmp=mem.pFirst; tmp<=mem.pLast; tmp++) {
			if(strstr(tmp->str, "*"))
				tmp->str[strlen(tmp->str)-1] = '\0';
			else
				delete tmp;
		}
	}

 void TLink::PrintFree() {
		TLink *tmp = mem.pFree;
		for( ; tmp!=NULL; tmp=tmp->pNext)
			std::cout << tmp -> str << std::endl;
	}
