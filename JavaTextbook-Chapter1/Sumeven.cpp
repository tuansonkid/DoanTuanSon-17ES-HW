#include <iostream>

using namespace std;

int main()
{
    int N;

    //Nhap gia tri N tu ban phim
    cout << "N = ";
    cin >> N;

    //Tinh tong
    int sum=0;
    for(int i=2; i<=N; i+=2) sum+=i;

    //Hien thi ket qua ra man hinh
    cout << "Sum = " << sum << endl;
}
