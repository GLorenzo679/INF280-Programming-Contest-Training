#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    string maxName = "NONE";
    map<string, int> animals;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        animals[name]++;
    }

    for (auto it = animals.begin(); it != animals.end(); it++) {
        if (it->second >= int(N / 2) + 1) {
            maxName = it->first;
            break;
        }
    }

    cout << maxName;

    return 0;
}