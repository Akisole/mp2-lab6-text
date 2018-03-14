#include "TText.h"
using namespace std;


TMem TLink::mem;

void main () {
	char name[] ="file.txt";
	setlocale(LC_ALL, "rus");

	TLink::InitMem(20);
	TText Text;
	Text.Read(name);

	Text.Print();
	cout << endl << "Выберите действие: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "Пункт: ";
	int m=0, tmp1, tmp2;
	while (m != 7) {
		switch (m) {
		case 1: Text.GoNextLink(); system("cls"); Text.Print(); cout << endl; 
			cout << "Выберите действие: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "Пункт: ";
			break;
		case 2: Text.GoDownLink(); system("cls"); Text.Print(); cout << endl; 
			cout << "Выберите действие: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "Пункт: ";
			break;
		case 3: Text.GoPrevLink(); system("cls"); Text.Print(); cout << endl; 
			cout << "Выберите действие: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "Пункт: ";
			break;
		case 4: system("cls"); Text.Print(); cout << endl;
			char ch[80]; tmp1=tmp2=0;
			cout << "Выберите действие: 1.InsNext 2.InsDown\n" << "Пункт: ";
			cin >> tmp1;
			if (tmp1 == 1) {
				system("cls"); Text.Print(); cout << endl;
				cout << "Выберите действие: 1.InsNextLine 2.InsNextSection\n" << "Пункт: ";
				cin >> tmp2;
				if (tmp2 == 1) {
					cout << "Введите строку: ";
					cin >> ch;
					Text.InsNextLine(ch);
				}
				if (tmp2 == 2) {
					cout << "Введите строку: ";
					cin >> ch;
					Text.InsNextSection(ch);
				}
			}
			if (tmp1 == 2) {
				system("cls"); Text.Print(); cout << endl;
				cout << "Выберите действие: 1.InsDownLine 2.InsDownSection\n" << "Пункт: ";
				cin >> tmp2;
				if (tmp2 == 1) {
					cout << "Введите строку: ";
					cin >> ch;
					Text.InsDownLine(ch);
				}
				if (tmp2 == 2) {
					cout << "Введите строку: ";
					cin >> ch;
					Text.InsDownSection(ch);
				}
			}
			system("cls"); Text.Print(); cout << endl;
			cout << "Выберите действие: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "Пункт: ";
			break;
		case 5: system("cls"); Text.Print(); cout << endl;
			tmp1=0;
			cout << "Выберите действие: 1.DelNext 2.DelDown\n" << "Пункт: ";
			cin >> tmp1;
			if (tmp1 == 1) Text.DelNext();
			if (tmp1 == 2) Text.DelDown();
			system("cls"); Text.Print(); cout << endl;
			cout << "Выберите действие: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "Пункт: ";
			break;
		case 6: system("cls"); Text.Print(); cout << endl;
			tmp1=0;
			cout << "Точно сохранить? 1.Да 2.Нет\n" << "Пункт: ";
			cin >> tmp1;
			if(tmp1 == 1) Text.Save(name);
			system("cls"); Text.Print(); cout << endl;
			cout << "Выберите действие: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "Пункт: ";
			break;
		}
		cin >> m;
	}
	cout << "Список свободных: " << endl;
	TLink::PrintFree();
	cout << "Чистка памяти. " << endl;
	TLink::MemClean(Text);
	cout << "Список свободных: " << endl;
	TLink::PrintFree();
}