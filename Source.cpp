#include "Keeper.h"
#include "string.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
	String str;
	Keeper kpr;
	int ch;
	bool flag = true;
	setlocale(LC_ALL, "Russian");

	while (flag) {

		cout << "1. Добавить" << endl;
		cout << "2. Удалить" << endl;
		cout << "3. Вывести на экран" << endl;
		cout << "4. Вывести на экран по нужному типу" << endl;
		cout << "5. Выход" << endl;

		cout << "Выберете пункт: ";
		cin >> ch;
		cin.get();
		cout << endl;

		switch (ch) {
		case 1:
			try {
				cin >> kpr;
			}
			catch (exceptions &e) {
				cout << e.what() << endl;
			}
			break;
		case 2:
			cout << kpr;
			if (kpr.GetSize()) {
				cout << "Выберете удаляемую запись: ";
				cin >> ch;
				cin.get();
				try {
					kpr.remove(--ch);
				}
				catch (exceptions &e) {
					cout << e.what() << endl;
				}
			}
			break;
		case 3:
			cout << kpr;
			break;
		case 4:
			cout << "Выберете тип: ";
			cin >> str;
			cout << endl;
			try {
				kpr.print(str);
			}
			catch (exceptions &e) {
				cout << e.what() << endl;
			}
			break;
		case 5:
			flag = false;
			break;
		default:
			cout << "Был выбран неверный пункт." << endl;
		}
		cout << endl;
	}

	return 0;
}