#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Static
{
    int Bachelor;
    int Master;
    int Specialty;
};

class Student
{
    public: Student();
            Student(string LastNameStr, string NameStr, string PatronymicStr, int YearStartStr, int YearFinishStr, string TypeStr);
            string getLastName();
            string getName();
            string getPtronymic();
            int getYearStart();
            int getYearFinish();
            string getType();
            void setLastName(string tmp);
            void setName(string tmp);
            void setPatronymic(string tmp);
            void setYearStart(int tmp);
            void setYearFinish(int tmp);
            void setType(string tmp);
    private: string LastName;
             string Name;
             string Patronymic;
             int YearStart;
             int YearFinish;
             string Type;
};

void static_data(Student * Students)
{
    Static statistical;
    statistical.Bachelor = 0;
    statistical.Master = 0;
    statistical.Specialty = 0;
    for(int i = 0; i<3;i++)
    {
        if((Students[i].getType().find("���")!=-1)||(Students[i].getType().find("Bach")!=-1))
            statistical.Bachelor++;
        if((Students[i].getType().find("����")!=-1)||(Students[i].getType().find("Mast")!=-1))
            statistical.Master++;
        if((Students[i].getType().find("����")!=-1)||(Students[i].getType().find("Spec")!=-1))
            statistical.Specialty++;
    }

    cout<<endl<<"����� ����������: ";
    cout<<endl<<"���������� ����������: "<<statistical.Bachelor;
    cout<<endl<<"���������� ���������: "<<statistical.Master;
    cout<<endl<<"���������� ������������: "<<statistical.Specialty;
    cout<<endl<<"����� ���������� �������: "<<3;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student man; //����� ������������ �� ��������
    Student woman("�������", "����", "��������", 2016, 2020, "��������"); //����� ������������ � �����������

    man.setLastName("������");
    man.setName("����");
    man.setPatronymic("��������");
    man.setYearStart(2020);
    man.setYearFinish(2022);
    man.setType("�������");

    cout<<endl<<"�������: ";
    cout<<endl<<"���: "<<woman.getLastName()<<" "<<woman.getName()<<" "<<woman.getPtronymic();
    cout<<endl<<"���� ��������: "<<woman.getYearStart()<<" - "<<woman.getYearFinish();
    cout<<endl<<"�������: "<<woman.getType()<<endl;

    Student students[3];
    string LastName;
    string Name;
    string Patronymic;
    int YearStart;
    int YearFinish;
    string Type;

    for(int i =0; i<3; i++)
    {
        cout<<endl<<"�������: ";
        cin>>LastName;
        students[i].setLastName(LastName);

        cout<<endl<<"���: ";
        cin>>Name;
        students[i].setName(Name);

        cout<<endl<<"��������: ";
        cin>>Patronymic;
        students[i].setPatronymic(Patronymic);

        cout<<endl<<"��� �����������: ";
        cin>>YearStart;
        students[i].setYearStart(YearStart);

        cout<<endl<<"��� ���������: ";
        cin>>YearFinish;
        students[i].setYearFinish(YearFinish);

        cout<<endl<<"�������: ";
        cin>>Type;
        students[i].setType(Type);
    }

    cout<<endl;
    cout<<setw(3)<<"�"<<"  "<<setw(15)<<"�������"<<"\t"<<setw(15)<<"���"<<"\t"<<setw(15)<<"��������"<<"\t"<<setw(15)<<"��� �����������"<<"\t"<<setw(15)<<"��� ���������"<<"\t"<<setw(15)<<"�������"<<endl;
    for (int i=0; i<3; i++)
    {
        cout<<setw(3)<<i+1<<"  ";
        cout<<setw(15)<<students[i].getLastName()<<"\t";
        cout<<setw(15)<<students[i].getName()<<"\t";
        cout<<setw(15)<<students[i].getPtronymic()<<"\t";
        cout<<setw(15)<<students[i].getYearStart()<<"\t";
        cout<<setw(15)<<students[i].getYearFinish()<<"\t";
        cout<<setw(15)<<students[i].getType()<<"\t";
        cout<<endl;
    }

    static_data(students);

    return 0;
}

Student::Student()
{
    LastName = "�� ���������";
    Name = "�� ���������";
    Patronymic = "�� ���������";
    YearStart = 1900;
    YearFinish = 1900;
    Type = "�� ���������";
}

Student::Student(string LastNameStr, string NameStr, string PatronymicStr, int YearStartStr, int YearFinishStr, string TypeStr)
{
    LastName = LastNameStr;
    Name = NameStr;
    Patronymic = PatronymicStr;
    YearStart = YearStartStr;
    YearFinish = YearFinishStr;
    Type = TypeStr;
}

string Student::getLastName()
{
    return LastName;
}

string Student::getName()
{
    return Name;
}

string Student::getPtronymic()
{
    return Patronymic;
}

int Student::getYearStart()
{
    return YearStart;
}

int Student::getYearFinish()
{
    return YearFinish;
}

string Student::getType()
{
    return Type;
}

void Student::setLastName(string tmp)
{
    LastName = tmp;
}

void Student::setName(string tmp)
{
    Name = tmp;
}

void Student::setPatronymic(string tmp)
{
    Patronymic = tmp;
}

void Student::setYearStart(int tmp)
{
    YearStart = tmp;
}

void Student::setYearFinish(int tmp)
{
    YearFinish = tmp;
}

void Student::setType(string tmp)
{
    Type = tmp;
}

