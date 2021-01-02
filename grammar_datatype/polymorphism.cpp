#include <iostream>
#include <vector>

//using namespace std;
using std::cout;
using std::string;

class Animal {
public:
    string name = "Animal";
    // 「虚函数」告诉编译器不要静态链接到该函数，而是根据所调用的对象类型(Class)去选择调用相应的函数，
    // 这种操作被称为动态链接或后期绑定，调用函数的方法需要在程序运行过程中查表完成，根据对象中虚指针指向的虚表中的地址
    // 那么「纯虚函数」就是父类的virtual没有主体，例如virtual int area()=0;
    // 用到多态时析构函数要写成虚函数?
    virtual void eat() {
        cout << this->name << " is eating\n";
    }
    virtual ~Animal() {
        cout << "Animal's deconstructor\n";
    }
};

// C++默认是protected继承
class Cat : virtual public Animal {
public:
    ~Cat() override {
        cout << "Cat's deconstructor\n";
    }
    string name = "Cat";
    void eat() override {
        cout << this->name << " is eating\n";
    }
};

// 虚继承解决什么问题: 例如BC继承了A，D又多继承了BC，如果A有name字段那么D会有两份name
// 虚继承: BC继承A后会得到A的name字段，但是BC再往下派生的类会没有name字段
// 可以认为虚继承为了解决diamond inheritance带来的字段重复
class Dog : virtual public Animal {
public:
    ~Dog() override {
        cout << "Dog's deconstructor\n";
    }
    string name = "Dog";
    void eat() override {
        cout << this->name << " is eating\n";
    }
};

void animal_eat_by_ref(Animal& animal) {
    animal.eat();
}

void animal_eat_by_ptr(Animal* animal) {
    cout << "type: " << typeid(decltype(animal)).name() << '\n';
    animal->eat();
}

struct DynAnimal {
    virtual void eat() = 0;
};

// 可以写成virtual DynAnimal也可以不加virtual
struct CatStruct: virtual DynAnimal {
    void eat() override {
        cout << "CatStruct is eatring" << '\n';
    }
};

struct DogStruct: DynAnimal {
    void eat() override {
        cout << "DogStruct is eatring" << '\n';
    }
};

// C++/Java函数重载(overload)的返回值的返回值可以不同
int main() {
    // new和delete一般要成对出现
    int* ptr = new int;
    delete ptr;
//    auto* animal = new Animal;
//    animal->eat();
    // 省略new Cat()的写法
    Cat cat;
    Dog dog;
    animal_eat_by_ref(cat);
    animal_eat_by_ref(dog);
    animal_eat_by_ptr(&cat);
    animal_eat_by_ptr(&dog);
    // 如果Animal的析构函数不是虚函数，则cat_2析构时会调用Animal的析构函数而不是Cat自己的析构函数造成UB
    Animal* cat_2 = new Cat();
    delete cat_2;

    cout << "== test DynAnimal\n\n";

    auto dyn_cat = CatStruct{};
    auto dyn_dog = DogStruct{};
    auto animals = std::vector<DynAnimal*>{&dyn_cat, &dyn_dog};
    for (auto animal : animals) {
        animal->eat();
    }

    // class Pig: Animal
    // can't cast Pig to it private Base class Animal
    // animal_eat(&pig);

    cout << "== end\n\n";
    return 0;
}
