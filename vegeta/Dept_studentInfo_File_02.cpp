#include <iostream>
#include <fstream>
using namespace std;
class student
{
    int rollno;
    char name[20];
    char div[20];
    char address[40];

public:
    void setData()
    {
        cout << "Enter roll no : " << endl;
        cin >> rollno;
        cout << "Enter name : " << endl;
        cin >> name;
        cout << "Enter Division : " << endl;
        cin >> div;
        cout << "Enter Address: " << endl;
        cin.ignore();
        cin.get(address, 40);
    }
    void showData()
    {
        cout << "Roll no of student is : " << rollno << endl;
        cout << "Name of student is : " << name << endl;
        cout << "Division of student is : " << div << endl;
        cout << "Address of student is : " << address << endl;
    }
    int retrollno()
    {
        return rollno;
    }
};

void write_record()
{
    ofstream of;
    of.open("stud.dat", ios ::app);
    student obj;
    obj.setData();
    of.write((char *)&obj, sizeof(obj));
    of.close();
}
void display()
{
    ifstream iffile;
    iffile.open("stud.dat", ios ::binary);
    student obj;
    while (iffile.get((char *)&obj, sizeof(obj)))
    {
        obj.showData();
    }
    iffile.close();
}
void search(int n)
{
    ifstream iffile;
    int flag = 0;
    iffile.open("stud.dat", ios ::binary);
    student obj;
    while (iffile.get((char *)&obj, sizeof(obj)))
    {
        if (obj.retrollno() == n)
        {
            obj.showData();
            flag = 1;
            break;
        }
    }
     iffile.close();
    if (flag == 0)
    {
        cout << "Data not present"<<endl;
    }
   
}
void del(int n)
{
    ifstream iffile;
    int flag = 0;
    ofstream of;
    iffile.open("stud.dat", ios ::binary);
    of.open("temp.txt", ios ::app);
    student obj;
    while (iffile.get((char *)&obj, sizeof(obj)))
    {
        if (obj.retrollno() != n)
        {
            of.write((char *)&obj, sizeof(obj));
            flag = 1;
            break;
        }
        iffile.close();
        of.close();
    }
    if (flag == 1)
    {
        cout << "Record not found" << endl;
    }
    cout << "Record Deleted" << endl;
     rename("stud.dat", "temp.txt");
    remove("stud.dat");
   
}
int main()
{
    int n;
    char ch;
    do
    {
        cout << "===========Student Record==========" << endl;
        cout << "1.Write Record" << endl;
        cout << "2.Display" << endl;
        cout << "3.Search" << endl;
        cout << "4.delete Record" << endl;

        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            write_record();
            break;

        case '2':
            display();
            break;

        case '3':
            cout << "Enter roll no u wanna search" << endl;
            cin >> n;
            search(n);
            break;
        case '4':
            cout << "Enter which roll no record u wanna delete" << endl;
            cin >> n;
            del(n);
            break;
        case '0':
            exit(0);
        }
    } while (ch != 0);
    return 0;
}
