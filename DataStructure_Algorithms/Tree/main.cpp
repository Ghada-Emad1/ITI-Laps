#include <iostream>

using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
};
class Tree{
    Node*root;
public:
    Tree(){
       root=NULL;

    }
    void Insert(Node *root,int x){
        if(root==NULL){
            root=new Node();
            root->data=x;
            root->left=root->right=NULL;

        }
        else if(root->data > x){
           Insert(root->right,x);
        }else{
            Insert(root->left,x);
        }
    }
    void Print(Node*root){
        Node*temp=root;
        if(temp==NULL){
            return;
        }
        Print(temp->left);
        cout<<temp->left->data;
    }
};
int main()
{
    Tree t;
    Node *root=NULL;

    t.Insert(root,3);
    t.Insert(root,2);
    t.Insert(root,4);
    t.Print(root);
    return 0;
}
