#include <iostream>
#include <conio.h>

using namespace std;

class Matrix
{
private:
    int m;
    int n;
    float **data;
public:
    Matrix(){
        cout << "Enter the number of rows: ";
        cin >> m;
        cout << "Enter the number of columns: ";
        cin >> n;
        data = new float*[m];
        for(int i=0; i<m; i++){
            data[i] = new float[n];
            for(int j=0; j<n; j++){
                cout << "Enter the element in " << i+1 << " row and " << j+1 << " column: ";
                cin >> data[i][j];
            }
        }
    }

    Matrix(int M, int N){
        m = M;
        n = N;
        data = new float*[m];
        for(int i=0; i<m; i++){
            data[i] = new float[n];
            for(int j=0; j<n; j++)
                data[i][j] = 0;
        }
    }

    Matrix(float **a, int M, int N){
        m = M;
        n = N;
        data = new float*[m];
        for(int i=0; i<m; i++){
            data[i] = new float[n];
            for(int j=0; j<n; j++)
                data[i][j] = a[i][j];
        }
    }

    void swap(int i, int j){
        for(int k=0; k<n; k++){
            data[i-1][k] = data[i-1][k] + data[j-1][k];
            data[j-1][k] = data[i-1][k] - data[j-1][k];
            data[i-1][k] = data[i-1][k] - data[j-1][k];
        }
    }

    Matrix transpose(){
        Matrix M(n, m);
        M.data = new float*[n];
        for(int i=0; i<n; i++){
            M.data[i] = new float[m];
            for(int j=0; j<m; j++)
                M.data[i][j] = data[j][i];
        }
        return M;
    }

    Matrix add(Matrix B){
        Matrix C(m, n);
        if (B.m == m && B.n == n){
            C.data = new float*[m];
            for(int i=0; i<m; i++){
                C.data[i] = new float[n];
                for(int j=0; j<n; j++){
                    C.data[i][j] = data[i][j] + B.data[i][j];
                }
            }
        }
        return C;
    }

    Matrix sub(Matrix B){
        Matrix C(m, n);
        if (B.m == m && B.n == n){
            C.data = new float*[m];
            for(int i=0; i<m; i++){
                C.data[i] = new float[n];
                for(int j=0; j<n; j++){
                    C.data[i][j] = data[i][j] - B.data[i][j];
                }
            }
        }
        return C;
    }

    bool equal(Matrix B){
        if (B.m != m || B.n != n)
            return false;
        else{
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(data[i][j] != B.data[i][j])
                        return false;
            return true;
        }
    }

    Matrix prod(Matrix B){
        Matrix C(m,B.n);
        if (n == B.m){
            C.data = new float*[m];
            for(int i=0; i<m; i++){
                C.data[i] = new float[B.n];
                for(int j=0; j<B.n; j++){
                    C.data[i][j]=0;
                    for(int k=0; k<n; k++){
                        C.data[i][j] += data[i][k] * B.data[k][j];
                    }
                }
            }
            return C;
        }
    }

    void display(){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Matrix M;
    cout << "Matrix M:\n";
    M.display();

    Matrix N = M.transpose();
    cout << "Matrix N:\n";
    N.display();

    Matrix C = M.add(N);
    cout << "Matrix C:\n";
    C.display();

    Matrix D = M.sub(N);
    cout << "Matrix D:\n";
    D.display();

    Matrix E = M.prod(N);
    cout << "Matrix E:\n";
    E.display();

    cout << M.equal(N) << endl;
    cout << endl;
}
