vector<vector<int>> verticalOrder(TreeNode* root) 
{
	if(root == NULL) return {};
	
	int col, maxI = INT_MIN, minI = INT_MAX;
	TreeNode* node;
	unordered_map<int,vector<int>>hashT;
	vector<vector<int>>res;
	queue<TreeNode*>qNode;
	queue<int>qCol;
	
	qNode.push(root);
	qCol.push(0);
	while(!qNode.empty())
	{
		node = qNode.front();
		qNode.pop();
		col = qCol.front();
		qCol.pop();
		minI = min(minI,col);
		maxI = max(maxI,col);
		
		hashT[col].push_back(node->val);
		if(node->left != NULL)
		{
			qNode.push(node->left);
			qCol.push(col-1);
			//minI = min(minI,col-1);
		}
		if(node->right != NULL)
		{
			qNode.push(node->right);
			qCol.push(col+1);
			//maxI = max(maxI,col+1);
		}
	}
	
	for(int i=minI ; i<=maxI ; i++)
		res.push_back(hashT[i]);
	
	return res;
}