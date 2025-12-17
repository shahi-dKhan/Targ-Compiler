/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "eppcompiler.h"

//Write your code below this line

EPPCompiler::EPPCompiler(){
    for(unsigned int i = 0;i<memory_size;i++){
        mem_loc.push_back(i);
    }
}


EPPCompiler::EPPCompiler(string out_file,int mem_limit){
    output_file = out_file;
    memory_size=mem_limit;
    for(unsigned int i = 0;i<memory_size;i++){
        mem_loc.push_back(i);
    }
}
void EPPCompiler::compile(vector<vector<string> > code){
    for(int i = 0;i<code.size();i++){
        targ.parse(code[i]);
        
        
        if(targ.expr_trees[targ.expr_trees.size()-1]->left->type=="VAR" || targ.expr_trees[targ.expr_trees.size()-1]->left->type=="RET"){
            //if(targ.expr_trees.back()->left->type=="RET" || targ.symtable->get_size()==0 || targ.symtable->search(code[i][0])==-1){
                int ad = mem_loc[mem_loc.size()-1];
                mem_loc.pop_back();
                targ.symtable->insert(code[i][0]);
                
                if(targ.symtable->search(code[i][0])!=-1){
                    mem_loc.push_back(ad);
                }
                else{
                    targ.symtable->assign_address(code[i][0],ad);
                }
                
        //}
            
            vector <string> z = generate_targ_commands();
            
            write_to_file(z);
        }
        else if(targ.expr_trees[targ.expr_trees.size()-1]->left->type=="DEL"){
            int s = targ.symtable->search(code[i][2]);
            mem_loc.push_back(s);
            vector <string> z = generate_targ_commands();
            for (int i = 0;i<z.size();i++){
                cout << z[i] << endl;
            }
            targ.symtable->remove(code[i][2]);
            write_to_file(z);
        }
    }
}
string generate(ExprTreeNode* abc){
    if(abc->type=="VAL"){
        string s = "PUSH";
        string z = to_string(abc->num);
        s = s+" " + z;
        return s;
    }
    else if(abc->type=="VAR"){
        string s = "PUSH";
        string z = to_string(abc->num);
        s = s+" "+"mem"+"["+z+"]";
        return s;
    }
    else{
        return abc->type;
    }
}
vector<string>vec;
void post_order_gen(ExprTreeNode* node, SymbolTable* simka){
    if(node==NULL){
        return;
    }
    post_order_gen(node->right, simka);
    post_order_gen(node->left, simka);
    vec.push_back(generate(node));


}


vector<string> EPPCompiler::generate_targ_commands(){
    //It enters for generating targ commands
    vec.clear();
    ExprTreeNode* current = targ.expr_trees[targ.expr_trees.size()-1];
    
    post_order_gen(current->right,targ.symtable);
    // for(int i = 0;i<vec.size();i++){
    //     cerr << vec[i] << endl;
    // }
    //It is correctly generating command till here
    if(current->left->type=="VAR"){
        vec.push_back("mem["+to_string(targ.symtable->search(current->left->id))+"] = POP");
    //It is correctly generating command till here
    }
    else if(current->left->type=="RET"){
        vec.push_back("RET = POP");
    }
    else if(current->left->type=="DEL"){
        vec.push_back("DEL = mem["+to_string(targ.symtable->search(current->right->id))+"]");
        return vec;
    }
    return vec;



}

void EPPCompiler::write_to_file(vector<string> commands){
    ofstream Myfile(output_file, ios::app);
    for(int i = 0;i<commands.size();i++){
        Myfile << commands[i] << endl;
    }
    Myfile.close();
}

EPPCompiler::~EPPCompiler(){
  
}


int main(){
    // a=(2-3)
    vector<string> vec1;
    vec1.push_back("a");
    vec1.push_back(":=");
    vec1.push_back("(");
    vec1.push_back("(");
    vec1.push_back("0");
    vec1.push_back("+");
    vec1.push_back("2");
    vec1.push_back(")");
    vec1.push_back("+");
    // vec1.push_back("(");
    vec1.push_back("12");
    // vec1.push_back(")");
    vec1.push_back(")");
    
    // b=(((2×a)+(a-7))-(12))
    vector<string> vec2;
    vec2.push_back("b");
    vec2.push_back(":=");
    vec2.push_back("(");
    vec2.push_back("(");
    vec2.push_back("(");
    vec2.push_back("2");
    vec2.push_back("*");
    vec2.push_back("a");
    vec2.push_back(")");
    vec2.push_back("+");
    vec2.push_back("(");
    vec2.push_back("a");
    vec2.push_back("-");
    vec2.push_back("7");
    vec2.push_back(")");
    vec2.push_back(")");
    vec2.push_back("-");
    // vec2.push_back("(");
    vec2.push_back("12");
    // vec2.push_back(")");
    vec2.push_back(")");

    vector<string> vec3;
    vec3.push_back("c");
    vec3.push_back(":=");
    vec3.push_back("(");
    vec3.push_back("b");
    vec3.push_back("/");
    vec3.push_back("a");
    vec3.push_back(")");

    vector<string> vec4;
    vec4.push_back("c");
    vec4.push_back(":=");
    vec4.push_back("(");
    vec4.push_back("1");
    vec4.push_back("+");
    vec4.push_back("2");
    vec4.push_back(")");

    vector<string> vec5;
    vec5.push_back("del");
    vec5.push_back(":=");
    vec5.push_back("c");

    vector<string> vec7;
    vec7.push_back("del");
    vec7.push_back(":=");
    vec7.push_back("b");

    vector<string> vec8;
    vec8.push_back("c");
    vec8.push_back(":=");
    vec8.push_back("(");
    vec8.push_back("-24");
    vec8.push_back(")");

    vector<string> vec9;
    vec9.push_back("b");
    vec9.push_back(":=");
    vec9.push_back("(");
    vec9.push_back("c");
    vec9.push_back("+");
    vec9.push_back("2");
    vec9.push_back(")");

    vector<string> vec6;
    vec6.push_back("ret");
    vec6.push_back(":=");
    vec6.push_back("c");
    vector<vector<string> > code;
    code.push_back(vec1);
    code.push_back(vec2);
    code.push_back(vec3);
    code.push_back(vec4);
    code.push_back(vec5);
    code.push_back(vec7); 
    code.push_back(vec8); 
    code.push_back(vec9); 
    code.push_back(vec6); 
    EPPCompiler compiler("output2.txt",3);
    compiler.compile(code);
}
