#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, i;

    //Nhap du lieu tu ban phim
    cout << "N = ";
    cin >> N;

    //Kiem tra so nguyen to
    if (N<2){
        cout << "N khong phai so nguyen to" << endl;
        return 0;
    }
    for (i=2; i<=round(sqrt(N)); i++)
        if (N%i == 0) break;
    if (i<=round(sqrt(N)))
        cout << "N khong phai so nguyen to" << endl;
    else
        cout << "N la so nguyen to" << endl;
}
