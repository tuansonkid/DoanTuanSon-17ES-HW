#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class Student
{
private:
    int id;
    string name;
    float aver;

public:
    Student(){
        name = "";
        id = 0;
        aver = 0;
    }

    Student(int i, string n, float a){
        id = i;
        name = n;
        aver = a;
    }

    string getName(){
        return name;
    }

    int getId(){
        return id;
    }

    float getAver(){
        return aver;
    }
};

class StudentManagement : Student
{
private:
    int num;
//    vector<Student> list;
    Student *list;

public:
    StudentManagement(){
        while(true){
            cout << "*-CHUONG TRINH QUAN LY SINH VIEN-*";
            cout << "\n*-Chuc nang chinh chuong trinh-*";
            cout << "\n 1.Nhap danh sach sinh vien ";
            cout << "\n 2.Xem danh sach sinh vien ";
            cout << "\n 3.Sap xep danh sach sinh vien tang dan diem trung binh ";
            cout << "\n 4.Tim sinh vien theo ten ";
            cout << "\n 5.Thoat " << endl;

            int num;
            cout << " Nhap mot so de chon chuc nang: ";
            cin >> num;
            switch(num){
            case 1:
                input();
                break;
            case 2:
                view();
                break;
            case 3:
                sort();
                break;
            case 4:
                search();
                break;
            case 5:
                cout << "---- Chuong trinh ket thuc ----";
            return;
            }
        }
    }

    void input(){
        cout << " Nhap so luong sinh vien: ";
        cin >> num;
        list = new Student[num];
        for(int i=1; i<=num; i++){
            cout << " Nhap thong tin cho sinh vien thu: " << i << endl;

            cout << " ID: ";
            int id;
            cin >> id;

            cout << " Ten: ";
            string name;
            cin >> name;

            cout << " Diem trung binh: ";
            float aver;
            cin >> aver;

            Student st(id,name,aver);
            list[i-1] = st;
//            list.push_back(st);
        }
        cout << "\n--------\n" << endl;
    }

    void view(){
        cout << " Thong tin danh sach sinh vien" << endl;
        for(int i=1; i<=num; i++)
            cout << "   " << i << ". ID = " << list[i-1].getId() << ", Ten = " << list[i-1].getName() << ", Diem trung binh = " << list[i-1].getAver() << endl;
        cout << "\n--------\n" << endl;
    }

    void sort(){
        for(int i=2; i<=num; i++)
            for(int j=1; j<i; j++)
                if (list[j-1].getAver()>list[i-1].getAver()){
                    Student sts;
                    sts = list[i-1];
                    list[i-1] = list[j-1];
                    list[j-1] = sts;
                }
        cout << "\n--Danh sach sinh vien sau khi sap xep--" << endl;
        for(int i=1; i<=num; i++)
            cout << "   " << i << ". ID = " << list[i-1].getId() << ", Ten = " << list[i-1].getName() << ", Diem trung binh = " << list[i-1].getAver() << endl;
        cout << "\n--------\n" << endl;
    }

    void search(){
        cout << "Nhap ten sinh vien can tim: ";
        string n;
        cin >> n;
        for(int i=1; i<=num; i++)
            if(list[i-1].getName()==n){
                cout << "ID = " << list[i-1].getId() << ", Ten = " << list[i-1].getName() << ", Diem trung binh = " << list[i-1].getAver() << endl;
                break;
            }
        cout << "\n--------\n" << endl;
    }
};

int main()
{
    StudentManagement();
    getch();
}
