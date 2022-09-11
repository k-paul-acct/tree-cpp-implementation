#pragma once

#include "node.h"

using namespace node;

namespace tree
{
	class BinaryTree
	{
	private:
		TreeNode* _Root;

	public:
		BinaryTree(TreeNode* root);
		~BinaryTree();

		void InorderTraversal();
		void PreorderTraversal();
		void PostorderTraversal();

		void InorderTraversalPrint();
		void PreorderTraversalPrint();
		void PostorderTraversalPrint();

		void Print();
	};
}