// Program to calculate scores for a word game based on the uniqueness of words submitted by players
#include <cstdio>
#include <cstring>

const int MAX_N = 1000;
const int MAX_WORDS = 1000;
const int WORD_LEN = 4; // 3 letters + null terminator

char player[3][MAX_N][WORD_LEN];

int count_occurrences(int test_n, const char* word) {
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < test_n; ++j) {
            if (strcmp(player[i][j], word) == 0) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    int t, n;
    std::scanf("%d", &t);

    while (t--) {
        std::scanf("%d", &n);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                std::scanf("%s", player[i][j]);
            }
        }

        int score[3] = {0};

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = count_occurrences(n, player[i][j]);
                if (count == 1) score[i] += 3;
                else if (count == 2) score[i] += 1;
            }
        }

        std::printf("%d %d %d\n", score[0], score[1], score[2]);
    }

    return 0;
}
