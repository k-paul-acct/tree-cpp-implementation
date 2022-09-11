#pragma once

namespace node
{
	class TreeNode
	{
	private:
		int _Value = 0;
		TreeNode* _Left = nullptr;
		TreeNode* _Right = nullptr;

	public:
		TreeNode();
		TreeNode(int value);
		TreeNode(int value, TreeNode* left, TreeNode* right);
		~TreeNode();

		TreeNode* GetLeftNode();
		TreeNode* GetRightNode();
		void SetLeftNode(TreeNode* node);
		void SetRightNode(TreeNode* node);
		int GetValue();
		void Print();
	};
}