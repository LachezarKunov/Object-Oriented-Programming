#include <iostream>
using namespace std;

class Animal 
{
public:
    virtual void makeSound() const = 0;

    virtual ~Animal() = default;
};

class Cat : public Animal 
{
public:
    void makeSound() const override
    {
        cout << "Meow";
    }
};

class Dog : public Animal 
{
public:
    void makeSound() const override
    {
        cout << "Bark";
    }
};

class Chicken : public Animal 
{
public:
    void makeSound() const override 
    {
        cout << "Cluck";
    }
};


int main()
{
    Animal** animals = new Animal*[3];

    animals[0] = new Cat();
    animals[1] = new Dog();
    animals[2] = new Chicken();

    for (size_t i = 0; i < 3; i++)
    {
        animals[i]->makeSound();
        cout << " ";
    }

    for (size_t i = 0; i < 3; i++)
    {
        delete animals[i];
    }

    delete[] animals;
}
