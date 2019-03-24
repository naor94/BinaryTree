#include "Tree.hpp"
using namespace ariel;


struct Node{
  int val;
  struct Node* left;
  struct Node* right;
  struct Node* parent;

  Node(){
    left=nullptr;
    right=nullptr;
    parent=nullptr;
    val=0;
  }
  Node(int val){
    left=nullptr;
    right=nullptr;
    parent=nullptr;
    this->val=val;
  }

};

Tree::Tree(){
  this->Root=nullptr;
  this->sizeNodes=0;
}


Tree& Tree::insert(int val){
  
  Node* cur= new Node(val);
  if(this->Root==nullptr){
    this->Root=cur;
    this->sizeNodes++;
  }
  else{
    bool exit =true;
    Node* temp=this->Root;

    while(exit){
    if(val>temp->val){
      if(temp->right==nullptr){
        this->sizeNodes++;
        temp->right=cur;
        cur->parent=temp;
        exit=false;

      }
      else{
        temp=temp->right;
      }

    }
      else{

          if(temp->left==nullptr){
          this->sizeNodes++;
            temp->left=cur;
            cur->parent=temp;
            exit=false;

      }
      else{
        temp=temp->left;
      }
    }
  }
}

return *this;
}


void Tree::remove(int val){
    std::cout<<"remove "<<std::endl;
  
}
int Tree::size(){
  return this->sizeNodes;;
}
bool Tree::contains(int val){
  if(this->Root==nullptr){
    return false;
  }

  else{
    Node* temp=this->Root;
    while(temp!=nullptr){
      if(temp->val==val){
        return true;
      }
      else if(temp->val>val){
        temp=temp->left;
      }
      else{
        temp=temp->right;
      }

    }
return false;
  }





}
int Tree::root(){
return this->Root->val;
}

Node* Tree::findNode(int val){

  Node* temp=this->Root;
  while(temp){
    if(temp->val==val){
    return temp;
  }
  else if(temp->val>val){
    temp=temp->left;
  }
  else{
    temp=temp->right;
  }

}
return nullptr;
}


int Tree::parent(int val){
  Node* ans= findNode(val);
   return ans->parent->val;
 



}
int Tree::left(int val){
  Node* ans= findNode(val);
  return ans->left->val;

}
int Tree::right(int val){
  Node* ans= findNode(val);
  //return ans->right->val;
  return 0;

}
void Tree::print(){
  std::cout<<"print"<<std::endl;
}

;
