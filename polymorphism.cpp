#include <iostream>

using namespace std;

class Animal {
public:
    string name = "Animal";
    // 「虚函数」告诉编译器不要静态链接到该函数，而是根据所调用的对象类型(Class)去选择调用相应的函数，
    // 这种操作被称为动态链接或后期绑定，调用函数的方法需要在程序运行过程中查表完成
    // 那么「纯虚函数」就是父类的virtual没有主体，例如virtual int area()=0;
    virtual void eat() {
        cout << this->name << " is eating\n";
    }
};

// C++默认是protected继承
class Cat : public Animal {
    string name = "Cat";
    void eat() override {
        cout << this->name << " is eating\n";
    }
};

class Dog : public Animal {
    string name = "Dog";
    void eat() override {
        cout << this->name << " is eating\n";
    }
};

class Pig: Animal {
    string name = "Pig";
    void eat() override {
        cout << this->name << " is eating\n";
    }
};

void animal_eat_by_ref(Animal& animal) {
    animal.eat();
}

void animal_eat_by_ptr(Animal* animal) {
    animal->eat();
}

// C++/Java函数重载(overload)的返回值的返回值可以不同
int main() {
    Animal* animal;
    Cat cat;
    Dog dog;
    Pig pig;
    animal_eat_by_ref(cat);
    animal_eat_by_ref(dog);
    animal_eat_by_ptr(&cat);
    animal_eat_by_ptr(&dog);
    // can't cast Pig to it private Base class Animal
    // animal_eat(&pig);
    return 0;
}
