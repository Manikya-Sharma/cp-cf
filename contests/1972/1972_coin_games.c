#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char seq[n + 1];
        scanf("%s", seq);

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (seq[j] == 'U')
                count++;
        }
        if (count % 2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
