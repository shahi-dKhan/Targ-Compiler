/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"

//Write your code below this line

Parser::Parser(){
    ExprTreeNode* root = new ExprTreeNode();
    symtable=new SymbolTable();
}

void Parser::parse(vector<string> expression){
    ExprTreeNode* root = new ExprTreeNode();
    root->type = "Something";
    root->id = ":=";
    root->num = -1;
    if(expression[0]=="del"){
        root->left = new ExprTreeNode("DEL",-1);
        root->left->id = "del";
        root->right = new ExprTreeNode("VAR",symtable->search(expression[2]));
        root->right->id = expression[2];
        expr_trees.push_back(root);
        return;
    }
    else if(expression[0]=="ret"){
        root->left = new ExprTreeNode("RET",-1);
        root->left->id = expression[0];
    }
    else{
        root->left = new ExprTreeNode("VAR",-1);
        root->left->id = expression[0];
        
    }
        if(expression.size()==3){
            if(expression[2][0]!='-'&& expression[2][0]>'9'){
                root->right = new ExprTreeNode("VAR",symtable->search(expression[2]));
                root->right->id = expression[2];
                expr_trees.push_back(root);
                return;
            }
            root->right = new ExprTreeNode("VAL",stoi(expression[2]));
            expr_trees.push_back(root);
            return;
        }
    
    
    
    root->right = new ExprTreeNode();
    ExprTreeNode* current = root->right;
    
    vector <ExprTreeNode*> stack;
    stack.push_back(current);
    for(int i = 2;i<expression.size();i++){
        if(expression[i]=="("){
            stack.push_back(current);
            current->left = new ExprTreeNode();
            current = current->left;
        }
        else if(expression[i]=="+"||expression[i]=="-"||expression[i]=="*"||expression[i]=="/"){
            current->num=-1;
            if(expression[i]=="+"){
                current->type="ADD";
            }
            if(expression[i]=="-"){
                current->type = "SUB";
            }
            if(expression[i]=="*"){
                current->type = "MUL";
            }
            if(expression[i]=="/"){
                current->type = "DIV";
            }
            stack.push_back(current);
            current->right=new ExprTreeNode();
            current=current->right;
        }
        else if(expression[i]==")"){

            current = stack[stack.size()-1];
            stack.pop_back();
        }
        else{
            
            if(expression[i][0]!='-'&& expression[i][0]>'9'){
                current->type = "VAR";
                current->id = expression[i];
                current->num = symtable->search(expression[i]);
            
            }
            else{
            current->type = "VAL";
            current->num = stoi(expression[i]);
            }
            current=stack[stack.size()-1];
            stack.pop_back();
        }
    
    }
    expr_trees.push_back(root);
}

Parser::~Parser(){
    delete symtable;
    expr_trees.empty();
}
//int main(){
//    Parser parsei;
//    vector <string> aniket;
//    aniket.push_back("ret");
//    aniket.push_back(":=");
//    aniket.push_back("(");
//    aniket.push_back("5");
//    aniket.push_back("+");
//    aniket.push_back("6");
//    aniket.push_back(")");
//    cout << endl;
//    parsei.parse(aniket);
//
//    return 0;
//}

