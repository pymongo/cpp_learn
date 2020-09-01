#include <functional>
#include <mutex>

using namespace std;

/*
 本题固定有5个哲学家，多个线程共享一个实例对象，会抢着调用同一个实例对象的wantsToEat方法
 大部分C++/Java解法都是使用Semaphore API，类似Mutex
 我注意到Rust的Semaphore Deprecated since 1.7.0: easily confused with system sempahores and not used enough to pull its weight
 而且Rust官方教程中的哲学家问题就是通过将Mutex去解决哲学家进餐问题的，所以我也用Mutex了
*/
class DiningPhilosophers {
public:
    static mutex forks[5];
    static void wantsToEat(
            int philosopher,
            function<void()> pickLeftFork,
            function<void()> pickRightFork,
            function<void()> eat,
            function<void()> putLeftFork,
            function<void()> putRightFork
    ) {
        int left_fork = philosopher;
        int right_fork = (philosopher + 1) % 5;
        forks[left_fork].lock();
        forks[right_fork].lock();

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        forks[left_fork].unlock();
        forks[right_fork].unlock();
    }
};


int main() {
    return 0;
}