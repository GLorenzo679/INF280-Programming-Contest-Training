#include <string>

int main() {
    int w = 0;
    int N = 0;
    int tot_area = 0;

    scanf("%d\n%d\n", &w, &N);

    for (int i = 0; i < N; i++) {
        int width = 0;
        int height = 0;
        scanf("%d %d\n", &width, &height);
        tot_area += width * height;
    }

    printf("%d", int(tot_area / w));

    return 0;
}