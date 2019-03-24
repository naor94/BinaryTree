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
  if (Tree::contains(val)==true) {
    throw "bad action";
  }
  
  
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
  Node* temp=findNode(val);
  if(temp==nullptr){
    throw "no val";
    return;
  }
  if(temp->left==nullptr&&temp->right==nullptr){
    if(temp==Root){
      Root=nullptr;
      this->sizeNodes--;
     // delete Root;
      return;
    }
    else{
      if(val>temp->parent->val){
        temp->parent->right=nullptr;
       // delete temp;
             this->sizeNodes--;

        return;
      }
      else{
        temp->parent->left=nullptr;
              this->sizeNodes--;

        return;
      }
    }
  }
  if(temp->left==nullptr&&temp->right!=nullptr){
    if(temp==Root){
      Root=temp->right;
            this->sizeNodes--;

     // delete temp;
      return;
    }
    else{
      if(temp->val>temp->parent->val){
        temp->parent->right=temp->right;
       // delete temp;
      }
      else{
        temp->parent->left=temp->right;
        //delete temp;
      }

      temp->right->parent=temp->parent;
            this->sizeNodes--;

      return;

    }

  }
  if(temp->left!=nullptr&&temp->right==nullptr){
    if(temp==Root){
      Root=temp->left;
            this->sizeNodes--;

      return;
    }
    if(temp->val>temp->parent->val){
      temp->parent->right=temp->left;
      
    }
    else{
      temp->parent->left=temp->left;
    }
    temp->left->parent=temp->parent;
          this->sizeNodes--;

    return;

  }
  if(temp->left!=nullptr&&temp->right!=nullptr){
    Node* t=temp->right;
    while(t->left){
      t=t->left;
    }
    remove(t->val);
          this->sizeNodes--;

    temp->val=t->val;
  }




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
  if(this->Root==NULL){
    throw "no root";
  }
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
  if(ans->parent!=nullptr){
       return ans->parent->val;

  }
  else{
throw "No Parent found";



}
}
int Tree::left(int val){
  Node* ans= findNode(val);
  if(ans->left!=nullptr){
  return ans->left->val;
  }
  else{
    throw "no left";
  }

}
int Tree::right(int val){
  Node* ans= findNode(val);
  if(ans->right!=nullptr){
  return ans->right->val;
  }
  else
  {
    throw "no right";
  }
  

}
void Tree::print(){
  std::cout<<"print"<<std::endl;
}
int main(){
  Tree t;
  std::cout<<t.size()<<std::endl;
  t.insert(4).insert(2);
  t.insert(6);
  t.insert(3);
  t.insert(5).insert(7);
  std::cout<<"after insert"<<" "<<t.size()<<std::endl;
  std::cout<<"before remove"<<" "<<t.size()<<std::endl;

  t.remove(7);
  std::cout<<"after remove"<<" "<<t.size()<<std::endl;

 
  
}
;
