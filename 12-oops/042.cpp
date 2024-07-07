#include <iostream>
#include <string>
#include <cstring>
// #include "042_Hero.cpp" // import class from another file
using namespace std;

class Hero
{

    // can only be accessed inside the class
private:
    int hidden_property;

    // can be accessed via class instance(object) and inside class
public:
    // data members / properties / attributes
    char *name;
    int health;
    char level;

    // Static Keyword
    // - data members that belong to a class, not object instance

    static int time;

    // size should have been 25
    // but it is 28
    // same thing happens in structures
    // reason for above is
    /*
    1. Padding is introduced in memory allocation to ensure proper alignment of data within structures. CPUs have specific memory alignment requirements for different types of data. When you have a structure containing different data types, the compiler might insert "padding bytes" between members to align them according to the CPU's requirements.

    2. Greedy alignment refers to the practice of arranging the members of a structure or class in such a way that padding is minimized. By placing members with larger alignment requirements before those with smaller alignment requirements, you can potentially reduce the amount of padding required.
    In languages like C++, where memory layout has a significant impact on performance due to cache lines and memory access patterns, arranging members to minimize padding can lead to better memory utilization and potentially improved runtime efficiency.
    */

    // Constructor
    // - invokes on object creation
    // - no return type

    // Default Constructor
    // - no parameters
    // - it is made by the compiler by default
    // - we can overwrite it by making our own default constructor
    // - if we have another constructor(Parameterized Constructor) then default constructor of compiler is removed

    Hero()
    {
        cout << "object created" << endl;
        cout << "constructor called" << endl;
        name = new char[100];
    }

    // Parameterized Constructor

    Hero(int health)
    {
        // local variable will be given preference, value of health will be assigned to itself, while the instance variables will have garbage value
        // health = health;
        // level = level;

        // "this" is a pointer, that points to the current object/instance of class

        this->health = health;
        cout << "this: " << this << endl; // same address as current object
    }

    // Parameterized Constructor: with function overloading

    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    // Copy Constructor
    // - generated automatically (like default constructor)

    // Shallow and Deep Copy
    // - default copy constructor -> shallow copy

    Hero(Hero &value)
    {
        // for deep copy
        char *temp = new char[strlen(value.name) + 1]; // + 1 for null character
        strcpy(temp, value.name);
        this->name = temp;

        this->health = value.health;
        this->level = value.level;
    }

    // Destructor
    // - to deallocate memory

    ~Hero()
    {
        cout << "object destroyed" << endl;
        delete[] name;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    // member function
    void print()
    {
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
        // cout << "Name: " << name << endl;
        // cout << "Hidden Property: " << hidden_property << endl;
    }

    // protected -> can be inheritied

    // getter
    int getHiddenProperty()
    {
        return hidden_property;
    }

    // setter
    int setHiddenProperty(int val)
    {
        // can apply some logic or condition here
        hidden_property = val;
    }

    // static functions
    // - belong to class, no need to create objects
    // - no this keyword, as there is no object

    static int random()
    {
        return time; // can only access static members
    }
};

// initialize
// "::" -> scope resolution operator
int Hero::time = 5;

class EmptyClass
{
    // no properties
};

int main()
{
    if (0)
    {
        string s; // --> here string is a class
        // syntax
        // Class object;
        // Class -> user defined data type / template / blueprint
        // object -> instance of class

        Hero h1; // using static allocation

        cout << "size of h1: " << sizeof(h1) << endl; // 20 + 4 + 1 => 25 (should be been, but output is 28)

        EmptyClass e;
        cout << "size of e: " << sizeof(e) << endl; // 1 byte for identification of the object is given by the compiler

        cout << endl;

        // Access Modifiers
        // private, public, protected
        // by default -> private

        Hero hero;
        // cout << "Health: " << hero.health << endl;
        // cout << "Level: " << hero.level << endl;
        hero.health = 70;
        hero.level = 'A';
        hero.print();

        // getters and setters
        hero.setHiddenProperty(100);
        cout << "Hidden property: " << hero.getHiddenProperty() << endl;

        // dynamic memory allocation
        Hero *h = new Hero;
        h->health = 90;
        h->level = 'B';

        cout << "Health: " << (*h).health << endl;
        cout << "Level: " << h->level << endl;

        cout << endl;
    }

    if (0)
    {
        // object created statically
        Hero hero;

        // object created dynamically
        Hero *dynamic_hero = new Hero; // same output as above, (default constructor is called)

        cout << endl;
    }

    if (0)
    {
        Hero h(95);
        cout << "Address of h is: " << &h << endl;
        h.print();

        Hero h2(99, 'A');
        h2.print();

        cout << endl;
    }

    if (0)
    {
        Hero hero(99, 'A');
        hero.print();

        Hero copy(hero);
        copy.print();

        copy.health = 80;

        hero.print();
        copy.print(); // change here only

        cout << endl;
        cout << endl;
    }

    if (0)
    {
        Hero hero(12, 'D');
        char name[] = "test";
        hero.setName(name);

        hero.print();

        // use default copy constructor
        // - shallow copy
        // - char* name points to the same memory location in both objects(hero, hero2)

        Hero hero2(hero);
        // or
        Hero hero3 = hero;

        hero.name[0] = 'G';

        hero.print();
        hero2.print(); // change refelected here also (when using shallow copy / default copy constructor)

        cout << endl;
    }

    if (0)
    {
        Hero a(10, 'C');
        Hero b(20, 'B');

        a = b; // Copy Assignment Operator
               /*
               it means
               a.health = b.health;
               a.level = b.level;
               */

        a.print();
        b.print();

        cout << endl;
    }

    if (0)
    {
        Hero a; // destructor automatically called

        Hero *b = new Hero; // call destructor manually
        delete b;
    }

    {

        cout << Hero::time << endl;

        Hero a;
        cout << a.time << endl; // not recommended

        Hero b;
        b.time = 10;

        cout << a.time << endl;
        cout << b.time << endl;
    }

    {
        cout << Hero::random() << endl;
    }

    return 0;
}