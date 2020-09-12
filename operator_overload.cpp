#include <iostream>

using std::ostream;

struct A {};

struct Point : A{
    int x;
    int y;
//    PointStruct() : x(0), y(0) {};
    Point operator+(const Point &rhs) const {
        auto point = Point{.x=0, .y=0};
        point.x = this->x + rhs.x;
        point.y = this->y + rhs.y;
        return point;
    }
    friend ostream& operator<<(ostream &output, Point& p) {
        output << "x=" << p.x << ", y=" << p.y << '\n';
        return output;
    }
};

int main() {
    auto a = Point{.x=1, .y=1};
    auto b = Point{.x=2, .y=2};
    std::cout << (a + b).x << std::endl;
    std::cout << a << std::endl;
    return 0;
}