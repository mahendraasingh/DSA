class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    if (root == NULL)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      int last;
      while (n--) {
        TreeNode *temp = q.front();
        q.pop();

        last = temp->val;
        if (temp->left)
          q.push(temp->left);

        if (temp->right)
          q.push(temp->right);
      }
      ans.push_back(last);
    }
    return ans;
  }
};