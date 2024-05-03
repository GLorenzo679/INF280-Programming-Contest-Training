#include <cstring>
#include <string>

int main() {
    char d[1001] = {0};
    int tmp_tot = 0;
    int p = 0;
    int c = 0;

    while (scanf("%[^\n]", d) == 1) {
        if (strcmp(d, "TOTAL") == 0) {
            scanf("%d", &p);

            if (tmp_tot >= p)
                printf("PAY");
            else
                printf("PROTEST");

            return 0;
        } else {
            scanf("%d %d\n", &p, &c);
            tmp_tot += p * c;
        }
    }

    return 0;
}