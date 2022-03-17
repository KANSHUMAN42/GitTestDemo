#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int val ){
        key = val ; 
        left = NULL ; 
        right = NULL ;
        height = 0 ; 
    }
};

int height(Node* root){
    if(root == NULL){
        return 0 ;
    }
    return max(height(root->left) , height(root->right))+1 ; 
}


Node* Left_rotation(Node* root){
    //for RR type unbalancing 
    Node* temp = root->right ; 
    Node* r = temp->left ; 
    temp->left = root ;
    root->right = r ;  

    root->height = max(height(root->left), height(root->right))+1 ;
    temp->height = max(height(root->left), height(root->right))+1 ;
    return temp ; 

}

Node* Right_rotation(Node* root){
    // for LL unbalacing 
    Node* temp = root->left ; 
    Node* r = temp->right  ; 
    temp->right = root ; 
    root->left = r ; 

    root->height = max(height(root->left), height(root->right))+1 ;
    temp->height = max(height(root->left), height(root->right))+1 ;
    return temp ; 
}

int getBalace( Node* root){
    if(root == NULL ){
        return 0 ; 
    }
    return height(root->left) - height(root->right) ; 
}

Node* insert(Node* root , int key){
    if(root == NULL){
        return new Node(key) ; 
    }
    if(key <  root->key){
        root->left = insert(root->left,key) ; 
    }
    if(key > root->key){
        root->right = insert(root->right,key) ;
    }else{
        return root ; 
    }

    root->height = max(height(root->left), height(root->right))+ 1 ; 
    int balance = getBalace(root) ;
    //ll case 
    if(balance > 1 && key < root->left->key) {
        return Right_rotation(root) ;
    }
    // rr case
     if(balance < -1 && key > root->right->key ){
        return  Left_rotation(root) ; 
    }
    
   // left r case
    if (balance > 1 && key > root->left->key)
    {
        root->left = Left_rotation(root->left);
        return Right_rotation(root);
    }
    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = Right_rotation(root->right);
        return Left_rotation(root);
    }
 
    /* return the (unchanged) node pointer */
    return root;
}






int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\Anshuman\\Desktop\\c++\\output.txt", "w", stdout);
#endif





    

}
