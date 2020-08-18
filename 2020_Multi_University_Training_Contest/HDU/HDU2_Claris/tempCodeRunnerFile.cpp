for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < i) {
                printf(" ");
            } else {
                printf("%d %c", ans[i][j], j == m - 1 ? '\n' : ' ');
            }
        }
    }