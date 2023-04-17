#include "bst.h"


class dataAnalysis
{
public:
	dataAnalysis()
	{

	}

	void readLine()
	{

	}

	void runAnalysis()
	{
		int units;
		string product;
		string transaction;

		string line;


		opFile.open("data.csv", std::ios::in);
		opFile >> line; //ignore 1st line
		while (!opFile.eof())
		{
			opFile >> line;
			if (line.empty() == false)
			{

				parseLine(line, units, product, transaction);

				if (transaction == "Purchased")
				{
					treePurchased.insertPub(product, units);
					//cout << "Purchased" << endl;
				}
				else
				{
					treeSold.insertPub(product, units);
					//cout << "Sold" << endl;
				}

			}
		}
		opFile.close();
		cout << "Products Sold Information:" << endl;
		treeSold.inOrderTraversalPub();
		treeSold.findSmallest();
		treeSold.findLargerst();

		cout << "\n" << endl;

		cout << "Products Purchased Information:" << endl;
		treePurchased.inOrderTraversalPub();
		treePurchased.findSmallest();
		treePurchased.findLargerst();


	}

private:
	bst treeSold;
	bst treePurchased;
	fstream opFile;

	void parseLine(string& line, int& units, string& product, string& transaction)
	{
		string delimiter = ",";
		string token;

		token = line.substr(0, line.find(delimiter));
		units = stoi(token);
		line.erase(0, line.find(delimiter) + delimiter.length());


		token = line.substr(0, line.find(delimiter));
		product = token;
		line.erase(0, line.find(delimiter) + delimiter.length());

		token = line.substr(0, line.find(delimiter));
		transaction = token;
		line.erase(0, line.find(delimiter) + delimiter.length());
	}


};