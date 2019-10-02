#include <iostream>

using namespace std;

//Dinh nghia ham tinh giai thua
static long fact(int n)
{
    //Tinh n giai thua
    int kq=1;
    for (int i=2; i<=n; i++)
        kq *= i;
    return kq;
}

int main()
{
    //Goi ham fact, do ham fact la static nen khong can tao doi tuong de goi ham
    long S = fact(7) + fact(10) + fact(12) + fact(14);

    //In ket qua ra man hinh
    cout << "Sum = " << S << endl;
}
