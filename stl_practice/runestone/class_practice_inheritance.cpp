#include<iostream>

using namespace std;

/*
            |Logic Gate|
            /           \
    |Binary Gate|   |Unary Gate|
    /           \        |
|AND|          |OR|    |NOT|

*/



// Base class
class LogicGate{
public:
    LogicGate(string n){
        label = n;
    }

    string getLabel(){
        return label;
    }

    virtual bool performGateLogic(){
        cout << "Base class -- performGateLogic() not defined." << endl;
        return false;
    };

    bool getOutput(){
        output = performGateLogic();
        return output;
    }

    virtual void setNextPin(bool source){
        cout << "Base class -- setNextPin() not defined." << endl;
    };
    

protected:
    string label;
    bool output;

};

// Subclass -- Binary Gate
class BinaryGate : public LogicGate{
public:
    BinaryGate(string n) : LogicGate(n){
        pinATaken = false;
        pinBTaken = false;
    }

    bool getPinA(){
        if (pinATaken==false){
            cout << "Enter Pin input for gate " << getLabel() << " : ";
            cin >> pinA;
            pinATaken = true;
        }
        return pinA;
    }

    bool getPinB(){
        if (pinBTaken==false){
            cout << "Enter Pin input for gate " << getLabel() << " : ";
            cin >> pinB;
            pinBTaken = true;
        }
        return pinB;
    }

    virtual void setNextPin(bool source){
        if (pinATaken==false){
            pinA = source;
            this->pinATaken = true;
        }else if (pinBTaken==false){
            pinB = source;
            this->pinBTaken = true;
        }
    }

protected:
    bool pinA;
    bool pinATaken;
    bool pinB;
    bool pinBTaken;
};


// Subclass -- Unary Gate
class UnaryGate : public LogicGate{
public:
    UnaryGate(string n) : LogicGate(n){
        pinTaken = false;
    }
    bool getPin(){
        if (pinTaken==false){
            cout << "Enter Pin input for gate " << getLabel() << " : ";
            cin >> pin;
            pinTaken = true;
        }
        return pin;
    }

    virtual void setNextPin(bool source){
        if (pinTaken==false){
            pin = source;
            this->pinTaken = true;
        }else{
            return;
        }
    }

protected:
    bool pin;
    bool pinTaken;
};


// AND gate
class AndGate : public BinaryGate{
public:
    AndGate(string n) : BinaryGate(n){};

    virtual bool performGateLogic(){
        bool a = getPinA();
        bool b = getPinB();
        if (a==1 && b==1){
            return true;
        }
        else{
            return false;
        }
    }
};

// OR gate
class OrGate : public BinaryGate{
public:
    OrGate(string n) : BinaryGate(n){};
    virtual bool performGateLogic(){
        bool a = getPinA();
        bool b = getPinB();
        if (a==1 || b==1){
            return true;
        }
        else{
            return false;
        }
    }
};

// NOT gate
class NotGate : public UnaryGate{
public:
    NotGate(string n) : UnaryGate(n) {};
    virtual bool performGateLogic(){
        return !(getPin());
    }
};

// Connector : HAS-A relationship
class Connector{
public:
    Connector(LogicGate *fgate, LogicGate *tgate){
        fromgate = fgate;
        togate = tgate;
        tgate->setNextPin(fromgate->getOutput());
    }

    LogicGate *getFrom(){
        return fromgate;
    }

    LogicGate *getTo(){
        return togate;
    }
private:
    LogicGate *fromgate;
    LogicGate *togate;
};



int main(){
    // AndGate gand1("gand1");
    // OrGate gor1("gor1");
    // NotGate gnot1("gnot1");

    // gand1.getOutput();
    // gor1.getOutput();
    // gnot1.getOutput();
    cout << "LogicGate Test" << endl;

    char stopme;

    //Setting labels
    AndGate gand1(" AND1 ");
    AndGate gand2(" AND2 ");
    OrGate  gor3(" OR ");
    NotGate gnot4(" NOT ");

    // The inputs can be changed here!
    gand1.setNextPin(0);
    gand1.setNextPin(0);
    gand2.setNextPin(0);
    gand2.setNextPin(0);

    //making comnnections
    Connector c1(&gand1, &gor3);
    Connector c2(&gand2, &gor3);
    Connector c3(&gor3, &gnot4);

    // The output shows order of operators
    cout << gnot4.getLabel() << "(";
    cout << "(" << gand1.getPinA() << gand1.getLabel() << gand1.getPinB() << ")";
    cout << gor3.getLabel();
    cout << "(" << gand2.getPinA() << gand2.getLabel() << gand2.getPinB() << ")";
    cout << ") results in " << gnot4.getOutput() << endl;

    cin >> stopme; //holds open window under some conditions.
    return 0;
}



/*
=== Used Library ===



Summary:

Parent:
    Base class / superclass

Child:
    subclasses / derived classes


Keyword:
    virtual -> Virtual function, inheritance


"IS-A" relationship     --> with inheritance
"HAS-A" relationship    --> with "no" inheritance


Pros:
    1. 

Cons:
    1. 




*/