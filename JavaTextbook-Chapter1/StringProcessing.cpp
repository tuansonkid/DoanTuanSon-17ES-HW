#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s = "Write a Java program very easily";

    //Dung de chua so luong ky tu 'a' co trong chuoi
    int count=0;

    //Dem so ki tu 'a'
    for (int i=0; i<s.length(); i++)
        if (s.at(i) == 'a') count++;
    cout << "so luong ky tu a co trong chuoi = " << count << endl;

    //Kiem tra chuoi co chua tu "Java" hay khong
    int index = s.find("Java");
    if (index>=0) cout << "Tu Java dau tien cua chuoi o vi tri " << index << endl;
    else cout << "Chuoi khong chua tu Java" << endl;

    //Kiem tra chuoi co bat dau bang cum tu "Write"
    if (s.find("Write")==0) cout << "Tu Write bat dau chuoi" << endl;
    else cout << "Tu Write khong bat dau chuoi" << endl;

    //Kiem tra chuoi co ket thuc bang tu "easily"
    if (s.find("easily")==s.length()-6) cout << "Tu easily ket thuc chuoi" << endl;
    else cout << "Tu easily khong ket thuc chuoi" << endl;
}
