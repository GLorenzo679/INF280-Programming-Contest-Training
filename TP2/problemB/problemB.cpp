#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string date, name;
    set<string> names;

    while (cin >> date) {
        getline(cin >> ws, name);
        names.insert(name);
    }

    cout << names.size();

    return 0;
}