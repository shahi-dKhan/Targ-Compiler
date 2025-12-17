/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
#include<iostream>

//Write your code below this line

SymbolTable::SymbolTable(){
    size = 0;
    root = NULL;
    
}
//void inorder(SymNode* a){
//    if(a==NULL){
//        return;
//    }
//    inorder(a->left);
//    
//    inorder(a->right);
//}
void Upheight(SymNode* a){
    if(a->left==NULL && a->right==NULL){
        a->height=0;
    }
    else if(a->left==NULL){
        Upheight(a->right);
        a->height=a->right->height+1;
    }
    else if(a->right==NULL){
        Upheight(a->left);
        a->height = a->left->height+1;
    }
    else{
        Upheight(a->left);
        Upheight(a->right);
        a->height = 1+max(a->left->height,a->right->height);
    }
    
}
int getheight(SymNode* a){
    if(a!=NULL){
        return a->height;
    }
    else{
        ;return -1;
    }
}
void SymbolTable::insert(string k){
    
    if(size==0){
        root = new SymNode();
        root->key = k;
        size++;
        return;
    }
    root->par=NULL;
    SymNode* current = root;
    SymNode* parent;
    while(current!=NULL){
        
        if(k<current->key){
            parent=current;
            current=current->left;
        }
        else{
            parent=current;
            current=current->right;
            
        }
       
        if(current!=NULL && current->key==k){
            return;
        }
    }
    current = new SymNode(k);
   
    current->par = parent;
    
    if(k<parent->key){
        parent->left=current;
    }
    else{
        parent->right=current;
    }
    size++;
    SymNode* up = current;
    while(up!=root){
        Upheight(up);
        up=up->par;
    }
    Upheight(root);
    //correct enough
    
    while(current!=NULL){
        if(getheight(current->left)-getheight(current->right)>=-1 && getheight(current->left)-getheight(current->right)<=1){
            current=current->par;
        }
        //correct now.
        if(getheight(current->left)-getheight(current->right)==2){
            if(getheight(current->left->left)-getheight(current->left->right)==1){
                int xy = 1;
                if(current==root){
                    xy=2;
                }
                    SymNode* karent = current->par;
                if(xy==1){
                    if(karent->left==current){
                        xy=3;
                    }
                    else{
                        xy=4;
                    }
                }
                current=current->RightRightRotation();
                Upheight(current->left);
                Upheight(current->right);
                if(xy==2){
                    root=current;
                    root->left=current->left;
                    root->right=current->right;
                    root->par = NULL;
                }
                else if(xy==3){
                    karent->left=current;
                }
                else if(xy==4){
                    karent->right=current;
                }
                while(current!=NULL){
                    Upheight(current);
                    current=current->par;
                }
                
                return;
            }
            else{
                int xy=1;
                if(current==root){
                    xy=2;
                }
                SymNode* karent = current->par;
                if(xy==1){
                    if(karent->left==current){
                        xy=3;
                    }
                    else{
                        xy=4;
                    }
                }
                current=current->LeftRightRotation();
                Upheight(current->left);
                Upheight(current->right);
                if(xy==2){
                    root=current;
                    root->left=current->left;
                    root->right=current->right;
                    root->par=NULL;
                }
                else if(xy==3){
                    karent->left=current;
                }
                else if(xy==4){
                    karent->right=current;
                }
                
                while(current->par!=NULL){
                    Upheight(current);
                    current=current->par;
                }
                
                return;
            }
        }
        else if(getheight(current->left)-getheight(current->right)==-2){
            if(getheight(current->right->right)-getheight(current->right->left)==1){
                int xy=1;
                if(current==root){
                    xy=2;
                }
                SymNode* karent = current->par;
                if(xy==1){
                    if(karent->left==current){
                        xy=3;
                    }
                    else{
                        xy=4;
                    }
                }
                
                current=current->LeftLeftRotation();
                
                
                Upheight(current->left);
                Upheight(current->right);
                if(xy==2){
                    root=current;
                    root->left=current->left;
                    root->right=current->right;
                    root->par=NULL;
                }
                
                else if(xy==3){
                    karent->left=current;
                    karent->left->par = karent;
                }
                else if(xy==4){
                    karent->right=current;
                    karent->right->par = karent;
                }
                while(current->par!=NULL){
                    Upheight(current);
                    current=current->par;
                }
                
                return;
            }
            else{
                int xy=1;
                if(current==root){
                    xy=2;
                }
                
                    SymNode* karent = current->par;
                if(xy==1){
                    if(karent->left==current){
                        xy=3;
                    }
                    else{
                        xy=4;
                    }
                }
                current=current->RightLeftRotation();
                Upheight(current->left);
                Upheight(current->right);
                if(xy==2){
                    root=current;
                    root->left=current->left;
                    root->right=current->right;
                    root->par=NULL;
                }
                else if(xy==3){
                    karent->left=current;
                }
                else if(xy==4){
                    karent->right=current;
                }
                while(current->par!=NULL){
                    Upheight(current);
                    current=current->par;
                }
                
                return;
            }
        }
        if(current==root){
            
            return;
        }
    }
}

void SymbolTable::remove(string k){
    root->par=NULL;
    
    
    if(root->left!=NULL){
        
    }
    
    if(size==1 && root->key==k){
        root=NULL;
        size=0;
        return;
    }
    SymNode* current = root;
    while(k!=current->key){
        if(k<current->key){
            current = current->left;
        }
        else if(k>current->key){
            current = current->right;
        }
    }
    
    if(current==NULL){
        return;
    }
    
    //correct till here
    if(current->left==NULL && current->right==NULL){
        
        SymNode* parent=current->par;
        
    
        if(parent->left==current){
            parent->left=NULL;
            delete current;
            size--;
        }
        else{
            parent->right = NULL;
            delete current;
            size--;
        }
        
        //assigning parent value properly
        while(parent!=NULL){
            Upheight(parent);
            if(getheight(parent->left)-getheight(parent->right)==2){
                if(getheight(parent->left->left)-getheight(parent->left->right)==1){
                    int xy = 1;
                    if(parent==root){
                        xy=2;
                    }
                        SymNode* karent = parent->par;
                    if(xy==1){
                        if(karent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->RightRightRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                        root->par = NULL;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }
                    return;
                    
                }
                else{
                    int xy = 1;
                    if(parent==root){
                        xy=2;
                    }
                        SymNode* karent = parent->par;
                    if(xy==1){
                        if(karent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->LeftRightRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                        root->par = NULL;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }
                    return;
                    
                }
            }
            else if(getheight(parent->left)-getheight(parent->right)==-2){
                if(getheight(parent->right->right)-getheight(parent->right->left)==1){
                    int xy = 1;
                    if(parent==root){
                        xy=2;
                    }
                        SymNode* karent = parent->par;
                    if(xy==1){
                        if(parent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->LeftLeftRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                        root->par=NULL;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent->par!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }
                    return;
                }
                else{
                    
                    int xy=1;
                    if(parent==root){
                        xy=2;
                    }
                
                    SymNode* karent = parent->par;
                    if(xy==1){
                        if(karent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->RightLeftRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                        root->par=NULL;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent->par!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }

            }
            
            if(parent==root){
                
                return;
            }
            }
            parent=parent->par;
            
        }
    }
    else if(current->left==NULL || current->right==NULL){
        if(current==root){
            if(current->left==NULL){
                root=root->right;
                delete current;
                size--;
                return;
            }
            else{
                root=root->left;
                delete current;
                size--;
                return;

            }
        }
        SymNode* parent=current->par;
        if(parent->left==current){
            if(current->left==NULL){
                SymNode* todel = current->right;
                parent->left = todel;
                todel->par = parent;
                delete current;
                size--;
            }
            else{
                SymNode* todel = current->left;
                parent->left = todel;
                todel->par = parent;
                delete current;
                size--;
            }
        }
        else{
            if(current->left==NULL){
                SymNode* todel = current->right;
                parent->right = todel;
                todel->par = parent;
                delete current;
                size--;
            }
            else{
                SymNode* todel = current->left;
                parent->right = todel;
                todel->par = parent;
                delete current;
                size--;
            }
        }
        while(parent!=NULL){
            Upheight(parent);
            if(getheight(parent->left)-getheight(parent->right)==2){
                if(getheight(parent->left->left)-getheight(parent->left->right)==1){
                    int xy = 1;
                    if(parent==root){
                        xy=2;
                    }
                        SymNode* karent = parent->par;
                    if(xy==1){
                        if(karent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->RightRightRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                        root->par = NULL;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }
                    return;
                    
                }
                else{
                    int xy = 1;
                    if(parent==root){
                        xy=2;
                    }
                        SymNode* karent = parent->par;
                    if(xy==1){
                        if(karent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->LeftRightRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                        root->par = NULL;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }
                    return;
                    
                }
            }
            else if(getheight(parent->left)-getheight(parent->right)==-2){
                if(getheight(parent->right->right)-getheight(parent->right->left)==1){
                    int xy = 1;
                    if(parent==root){
                        xy=2;
                    }
                        SymNode* karent = parent->par;
                    if(xy==1){
                        if(parent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->LeftLeftRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                        root->par=NULL;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent->par!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }
                    return;
                }
                else{
                    int xy=1;
                    if(parent==root){
                        xy=2;
                    }
                
                    SymNode* karent = parent->par;
                    if(xy==1){
                        if(karent->left==parent){
                            xy=3;
                        }
                        else{
                            xy=4;
                        }
                    }
                    parent=parent->RightLeftRotation();
                    Upheight(parent->left);
                    Upheight(parent->right);
                    if(xy==2){
                        root=parent;
                        root->left=parent->left;
                        root->right=parent->right;
                    }
                    else if(xy==3){
                        karent->left=parent;
                    }
                    else if(xy==4){
                        karent->right=parent;
                    }
                    while(parent->par!=NULL){
                        Upheight(parent);
                        parent=parent->par;
                    }

            }
            
            if(parent==root){
                
                return;
            }
            }
            parent=parent->par;
            
        }
        
    }
    else{
        
        SymNode* success = current->right;
        while(success->left!=NULL){
            success=success->left;
        }
        SymNode* kar = new SymNode();
        if(current==root){
            kar=success->par;
            if(kar==root){
                success->left=root->left;
                root=success;
                root->left=success->left;
                root->right=success->right;
                if(root->left!=NULL){
                    root->left->par=root;
                }
                if(root->right!=NULL){
                    root->right->par=root;
                }
                kar = root;
            }
            else{
                if(kar->right==success){
                    kar->right=success->right;
                }
                else{
                    kar->left=success->right;
                }
                root->left->par=success;
                root->right->par=success;
                success->left=root->left;
                success->right=root->right;
                root=success;
                root->left=success->left;
                root->right=success->right;
            }
            //cerr<<current->key << endl;
            delete current;
            size--;
        }
        else{
            
            SymNode* parent = current->par;
            kar = success->par;
            if(kar->right==success){
                kar->right=success->right;
                if(success->right!=NULL){
                    success->right->par=kar;
                }
            }
            else{
                kar->left=success->right;
                if(kar->left!=NULL){
                    kar->left->par = kar;
                }
            }
            
            if(current==parent->left){
                parent->left=success;
                success->left=current->left;
                success->right=current->right;
                success->par = parent;
                if(current->left!=NULL){
                    current->left->par=success;
                }
                if(current->right!=NULL){
                    current->right->par=success;
                }
            }
            else{
                parent->right=success;
                success->left=current->left;
                success->right=current->right;
                success->par=parent;
                if(current->left!=NULL){
                    current->left->par = success;
                }
                if(current->right!=NULL){
                    current->right->par = success;
                }
            }
            
            delete current;
            size--;
        }
                while(kar!=NULL){
                    Upheight(kar);
                    if(getheight(kar->left)-getheight(kar->right)==2){
                        if(getheight(kar->left->left)-getheight(kar->left->right)==1){
                            int xy = 1;
                            if(kar==root){
                                xy=2;
                            }
                                SymNode* karent = kar->par;
                            if(xy==1){
                                if(karent->left==kar){
                                    xy=3;
                                }
                                else{
                                    xy=4;
                                }
                            }
                            kar=kar->RightRightRotation();
                            Upheight(kar->left);
                            Upheight(kar->right);
                            if(xy==2){
                                root=kar;
                                root->left=kar->left;
                                root->right=kar->right;
                                root->par = NULL;
                            }
                            else if(xy==3){
                                karent->left=kar;
                            }
                            else if(xy==4){
                                karent->right=kar;
                            }
                            while(kar!=NULL){
                                Upheight(kar);
                                kar=kar->par;
                            }
                            return;
                            
                        }
                        else{
                            int xy = 1;
                            if(kar==root){
                                xy=2;
                            }
                                SymNode* karent = kar->par;
                            if(xy==1){
                                if(karent->left==kar){
                                    xy=3;
                                }
                                else{
                                    xy=4;
                                }
                            }
                            kar=kar->LeftRightRotation();
                            Upheight(kar->left);
                            Upheight(kar->right);
                            if(xy==2){
                                root=kar;
                                root->left=kar->left;
                                root->right=kar->right;
                                root->par = NULL;
                            }
                            else if(xy==3){
                                karent->left=kar;
                            }
                            else if(xy==4){
                                karent->right=kar;
                            }
                            while(kar!=NULL){
                                Upheight(kar);
                                kar=kar->par;
                            }
                            return;
                            
                        }
                    }
                    else if(getheight(kar->left)-getheight(kar->right)==-2){
                        if(getheight(kar->right->right)-getheight(kar->right->left)==1){
                            int xy = 1;
                            if(kar==root){
                                xy=2;
                            }
                                SymNode* karent = kar->par;
                            if(xy==1){
                                if(kar->left==kar){
                                    xy=3;
                                }
                                else{
                                    xy=4;
                                }
                            }
                            kar=kar->LeftLeftRotation();
                            Upheight(kar->left);
                            Upheight(kar->right);
                            if(xy==2){
                                root=kar;
                                root->left=kar->left;
                                root->right=kar->right;
                                root->par=NULL;
                            }
                            else if(xy==3){
                                karent->left=kar;
                            }
                            else if(xy==4){
                                karent->right=kar;
                            }
                            while(kar->par!=NULL){
                                Upheight(kar);
                                kar=kar->par;
                            }
                            return;
                        }
                        else{
                            int xy=1;
                            if(kar==root){
                                xy=2;
                            }
                        
                            SymNode* karent = kar->par;
                            if(xy==1){
                                if(karent->left==kar){
                                    xy=3;
                                }
                                else{
                                    xy=4;
                                }
                            }
                            kar=kar->RightLeftRotation();
                            Upheight(kar->left);
                            Upheight(kar->right);
                            if(xy==2){
                                root=kar;
                                root->left=kar->left;
                                root->right=kar->right;
                            }
                            else if(xy==3){
                                karent->left=kar;
                            }
                            else if(xy==4){
                                karent->right=kar;
                            }
                            while(kar->par!=NULL){
                                Upheight(kar);
                                kar=kar->par;
                            }

                        }
                    }
                    
                    if(kar==root){
                        
                        return;
                    }
                    
                    kar=kar->par;
                }
                    
            
    }
                
            
}
        


int SymbolTable::search(string k){
    
    if(root==NULL){
        return -2;
    }
    else{
        SymNode* current = root;
        while(current->key!=k && current!=NULL){
            if(k<current->key){
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
        if(current!=NULL){
            return current->address;
        }
        return -2;
    }
}

void SymbolTable::assign_address(string k,int idx){
  
    SymNode* current = root;
    while(current->key!=k){
        if(k<current->key){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    current->address = idx;

    
    
}

int SymbolTable::get_size(){
    return size;

}

SymNode* SymbolTable::get_root(){
    return root;
}

void devil(SymNode* root){
    if(root==NULL){
        return;
    }
    devil(root->left);
    devil(root->right);
    delete root;
}
SymbolTable::~SymbolTable(){
    devil(root);
    
}


