#include "Stack.h"
#include <string.h>

class TLink {
public:
	char str[80];
	TLink *pNext, *pDown;

	TLink (char *s = NULL, TLink *pN = NULL, TLink *pD = NULL) {
		
	}
	~TLink();

};


class TText {
	TLink *pFirsr, *pCurr;
	TStack<TLink*> st;
public:
	TText();

	void GoNextLink() {
		if (pCurr->pNext!=NULL) {
			st.Push(pCurr);
			pCurr = pCurr->pNext;
		}
	}
	void GoDownLink() {
		if (pCurr->pDown!=NULL) {
			st.Push(pCurr);
			pCurr = pCurr->pDown;
		}
	}
	void GoPrevLink() {
		if (!st.IsEmpty()) 
			pCurr = st.Pop();
	}

	void InsNextLine (char *s) {
		TLink *p = new TLink(s, pCurr->pNext, NULL);
		pCurr->pNext=p;
	}
	void InsNextSection (char *s) {
		TLink *p = new TLink(s, NULL, pCurr->pNext);
		pCurr->pNext=p;
	}
	void InsDownLine (char *s) {
		TLink *p = new TLink(s, pCurr->pDown, NULL);
		pCurr->pDown=p;
	}
	void InsDownSection (char *s) {
		TLink *p = new TLink(s, NULL, pCurr->pDown);
		pCurr->pDown=p;
	}

	void DelNext() {
		if (pCurr->pNext != NULL) {
			TLink *tmp = pCurr->pNext;
			pCurr->pNext = tmp->pNext;
			delete tmp;
		}
	}
	void DelDown() {
		if (pCurr->pDown != NULL) {
			TLink *tmp = pCurr->pDown;
			pCurr->pDown = tmp->pNext;
			delete tmp;
		}
	}


};