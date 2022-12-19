#include <iomanip>
#include <bits/stdc++.h>

#define N 7
#define INF 999
using namespace std;
// Cost matrix of the graph
int costMat[N][N] = {
    {0, 2, 6, INF, INF, INF, INF},
    {3, 1, 2, 1, 9, INF, INF},
    {6, 2, 0, 5, 4, 2, 2},
    {INF, 1, 1, 0, 2, INF, 4},
    {INF, INF, 4, 5, 0, 2, 1},
    {INF, INF, 2, INF, 2, 0, 1},
    {INF, INF, INF, 4, 1, 1, 0}};
void floydWarshal()
{
        int cost[N][N]; // defind to store shortest distance from any N to any N
        for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                        cost[i][j] = costMat[i][j]; // copy costMatrix to new matrix
        for (int k = 0; k < N; k++)
        {
                for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++)
                                if (cost[i][k] + cost[k][j] < cost[i][j])
                                        cost[i][j] = cost[i][k] + cost[k][j];
        }
        cout << "The matrix:" << endl;
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < N; j++)
                        cout << setw(3) << cost[i][j];
                cout << endl;
        }
}
int main()
{
        floydWarshal();
}
