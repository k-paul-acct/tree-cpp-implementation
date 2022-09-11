#include <iostream>

#include "node.h"

namespace node
{

	TreeNode::TreeNode()
	{
	}

	TreeNode::TreeNode(int value)
	{
		_Value = value;
	}

	TreeNode::TreeNode(int value, TreeNode* left, TreeNode* right)
	{
		_Value = value;
		_Left = left;
		_Right = right;
	}

	TreeNode::~TreeNode()
	{
		free(this);
	}

	TreeNode* TreeNode::GetLeftNode()
	{
		return _Left;
	}

	TreeNode* TreeNode::GetRightNode()
	{
		return _Right;
	}

	void TreeNode::SetLeftNode(TreeNode* node)
	{
		_Left = node;
	}

	void TreeNode::SetRightNode(TreeNode* node)
	{
		_Right = node;
	}

	int TreeNode::GetValue()
	{
		return _Value;
	}

	void TreeNode::Print()
	{
		std::cout << this->_Value;
	}
}