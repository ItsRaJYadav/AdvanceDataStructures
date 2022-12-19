#include <iostream>
#include <queue>
using namespace std;
struct node
{
        int data;
        node *left, *right;
        node(int key)
        {
                data = key;
                left = NULL;
                right = NULL;
        }
};
void bfs(node *root)
{
        if (root == NULL)
        {
                return;
        }
        queue<node *> q;
        q.push(root);
        while (q.empty() == false)
        {
                node *curr = q.front();
                q.pop();
                cout << curr->data;
                if (curr->left)
                {
                        q.push(curr->left);
                }
                if (curr->right)
                {
                        q.push(curr->right);
                }
        }
}
int main()
{
        struct node *root = new node(1);
        root->left = new node(2);
        root->right = new node(3);
        root->left->left = new node(4);
        root->right->right = new node(5);
        bfs(root);
        return 0;
}
