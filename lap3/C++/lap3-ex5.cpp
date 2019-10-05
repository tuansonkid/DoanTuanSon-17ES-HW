#include <iostream>
#include <conio.h>

using namespace std;

class Fraction
{
private:
    int numerator, dinominator;
public:
    Fraction(){
        numerator = 0;
        dinominator = 1;
    }

    Fraction(int n, int d){
        numerator = n;
        dinominator = d;
    }

    Fraction(const Fraction &A){
        this->numerator = A.numerator;
        this->dinominator = A.dinominator;
    }

    Fraction operator+(Fraction &B){
        Fraction C;
        C.numerator = this->numerator*B.dinominator + B.numerator*this->dinominator;
        C.dinominator = this->dinominator * B.dinominator;
        return C;
    }
    Fraction operator-(Fraction &B){
        Fraction C;
        C.numerator = this->numerator*B.dinominator - B.numerator*this->dinominator;
        C.dinominator = this->dinominator * B.dinominator;
        return C;
    }
    bool operator==(Fraction &B){
        return (double(this->numerator)/double(this->dinominator) == double(B.numerator)/double(B.dinominator));
    }
    Fraction operator*(Fraction &B){
        Fraction C;
        C.numerator = this->numerator * B.numerator;
        C.dinominator = this->dinominator * B.dinominator;
        return C;
    }

    void display(){
        if (numerator%dinominator == 0)
            cout << numerator/dinominator << endl;
        else
            cout << numerator << "/" << dinominator << endl;
    }
};

int main()
{
    Fraction A(2,5);
    cout << "Fraction A: ";
    A.display();

    Fraction B(3,7);
    cout << "Fraction B: ";
    B.display();

    Fraction C = A + B;
    cout << "Fraction C: ";
    C.display();

    Fraction D = A - B;
    cout << "Fraction D: ";
    D.display();

    Fraction E = A * B;
    cout << "Fraction E: ";
    E.display();

    if (A==B)
        cout << "Fraction A is equal to B" << endl;
    else
        cout << "Fraction A is not equal to B" << endl;
}
