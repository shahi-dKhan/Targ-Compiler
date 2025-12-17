/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"
#include <iostream>

//Write your code below this line

SymNode::SymNode(){
    key = "";
    height = 0;
    address = -1;
    SymNode* par = NULL;
    SymNode* left = NULL;
    SymNode* right = NULL;
}

SymNode::SymNode(string k){
    key = k;
    height = 0;
    address = -1;
    par = NULL;
    left = NULL;
    right = NULL;

}
// void Upheight(SymNode* a){
//     if(a->left==NULL && a->right==NULL){
//         a->height=0;
//     }
//     else if(a->left==NULL){
//         a->height=a->right->height+1;
//     }
//     else if(a->right==NULL){
//         a->height = a->left->height+1;
//     }
//     else{
//         a->height = 1+max(a->left->height,a->right->height);
//     }
// }

// int getheight(SymNode* a){
//     if(a!=NULL){
//         return a->height;
//     }
//     else{
//         return -1;
//     }
// }

SymNode* SymNode::LeftLeftRotation(){
    SymNode* r1 = this->right;
    SymNode* r2 = r1->right;
    r1->par = this->par;
    this->right = r1->left;
    r1->left = this;
    this->par = r1;
    return r1;
}

SymNode* SymNode::RightRightRotation(){
    SymNode* l1 = this->left;
    l1->par = this->par;
    this->left = l1->right;
    l1->right = this;
    this->par = l1;
    return l1;
}

SymNode* SymNode::LeftRightRotation(){
    SymNode* l1 = this->left;
    SymNode* l2 = l1->right;
    this->left = l2->right;
    l2->par = this->par;
    this->par = l2;
    l1->right = l2->left;
    l2->right = this;
    l2->left = l1;
    l1->par = l2;
    return l2;
}

SymNode* SymNode::RightLeftRotation(){
    SymNode* l1 = this->right;
    SymNode* l2 = l1->left;
    this->right = l2->left;
    l2->par = this->par;
    this->par = l2;
    l1->left = l2->right;
    l2->right = l1;
    l2->left = this;
    l1->par = l2;
    return l2;
}

SymNode::~SymNode(){
    height = -1;
    address = -1;
    key="";
    this->left = NULL;
    this->right = NULL;

    
}

// int main(){
//     SymNode* vijay = new SymNode("I");
//     SymNode* anurag = new SymNode("love");
//     SymNode* tiwari = new SymNode("you");
//     vijay->right = anurag;
//     anurag->left = tiwari;
//     anurag->par = vijay;
//     tiwari->par = anurag;
//     vijay->RightLeftRotation();
//     cout << vijay->par->left->key<< endl;

// }
