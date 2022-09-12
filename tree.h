#pragma once

#include "node.h"

using namespace node;

namespace tree
{
	class BinaryTree
	{
	protected:
		TreeNode* _Root = nullptr;

		BinaryTree();

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

	class BsTree : public BinaryTree
	{
	public:
		BsTree();
		BsTree(int rootValue);
		~BsTree();

		void AddElement(int element);
		void DeleteElement(int element);
		bool Exists(int element);
	};
}