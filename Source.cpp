#include "Keeper.h"

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

        cout << "1. ????????" << endl;
        cout << "2. ???????" << endl;
        cout << "3. ??????? ?? ?????" << endl;
        cout << "4. ??????? ?? ????? ?? ??????? ????" << endl;
        cout << "5. ?????" << endl;

        cout << "???????? ?????: ";
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
                    cout << "???????? ????????? ??????: ";
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
                cout << "???????? ???: ";
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
                cout << "??? ?????? ???????? ?????." << endl;
        }
        cout << endl;
    }

    return 0;
}