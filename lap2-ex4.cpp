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

    Matrix(float **a){
        int count1=0, count2=0;
        while(a[count1] != NULL)
                count1++;
        while(a[count1][count2] != NULL)
            count2++;
        m=count1+1;
        n=count2+1;
        data = new float*[m];
        for(int i=0; i<m; i++){
            data[i] = new float[n];
            for(int j=0; j<n; j++)
                data[i][j] = a[i][j];
        }
    }

    ~Matrix(){
        for(int i = 0; i<m; i++)
            delete data[i];
        delete data;
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
        if (B.m != this->m || B.n != this->n)
            return 0;
        else{
            Matrix C(m, n);
            C.data = new float*[m];
            for(int i=0; i<m; i++){
                C.data[i] = new float[n];
                for(int j=0; j<n; j++)
                    C.data[i][j] = this->data[i][j] + B.data[i][j];
            }
            return C;
        }
    }

    Matrix sub(Matrix B){
        if (B.m != this->m || B.n != this->n)
            return 0;
        else{
            Matrix C(m, n);
            C.data = new float*[m];
            for(int i=0; i<m; i++){
                C.data[i] = new float[n];
                for(int j=0; j<n; j++)
                    C.data[i][j] = this->data[i][j] - B.data[i][j];
            }
            return C;
        }
    }

    bool equal(Matrix B){
        if (B.m != this->m || B.n != this->n)
            return false;
        else{
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(this->data[i][j] != B.data[i][j])
                        return false;
            return true;
        }
    }

    Matrix prod(Matrix B){
        if (this->m != B.n)
            return 0;
        else{
            Matrix C(m, n);
            C.data = new float*[m];
            for(int i=0; i<B.m; i++){
                C.data[i] = new float[n];
                for(int j=0; j<n; j++)
                    for(int k=0; k<m; k++)
                    C.data[i][j] += this->data[i][k] * B.data[k][j];
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
    Matrix A(2,2);
    A.display();
    M.display();
    Matrix N = M.transpose();
    N.display();
    Matrix C = M.add(N);
    C.display();
    Matrix D = M.sub(N);
    D.display();
    cout << M.equal(N) << endl;
    cout << endl;
    Matrix E = M.prod(N);
    E.display();
    return 0;
}
