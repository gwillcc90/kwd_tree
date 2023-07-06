
#include <string>
#include <iostream>

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
	string TRACE = "Inserting Node";
	struct kTreeNode* pCrawl = root;

	// go through each character in the keyword
	for (int i = 0; i < key.length(); i++)
	{
		// if character is 'A'
		if (key[i] == 'A')
		{
			cout << TRACE << "A" << endl;
			// if there is not a childA node, create one.
			if (!pCrawl->childA)
				pCrawl->childA = getNode();
			pCrawl = pCrawl->childA;
		}
		// if character is 'T'
		else if (key[i] == 'T')
		{
			cout << TRACE << "T" << endl;
			// if there is not a childT node, create one.
			if (!pCrawl->childT)
				pCrawl->childT = getNode();
			pCrawl = pCrawl->childT;
		}
		// if character is 'G'
		else if (key[i] == 'G')
		{
			cout << TRACE << "G" << endl;
			// if there is not a childG node, create one.
			if (!pCrawl->childG)
				pCrawl->childG = getNode();
			pCrawl = pCrawl->childG;
		}
		// if character is 'C'
		else if (key[i] == 'C')
		{
			cout << TRACE << "C" << endl;
			// if there is not a childC node, create one.
			if (!pCrawl->childC)
				pCrawl->childC = getNode();
			pCrawl = pCrawl->childC;
		}
	}

	// mark last node as end of keyword
	pCrawl->isEndOfWord = true;
}

bool search(struct kTreeNode*, string keyword)
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


	return 0;
}


int main()
{
	// PROMPT
	string PROMPT = "Node addr:";

	struct kTreeNode* kTreeRoot = getNode();
	insert(kTreeRoot, "ATTA");
	cout << PROMPT << " A: " << kTreeRoot->childA << endl;
	cout << PROMPT << " G: " << kTreeRoot->childG << endl;
	cout << PROMPT << " T: " << kTreeRoot->childT << endl;
	cout << PROMPT << " C: " << kTreeRoot->childC << endl;
	
	bool a = (kTreeRoot->childC == NULL);
	cout << PROMPT << " does not exist: " << a << endl;
	system("pause");
	return 0;
}