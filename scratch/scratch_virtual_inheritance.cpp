#include <iostream>
using namespace std;

class A {
public:
    A() { cout<<"A::A"<<endl; }
    virtual ~A() { cout<<"A::~A"<<endl; }

    void f1() { cout<< "A::f1"<<endl; }
    virtual void f2() { cout<< "A::f2" <<endl; }
};

class B : public A {
public:
    B() { cout<<"B::B"<<endl; }
    ~B() { cout<< "B::~B" <<endl; }

    void f1() {cout<<"B::f1"<<endl;}
    void f2() {cout<<"B::f2"<<endl;}
};

class C: public B {
public:
    C() { cout<< "C::C" <<endl; }
    ~C() { cout<< "C::~C" <<endl; }

    void f1() { cout<<"C::f1"<<endl; }
    void f2() { cout<<"C::f2"<<endl; }
};

void Release(A* p) {
p->f1();
p->f2();
delete p;
}

int main()
{
    A* p1 = new A;
    A* p2 = new B;

    Release(p1);
    Release(p2);

    C c;
    c.f1();
    c.f2();

    cout << "not release C yet;" << endl;
    // Release(c);
    return 0;
}