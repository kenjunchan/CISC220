

#ifndef NodeT_HPP_
#define NodeT_HPP_

#include <string>
using namespace std;

class NodeT {
	friend class BSTY;

public:
	string data;
	int height;
	NodeT *left;
	NodeT *right;
	NodeT *parent;
	string def;

	NodeT(string x);
	NodeT(string x, string y);
	~NodeT();
	void printNode();
};



#endif /* NodeT_HPP_ */
