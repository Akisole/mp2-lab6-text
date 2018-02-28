#include "TText.h"
using namespace std;

void main () {
	setlocale(LC_ALL, "rus");

	TText Text;

	char name[] ="file.txt";
	Text.Read(name);
	Text.Print();

}