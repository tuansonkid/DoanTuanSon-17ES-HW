#include <iostream>

using namespace std;

int main()
{
    float a, b, c;

    //Nhập dữ liệu từ bàn phím
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    //Kiểm tra 3 cạnh tam giác có hợp lệ hay không
    if ((a+b>c) && (a+c>b) && (b+c>a) && (a>0) && (b>0) && (c>0)){
        cout << "a, b, c la canh cua " << endl;
        if ((a==b) && (b==c)) cout << "Tam giac deu" << endl;
        else
            if ((a==b) || (b==c) || (a==c)) cout << "Tam giac can" << endl;
            else
                if (((a*a + b*b == c*c) && (a==b)) || ((a*a + c*c == b*b) && (a==c)) ||
                    ((c*c + b*b == a*a) && (c==b))) cout << "Tam giac vuong can" << endl;
                else
                    if ((a*a == b*b + c*c) || (b*b == a*a + c*c) || (c*c == b*b + a*a))
                        cout << "Tam giac vuong" << endl;
                    else
                        cout << "Tam giac thuong" << endl;
    }
    else
        cout << "3 canh tam giac khong hop le" << endl;
}
