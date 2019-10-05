#include <iostream>
#include <conio.h>

using namespace std;

class Complex
{
private:
    float real, image;
public:
    Complex();
    Complex(float r, float i);
    Complex(const Complex &A);

    Complex operator+(Complex &B){
        float r = real + B.real;
        float i = image + B.image;
        return Complex(r, i);
    }

    Complex operator-(Complex &B){
        float r = real - B.real;
        float i = image - B.image;
        return Complex(r, i);
    }

    bool operator==(Complex &B){
        if (real == B.real && image == B.image)
            return true;
        else
            return false;
    }

    Complex operator*(Complex &B){
        float r = real * B.real;
        float i = image * B.image;
        return Complex(r, i);
    }

    void display();
};

Complex::Complex(){
    cout << "Input real and image: ";
    cin >> real >> image;
}

Complex::Complex(float r, float i){
    real = r;
    image = i;
}

Complex::Complex(const Complex &A){
    real = A.real;
    image = A.image;
}

void Complex::display(){
    cout << real << " + j" << image << endl;
}

int main()
{
    Complex A, B;
    cout << "Complex A: ";
    A.display();
    cout << "Complex B: ";
    B.display();

    Complex C = A + B;
    cout << "Complex C: ";
    C.display();

    Complex D = A - B;
    cout << "Complex D: ";
    D.display();

    Complex E = A * B;
    cout << "Complex E: ";
    E.display();

    if(A==B)
        cout << "Complex A is equal to B" << endl;
    else
        cout << "Complex A is not equal to B" << endl;

    getch();
}
