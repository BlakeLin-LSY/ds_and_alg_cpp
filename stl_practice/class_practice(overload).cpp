#include<iostream>

using namespace std;

int gcd(int m, int n){
    while(m%n != 0){
        int old_m = m;
        int old_n = n;

        m = old_n;
        n = old_m%old_n;
    }
    return n;
}

class Fraction{
    public:
        Fraction(int top = 0, int bottom = 1){
            /* Constructor method */
            num = top;          // Numerator
            den = bottom;       // Denominator
            int gcd_val = gcd(top, bottom);
            if(gcd_val != 1){
                num /= gcd_val;
                den /= gcd_val;
            }
        }
        void show(){
            cout << num << "/" << den << endl;
        }
        // Fraction operator +(const Fraction &otherFrac){
        //     int new_num = otherFrac.num*den + otherFrac.den*num;
        //     int new_den = otherFrac.den*den;
        //     return Fraction(new_num, new_den);
        // }

    
    //the following tells the compiler to look for this friend's definition outside the class
    friend ostream &operator << (ostream &stream, const Fraction &frac);
    friend Fraction operator + (const Fraction &frac1, const Fraction &frac2);
    friend bool operator == (const Fraction &frac1,const Fraction &frac2);

    private:
        int num;
        int den;
    // protected:
};  // The ";" is required by C++ to end a class definition;

ostream &operator << (ostream &stream, const Fraction &frac){
    stream << frac.num << "/" << frac.den;
    return stream;
}
Fraction operator + (const Fraction &frac1, const Fraction &frac2){
    int _num = frac1.den*frac2.num + frac2.num*frac1.den;
    int _den = frac1.den*frac2.den;
    return Fraction(_num, _den);
    // int common = gcd(_num, _den);
    // return Fraction(_num/common, _den/common);
}
bool operator == (const Fraction &frac1,const Fraction &frac2){
    int _num = frac1.num*frac2.den;
    int _den = frac1.den*frac2.num;
    return _num == _den;
}

int main(){

    Fraction m_fraction(7, 21);
    m_fraction.show();
    // cout << m_fraction.num << " / " << m_fraction.den << endl;  
    //// -> private variable cannot be accessed directly;
    cout << "cout: " << m_fraction << endl;

    Fraction f1(2,9);
    Fraction f2(3,4);
    Fraction f3 = f1 + f2;
    cout << f3 << " is " << f1 << " + " << f2 << endl;


    Fraction x(2, 4);
    Fraction y(4, 8);
    cout << x << " + " << y << " = " << x+y << endl;
    if (x==y){
        cout << "x is equal to y" << endl;
    }
    else{
        cout << "x is not equal to y" << endl;
    }

    return 0;
}



/*
=== Used Library ===



Summary:

1. Class definition
    - Properties    <->     attribute
    - Behaviors     <->     method
    Instance -> an object created from a class

2. Object-Oriented Programming (OOP) properties
    - Abstraction       : Focus on the desired properties and behaviors
    - Encapsulation     : Can hide the contents of a class
    - Inheritance       : Inheritance from other object(/class)
    - Polymorphism      : Ability to appear in many form

3. Operator Overloading (ostream, +)


Methods:



Pros:
    1. 

Cons:
    1. 




*/