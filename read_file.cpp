#include "read_file.h"
#include <Windows.h>

using namespace std;

void printCal() {
    SetConsoleOutputCP(CP_UTF8);
    ifstream File("C:\\Users\\Nully\\CLionProjects\\lab_OOP1\\price.txt");
    if (!File.is_open()) {
        cerr << "Невдалося відкрити файл" << endl;
        return;
    }

    money total{0, 0};
    string line;

    regex rgx("(\\d+)\\s*грн\\s*(\\d{1,3})\\s*коп\\s*,\\s*(\\d+)\\s*шт");

    while (getline(File, line)) {
        smatch match;

        money prod{ 0, 0 };
        int quantity = 1;

        if (std::regex_search(line, match, rgx)) {
            prod.grn = stoi(match[1].str());
            prod.kop = stoi(match[2].str());
            quantity = stoi(match[3].str());

        } else {
            cout << "Помилка при обробці рядка: " << line << endl;
        }
        multiplyMoney(prod, quantity);
        addMoney(total, prod);
    }

    cout << "\nЗагальна сума: ";
    printMoney(total);
    cout << endl;

    aroundMoney(total);
    cout << "Сума після заокруглення: ";
    printMoney(total);
    cout << endl;

    File.close();
}
