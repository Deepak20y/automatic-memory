#include <cstdio>
using namespace std;
int f[1001][1001][2];
char g[1001][1001][2];
int n, i, j, k, x = 0;
void print(int x, int y)
{
    if (x == 1 && y == 1)
        return;
    if (g[x][y][k])
        print(x - 1, y), putchar('D');
    else
        print(x, y - 1), putchar('R');
}
int main()
{
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
        f[0][i][0] = f[0][i][1] = f[i][0][0] = f[i][0][1] = 0x3f3f3f3f;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &k);
            if (k)
            {
                for (; !(k % 2); k /= 2)
                    ++f[i][j][0];
                for (; !(k % 5); k /= 5)
                    ++f[i][j][1];
            }
            else
                x = i;
            for (k = 0; k < 2; ++k)
                if ((g[i][j][k] = f[i - 1][j][k] < f[i][j - 1][k]))
                    f[i][j][k] += f[i - 1][j][k];
                else
                    f[i][j][k] += f[i][j - 1][k];
        }
    k = f[n][n][1] < f[n][n][0];
    if (x && f[n][n][k] > 1)
    {
        puts("1");
        for (i = 2; i <= x; i++)
            putchar('D');
        for (i = 2; i <= n; i++)
            putchar('R');
        for (i = x + 1; i <= n; i++)
            putchar('D');
    }
    else
        printf("%d\n", f[n][n][k]), print(n, n);
}