#include <iostream>
#include <stdexcept>


struct Node;


namespace ariel{
  class Tree;
}


class ariel:: Tree{

private:
struct Node *Root;
int sizeNodes;
void  DestroyRecursive(Node* root);

public:
Tree();
~Tree();
Tree& insert(int val);
void remove(int val);
int size();
bool contains(int val);
int root();
int parent(int val);
int left(int val);
int right(int val);
void print();
void print(Node* root);

  Node* findNode(int val);


};
