#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

long long convertToDecimal(const string& num, int base) {
    long long value = 0;
    long long power = 1;

    for (int i = num.size() - 1; i >= 0; i--) {
        value += (num[i] - '0') * power;
        power *= base;
    }

    return value;
}

int main() {
    int K;
    cin >> K;

    while (K--) {
        string numX, numY;
        cin >> numX >> numY;

        unordered_map<long long, int> valueToBaseX;
        bool found = false;

        for (int baseX = 10; baseX <= 15000; baseX++) {
            long long valueX = convertToDecimal(numX, baseX);
            valueToBaseX[valueX] = baseX;
        }

        for (int baseY = 10; baseY <= 15000 && !found; baseY++) {
            long long valueY = convertToDecimal(numY, baseY);

            if (valueToBaseX.find(valueY) != valueToBaseX.end()) {
                cout << valueToBaseX[valueY] << " " << baseY << endl;
                found = true;
            }
        }
    }
    return 0;
}