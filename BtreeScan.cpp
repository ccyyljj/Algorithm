#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visitAlongLeftBranch(TreeNode* root, stack<TreeNode*>& s, vector<int>& result) {
	TreeNode* p = root;
	while (p != NULL) {
		result.push_back(p->val);
		s.push(p->right);
		p = p->left;
	}
}

void VLR_order(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int> result;
	while (1) {
		visitAlongLeftBranch(root, s, result);
		if (s.empty()) {
			break;
		}
		root = s.top();
		s.pop();
	}
}

void VLR_order_2(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int> result;
	if (root == NULL) return;
	s.push(root);
	while (!s.empty()) {
		TreeNode* x = s.top();
		result.push_back(x->val);
		s.pop();
		if (x->right != NULL) {
			s.push(x->right);
		}
		if (x->left != NULL) {
			s.push(x->left);
		}
	}
}

void LRV_order(TreeNode* root) {
	//reverse of VRL
	stack<TreeNode*> s;
	vector<int> result;
	if (root == NULL) return;
	s.push(root);
	while (!s.empty()) {
		TreeNode* x = s.top();
		result.push_back(x->val);
		s.pop();

		if (x->left != NULL) {
			s.push(x->left);
		}
		if (x->right != NULL) {
			s.push(x->right);
		}
	}
	reverse(result.begin(), result.end());
}

void Layer_order(TreeNode *root) {
	queue<TreeNode*> que;
	vector<int> result;
	if (root == NULL) return;
	que.push(root);
	while (!que.empty()) {
		TreeNode* x = que.front();
		result.push_back(x->val);
		que.pop();
		if (x->left != NULL) {
			que.push(x->left);
		}
		if (x->right != NULL) {
			que.push(x->right);
		}
	}
}

void travelAlongLeftBranch(TreeNode* root, stack<TreeNode*>& s) {
	TreeNode* p = root;
	while (p != NULL) {
		s.push(p);
		p = p->left;
	}
}

void LVR_order(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int> result;
	while (1) {
		travelAlongLeftBranch(root, s);
		if (s.empty()) {
			break;
		}
		root = s.top();
		s.pop();
		result.push_back(root->val);
		root = root->right;
	}
}

void main() {
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n6 = new TreeNode(6);
	TreeNode *n7 = new TreeNode(7);

	TreeNode* root = n1;
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	Layer_order(root); 
	VLR_order(root);
	VLR_order_2(root);
	LVR_order(root);
	LRV_order(root);
}

















vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> que;
	vector<vector<int>> result;
	if (root == NULL) {
		return result;
	}
	que.push(root);
	while (!que.empty()) {
		int count = que.size();
		vector<int> layer;
		while (count > 0) {
			TreeNode* p = que.front();
			que.pop();
			layer.push_back(p->val);
			if (p->left != NULL) {
				que.push(p->left);
			}
			if (p->right != NULL) {
				que.push(p->right);
			}
			count--;
		}
		result.push_back(layer);
	}
	return result;
}