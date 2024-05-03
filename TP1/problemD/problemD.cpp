#include <climits>
#include <string>

int main() {
    int min = INT_MAX;
    int max = INT_MIN;
    char string[3000];

    while (scanf("%[^\n]%*c", string) != EOF) {
        char *p = string;
        int val;

        // Skip the date part
        while (*p != ' ') p++;
        p++;

        while (sscanf(p, "%d", &val) == 1) {
            if (val < min) min = val;
            if (val > max) max = val;

            // Move p to the next integer
            while (*p != ' ' && *p != '\0') p++;
            if (*p == '\0') break;
            p++;
        }
    }

    printf("%d %d\n", min, max);

    return 0;
}