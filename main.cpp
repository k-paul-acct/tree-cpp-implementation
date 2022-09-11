#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "tree.h"
#include "node.h"

int main()
{
	auto root = new TreeNode(3,
		new TreeNode(2,
			new TreeNode(8),
			new TreeNode(9,
				new TreeNode(7),
				new TreeNode(1))),
		new TreeNode(5,
			nullptr,
			new TreeNode(0)));

	auto tree = new tree::BinaryTree(root);

	std::cout << "inorder traversal: ";
	tree->InorderTraversalPrint();
	std::cout << std::endl;

	std::cout << "postorder traversal: ";
	tree->PostorderTraversalPrint();
	std::cout << std::endl;

	std::cout << "preorder traversal: ";
	tree->PreorderTraversalPrint();
	std::cout << std::endl;

	tree->Print();

	tree->~BinaryTree();

	std::cout << "memory leaks found: " << _CrtDumpMemoryLeaks() << std::endl;

	std::cin.get();
	return 0;
}