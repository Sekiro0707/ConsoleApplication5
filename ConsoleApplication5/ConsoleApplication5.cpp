#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


struct delo
{
    string name;
    int prior;
    string ops;
    string date;
};

void delet(delo* mas, int size, int index)
{
    bool b = 0;
    cout << "вы точно хотите удалить:  " << mas[index].name; cin >> b;
    if (b)
    {
        mas[index].name = '/0';


    }
}


void wod(delo& d)
{
    cout << "Введите название задания: "; cin >> d.name;
    cout << "Введите приоритет задания (от 1 до 10 где 1 наивысший приоритет!):"; cin >> d.prior;
    cout << "Введите  описание задания: "; cin >> d.ops;
    cout << "Введите  дату задания в формате день /неделя/месяц "; cin >> d.date;


}

void edit(delo* mas, int size, int index)
{
    if (index > size)
    {
        cout << "такого задания не введено" << endl;
        return;
    }
    cout << "Введите новое имя:" << endl; cin >> mas[index].name;
    cout << "введите новый приоритет:" << endl;cin >> mas[index].prior;
    cout << "Введите новое описание:" << endl; cin >> mas[index].ops;
    cout << "Введите новую дату:  в формате день /неделя/месяц  00/00/00 " << endl;  cin >> mas[index].date;
}

int find(delo* mas, int size, int prior, string name = "", string ops = "", string date = "")
{
    for (int i = 0; i < size; i++)
    {
        if (mas[i].name == name)
        {
            return i;
        }
        else if (mas[i].prior == prior)
        {
            return i;
        }
        else if (mas[i].ops == ops)
        {
            return i;
        }
        else if (mas[i].date == date)
        {
            return i;
        }
    }
    cout << "Такое задание отсутствует! " << endl;
    return -1;
}

void outo(delo* date)
{
    string date1 = "";
    int a = 0;
    int d = 0, n = 0, m = 0;
    cout << "хотите отобразить все дела на день, на неделю или на месяц? нажмите от 1 до 3:"; cin >> a;
    if (a > 3)
    {
        cout << "нет такого параметра"  "\n" << "попробуй еще раз"; cin >> a;

    }
    else if (a = 1)
    {
        getline(date, date1);


    }
}

void sort(delo* mas, int size, int prior, string date = "")
{

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string d = 0, t = 0;

    string name = "";
    int prior = 1;
    string ops = "";
    string date = "";
    short menu = -1;
    do
    {
        cout << "MENU";
        cout << "1 - Ввести новую задачу;" << endl;
        cout << "2 - Удалить задачу;" << endl;
        cout << "3 - редактировать задание;" << endl;
        cout << "4 - найти задание;" << endl;
        cout << "5 - вывести на экран задания;" << endl;
        cout << "6 - отсортировать задания;" << endl;
        cout << "Оберіть пункт меню: " << endl;
        cin >> menu;
        system("cls");
        switch (menu)
        {
        case 1:

            wod();

            break;
        case 2:
            delet();

            break;
        case 3:
            edit();
        case 4:
            find();

        case 5:
            outo();
        case 6:
            sort();

        }
    }