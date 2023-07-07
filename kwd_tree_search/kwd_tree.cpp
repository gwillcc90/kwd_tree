
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
kTreeNode
Has four pointers:
  childA: if 'A' is next character in the keyword, child node childA is added
  childT: if 'T' is next character in the keyword, child node childT is added
  childG: if 'G' is next character in the keyword, child node childG is added
  childC: if 'C' is next character in the keyword, child node childC is added

Has one boolean member:
   isEndOfWord: is true if kTreeNode represents the last character of a keyword otherwise false
 */
struct kTreeNode
{
	struct kTreeNode* childA;
	struct kTreeNode* childT;
	struct kTreeNode* childG;
	struct kTreeNode* childC;

	// isEndOfWord is true if the node represents 
	// end of a keyword
	bool isEndOfWord;
};

// Returns new kTree node (initialized to NULLs) 
struct kTreeNode* getNode(void)
{
	struct kTreeNode* pNode = new kTreeNode;
	pNode->isEndOfWord = false;

	pNode->childA = NULL;
	pNode->childT = NULL;
	pNode->childG = NULL;
	pNode->childC = NULL;

	return pNode;
}

// If keyword not present in the tree, inserts keyword into Keyword tree
// If the keyword is prefix of kTree node, just  marks leaf node

void insert(struct kTreeNode* root, string key)
{
	//string TRACE = "Inserting Node";
	struct kTreeNode* pCrawl = root;

	// go through each character in the keyword
	for (int i = 0; i < key.length(); i++)
	{
		// if character is 'A'
		if (key[i] == 'A')
		{
			//cout << TRACE << "A" << endl;
			// if there is not a childA node, create one.
			if (!pCrawl->childA)
				pCrawl->childA = getNode();
			pCrawl = pCrawl->childA;
		}
		// if character is 'T'
		else if (key[i] == 'T')
		{
			//cout << TRACE << "T" << endl;
			// if there is not a childT node, create one.
			if (!pCrawl->childT)
				pCrawl->childT = getNode();
			pCrawl = pCrawl->childT;
		}
		// if character is 'G'
		else if (key[i] == 'G')
		{
			//cout << TRACE << "G" << endl;
			// if there is not a childG node, create one.
			if (!pCrawl->childG)
				pCrawl->childG = getNode();
			pCrawl = pCrawl->childG;
		}
		// if character is 'C'
		else if (key[i] == 'C')
		{
			//cout << TRACE << "C" << endl;
			// if there is not a childC node, create one.
			if (!pCrawl->childC)
				pCrawl->childC = getNode();
			pCrawl = pCrawl->childC;
		}
	}

	// mark last node as end of keyword
	pCrawl->isEndOfWord = true;
}

bool search(struct kTreeNode* root, string keyword)
{
	/*
	Search a keyword tree for a keyword.

	ARGS
	-----
	kTreeNode: Root (or other) node in a keyword tree.
	keyword: keyword to search

	RETURNS
	--------
	0 if keyword not in tree, else 1
	*/
	kTreeNode* temp_tree = root;
	string::iterator it = keyword.begin();
	for (; it < keyword.end(); it++)
	{
		//cout << "Keyword index: " << i << endl;
		cout << *it << endl;
		//if (keyword[i] == 'A')
		if (*it == 'A')
		{
			//cout << setw(5) << left << " " << keyword[i] << endl;
			if (temp_tree->childA)
			{
				//cout << setw(5) << left << " " << keyword[i];
				//cout << " pointer exists" << endl;
				temp_tree = temp_tree->childA;
			}
			else { return 0; }
		}
		//else if (keyword[i] == 'G')
		else if (*it == 'G')
		{
			//cout << setw(5) << left << " " << keyword[i] << endl;
			if (temp_tree->childG)
			{
				//cout << setw(5) << left << " " << keyword[i];
				//cout << " pointer exists" << endl;
				temp_tree = temp_tree->childG;
			}
			else { return 0; }
		}
		//else if (keyword[i] == 'C')
		else if (*it == 'C')
		{
			//cout << setw(5) << left << " " << keyword[i] << endl;
			if (temp_tree->childC)
			{
				//cout << setw(5) << left << " " << keyword[i];
				//cout << " pointer exists" << endl;
				temp_tree = temp_tree->childC;
			}
			else { return 0; }
		}
		//else if (keyword[i] == 'T')
		else if (*it == 'T')
		{
			//cout << setw(5) << left << " " << keyword[i] << endl;
			if (temp_tree->childT)
			{
				//cout << setw(5) << left << " " << keyword[i];
				//cout << " pointer exists" << endl;
				temp_tree = temp_tree->childT;
			}
			else { return 0; }
		}
		else { return 0; }
	}
	/* 
	Here function returned 0 bc keyword isn't in tree
	or continues to see if an end node was reached
	*/

	return temp_tree->isEndOfWord ? 1 : 0;
}


int main()
{
	// Define file name to create
	string of_name = "output.txt";
	// Create & open file for output
	ofstream outfile; outfile.open(of_name);

	// Instantiate keyword tree
	struct kTreeNode* kTreeRoot = getNode();

	// Insert keywords into keyword tree (creating tree)
	insert(kTreeRoot, "ATGC");
	insert(kTreeRoot, "TTA");
	insert(kTreeRoot, "AT");
	insert(kTreeRoot, "ATA");

	// Vector of test cases
	vector<string> test_cases{"TA", "ATGC", "A", "GC", "AT"};
	// Iterator for vector
	vector<string>::iterator it = test_cases.begin();

	// Iterate
	for (; it < test_cases.end(); it++)
	{
		cout << "Test Case: " << *it << endl;
		outfile << "Test Case: " << *it << endl;
		if (search(kTreeRoot, *it)) 
		{ 
			cout << "Keyword exists" << endl; 
			outfile << "Keyword exists" << endl;
			outfile << endl;
		}
		else 
		{ 
			cout << "Does not exist." << endl; 
			outfile << "Keyword does not exist" << endl;
			outfile << endl;
		}
		cout << endl;
	}

	outfile.close();

	system("pause");
	return 0;
}



// Extra code for tracing/debugging
/*
	Below:
	struct kTreeNode* kTreeRoot = getNode();
	insert(kTreeRoot, "ATTA");

	Add:
	string PROMPT = "Node addr:";
	cout << PROMPT << " A: " << kTreeRoot->childA << endl;
	cout << PROMPT << " G: " << kTreeRoot->childG << endl;
	cout << PROMPT << " T: " << kTreeRoot->childT << endl;
	cout << PROMPT << " C: " << kTreeRoot->childC << endl;

	bool a = (kTreeRoot->childC == NULL);
	cout << PROMPT << " does not exist: " << a << endl;

*/