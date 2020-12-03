#include <iostream>
#include <boost/random.hpp>

// g++ boost_example_random.cpp -lboost_random
int main() {
    // 伯努利分布: 在0/1中随机产生一个数，就像抛硬币，不是0，就是1
    // 随机数生成器
    boost::random::mt19937 gen(time(nullptr));
    // 随机数分布器
    boost::random::bernoulli_distribution<> dist;
    std::cout << "Test -lboost_random bernoulli_distribution API: \n";
    for (int i = 0; i < 10; ++i) {
        std::cout << dist(gen) << ' ';
    }
    std::cout << '\n';
}
