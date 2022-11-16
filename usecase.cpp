#include <fstream>
#include <iostream>
#include "bst.cpp"
#include <stdlib.h>
#include <sstream>

using namespace std;

void getData(string &line, string &data, string &key)
{
	int i = 0;
	int length = line.size();
	// get data (first half of string)
	for (; i < length && line[i] != ','; ++i)
	{
		data.push_back(line[i]);
	}

	// get key (second half of string)
	i += 1;
	for (; i < length && line[i] != '\n'; ++i)
	{
		key.push_back(line[i]);
	}
}

template <typename D, typename K>
BST<D, K> *create_bst(string fname)
{
	BST<D, K> *bst = new BST<D, K>;

	fstream inputFile(fname); // open file
	if (inputFile.fail())
	{
		cerr << "Error opening the file.\n";
	}

	string line;
	while (getline(inputFile, line))
	{ // read line by line
		string data;
		string key;
		getData(line, data, key);
		bst->insert(data, key);
	}

	return bst;
}

template <typename D, typename K>
string convert(BST<D, K> *bst, string bin)
{
	int binSize = bin.size();
	if (binSize % 4 != 0)
	{
		string paddedBin;
		paddedBin.append(4 - (binSize%4), '0'); // fill in leading 0's
		paddedBin.append(bin);
		bin = paddedBin;											  // copy padddedBin to bin
	}

	string hex;
	// iterate over the whole bin to get groups of 4
	for (int i = 0; i < bin.size(); i += 4)
	{
		string subBin = bin.substr(i, 4);
		hex.append(bst->get(subBin));
	}
	return hex;
}