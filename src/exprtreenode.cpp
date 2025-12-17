/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

//Write your code below this line

ExprTreeNode::ExprTreeNode(){
    id  = "";
    type="";

}

ExprTreeNode::ExprTreeNode(string t,int v){
    type = t;
    num = v;
  
}

ExprTreeNode::~ExprTreeNode(){
    id = "";
    num=-1;
}

// /* Do NOT add/remove any includes statements from this header file */
// /* unless EXPLICTLY clarified on Piazza. */
// #include "exprtreenode.h"
// ExprTreeNode::ExprTreeNode(){
    
//     string type = "";
// }
// ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v){
//     evaluated_value = new UnlimitedRational();
//     type = t;
//     val = new UnlimitedRational(v,new UnlimitedInt("1"));
    


// }
// ExprTreeNode::ExprTreeNode(string t, UnlimitedRational* v){
//     evaluated_value = new UnlimitedRational();
//     type = t;
//     val = v;
    

// }
// ExprTreeNode::~ExprTreeNode(){
//     delete evaluated_value;
//     delete val;
// }

