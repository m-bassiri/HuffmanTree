#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "InternalNode.h"
#include "LeafNode.h"
#include "MinHeap.h"

using namespace std;

//a recursive function printing the code of all characters
void printCode(BaseNode* root, vector<bool> code) {
	if (root->isLeaf()) {
		LeafNode *x = dynamic_cast<LeafNode*>(root);
		cout << x->getElement() << " = ";
		for (auto i : code) {
			cout << i;
		}
		cout << endl;
		return;
	}
	InternalNode *x = dynamic_cast<InternalNode*>(root);
	code.push_back(0);
	printCode(x->getLeftChild(), code);
	code.pop_back();
	code.push_back(1);
	printCode(x->getRightChild(), code);
	return;
}
 
//a pair of character and number of its repeats
struct repeat
{
	char c;
	int rep;
};

int main() {
	vector <repeat> reps; //a vector holding repeats

	//getting input
	string address;
	cout << "Please enter file address: ";
	cin >> address;
	ifstream file(address.c_str());
	if (!file.is_open()) {
		cout << "The file doesn't exist!\n";
		return 0;
	}

	//filling repeats vector
	string content;
	getline(file, content);
	if (content[0] == 0) {
		cout << "File is empty!\n";
		return 0;
	}
	for (char i = 'A'; i <= 'Z'; i++) {
		int cnt = 0;
		for (auto x : content) {
			if (x == i)
				cnt++;
		}
		if (cnt) {
			repeat r = { i, cnt };
			reps.push_back(r);
		}
	}

	//adding chars and their repeats to min heap
	MinHeap h(reps.size());
	for (auto x : reps) {
		LeafNode* node = new LeafNode(x.c, x.rep);
		h.insertKey(node);
	}

	//generating chars tree
	while (!h.lastElement())
	{
		BaseNode *node1 = h.extractMin();
		BaseNode *node2 = h.extractMin();
		if (node1->getWeight() >= node2->getWeight()) {
			BaseNode *temp = node1;
			node1 = node2;
			node2 = temp;
		}
		InternalNode* node = new InternalNode(node1, node2, node1->getWeight() + node2->getWeight());
		h.insertKey(node);
	}

	//printing code of each characters using printCode() recursive function
	vector<bool> code;
	printCode(h.extractMin(), code);
	return 0;
}