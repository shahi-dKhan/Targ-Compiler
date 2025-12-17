/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"
UnlimitedRational::UnlimitedRational(){
    p = nullptr;
    q = nullptr;
}
UnlimitedInt* GCD(UnlimitedInt* i1, UnlimitedInt* i2){
    if(i1->to_string()=="0"){
        return i2;
    }
    else if(i2->to_string()=="0"){
        return i1;
    }
    else if(i1->to_string()==i2->to_string()){
        return i1;
    }
    
    else{
        if(UnlimitedInt::sub(i2,i1)->get_sign()==1){
            return GCD(UnlimitedInt::mod(i1,i2),i2);
        }
        else{
            return GCD(i1,UnlimitedInt::mod(i2,i1));
        }
    }
}
UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){ 
    int xy = 1;
    if(num->get_sign()!=den->get_sign()){
        xy=-1;
    }
    string s1 = num->to_string();
    string s2 = num->to_string();
    if(s1[0]=='-'){
        s1.erase(s1.begin());
        delete num;
        num = new UnlimitedInt(s1);
    }
    if(s2[0]=='-'){
        s2.erase(s2.begin());
        delete den;
        den = new UnlimitedInt(s2);
    }

    UnlimitedInt* gcd = GCD(num,den);
    UnlimitedInt* temp = UnlimitedInt::div(num,gcd);
    p =new UnlimitedInt(temp->get_array(),temp->get_size(),xy,temp->get_size());
    q = UnlimitedInt::div(den,gcd);
}


UnlimitedRational::~UnlimitedRational(){
    delete p;
    delete q;
}
UnlimitedInt* UnlimitedRational::get_p(){
    return p;
}
UnlimitedInt* UnlimitedRational::get_q(){
    return q;
}
string UnlimitedRational::get_p_str(){
    return p->to_string();
}
string UnlimitedRational::get_q_str(){
    return q->to_string();
}
string UnlimitedRational::get_frac_str(){
    return p->to_string()+"/"+q->to_string();
}
UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* a = UnlimitedInt::mul(i1->get_p(),i2->get_q());
    UnlimitedInt* b = UnlimitedInt::mul(i1->get_q(),i2->get_p());
    UnlimitedInt* c = UnlimitedInt::add(a,b);
    UnlimitedInt* d = UnlimitedInt::mul(i1->get_q(),i2->get_q());
    UnlimitedRational* ans = new UnlimitedRational(c,d);
    return ans;

}

UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* a = UnlimitedInt::mul(i1->get_p(),i2->get_q());
    UnlimitedInt* b = UnlimitedInt::mul(i1->get_q(),i2->get_p());
    UnlimitedInt* c = UnlimitedInt::sub(b,a);
    UnlimitedInt* d = UnlimitedInt::mul(i1->get_q(),i2->get_q());
    UnlimitedRational* ans = new UnlimitedRational(c,d);
    return ans; 

}
UnlimitedRational *UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* a = UnlimitedInt::mul(i1->get_p(),i2->get_p());
    UnlimitedInt* b = UnlimitedInt::mul(i1->get_q(),i2->get_q());
    UnlimitedRational* ans = new UnlimitedRational(a,b);
    return ans;
}
UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt* a = UnlimitedInt::mul(i1->get_p(),i2->get_q());
    UnlimitedInt* b = UnlimitedInt::mul(i1->get_q(),i2->get_p());
    UnlimitedRational* ans = new UnlimitedRational(a,b);
    return ans;
}