#include "abstractNode.h"

class transactionNode : public node //derived class is transactionNode and base class is node
{
public:
	transactionNode()
	{

	}
	~transactionNode() //destructor 
	{

	}
	transactionNode(int uData)
	{
		units = uData;
	}

	void setUnit(int uUnit)
	{
		units = uUnit;
	}
	int getUnit()
	{
		return units;
	}
	void printData()
	{

	}


private:
	int units;

public:

};