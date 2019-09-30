#include <iostream>
#include <conio.h>

using namespace std;

class Vector
{
private:
    int n;
    float *data;
public:
    Vector(){
        cout << "Enter the size of vector: ";
        cin >> n;
        data = new float[n];
        for (int i=0; i<n; i++){
            cout << "Enter the " << i+1 << "element of vector: ";
            cin >> data[i];
        }
    }

    Vector(float *a, int n){
        this->n = n;
        data = new float[n];
        for(int i=0; i<n; i++){
            data[i] = *(a+i);
        }
    }

    ~Vector(){
        delete[] data;
    }

    int capacity(){
        return n;
    }

    void clear(){
        delete[] data;
        n=0;
    }

    bool contains(float elem){
        for (int i=0; i<n; i++){
            if (data[i] == elem)
                return true;
            else
                return false;
        }
    }

    int indexOf(float elem){
        for(int i=0; i<n; i++)
            if (data[i] == elem)
                return i+1;
        return 0;
    }

    int lastIndexOf(float elem){
        for (int i = n-1; i >=0; i--)
            if (data[i] == elem)
                return i+1;
        return 0;
    }

    float elementAt(int index){
        return data[index-1];
    }

    bool isEmpty(){
        if(n == 0)
            return true;
        else
            return false;
    }

    int toArray(float *d){
        for (int i = 0; i < n; i++){
            *(d+i) = data[i];
        }
        return n;
    }

    void display(){
        for (int i = 0; i < n; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main()
{
    float a[]={1,4,5,4,1};
    float d[]={};
    Vector c(a, 5);
    Vector b;

    cout << "Capacity of b: " << b.capacity() << endl;
    cout << "Does b contain 15? : " << b.contains(15) << endl
         << "Does b contain 3? : " << b.contains(3) << endl;

    cout << "Index position of 3: " << b.indexOf(3) << endl
         << "Index position of 15: " << b.indexOf(15) << endl;

    cout << "Last Index position of 3: " << b.lastIndexOf(3) << endl
         << "Last Index position of 15: " << b.lastIndexOf(15) << endl;

    cout << "Element at position 1 is: " << b.elementAt(1) << endl;

    cout << "Vector b: ";
    b.display();

    cout << "Put elements from vector b to array d." << endl;
    int n = b.toArray(d);   //return the size of vector b
    cout << "Vector d: ";
    for (int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
    cout << endl;

    b.clear();
    cout << "b was cleared." << endl;
    cout << "Capacity of b: " << b.capacity() << endl;

    cout << "Is b empty? : " << b.isEmpty() << endl
         << "Is c empty? : " << c.isEmpty() << endl;
}


