#include <iostream>


struct Node;


namespace ariel{
  class Tree;
}


class ariel:: Tree{

public:
struct Node *Root;
int sizeNodes;
Tree();

Tree insert(int val);
void remove(int val);
int size();
bool contains(int val);
int root();
int parent(int val);
int left(int val);
int right(int val);
void print();

  Node* findNode(int val);


};
