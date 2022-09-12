#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "tree.h"
#include "node.h"

int main()
{
	// Binary tree usage example in general.
	auto root =
		new TreeNode(3,
			new TreeNode(2,
				new TreeNode(8),
				new TreeNode(9,
					new TreeNode(7),
					new TreeNode(1))),
			new TreeNode(5,
				nullptr,
				new TreeNode(0)));
	auto tree = new tree::BinaryTree(root);

	std::cout << "Binary tree example:" << std::endl;
	tree->Print();

	std::cout << "inorder traversal: ";
	tree->InorderTraversalPrint();
	std::cout << std::endl;
	std::cout << "postorder traversal: ";
	tree->PostorderTraversalPrint();
	std::cout << std::endl;
	std::cout << "preorder traversal: ";
	tree->PreorderTraversalPrint();
	std::cout << std::endl << std::endl;

	// Binary search tree usage example.
	auto bsTree = new tree::BsTree(9);
	bsTree->AddElement(7);
	bsTree->AddElement(12);
	bsTree->AddElement(5);
	bsTree->AddElement(6);
	bsTree->AddElement(8);
	bsTree->AddElement(19);
	bsTree->AddElement(21);
	bsTree->AddElement(-12);
	bsTree->AddElement(-3);
	bsTree->AddElement(15);
	bsTree->AddElement(14);
	bsTree->AddElement(16);
	bsTree->AddElement(20);

	std::cout << "Binary search tree example:" << std::endl;
	bsTree->Print();

	std::cout << "inorder traversal: ";
	bsTree->InorderTraversalPrint();
	std::cout << std::endl;

	bsTree->DeleteElement(19);

	std::cout << "Binary search tree delete element example:" << std::endl;
	bsTree->Print();

	std::cout << "inorder traversal after deleting: ";
	bsTree->InorderTraversalPrint();
	std::cout << std::endl;

	// Memory release.
	tree->~BinaryTree();
	bsTree->~BsTree();

	// Leaks info.
	std::cout << "memory leaks found: " << _CrtDumpMemoryLeaks() << std::endl;

	// Waiting for input to close the terminal.
	std::cin.get();

	return 0;
}