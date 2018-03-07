#include "Stack.h"
#include <string.h>

#include <fstream>
#include <iostream>

class TLink {
public:
	char str[80];
	TLink *pNext, *pDown;

	TLink (char *s = NULL, TLink *pN = NULL, TLink *pD = NULL) {
		pNext=pN;
		pDown=pD;
		if(s==NULL)
			str[0] = '\0';
		else strcpy(str,s);
	}
	~TLink(){}
};

class TText {
	TLink *pFirsr, *pCurr;
	TStack<TLink*> st;
	int lvl;
public:
	TText(){}

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

	TLink* ReadRec (std::ifstream& file) {
		char buf[80];
		TLink *tmp, *ftmp=NULL;
		while (!file.eof()) {
			file.getline(buf, 80, '\n');
			if(buf[0] == '}')
				break;
			else if (buf[0] == '{')
				tmp -> pDown = ReadRec(file);
			else {
				if(ftmp == NULL){
					ftmp = new TLink(buf);
					tmp = ftmp;
				}
				else {
					tmp -> pNext = new TLink(buf);
					tmp = tmp -> pNext;
				}
			}
		}
		return ftmp;
	}
	void Read (char *fn) {
		std::ifstream ifs(fn);
		pFirsr = ReadRec(ifs);
		pCurr = pFirsr;
	}

	void PrintRec (TLink *tmp) {
		if(tmp != NULL) {
			if (pCurr == tmp){
				std::cout << '>';
				for(int i=0; i<lvl+1; i++)
					std::cout << ' ';
			}
			else 
				for(int i=0; i<lvl+2; i++)
					std::cout << ' ';
			std::cout << tmp -> str << std::endl;
			lvl++;
			PrintRec(tmp->pDown);
			lvl--;
			PrintRec(tmp->pNext);
		}
	}
	void Print() {
		lvl = 0;
		PrintRec(pFirsr);
	}

	void SaveRec (TLink *tmp, std::ofstream &file){
		file << tmp->str << '\n';
		if(tmp->pDown != NULL) {
			file << "{\n";
			SaveRec(tmp->pDown, file);
			file << "}\n";
		}
		if(tmp->pNext != NULL)
			SaveRec(tmp->pNext, file);
	}
	void Save (char *fn) {
		std::ofstream ofs(fn);
		SaveRec(pFirsr, ofs);
	}

	TLink* CopyRec(TLink *tmp) {
		TLink *pN=NULL, *pD=NULL;
		if(tmp->pDown != NULL)
			pD = CopyRec(tmp->pDown);
		if(tmp->pNext != NULL)
			pN = CopyRec(tmp->pNext);
		TLink *zvn = new TLink(tmp->str, pN, pD);
		return zvn;
	}
	TLink* Copy() {
		return(pFirsr);
	}

	//Итерирование
	void Reset() {
		pCurr = pFirsr;
		st.Clear();
		st.Push(pCurr);
		if (pFirsr->pDown != NULL)
			st.Push(pFirsr->pDown);
		if (pFirsr->pNext != NULL)
			st.Push(pFirsr->pNext);
	}
	void GoNext() {
		pCurr = st.Pop();
		if(pCurr != pFirsr) {
			if(pCurr->pNext != NULL)
				st.Push(pCurr->pNext);
			if(pCurr->pDown != NULL)
				st.Push(pCurr->pDown);
		}
	}
	//IsEnd
};