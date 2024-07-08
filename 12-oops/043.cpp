#include <iostream>
#include <string>
using namespace std;

// 1. Encapsulation: wrapping up data members and functions in a single Entity(Class)
// - Full Encapsulated Class -> all data members are private
// - Encapsulation -> "Information hiding" / "Data hiding"

class Person
{
private:
    int age;

public:
    int getAge()
    {
        return this->age;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

// 2. Inheritance

// see table for visibility mode(public, private, protected mode inheritance)

class Human
{
public:
    int height;
    int weight;

    // private:
    int age;

public:
    int getAge()
    {
        return age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};

// class Male : protected Human
// class Male : private Human
class Male : public Human
{
public:
    string color;

    void sleep()
    {
        cout << "I am sleeping...(male)" << endl;
    }
};

// Types of Inheritance
// 1. Single Inheritance
class Animal
{
public:
    int age;

    void bark()
    {
        cout << "Barking..." << endl;
    }

    void common()
    {
        cout << "common animal" << endl;
    }
};

class Dog : public Animal
{
};

// 2. Multilevel Inheritance

class GermanShepherd : public Dog
{
};

// 3. Multiple Inheritance
class AnotherHuman
{
public:
    void speak()
    {
        cout << "Speaking..." << endl;
    }

    void common()
    {
        cout << "common another human" << endl;
    }
};

class Animal_and_Human : public Animal, public AnotherHuman
{
};

// 4. Hierarchical Inheritance
class A
{
public:
    void func1()
    {
        cout << "Inside function 1" << endl;
    }
};

class B : public A
{
public:
    void func2()
    {
        cout << "Inside function 2" << endl;
    }
};

class C : public A
{
public:
    void func3()
    {
        cout << "Inside function 3" << endl;
    }
};

// 5. Hybrid Inheritance
// combination of more than 1 type of inheritance

// Inheritance Ambiguity
// see code for Mutiple inheritance

// 3. Polymorphism

// Compile time Polymorphism / Static Polymorphism
// 1. Function overloading
// - functions with differnce in return type can not be overloaded
class Function_Overloading
{
public:
    void sayHello()
    {
        cout << "Hello world" << endl;
    }

    void sayHello(string name)
    {
        cout << "Hello " << name << endl;
    }
};

// 2. Operator overloading
class Operator_Overloading
{
public:
    int a;
    int b;

    int add()
    {
        return a + b;
    }

    void operator+(Operator_Overloading &obj)
    {
        // int value1 = this->a;
        // int value2 = obj.a;
        // cout << "output: " << (value2 - value1) << endl;
        cout << "Hello operator overloading" << endl;
    }

    void operator()()
    {
        cout << "Mai bracket hu" << endl;
    }
};

// Runtime Polymorphism / Dynamic Polymorphism
// - method overloading

// 4. Abstraction -> "Implementation Hiding"
// private access modifier

class Parent
{
public:
    void show()
    {
        cout << "Parent class" << endl;
    }
};

class SubClass1 : public Parent
{
public:
    void show()
    {
        cout << "sub class 1" << endl;
    }
};

class SubClass2 : public Parent
{
public:
    void show()
    {
        cout << "sub class 2" << endl;
    }
};

int main()
{
    {

        Person first;
        first.setAge(19);
        cout << "Age: " << first.getAge() << endl;
        cout << endl;
    }

    {
        Male m;

        // inherited propteries
        cout << m.height << endl;
        cout << m.weight << endl;
        cout << m.age << endl;

        cout << m.color << endl;

        m.sleep();

        m.setWeight(75);
        cout << m.weight << endl;

        cout << endl;
    }

    {
        Dog d;
        d.bark();

        GermanShepherd g;
        g.bark();

        Animal_and_Human o;
        o.speak();
        o.bark();

        A a;
        a.func1();

        B b;
        b.func1();
        b.func2();

        C c;
        c.func1();
        c.func3();

        // Inheritance Ambiguity
        // o.common(); --> error
        o.Animal::common();
        o.AnotherHuman::common();
    }

    {
        Function_Overloading fo;
        fo.sayHello();
        fo.sayHello("Naman");

        Operator_Overloading o1, o2;
        o1.a = 4;
        o2.a = 7;

        o1 + o2;
        o1();
    }

    {
        SubClass1 o1;
        SubClass2 o2;

        o1.show();
        o2.show();
    }

    return 0;
}