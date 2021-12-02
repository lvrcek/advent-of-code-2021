#include <bits/stdc++.h>

using namespace std;


int main() {
    string command;
    int val;
    int forward = 0, depth = 0, aim = 0;
    while (cin >> command >> val) {
        if (command == "forward") {
            forward += val;
            depth += aim * val;
        }
        else if (command == "down") {
            aim += val;
        }
        else {
            aim -= val;
        }
    }
    cout << forward * depth << endl;
    return 0;
}