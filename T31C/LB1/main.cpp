#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

using namespace std;

//��������� ������ �� �����
struct Student
{
    string LastName;
    string Name;
    string Patronymc;
    int YearStart;
    int YearFinish;
    string Type;
};

//��������� ��� ����������
struct Static
{
    int Bachelor;
    int Master;
    int Specialty;
};

//������� ���������� ����� � ����� � �������
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

//������ ������ �� �����
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

//����� ������ �� �����
void output (Student* Students, int countStr)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<setw(3)<<"�"<<"  "<<setw(15)<<"�������"<<"\t"<<setw(15)<<"���"<<"\t"<<setw(15)<<"��������"<<"\t"<<setw(15)<<"��� �����������"<<"\t"<<setw(15)<<"��� ���������"<<"\t"<<setw(15)<<"�������"<<endl;

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

//�������������� ������
void edit_data(Student* Students, int countStr)
{
    cout<<endl<<"�������� ����� ������: ";
    int number = 0;
    cin >>number;

    if (number<=countStr)
    {
        cout<<endl<<"�������: "<<Students[number-1].LastName;
        cout<<endl<<"���: "<<Students[number-1].Name;
        cout<<endl<<"��������: "<<Students[number-1].Patronymc;
        cout<<endl<<"��� �����������: "<<Students[number-1].YearStart;
        cout<<endl<<"��� ���������: "<<Students[number-1].YearFinish;
        cout<<endl<<"�������: "<<Students[number-1].Type;

        cout<<endl<<endl<<"������� ����� ������: ";
        cout<<endl<<"�������: ";
        cin>>Students[number-1].LastName;
        cout<<endl<<"���: ";
        cin>>Students[number-1].Name;
        cout<<endl<<"��������: ";
        cin>>Students[number-1].Patronymc;
        cout<<endl<<"��� �����������: ";
        cin>>Students[number-1].YearStart;
        cout<<endl<<"��� ���������: ";
        cin>>Students[number-1].YearFinish;
        cout<<endl<<"�������: ";
        cin>>Students[number-1].Type;

        output(Students, countStr);
    }
    else cout<<endl<<"�� ������� �������� ��������� �� ��������";
}

//���������� ������
void save_data(Student* Students, int countStr)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<endl<<"������� �������� ������ �����: ";
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

    cout<<"������ ��������� � ����e � ��������� "<<nameFile<<".txt"<<endl;
}

//���������� ����������
void static_data (Student *Students, int countStr)
{
    Static statistical;
    statistical.Bachelor = 0;
    statistical.Master = 0;
    statistical.Specialty = 0;
    for(int i = 0; i<countStr;i++)
    {
        if((Students[i].Type.find("���")!=-1)||(Students[i].Type.find("Bach")!=-1))
            statistical.Bachelor++;
        if((Students[i].Type.find("����")!=-1)||(Students[i].Type.find("Mast")!=-1))
            statistical.Master++;
        if((Students[i].Type.find("����")!=-1)||(Students[i].Type.find("Spec")!=-1))
            statistical.Specialty++;
    }

    cout<<endl<<"����� ����������: ";
    cout<<endl<<"���������� ����������: "<<statistical.Bachelor;
    cout<<endl<<"���������� ���������: "<<statistical.Master;
    cout<<endl<<"���������� ������������: "<<statistical.Specialty;
    cout<<endl<<"����� ���������� �������: "<<countStr;
}

//������� ������� - ����
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool start = true;

    cout<<"������� ���� � ����� � �������: ";
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
        cout<<endl<<endl<<"�������� ����� ����: 1 - ������������� ������, 2 - ����������, 3 - ��������� ������, 4 - ���������"<<endl;
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
