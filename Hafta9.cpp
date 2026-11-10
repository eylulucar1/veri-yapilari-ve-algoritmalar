#include <iostream>
// Week 9 - AVL Tree Implementation
using namespace std;
typedef struct AVLnode{
    int data,high;
    struct AVLnode *left,*right;
}AVLnode;
int max(int a,int b){
    return (a > b) ? a : b;
}
int h(AVLnode* d){
    return (d==NULL) ? -1 : d->high;
}
int getBalance(AVLnode* d){
    return (d==NULL) ? 0 : h(d->left)-h(d->right);
}
AVLnode* rightRotate(AVLnode* d){ 
    /*d->left child is y and y->right child is T2. So we need to rotate right around d. 
    After rotation, y becomes the new root of the subtree, d becomes the right child of y, and T2 becomes the left child of d.*/
    AVLnode* x = d->left;
    AVLnode* T2 = x->right;
    x->right = d;
    d->left = T2;
    d->high = 1 + max(h(d->left),h(d->right));
    x->high = 1 + max(h(x->left),h(x->right));
    return x;
}
AVLnode* leftRotate(AVLnode* d){
    /*d->right child is y and y->left child is T2. So we need to rotate left around d. 
    After rotation, y becomes the new root of the subtree, d becomes the left child of y, and T2 becomes the right child of d.*/
    AVLnode* y = d->right;
    AVLnode* T2 = y->left;
    y->left = d;
    d->right = T2;
    d->high = 1 + max(h(d->left),h(d->right));
    y->high = 1 + max(h(y->left),h(y->right));
    return y;
}
AVLnode* avlAdd(AVLnode* node, int key){
    if(node == NULL){
        AVLnode* n = (AVLnode*)malloc(sizeof(AVLnode));
        n->data = key; n->high = 0; n->left = n->right = NULL;
        return n;
    }
    if(key < node->data) node->left= avlAdd(node->left,key);
    if(key > node->data) node->right= avlAdd(node->right,key);
    else return node;

    node->high = 1 + max(h(node->left),h(node->right));
    int balance = getBalance(node);
    if(balance>1 && key < node->left->data) return rightRotate(node);
    if(balance< -1 && key > node->right->data) return leftRotate(node);
    if(balance > 1 && key > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && key < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void printInOrder(AVLnode* root){
    if(root != NULL){
        printInOrder(root->left);
        cout<<root->data<<" ";
        printInOrder(root->right);
    }
}
void printPreOrder(AVLnode* root){
    if(root != NULL){
        cout<<root->data<<" ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
void printPostOrder(AVLnode* root){
    if(root != NULL){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    AVLnode* root = NULL;
    for(int i=0; i<10; i++){
        root = avlAdd(root,rand()%100);
    }
    printInOrder(root);
    cout<<endl;
    printPreOrder(root);
    cout<<endl;
    printPostOrder(root);
    cout<<endl;
    return 0;
}

// Zaman karmaşıklığı : O(nlogn)
