#include <iostream>
#include <string>
#include <tuple>

#include "tree.h"

namespace tree
{
	BinaryTree::BinaryTree()
	{
	}

	BinaryTree::BinaryTree(TreeNode* root)
	{
		_Root = root;
	}

	void _FreeSubTree(TreeNode* node)
	{
		if (node == nullptr) return;

		_FreeSubTree(node->GetLeftNode());
		_FreeSubTree(node->GetRightNode());
		node->~TreeNode();
	}

	BinaryTree::~BinaryTree()
	{
		_FreeSubTree(_Root);
		free(this);
	}

	TreeNode* _Find(TreeNode* root, int element)
	{
		return nullptr;
	}

	// Returns a reference to a node, one of whose children is an element.
	// The bool variable indicates whether the found element is the left child of the parent node.
	// If the element is not found, TreeNode* is set to nullptr.
	std::tuple<TreeNode*, bool> _FindParent(TreeNode* root, int element)
	{
		TreeNode* node = root;
		bool inLeft = false;

		while (node != nullptr)
		{
			if (node->GetLeftNode() != nullptr &&
				node->GetLeftNode()->GetValue() == element)
			{
				inLeft = true;
				break;
			}

			if (node->GetRightNode() != nullptr &&
				node->GetRightNode()->GetValue() == element)
			{
				inLeft = false;
				break;
			}

			if (element < node->GetValue())
			{
				node = node->GetLeftNode();
			}
			else
			{
				node = node->GetRightNode();
			}
		}

		return { node, inLeft };
	}

	TreeNode* _GetMostLeftNode(TreeNode* root)
	{
		TreeNode* node;

		if ((node = root) == nullptr) return nullptr;

		while (node->GetLeftNode() != nullptr)
		{
			node = node->GetLeftNode();
		}

		return node;
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
		if (node == nullptr) return;

		_InorderTraversalPrint(node->GetLeftNode());
		std::cout << node->GetValue() << ' ';
		_InorderTraversalPrint(node->GetRightNode());
	}

	void BinaryTree::InorderTraversalPrint()
	{
		_InorderTraversalPrint(_Root);
	}

	void _PreorderTraversalPrint(TreeNode* node)
	{
		if (node == nullptr) return;

		std::cout << node->GetValue() << ' ';
		_PreorderTraversalPrint(node->GetLeftNode());
		_PreorderTraversalPrint(node->GetRightNode());
	}

	void BinaryTree::PreorderTraversalPrint()
	{
		_PreorderTraversalPrint(_Root);
	}

	void _PostorderTraversalPrint(TreeNode* node)
	{
		if (node == nullptr) return;

		_PostorderTraversalPrint(node->GetLeftNode());
		_PostorderTraversalPrint(node->GetRightNode());
		std::cout << node->GetValue() << ' ';
	}

	void BinaryTree::PostorderTraversalPrint()
	{
		_PostorderTraversalPrint(_Root);
	}

	void _Print(TreeNode* node, int level)
	{
		if (node == nullptr) return;

		for (int _ = 0; _ < level; ++_)
		{
			std::cout << '\t';
		}

		std::cout << node->GetValue() << std::endl;
		_Print(node->GetRightNode(), level + 1);
		_Print(node->GetLeftNode(), level + 1);
	}

	void BinaryTree::Print()
	{
		_Print(_Root, 0);
	}


	BsTree::BsTree()
	{
	}

	BsTree::BsTree(int rootValue)
	{
		_Root = new TreeNode(rootValue);
	}

	BsTree::~BsTree()
	{
	}

	void _AddElement(TreeNode* node, int element)
	{
		if (node == nullptr) return;

		if (element < node->GetValue())
		{
			if (node->GetLeftNode() == nullptr)
			{
				node->SetLeftNode(new TreeNode(element));
			}
			else
			{
				_AddElement(node->GetLeftNode(), element);
			}
		}
		else
		{
			if (node->GetRightNode() == nullptr)
			{
				node->SetRightNode(new TreeNode(element));
			}
			else
			{
				_AddElement(node->GetRightNode(), element);
			}
		}
	}

	void BsTree::AddElement(int element)
	{
		_AddElement(_Root, element);
	}

	void _DeleteElement(TreeNode* node, int element)
	{
		TreeNode* foundParent;
		bool inLeft;
		std::tie(foundParent, inLeft) = _FindParent(node, element);

		if (foundParent == nullptr) return;

		TreeNode* toJoin;
		auto foundNode = inLeft ? foundParent->GetLeftNode() : foundParent->GetRightNode();
		auto foundNodeHasLeft = foundNode->GetLeftNode() != nullptr;
		auto foundNodeHasRight = foundNode->GetRightNode() != nullptr;

		if (!(foundNodeHasLeft && foundNodeHasRight))
		{
			toJoin = foundNodeHasLeft ? foundNode->GetLeftNode() : foundNode->GetRightNode();
		}
		else
		{
			auto mostLeft = _GetMostLeftNode(foundNode->GetRightNode());
			auto mostLeftValue = mostLeft->GetValue();

			_DeleteElement(node, mostLeftValue);

			toJoin = new TreeNode(mostLeftValue);

			toJoin->SetLeftNode(foundNode->GetLeftNode());
			toJoin->SetRightNode(foundNode->GetRightNode());
		}

		if (inLeft)
		{
			foundParent->SetLeftNode(toJoin);
		}
		else
		{
			foundParent->SetRightNode(toJoin);
		}

		foundNode->~TreeNode();
	}

	void BsTree::DeleteElement(int element)
	{
		_DeleteElement(_Root, element);
	}

	bool BsTree::Exists(int element)
	{
		return 0;
	}
}