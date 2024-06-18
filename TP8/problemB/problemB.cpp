#include <iostream>

using namespace std;

int main() {
    int D, H, M;
    cin >> D >> H >> M;

    if (D < 11) {
        cout << -1 << endl;
        return 0;
    }

    if ((D == 11) && (H < 11)) {
        cout << -1 << endl;
        return 0;
    }

    if ((D == 11) && (H == 11) && (M < 11)) {
        cout << -1 << endl;
        return 0;
    }

    int total_min = 24 * 60 * (D - 11) + 60 * (H - 11) + (M - 11);

    cout << total_min << endl;

    return 0;
}