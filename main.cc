#include <iostream>
#include "node.h"
#include "bTree.h"
using namespace std;

int main() {
    BTree myTree;
    myTree.addNode(10);
    myTree.addNode(12);
    myTree.addNode(2);
    myTree.addNode(100);
    myTree.addNode(-2);

    /* Search test */
    int n = 100;
    cout << "Is " << n << " in the tree? ";
    if(myTree.search(n)) cout << "Yes\n";
    else cout << "No\n";

    /* Print test */
    cout << "PreOrder print: "; myTree.printPreOrder(); cout << endl;
    cout << "PostOrder print: "; myTree.printPostOrder(); cout << endl;
}
