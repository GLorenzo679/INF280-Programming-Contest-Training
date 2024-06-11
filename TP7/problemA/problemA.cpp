#include <complex>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, P;
    double tot_area = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        double x0, y0, x1, y1, start_x, start_y;
        double area = 0;
        cin >> P >> x0 >> y0;

        start_x = x0;
        start_y = y0;

        for (int j = 1; j < P; j++) {
            cin >> x1 >> y1;

            area += (x1 - x0) * (y1 + y0) / 2;
            x0 = x1;
            y0 = y1;
        }

        area += (start_x - x1) * (start_y + y1) / 2;
        tot_area += abs(area);
    }

    cout << (long)tot_area << endl;

    return 0;
}