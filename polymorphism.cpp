#include <iostream>

using namespace std;

class Animal {
public:
    string name = "Animal";
    void eat() const {
        cout << this->name << " is eating\n";
    }
};

// C++默认是protected继承
class Cat : public Animal {
    string name = "Cat";
    // override
    void eat() {
        cout << this->name << " is eating\n";
    }
};

class Dog : public Animal {
    string name = "Dog";
    void eat() {
        cout << "Dog is eating\n";
    }
};

class Pig: Animal {
    string name = "Pig";
    void eat() {
        cout << this->name << " is eating\n";
    }
};

//
void animal_eat(Animal* animal) {
    animal->eat();
}

// C++/Java函数重载(overload)的返回值的返回值可以不同
int main() {
    Animal* animal;
    Cat cat;
    Dog dog;
    Pig pig;
    animal = &dog;
    animal->eat();
    animal_eat(&cat);
    animal_eat(&dog);
    // can't cast Pig to it private Base class Animal
//    animal_eat(&pig);
    return 0;
}
