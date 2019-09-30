#include <iostream>
#include <conio.h>

using namespace std;

class Complex;
class Real
{
private:
    float value;
public:
    Real(float v=0){
        value = v;
    }
    void display(){
        cout << value;
    }
//    friend Complex prod(Real &A, Complex &B);
    friend class Complex;
};

class Complex
{
private:
    float real, image;
public:
    Complex(float a=0, float b=0){
        real = a;
        image = b;
    }
    void display(){
        cout << real << " + j*" << image;
    }
//    friend Complex prod(Real &A, Complex &B);
    Complex prod(Real &A){
        Complex C;
        C.real = A.value * real;
        C.image = A.value * image;
        return C;
    }
};

//Complex prod(Real &A, Complex &B){
//    Complex C;
//    C.real = A.value * B.real;
//    C.image = A.value * B.image;
//    return C;
//}

main()
{
    Real A(6);
    Complex B(5,4);
    A.display();
    cout << "*(";
    B.display();
    cout <<")=";
    Complex C = B.prod(A);
    C.display();
    getch();
}
