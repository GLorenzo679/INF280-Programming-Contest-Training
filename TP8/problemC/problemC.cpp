#include <iostream>

using namespace std;

int main() {
    int M, D, N;
    int len = 0;
    int max_len = 0;
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> D >> N;

        if ((D >= 31) && (N >= 21))
            len++;
        else
            len = 0;

        if (len > max_len) max_len = len;
    }

    cout << max_len << endl;

    return 0;
}