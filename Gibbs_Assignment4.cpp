#include "Stock.h"
#include "BinarySearchTree.h"
#include <fstream>



using namespace std;

int main()
{
	BinarySearchTree<Stock> tree;
	fstream stockFile;
	
	stockFile.open("Stocks.txt");



	//tree.destroy();

	return 0;
}
