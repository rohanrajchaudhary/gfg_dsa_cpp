/*
Structure of binary tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            // If number of nodes at current level does not match
            if (n1 != n2) return false;

            vector<int> level1, level2;

            for (int i = 0; i < n1; ++i) {
                Node* curr1 = q1.front();
                q1.pop();
                level1.push_back(curr1->data);

                if (curr1->left) q1.push(curr1->left);
                if (curr1->right) q1.push(curr1->right);

                Node* curr2 = q2.front();
                q2.pop();
                level2.push_back(curr2->data);

                if (curr2->left) q2.push(curr2->left);
                if (curr2->right) q2.push(curr2->right);
            }

            // Check if level values are anagrams
            sort(level1.begin(), level1.end());
            sort(level2.begin(), level2.end());

            if (level1 != level2) {
                return false;
            }
        }

        return q1.empty() && q2.empty();
    }
};