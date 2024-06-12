#include <stdio.h>
#define MAX 9999
#define N 4

int distan[N][N] = {
    {0, 22, 26, 30},
    {30, 0, 45, 35},
    {25, 45, 0, 60},
    {30, 35, 40, 0}
};

int completed_visit = (1 << N) - 1;
int DP[32][N];

int TSP(int mark, int position) {
    if (mark == completed_visit) {
        return distan[position][0];
    }
    if (DP[mark][position]!= -1) {
        return DP[mark][position];
    }
    int answer = MAX;
    for (int city = 0; city < N; city++) {
        if ((mark & (1 << city)) == 0) {
            int newAnswer = distan[position][city] + TSP(mark | (1 << city), city);
            answer = answer < newAnswer? answer : newAnswer;
        }
    }
    DP[mark][position] = answer;
    return answer;
}

int main() {
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            DP[i][j] = -1;
        }
    }
    printf("Minimum Distance Travelled -> %d\n", TSP(1, 0));
    return 0;
}
