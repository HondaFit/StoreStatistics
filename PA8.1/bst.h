#include "derivedTransactionNode.h"

class bst
{
public:


	~bst() // calls destroy tree
	{

	}
	void destreeTree() // it should visit each node in postOrder to delete them
	{

	}
	bst()
	{
		/*transactionNode* newTran = new transactionNode;
		root = new node;

		root = newTran;*/
	}

	void setRoot(node* uRoot)
	{
		root = uRoot;
	}
	node*& getRoot()
	{
		return root;
	}

	void insertPub(string product, int units)// public used to hide pointer information, i.e. won’t pass in the root of the tree into this function, only the private insert() function
	{
		if (root != NULL)
		{
			node* current = root;
			while (current != NULL)
			{
				if (current->getUnit() > units)
				{
					if (current->getLeft() != NULL)
					{
						current = current->getLeft();
					}
					else
					{
						node* newNode = new node;
						transactionNode* newTran = new transactionNode(units);
						//newTran->setUnit(units);
						newTran->setProduct(product);
						newNode = newTran;

						current->setLeft(newNode);
						current = NULL;
					}
				}
				else
				{
					if (current->getRight() != NULL)
					{
						current = current->getRight();
					}
					else
					{
						node* newNode = new node;
						transactionNode* newTran = new transactionNode(units);
						//newTran->setUnit(units);
						newTran->setProduct(product);
						newNode = newTran;

						current->setRight(newNode);
						current = NULL;
					}
				}
			}
		}
		else
		{
			transactionNode* newTran = new transactionNode;

			//transactionNode t1;
			root = new node;

			root = newTran;
			newTran->setUnit(units);
			newTran->setProduct(product);





		}
	}

	void inOrderTraversalPub() // yes, once again it’s private to hide pointer information
	{
		inOrderTraversal(root);
	}

	void findSmallest()//which returns a reference to a TransactionNode (i.e TransactionNode&) with the smallest mUnits
	{
		node* current = root;
		while (current->getLeft() != NULL)
		{
			current = current->getLeft();
		}
		cout << "\nlowest sold/purchased product:" << endl;
		cout << "Product: " << current->getProdutct() << "\n Units Sold: " << current->getUnit() << endl;

	}
	void findLargerst()//which returns a reference to a TransactionNode with the largest mUnits
	{
		node* current = root;
		while (current->getRight() != NULL)
		{
			current = current->getRight();
		}
		cout << "\nhighest sold/purchased product:" << endl;
		cout << "Product: " << current->getProdutct() << "\n Units Sold: " << current->getUnit() << endl;

	}


private:
	node* root;

	void insert() //yes, it’s private, and it dynamically allocates a TransactionNode and inserts recursively in the correct subtree based onmUnits; should pass in a reference to a pointer(i.e.Node*& pT)
	{

	}

	void inOrderTraversal(node* uRoot) // which recursively visits and prints the contents (mData and mUnits) of each node in the tree in order; each node’s printData() should be called
	{
		node* current = uRoot;
		if (current == NULL) {
			return;
		}
		inOrderTraversal(current->getLeft());
		cout << "Product: " << current->getProdutct() << "\n Units Sold: " << current->getUnit() << endl;
		inOrderTraversal(current->getRight());
	}
};