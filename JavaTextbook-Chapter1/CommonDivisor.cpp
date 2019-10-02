#include <iostream>

using namespace std;

//Dinh nghia ham tinh uoc so chung lon nhat
static int comDiv(int a, int b)
{
    return (b==0)?a:comDiv(b, a%b);
}

int main()
{
    int a;
    int b;

    //Nhap du lieu tu ban phim
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    //Goi ham va in ket qua ra man hinh
    cout << "USCLN cua " << a << " va " << b << " la " << comDiv(a,b) << endl;
}
