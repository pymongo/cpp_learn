#include <iostream>
#include <thread>
#include <chrono> /* chrono::milliseconds */
#include <ctime>  /* time_t, strftime, localtime */

using namespace std;

string formatDate() {
    /* Alternative in python or node.js
      python3 -c "print(__import__('time').strftime('%H:%M:%S'))"
      system("node -e \"console.log(Date().slice(16,24))\"");
    */
    time_t now = time(nullptr);
    char tmp[32];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return tmp;
}

// Add [[noreturn]] to Endless loop
[[noreturn]] void timer() {
    while (true) {
        cout << formatDate() << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

// g++ -pthread -o thread thread.cpp && thread
int main(int argc, char *argv[]) {
    thread thread_a(timer);
    thread_a.join();
    return 0;
}
