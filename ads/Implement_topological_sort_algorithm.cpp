
#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int n, vector<int> adj[])
{
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
                for (auto it : adj[i])
                {
                        indegree[it]++;
                }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
                if (indegree[i] == 0)
                        q.push(i);
        }
        while (!q.empty())
        {
                int currNode = q.front();
                q.pop();
                ans.push_back(currNode);
                for (auto it : adj[currNode])
                {
                        indegree[it]--;
                        if (indegree[it] == 0)
                                q.push(it);
                }
        }
        return ans;
        // code here
}
int main()
{
        int n;
        cin >> n;
        vector<int> adj[n];
        int e;
        cin >> e;
        for (int i = 0; i < e; i++)
        {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        vector<int> temp = topoSort(n, adj);
        for (auto it : temp)
                cout << it << " ";
        cout << endl;
}
