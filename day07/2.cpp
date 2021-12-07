#include <bits/stdc++.h>


std::vector<int> split(std::string s, std::string del) {
    int start = 0;
    int end = s.find(del);
    std::vector<int> tokens;
    while (end != -1) {
        tokens.push_back(atoi(s.substr(start, end - start).c_str()));
        start = end + del.size();
        end = s.find(del, start);
    }
    tokens.push_back(atoi(s.substr(start, end - start).c_str()));
    return tokens;
}

int distance(int n) {
    return n * (n + 1) / 2;
}

int main() {
    std::string line;
    std::ifstream iss("in.txt");
    getline(iss, line);
    std::vector<int> positions = split(line, ",");
    int start = *min_element(positions.begin(), positions.end());
    int end = *max_element(positions.begin(), positions.end());
    // std::cout << start << " " << end << std::endl;
    int min_fuel = INT_MAX;
    for (int i = start; i <= end; ++i) {
        int fuel = 0;
        for (auto& n : positions)
            fuel += distance(abs(n - i));
        if (fuel < min_fuel)
            min_fuel = fuel;
    }

    std::cout << min_fuel << std::endl;
    return 0;
}