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
	cout << endl << "�������� ��������: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "�����: ";
	int m=0, tmp1, tmp2;
	while (m != 7) {
		switch (m) {
		case 1: Text.GoNextLink(); system("cls"); Text.Print(); cout << endl; 
			cout << "�������� ��������: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "�����: ";
			break;
		case 2: Text.GoDownLink(); system("cls"); Text.Print(); cout << endl; 
			cout << "�������� ��������: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "�����: ";
			break;
		case 3: Text.GoPrevLink(); system("cls"); Text.Print(); cout << endl; 
			cout << "�������� ��������: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "�����: ";
			break;
		case 4: system("cls"); Text.Print(); cout << endl;
			char ch[80]; tmp1=tmp2=0;
			cout << "�������� ��������: 1.InsNext 2.InsDown\n" << "�����: ";
			cin >> tmp1;
			if (tmp1 == 1) {
				system("cls"); Text.Print(); cout << endl;
				cout << "�������� ��������: 1.InsNextLine 2.InsNextSection\n" << "�����: ";
				cin >> tmp2;
				if (tmp2 == 1) {
					cout << "������� ������: ";
					cin >> ch;
					Text.InsNextLine(ch);
				}
				if (tmp2 == 2) {
					cout << "������� ������: ";
					cin >> ch;
					Text.InsNextSection(ch);
				}
			}
			if (tmp1 == 2) {
				system("cls"); Text.Print(); cout << endl;
				cout << "�������� ��������: 1.InsDownLine 2.InsDownSection\n" << "�����: ";
				cin >> tmp2;
				if (tmp2 == 1) {
					cout << "������� ������: ";
					cin >> ch;
					Text.InsDownLine(ch);
				}
				if (tmp2 == 2) {
					cout << "������� ������: ";
					cin >> ch;
					Text.InsDownSection(ch);
				}
			}
			system("cls"); Text.Print(); cout << endl;
			cout << "�������� ��������: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "�����: ";
			break;
		case 5: system("cls"); Text.Print(); cout << endl;
			tmp1=0;
			cout << "�������� ��������: 1.DelNext 2.DelDown\n" << "�����: ";
			cin >> tmp1;
			if (tmp1 == 1) Text.DelNext();
			if (tmp1 == 2) Text.DelDown();
			system("cls"); Text.Print(); cout << endl;
			cout << "�������� ��������: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "�����: ";
			break;
		case 6: system("cls"); Text.Print(); cout << endl;
			tmp1=0;
			cout << "����� ���������? 1.�� 2.���\n" << "�����: ";
			cin >> tmp1;
			if(tmp1 == 1) Text.Save(name);
			system("cls"); Text.Print(); cout << endl;
			cout << "�������� ��������: 1.GoNex 2.GoDown 3.GoPrev 4.Ins 5.Del 6.Save 7.Exit\n" << "�����: ";
			break;
		}
		cin >> m;
	}
	cout << "������ ���������: " << endl;
	TLink::PrintFree();
	cout << "������ ������. " << endl;
	TLink::MemClean(Text);
	cout << "������ ���������: " << endl;
	TLink::PrintFree();
}