#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

//структура данных из файла
struct Student
{
    string LastName;
    string Name;
    string Patronymc;
    int YearStart;
    int YearFinish;
    string Type;
};

//структура для статистики
struct Static
{
    int Bachelor;
    int Master;
    int Specialty;
};

//подсчет количества строк в файле с данными
int count_str_rom_file(char* filename)
{
    int countStr = 0;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream ff(filename);
    if(ff)
    {
        char *str = new char[1024];
        while(!ff.eof())
        {
            ff.getline(str, 1024, '\n');
            countStr++;
        }
        ff.close();
    }else
        cout<<"Open file error";
    return countStr;
}

//чтение данных из файла
void input_from_file(char* filename, Student* Students, int countStr)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream ff(filename);
    if(ff)
    {
        for(int i=0; i<countStr;i++)
        {
            ff>>Students[i].LastName;
            ff>>Students[i].Name;
            ff>>Students[i].Patronymc;
            ff>>Students[i].YearStart;
            ff>>Students[i].YearFinish;
            ff>>Students[i].Type;
        }
        ff.close();
    }else
        cout<<"Open file error";
}

//вывод данных на экран
void output (Student* Students, int countStr)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<setw(3)<<"№"<<"  "<<setw(15)<<"Фамилия"<<"\t"<<setw(15)<<"Имя"<<"\t"<<setw(15)<<"Отчество"<<"\t"<<setw(15)<<"Год поступления"<<"\t"<<setw(15)<<"Год окончания"<<"\t"<<setw(15)<<"Уровень"<<endl;

    for(int i =0; i<countStr;i++)
    {
        cout<<setw(3)<<i+1<<"  ";
        cout<<setw(15)<<Students[i].LastName<<"\t";
        cout<<setw(15)<<Students[i].Name<<"\t";
        cout<<setw(15)<<Students[i].Patronymc<<"\t";
        cout<<setw(15)<<Students[i].YearStart<<"\t";
        cout<<setw(15)<<Students[i].YearStart<<"\t";
        cout<<setw(15)<<Students[i].Type<<"\t";
        cout<<endl;
    }
}

//редактирование данных
void edit_data(Student* Students, int countStr)
{
    cout<<endl<<"Выберите номер строки: ";
    int number = 0;
    cin >>number;

    if (number<=countStr)
    {
        cout<<endl<<"Фамилия: "<<Students[number-1].LastName;
        cout<<endl<<"Имя: "<<Students[number-1].Name;
        cout<<endl<<"Отчество: "<<Students[number-1].Patronymc;
        cout<<endl<<"Год поступления: "<<Students[number-1].YearStart;
        cout<<endl<<"Год окончания: "<<Students[number-1].YearFinish;
        cout<<endl<<"Уровень: "<<Students[number-1].Type;

        cout<<endl<<endl<<"Введите новые данные: ";
        cout<<endl<<"Фамилия: ";
        cin>>Students[number-1].LastName;
        cout<<endl<<"Имя: ";
        cin>>Students[number-1].Name;
        cout<<endl<<"Отчество: ";
        cin>>Students[number-1].Patronymc;
        cout<<endl<<"Год поступления: ";
        cin>>Students[number-1].YearStart;
        cout<<endl<<"Год окончания: ";
        cin>>Students[number-1].YearFinish;
        cout<<endl<<"Уровень: ";
        cin>>Students[number-1].Type;

        output(Students, countStr);
    }
    else cout<<endl<<"Вы выбрали значение выходящее за диапазон";
}

//сохранение данных
void save_data(Student* Students, int countStr)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<endl<<"Введите название нового файла: ";
    string nameFile;
    cin>> nameFile;

    ofstream ff;
    ff.open(nameFile+".txt");
    for(int i =0; i<countStr;i++)
    {
        ff<<Students[i].LastName<<" ";
        ff<<Students[i].Name<<" ";
        ff<<Students[i].Patronymc<<" ";
        ff<<Students[i].YearStart<<" ";
        ff<<Students[i].YearFinish<<" ";
        ff<<Students[i].Type<<" ";
        ff<<endl;
    }
    ff.close();

    cout<<"Данные сохранены в файлe с названием "<<nameFile<<".txt"<<endl;
}

//вычисление статистики
void static_data (Student *Students, int countStr)
{
    Static statistical;
    statistical.Bachelor = 0;
    statistical.Master = 0;
    statistical.Specialty = 0;
    for(int i = 0; i<countStr;i++)
    {
        if((Students[i].Type.find("Бак")!=-1)||(Students[i].Type.find("Bach")!=-1))
            statistical.Bachelor++;
        if((Students[i].Type.find("Маги")!=-1)||(Students[i].Type.find("Mast")!=-1))
            statistical.Master++;
        if((Students[i].Type.find("Спец")!=-1)||(Students[i].Type.find("Spec")!=-1))
            statistical.Specialty++;
    }

    cout<<endl<<"Итоги статистики: ";
    cout<<endl<<"Количество бакалавров: "<<statistical.Bachelor;
    cout<<endl<<"Количество магистров: "<<statistical.Master;
    cout<<endl<<"Количество специалистов: "<<statistical.Specialty;
    cout<<endl<<"Общее количество записей: "<<countStr;
}

//главная функция - меню
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool start = true;

    cout<<"Введите путь к файлу с данными: ";
    char* path = new char[1024];
    cin>>path;

    int countStr = count_str_rom_file(path);
    Student *Students = new Student[countStr];
    if(countStr==0)
    {
        start = false;
    }
    else
    {
        input_from_file(path, Students, countStr);
        output(Students, countStr);
    }

    while(start)
    {
        cout<<endl<<endl<<"Выберите пункт меню: 1 - Редактировать данные, 2 - Статистика, 3 - Сохранить данные, 4 - Закончить"<<endl;
        int menu = 0;
        cin>>menu;

        if(menu == 1)
        {
            edit_data(Students, countStr);
        }
        else if (menu == 2)
        {
            static_data(Students, countStr);
        }
        else if (menu == 3)
        {
            save_data(Students, countStr);
        }
        else if(menu == 4)
        {
            start = false;
            delete Students;
        }
    }
    return 0;
}
