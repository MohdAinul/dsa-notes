#include <iostream>
using namespace std;

class Sol {
   public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Sol obj;
    cout << obj.fib(10);

    return 0;
}