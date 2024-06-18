#include <iostream>

using namespace std;

int main() {
    int N, M = 0;
    cin >> N >> M;

    if ((N >= 31) && (M >= 21))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}