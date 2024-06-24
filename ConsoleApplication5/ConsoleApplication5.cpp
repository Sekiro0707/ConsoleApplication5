#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;



struct delo {
    string name;
    int prior;
    string ops;
    string date;
};

void delet(delo* mas, int size, int index) {
    bool b = 0;
    cout << "Ви точно хочете видалити: " << mas[index].name << "? (1 - так, 0 - ні) ";
    cin >> b;
    if (b) {
        mas[index].name = "";
    }
}

void wod(delo& d) {
    cout << "Введите название задания: ";
    cin.ignore();
    getline(cin, d.name);
    cout << "Введите приоритет задания (от 1 до 10 где 1 наивысший приоритет!): ";
    cin >> d.prior;
    cout << "Введите описание задания: ";
    cin.ignore();
    getline(cin, d.ops);
    cout << "Введите дату задания в формате день/неделя/месяц: ";
    getline(cin, d.date);
}

void edit(delo* mas, int size, int index) {
    if (index >= size) {
        cout << "Такого задания не введено" << endl;
        return;
    }
    cout << "Введите новое имя: ";
    cin.ignore();
    getline(cin, mas[index].name);
    cout << "Введите новый приоритет: ";
    cin >> mas[index].prior;
    cout << "Введите новое описание: ";
    cin.ignore();
    getline(cin, mas[index].ops);
    cout << "Введите новую дату в формате день/неделя/месяц: ";
    getline(cin, mas[index].date);
}

int find(delo* mas, int size, int prior, string name = "", string ops = "", string date = "") {
    for (int i = 0; i < size; i++) {
        if ((name != "" && mas[i].name == name) ||
            (prior != -1 && mas[i].prior == prior) ||
            (ops != "" && mas[i].ops == ops) ||
            (date != "" && mas[i].date == date)) {
            return i;
        }
    }
    cout << "Такое задание отсутствует! " << endl;
    return -1;
}

void outo(delo* mas, int size) {
    string date1 = "";
    int a = 0;
    cout << "Хотите отобразить все дела на день, на неделю или на месяц? нажмите от 1 до 3: ";
    cin >> a;
    if (a > 3) {
        cout << "Нет такого параметра" << "\n" << "Попробуйте еще раз: ";
        cin >> a;
    }
    else {
        cout << "Введите дату в формате день/неделя/месяц: ";
        cin.ignore();
        getline(cin, date1);
        for (int i = 0; i < size; i++) {
            if ((a == 1 && mas[i].date.substr(0, 2) == date1.substr(0, 2)) ||
                (a == 2 && mas[i].date.substr(3, 2) == date1.substr(3, 2)) ||
                (a == 3 && mas[i].date.substr(6, 2) == date1.substr(6, 2))) {
                cout << mas[i].name << " " << mas[i].prior << " " << mas[i].ops << " " << mas[i].date << endl;
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<delo> tasks;
    delo tempTask;

    short menu = -1;
    do {
        cout << "Список справ" <<endl;
        cout << "MENU" << endl;
        cout << "1 - Ввести новую задачу;" << endl;
        cout << "2 - Удалить задачу;" << endl;
        cout << "3 - Редактировать задание;" << endl;
        cout << "4 - Найти задание;" << endl;
        cout << "5 - Вывести на экран задания;" << endl;
        cout << "Оберіть пункт меню: ";
        cin >> menu;
        system("cls");
        int index = 0;

        switch (menu) {
        case 1:
            wod(tempTask);
            tasks.push_back(tempTask);
            break;
        case 2:
            cout << "Введите индекс задачи для удаления: ";
            cin >> index;
            if (index >= 0 && index < tasks.size()) {
                delet(tasks.data(), tasks.size(), index);
            }
            else {
                cout << "Неверный индекс" << endl;
            }
            break;
        case 3:
            cout << "Введите индекс задачи для редактирования: ";
            cin >> index;
            if (index >= 0 && index < tasks.size()) {
                edit(tasks.data(), tasks.size(), index);
            }
            else {
                cout << "Неверный индекс" << endl;
            }
            break;
        case 4:
            int prior;
            string name, ops, date;
            cout << "Введите приоритет (или -1 для пропуска): ";
            cin >> prior;
            cout << "Введите имя (или пустую строку для пропуска): ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите описание (или пустую строку для пропуска): ";
            getline(cin, ops);
            cout << "Введите дату (или пустую строку для пропуска): ";
            getline(cin, date);
            index = find(tasks.data(), tasks.size(), prior, name, ops, date);
            if (index != -1) {
                cout << "Найдено задание: " << tasks[index].name << " " << tasks[index].prior << " " << tasks[index].ops << " " << tasks[index].date << endl;
            }
            break;
        case 5:
            outo(tasks.data(), tasks.size());
            break;
        case 0:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный пункт меню" << endl;
        }
    } while (menu != 0);

    return 0;
}
