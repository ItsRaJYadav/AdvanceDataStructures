
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string LCS(string X, string Y)
{
        int m = X.length();
        int n = Y.length();

        int L[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
                for (int j = 0; j <= n; j++)
                {
                        if (i == 0 || j == 0)
                                L[i][j] = 0;

                        else if (X[i - 1] == Y[j - 1])
                                L[i][j] = L[i - 1][j - 1] + 1;

                        else
                                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
        }

        int index = L[m][n];

        string lcs(index + 1, ' ');

        int i = m, j = n;
        while (i > 0 && j > 0)
        {
                if (X[i - 1] == Y[j - 1])
                {
                        lcs[index - 1] = X[i - 1]; // put current character in result
                        i--;
                        j--;
                        index--;
                }

                else if (L[i - 1][j] > L[i][j - 1])
                        i--;
                else
                        j--;
        }

        return lcs;
}

int main()
{
        string X, Y;

        cout << "Enter first string: ";
        cin >> X;
        cout << "Enter second string: ";
        cin >> Y;
        string lcs = LCS(X, Y);
        cout << "The longest common subsequence is: " << lcs << endl;

        return 0;
}
