#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    int C;
    int K = 0;

    vector<int> sol;

    cin >> N;
    vector<int> notes(N);
    for (int i = 0; i < N; i++) cin >> notes[i];

    cin >> C;
    vector<int> chord(C);
    for (int i = 0; i < C; i++) cin >> chord[i];
    sort(chord.begin(), chord.end());

    for (int i = 0; i <= N - C; i++) {
        vector<int> window(notes.begin() + i, notes.begin() + i + C);

        sort(window.begin(), window.end());

        int diff = window[0] - chord[0];

        for (int j = 0; j < C; j++) {
            if (window[j] - chord[j] != diff) break;
            if (j == C - 1) {
                K++;
                sol.push_back(i + 1);
            }
        }
    }

    cout << K << endl;
    for (int i = 0; i < int(sol.size()); i++) cout << sol[i] << endl;

    return 0;
}
