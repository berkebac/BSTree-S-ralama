#include <iostream>

using namespace std;

class Node{
  public:
    int sayi_1, sayi_2;
    Node *left;
    Node *right;

    Node(void);
    Node( int s1, int s2);
};
Node::Node(void){
    sayi_1=0;
    sayi_2=0;
    left=0;
    right=0;
}
Node::Node(int s1, int s2){
    sayi_1=s1;
    sayi_2=s2;
    left=0;
    right=0;
}

class BSTree{
  public:
    Node *root;

    BSTree(void);

    void AgacaDegerEkle( Node * );
    void AgacaDegerEkle(int s1, int s2);
    void EkranaYazdir( void );
    void inorder(Node *);
    //void postorder(Node*);
    //void preorder(Node*);

};

BSTree::BSTree(void){
    root=0;
}
void BSTree::AgacaDegerEkle(int s1, int s2){
    AgacaDegerEkle( new Node(s1,s2) );
}
void BSTree::AgacaDegerEkle(Node *yeni){
    if( root==0 ){
        root=yeni;
        return;
    }
    Node *temp=root;
    while(true){
        if( temp->sayi_1 < yeni->sayi_1 ){
            if( temp->right==0 ){
                temp->right = yeni;
                return;
            }else{
                temp = temp->right;
            }
        }else{
            if( temp->left==0 ){
                temp->left = yeni;
                return;
            }else{
                temp = temp->left;
            }
        }
    }
}
void BSTree::EkranaYazdir(void){
    inorder( root );
}
void BSTree::inorder(Node *temp){
    if( temp!=0 ){
        inorder(temp->left);
        cout<<temp->sayi_1<<" "<<temp->sayi_2<<endl;
        inorder(temp->right);
    }
}

int main()
{
    BSTree *bst = new BSTree();
    bst->AgacaDegerEkle(16,0);
    bst->AgacaDegerEkle(20,0);
    bst->AgacaDegerEkle(9,0);
    bst->AgacaDegerEkle(30,0);
    bst->AgacaDegerEkle(10,0);
    bst->AgacaDegerEkle(5,0);

    bst->EkranaYazdir();

    return 0;
}




