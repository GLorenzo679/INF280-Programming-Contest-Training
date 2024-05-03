#include <cstring>
#include <string>

int main() {
    unsigned long tot_int = 0, tot_dec = 0;
    unsigned long integer, decimal;

    while (scanf("%lu.%lu", &integer, &decimal) != EOF) {
        tot_int += integer;
        tot_dec += decimal;
    }

    tot_int += tot_dec / 100;
    tot_dec %= 100;

    printf("%lu.%02lu\n", tot_int, tot_dec);

    return 0;
}