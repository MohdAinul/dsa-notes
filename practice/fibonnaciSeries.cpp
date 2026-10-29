#include <iostream>
using namespace std;

class Sol {
   public:
    void fib(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            cout << a << " ";
            int ans = a + b;
            a = b;
            b = ans;
        }
    }
};

int main() {
    Sol obj;
    obj.fib(1);

    // cout << "fib is" << obj << endl;

    return 0;
}