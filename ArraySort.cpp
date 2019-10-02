#include <iostream>

using namespace std;

int main()
{
    //Tao va khoi tao gia tri cho mang
    int A[] = {5, 7, 2, 4, 8};

    //Sap xep mang theo chieu tang dan
    for (int i=0; i<sizeof(A)/sizeof(int)-1; i++)
        for (int j=i+1; j<sizeof(A)/sizeof(int); j++)
            if (A[i] > A[j]){
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }

    //In ra man hinh
    for (int i=0; i<sizeof(A)/sizeof(int); i++)
        cout << A[i] << " ";
}
