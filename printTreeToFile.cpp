#include "printTreeToFile.h"

void printTreeToFile(const BSNode* bs, std::string output)
{
	std::ofstream file(output);
	file.close();
	BSTToFile(bs, output);
}

void BSTToFile(const BSNode* bs, std::string fname) {
	std::ofstream file(fname, std::fstream::app);
	file << bs->getData() << " ";
	file.close();
	if (bs->getLeft())
	{
		BSTToFile(bs->getLeft(),fname);
	}
	file.open(fname, std::fstream::app);
	file << "# ";
	file.close();
	if (bs->getRight())
	{
		BSTToFile(bs->getRight(), fname);
	}
}
