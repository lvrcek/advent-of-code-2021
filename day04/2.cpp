// Copyright (c) 2021 Lovro Vrcek

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::string;


std::vector<int> split(string s, string del = " ") {
    int start = 0;
    int end = s.find(del);
    std::vector<int> v;
    while (end != -1) {
        int n = atoi(s.substr(start, end-start).c_str());
        v.push_back(n);
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back(atoi(s.substr(start, end-start).c_str()));
    return v;
}

void print_vector(std::vector<int> v) {
    for (auto& n : v)
        cout << n << " ";
    cout << endl;
}

void print_grid(std::vector<std::vector<int>> grid) {
    for (auto& v : grid)
        print_vector(v);
    cout << endl;
}

void print_bingo(std::vector<std::vector<std::vector<int>>> bingo) {
    for (auto& t : bingo)
        print_grid(t);
    cout << endl;
}

bool check_grid_row(std::vector<std::vector<int>> grid) {
    bool flag = false;
    for (auto& line : grid) {
        flag = true;
        for (auto& n : line) {
            if (n != -1)
                flag = false;
        }
        if (flag)
            return true;
    }
    return false;
}

bool check_grid_col(std::vector<std::vector<int>> grid) {
    for (int i = 0; i < grid[0].size(); ++i) {
        bool flag = true;
        for (int j = 0; j < grid.size(); ++j) {
            if (grid[j][i] != -1)
                flag = false;
        }
        if (flag)
            return true;
    }
    return false;
}

int sum_grid(std::vector<std::vector<int>> grid) {
    int sum = 0;
    for (auto& line : grid) {
        for (auto& n : line) {
            if (n != -1)
                sum += n;
        }
    }
    return sum;
}

int main() {
    std::string line;
    std::ifstream infile("in.txt");
    std::vector<std::vector<std::vector<int>>> bingo;
    std::vector<std::vector<int>> grid;

    std::getline(infile, line);
    std::vector<int> numbers = split(line, ",");
    std::getline(infile, line);

    while (std::getline(infile, line)) {
        if (line.size() <= 1) {
            bingo.push_back(grid);
            grid.clear();
            continue;
        }
        std::istringstream iss(line);
        int a, b, c, d, e;
        iss >> a >> b >> c >> d >> e;
        std::vector<int> v = {a, b, c, d, e};
        grid.push_back(v);
    }
    bingo.push_back(grid);

    // print_bingo(bingo);
    // cout << bingo.size() << " " << bingo[0].size() << endl;

    std::vector<std::vector<int>> best;
    std::set<int> solved;
    bool flag = false;
    int last;
    for (auto& n : numbers) {
        if (flag)
            break;
        int index = 0;
        for (auto& grid : bingo) {
            for (auto& line : grid) {
                for (int i = 0; i < line.size(); i++) {
                    if (line[i] == n)
                        line[i] = -1;
                }
            }
            if (check_grid_row(grid) || check_grid_col(grid)) {
                solved.insert(index);
                if (solved.size() == bingo.size()) {
                    best = grid;
                    last = n;
                    flag = true;
                    break;
                }
            }
            ++index;
        }
    }

    int sum = sum_grid(best);
    cout << sum << " " << last << " " << sum * last << endl;
    return 0;
}
