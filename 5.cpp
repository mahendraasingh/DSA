class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {

      int level = q.size();
      vector<int> temp;
      while (level != 0) {
        TreeNode *t = q.front();
        q.pop();
        temp.push_back(t->val);
        if (t->left != NULL) {
          q.push(t->left);
        }
        if (t->right != NULL) {
          q.push(t->right);
        }
        level--;
      }
      ans.push_back(temp);
    }
    return ans;
  }
};