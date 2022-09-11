#include <iostream>
#include <string>

#include "tree.h"

namespace tree
{
	BinaryTree::BinaryTree(TreeNode* root)
	{
		_Root = root;
	}

	void _FreeSubTree(TreeNode* node)
	{
		if (node != nullptr)
		{
			_FreeSubTree(node->GetLeftNode());
			_FreeSubTree(node->GetRightNode());
			node->~TreeNode();
		}
	}

	BinaryTree::~BinaryTree()
	{
		_FreeSubTree(_Root);
		free(this);
	}

	void BinaryTree::InorderTraversal()
	{

	}

	void BinaryTree::PreorderTraversal()
	{

	}

	void BinaryTree::PostorderTraversal()
	{

	}

	void _InorderTraversalPrint(TreeNode* node)
	{
		if (node != nullptr)
		{
			_InorderTraversalPrint(node->GetLeftNode());
			std::cout << node->GetValue() << ' ';
			_InorderTraversalPrint(node->GetRightNode());
		}
	}

	void BinaryTree::InorderTraversalPrint()
	{
		_InorderTraversalPrint(_Root);
	}

	void _PreorderTraversalPrint(TreeNode* node)
	{
		if (node != nullptr)
		{
			std::cout << node->GetValue() << ' ';
			_PreorderTraversalPrint(node->GetLeftNode());
			_PreorderTraversalPrint(node->GetRightNode());
		}
	}

	void BinaryTree::PreorderTraversalPrint()
	{
		_PreorderTraversalPrint(_Root);
	}

	void _PostorderTraversalPrint(TreeNode* node)
	{
		if (node != nullptr)
		{
			_PostorderTraversalPrint(node->GetLeftNode());
			_PostorderTraversalPrint(node->GetRightNode());
			std::cout << node->GetValue() << ' ';
		}
	}

	void BinaryTree::PostorderTraversalPrint()
	{
		_PostorderTraversalPrint(_Root);
	}

	void _Print(TreeNode* node, int level)
	{
		if (node != nullptr)
		{
			for (int _ = 0; _ < level; ++_)
			{
				std::cout << '\t';
			}
			std::cout << node->GetValue() << '\t' << std::endl;
			_Print(node->GetRightNode(), level + 1);
			_Print(node->GetLeftNode(), level + 1);
		}
	}

	void BinaryTree::Print()
	{
		_Print(_Root, 0);
	}
}