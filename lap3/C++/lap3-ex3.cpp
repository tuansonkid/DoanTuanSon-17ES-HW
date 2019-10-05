#include <iostream>
#include <conio.h>

using namespace std;

class Matrix
{
private:
    int n;
    int m;
    float data[100][100];
public:
    Matrix(){
    cout<<"Enter your matrix size: \nRow:     n = "; cin>>n;
    cout<<"Column:  m = "; cin>>m;
    cout<<endl;
    for (int i=0;i<n;i++)
        for(int j=0; j<m; j++){
            cout <<"data["<<i<<"]["<<j<<"]= ";
            cin >> data[i][j];
        }
    }

    Matrix(int N, int M){
        n = N;
        m = M;
        for (int i=0;i<n;i++)
            for(int j=0; j<m; j++)
                data[i][j]=0;
    }

    Matrix(float a[][100], int row, int col){
        for (int i=0; i<row;i++)
            for (int j=0; j<col; j++)
                data[i][j] = a[i][j];
    }

    Matrix(const Matrix &A){
        m = A.m;
        n = A.n;
         for (int i=0; i<A.n;i++)
            for (int j=0; j<A.m; j++)
                data[i][j] = A.data[i][j];
    }

    Matrix operator+(Matrix &B){
        Matrix temp(B.n, B.m);
        temp.n = B.n; temp.m = B.m;
        for (int i=0; i<B.n; i++)
            for (int j=0; j<B.m; j++)
                temp.data[i][j] = data[i][j] + B.data[i][j];
        return (temp);
    }

    Matrix operator-(Matrix &B){
        Matrix temp(B.n, B.m);
        temp.n = B.n; temp.m = B.m;
        for (int i=0; i<B.n; i++)
            for (int j=0; j<B.m; j++)
                temp.data[i][j] = data[i][j] - B.data[i][j];
        return (temp);
    }

    bool operator==(Matrix &B){
        for (int i=0; i<B.n; i++)
            for (int j=0; j<B.m; j++){
                if (data[i][j] == B.data[i][j])
                    continue;
                else
                    return false;
        }
        return true;
    }

    Matrix operator*(Matrix &B){
        Matrix temp(B.n, B.m);
        temp.n = B.n; temp.m = B.m;
        for (int i=0; i<B.n; i++)
            for (int j=0; j<B.m; j++)
                temp.data[i][j] = data[i][j] * B.data[i][j];
        return (temp);
    }

    void display(){
         for (int i=0; i<n; i++){
            for (int j=0; j<m; j++)
                cout <<data[i][j] << " ";
            cout <<endl;
        }
    }
};

int main()
{
    Matrix A;
    cout <<"\nMatrix A:\n";
    A.display();

    Matrix B(A);
    cout <<"\nMatrix B:\n";
    B.display();

    Matrix C= A+B;
    cout <<"\nMatrix C = A + B:\n";
    C.display();

    Matrix D= A-B;
    cout <<"\nMatrix D = A - B:\n";
    D.display();

    Matrix F = A*B;
    cout <<"\nMatrix F = A * B:\n";
    F.display();

    if (A==B)
        cout <<"Matrix A equal matrix B";
    else
        cout <<"Matrix A is not equal to matrix B";

    getch();
}
