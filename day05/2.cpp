// Copyright (c) 2021 Lovro Vrcek

#include <bits/stdc++.h>


std::vector<std::string> split(std::string s, std::string del) {
    int start = 0;
    int end = s.find(del);
    std::vector<std::string> v;
    while (end != -1) {
        v.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back(s.substr(start, end-start));
    return v;
}

void print_vector(std::vector<int> v) {
    for (auto& n : v)
        std::cout << n << " ";
    std::cout << std::endl;
}

void print_grid(std::vector<std::vector<int>> grid) {
    for (auto& v : grid)
        print_vector(v);
    std::cout << std::endl;
}

int count_elements(std::vector<std::vector<int>> grid) {
    int count = 0;
    for (auto& line : grid) {
        for (auto& n : line) {
            if (n > 1) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    std::string line;
    std::ifstream iss("in.txt");
    std::vector<std::vector<int>> grid;
    int limit = 1000;

    for (int i = 0; i < limit; ++i) {
        std::vector<int> tmp;
        for (int j = 0; j < limit; ++j) {
            tmp.push_back(0);
        }
        grid.push_back(tmp);
    }

    while (getline(iss, line)) {
        int a_x, a_y, b_x, b_y;
        std::vector<std::string> v = split(line, " -> ");
        std::vector<std::string> left = split(v[0], ",");
        std::vector<std::string> right = split(v[1], ",");
        a_x = atoi(left[0].c_str()); a_y = atoi(left[1].c_str());
        b_x = atoi(right[0].c_str()); b_y = atoi(right[1].c_str());

        if (a_x == b_x) {
           int start = a_y < b_y ? a_y : b_y;
           int end = a_y > b_y ? a_y : b_y;
           for (int i = start; i <= end; i++) {
               grid[i][a_x] += 1;
           }
        } else if (a_y == b_y) {
           int start = a_x < b_x ? a_x : b_x;
           int end = a_x > b_x ? a_x : b_x;
           for (int i = start; i <= end; i++) {
               grid[a_y][i] += 1;
           }
        } else {
            int step_x = a_x < b_x ? 1 : -1;
            int step_y = a_y < b_y ? 1 : -1;
            int i = a_x, j = a_y;
            while (true) {
                grid[j][i]++;
                if (i == b_x) break;
                i += step_x;
                j += step_y;
            }
        }
    }

    std::cout << count_elements(grid) << std::endl;
    return 0;
}
