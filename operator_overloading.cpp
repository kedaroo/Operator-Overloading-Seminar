#include <iostream>
#include <cmath>

using namespace std;

class Timestamp {

    private:
    float hr, min, sec;

    public:

    // Default constructor
    Timestamp(){
        hr = 0;
        min = 0;
        sec = 0;
    }

    // Parameterized constructor
    Timestamp(float x, float y, float z) {
        hr = x;
        min = y;
        sec = z;
    }

    // Copy constructor
    Timestamp(const Timestamp &ts) {
      hr = ts.hr;
      min = ts.min;
      sec = ts.sec;
    }

    // Overloading + operator
    Timestamp operator+(Timestamp t) {
        Timestamp temp;
        int x, y;
        x = this->sec + t.sec;
        y = (x/60) + this->min + t.min;
        temp.hr=this->hr + t.hr + (y/60);
        temp.min=y % 60;
        temp.sec=x % 60 ;
        return temp;
    }

    // Overloading - operator
    Timestamp operator-(Timestamp t) {
        Timestamp temp;

        if (t.sec > this->sec) {
            temp.sec = 60 - abs(this->sec - t.sec);
            this->min--;
        } else {
            temp.sec = this->sec - t.sec;
        }
        if (t.min > this->min) {
            temp.min = 60 - abs(this->min - t.min);
            this->hr--;
        } else {
            temp.min = this->min - t.min;
        }
        temp.hr = this->hr - t.hr;

        return temp;
    }

    // Overloading preincrement operator
    Timestamp operator++() {
        this->hr++;
        this->min++;
        this->sec++;
        return *this; 
    }

    // Overloading postincrement operator
    Timestamp operator++(int) {
        Timestamp temp = *this;
        this->hr++;
        this->min++;
        this->sec++;
        return temp;
    }

    // Overloading decrement operator
    Timestamp operator--(int) {
        this->hr--;
        this->min--;
        this->sec--;
        return *this;
    }

    // Overloading insertion << operator
    friend ostream& operator<<(ostream &o, const Timestamp &t) {
        o << "Hr: " << t.hr << endl << "Min: " << t.min << endl << "Sec: " << t.sec;
        return o;
    }

    // overloading extraction >> operator
    friend istream& operator>>(istream &i, Timestamp &t) {
        i >> t.hr >> t.min >> t.sec;
        return i;
    }

    // Overloading assignment = operator
    void operator=(const Timestamp &t) {
        this->hr = t.hr;
        this->min = t.min;
        this->sec = t.sec;
    }

    // Destructor
    ~ Timestamp() {}
};

class Complex {

    private:
        float real, imaginary;

    public:

        // Default constructor
        Complex() {
            real = 0;
            imaginary = 0;
        }

        // Parameterized constructor
        Complex(float r, float i) {
            real = r;
            imaginary = i;
        }

        // Copy constructor
        Complex(const Complex &C) {
            real = C.real;
            imaginary = C.imaginary;
        }

        // Overloading multiplication * operator
        Complex operator*(const Complex &C) {
            Complex temp;
            temp.real = (this->real * C.real) - (this->imaginary * C.imaginary);
            temp.imaginary = (this->real * C.imaginary) + (C.real * this->imaginary);
            return temp;
        }

        // Overloading division / operator
        Complex operator/(const Complex &C) {
            Complex temp;
            Complex conjugate(C.real, (C.imaginary*-1));
            Complex numerator = *this * conjugate;
            float denominator = pow(C.real, 2) + pow(C.imaginary, 2);
            temp.real = numerator.real/denominator;
            temp.imaginary = numerator.imaginary/denominator;
            return temp;
        }

      void get() {
        cout << real << " " << imaginary << 'i' << endl;
      }
};

int main() {

    Timestamp t1(1,2,3), t2(3,4,5);
    Timestamp t3, t4, t5, t6, t7, t8, t9;

    cout << "T1:\n" << t1 << endl << "T2:\n " << t2 << endl;
    // Addition
    t3 = t1 + t2;
    cout << "\nTimestamp 1 + Timestamp 2:\n" << t3 << endl;
    
    // Subtraction
    t4 = t2 - t1;
    cout << "\nTimestamp 2 - Timestamp 1:\n" << t4 << endl;

    // Preincrement:
    t5 = ++t4;
    cout << "\nPreincrementing: T5 = ++T4:\n" << t4 << endl << t5; 

    // postincrement:
    t6 = t4++;
    cout << "\nPostincrementing: T5 = T4++:\n" << t4 << endl << t5;

    // Implementing extraction operator
    cout << "\nEnter values for T7:" << endl;
    cin >> t7;
    cout << "T7:\n" << t7 << endl;

    // Decrement:
    t8 = t7--;
    cout << "\nDecrementing: T8 = T7--:\n" << t8 << endl << t5;    

    // Implementing assignment operator:
    t9 = t8;
    cout << "Assigning T8 values to T9:" << endl;
    cout << "\nT9:\n" << t9 << endl;

    // Implementing class Complex
    Complex c1(2,4), c2(8,2), c3, c4;

    // Multiplication:
    c3 = c2*c1;
    c3.get();

    // Division:
    c4 = c2/c1;
    c4.get();

    return 0;
}