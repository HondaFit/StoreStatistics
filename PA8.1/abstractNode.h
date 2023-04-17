#include "header.h"

class node //base class is node, derived class is transcationNode
{
public:
	virtual ~node() //virtual deconstructor
	{
		cout << "Deconstruction Base" << endl;
	}


	node()
	{
		product = "";
		left = NULL;
		right = NULL;

	}

	node(string uData) // constructor which accepts a string to set the data; each pointer in the node is set to null
	{
		product = uData;
		left = NULL;
		right = NULL;
	}

	void setProduct(string uData)
	{
		product = uData;
	}
	string getProdutct()
	{
		return product;
	}

	virtual int getUnit()
	{
		return 0;
	}

	void setLeft(node* uLeft)
	{
		left = uLeft;
	}
	void setRight(node* uRight)
	{
		right = uRight;
	}

	node*& getLeft()
	{
		return left;
	}
	node*& getRight()
	{
		return right;
	}





private:


protected:

	string product;
	node* left;
	node* right;

};