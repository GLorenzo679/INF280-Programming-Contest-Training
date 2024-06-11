#include <iostream>
#include <map>
#include <vector>

using namespace std;

pair<double, double> move(pair<double, double> pos, char direction) {
    map<char, pair<double, double>> directions = {
        {'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

    return {pos.first + directions[direction].first,
            pos.second + directions[direction].second};
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        pair<int, int> start = {0, 0};
        double area = 0;

        for (int j = 1; j < int(s.size()); j++) {
            pair<double, double> next = move(start, s[j]);
            area +=
                (start.first * next.second - next.first * start.second) / 2.0;
            start = next;
        }

        if (area < 0) cout << "CW" << endl;
        if (area > 0) cout << "CCW" << endl;
    }

    return 0;
}