/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"

string reverse(string b){
    string c;
    for(int i = b.size()-1;i>=0;i--){
        c.push_back(b[i]);
    }
    return c;
}
UnlimitedInt::UnlimitedInt(){
    size = 0;
    capacity = 0;
    sign = 1;
    unlimited_int = new int[size];
}
UnlimitedInt::UnlimitedInt(string s){
    size = s.size();
    capacity = 0;
    capacity = max(capacity,size);
    //cout << capacity << endl;
        if(s[0]=='-'){
            sign = -1;
        }
        else{
            sign = 1;
        }
        unlimited_int = new int[capacity];
        if(sign==-1){
            int sha = s.size();
            for(int i = 1;i<sha;i++){
                unlimited_int[i-1] = (s[i]-'0');
                // cout << s[i] << endl;
                // cout << unlimited_int[i] << endl;
            }
            size--;
        }
        else{
            int sha = s.size();
            for(int i = 0;i<sha;i++){
                unlimited_int[i] = s[i]-'0';
                
            }
        }
        int i = 0;
        while(unlimited_int[i]==0 && i<size){
            i++;
        }
        if(i==size){
            int* arr1 = new int[1];
            arr1[0]=0;
            delete[] unlimited_int;
            size=1;
            this->unlimited_int=arr1;
            
        }
        else if(i>0){
            int* arr1 = new int[size-i];
            
            for(int j = 0;j<size-i;j++){
                arr1[j]=unlimited_int[j+i];
            
            }
            size-=i;
            delete[] unlimited_int;
            this->unlimited_int=arr1;
        }
        
    

    
    // char x;
    // for(int i = 0;i<size;i++){
    //     x = unlimited_int[i]+'0';
    //     cout << x << endl;
    //}
}

UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
    sign = sgn;
    capacity = cap;
    size = sz;
    unlimited_int = ulimited_int;

}

UnlimitedInt::~UnlimitedInt(){
    delete[] unlimited_int;
    size = 0;
    sign = 1;
    capacity = 0;
}
int UnlimitedInt::get_size(){
    return size;
}
int UnlimitedInt :: get_sign(){
    return sign;
}
int* UnlimitedInt :: get_array(){
    return unlimited_int;
}
int UnlimitedInt :: get_capacity(){
    return capacity;
}
string UnlimitedInt :: to_string(){

    
    string k;
    if(sign==-1){
        k="-";
    }
    else{
        k="";
    }
    char x;
    for(int i = 0;i<size;i++){
        //cout << unlimited_int[i] << endl;
        x = '0'+unlimited_int[i];
        //cout << x << endl;
        k.push_back(x);
        
    }
    return k;
    
}
UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){
    int c = 0;
    int s;
    int* arr1 = i1->get_array();
    int* arr2 = i2->get_array();
    int s1 = i1->get_size();
    int s2 = i2->get_size();
    string z;
    if((s1>s2)&& i1->get_sign()==i2->get_sign()){
        for(int i = 0;i<s1;i++){
            if(i<s2){
                s = (arr1[s1-1-i]+arr2[s2-1-i]+c)%10;
                c = int((arr1[s1-1-i]+arr2[s2-1-i]+c)/10);
                char x = s+'0';
                z.push_back(x);
            }
            else{
                s = (arr1[s1-1-i]+c)%10;
                c = int((arr1[s1-i-1]+c)/10);
                char x = s+'0';
                z.push_back(x);
            }
        }
        if(c==1){
            char x = '1';
            z.push_back(x);
        }
        if(i1->get_sign()==-1){
            z.push_back('-');
        }
        //cout << z << endl;
        z=reverse(z);
        //cout << z << endl;
        UnlimitedInt* ap = new UnlimitedInt(z);
        return ap;

        
    }
    else if((s1<=s2)&& i1->get_sign()==i2->get_sign()){
        for(int i = 0;i<s2;i++){
            if(i<s1){
                s = (arr1[s1-1-i]+arr2[s2-1-i]+c)%10;
                c = int((arr1[s1-1-i]+arr2[s2-1-i]+c)/10);
                char x = s+'0';
                z.push_back(x);
            }
            else{
                s = (arr2[s2-1-i]+c)%10;
                c = int((arr2[s2-i-1]+c)/10);
                char x = s+'0';
                z.push_back(x);
            }
        }
        if(c==1){
            char x = '1';
            z.push_back(x);
        }
        if(i1->get_sign()==-1){
            z.push_back('-');
        }
        //cout << z << endl;
        z=reverse(z);
        //cout << z << endl;
        UnlimitedInt* ap = new UnlimitedInt(z);
        return ap;
    }
    else if(i1->get_sign() == -1 && i2->get_sign()==1){
        UnlimitedInt* su = new UnlimitedInt(arr1, s1, -1, s1);
        return sub(su,i2);
    }
    else{
        UnlimitedInt* su = new UnlimitedInt(arr2, s2, -1, s2);
        return sub(i1,su);
    }


    
    
    
    

}
UnlimitedInt* UnlimitedInt :: sub(UnlimitedInt* i1, UnlimitedInt* i2){
    int c = 0;
    int s;
    int* arr1 = i1->get_array();
    int* arr2 = i2->get_array();
    int s1 = i1->get_size();
    int s2 = i2->get_size();
    //cout << s1 << endl;
    //cout << s2 << endl;
    if(i1->sign==-1 && i2->sign == 1){
        UnlimitedInt* ad = new UnlimitedInt(arr1,s1,1,s1);
        return add(ad,i2);
    }
    else if(i1->sign==1 && i2->sign==-1){
        UnlimitedInt* ad = new UnlimitedInt(arr1,s1,-1,s1);
        return add(ad,i2);
    }
    else{
        string z;
        if(s2>s1){
            for(int i = 0;i<s2;i++){
                if(i<s1){
                    s=(arr2[s2-1-i] - arr1[s1-i-1] - c);
                    //cout << s << endl;
                    if(s<0){
                        s=s%10;
                        if(s<0){

                        
                        s=10+s;
                        }
                        //cout << s << endl;
                        c=1;
                        //cout << c << endl;
                    }
                    else{
                        c=0;
                    }
                    char x = s+'0';
                    z.push_back(x);
                }
                else{
                    //cout << c << endl;
                    s=(arr2[s2-1-i]-c);
                    if(s<0){
                        s=s%10;
                        if(s<0){
                            s=10+s;
                            c=1;
                        }
                    }
                    else{
                        c=0;
                    }
                    char x = s+'0';
                    z.push_back(x);
                    if(i1->get_sign()==-1){
                        z.push_back('-');
                    }
                }

            }
            z=reverse(z);
            //cout << z << endl;
            //cout << z << endl;
            UnlimitedInt* ans = new UnlimitedInt(z);
            return ans;
        }
        else if(s1>s2){
            string z;
            for(int i = 0;i<s1;i++){
                if(i<s2){
                    s=(arr1[s1-1-i] - arr2[s2-i-1] - c);
                    // cout << s << endl;
                    //cout << s << endl;
                    if(s<0){
                        ;
                        if(s<0){
                            s=s%10;
                            if(s<10){
                                s=10+s;
                            }
                        }
                        // cout << s << endl;
                        c=1;
                    }
                    else{
                        s=s%10;
                        c=0;
                    }
                    char x = s+'0';
                    z.push_back(x);
                    
                    // cout << c << endl;
                }
                
                else{
                    s=(arr1[s1-1-i]-c)%10;
                    if(s<0){
                        s=10+s;
                        c=1;
                    }
                    else{
                        c=0;
                    }
                    char x = s+'0';
                    z.push_back(x);
                    
                    }
                }
                z.push_back('-');
                    //cout << z << endl;
                    if(i1->get_sign()==-1){
                        z.pop_back();

            }
            z=reverse(z);
            //cout << z << endl;
            UnlimitedInt* ans = new UnlimitedInt(z);
            return ans;
        }
        else{
            //cout << i1->to_string() << endl;
            //cout << arr1[0] << endl;
            int xy=1;
            for(int i = 0;i<s1;i++){
                if(arr1[i]<arr2[i]){
                    break;
                }
                else if(arr1[i]>arr2[i]){
                    //cout << arr1[i] << endl;
                    //cout << arr2[i] << endl;

                    // int* arr1 = i2->get_array();
                    
                    
                    // int* arr2 = i1->get_array();
                    swap(arr1,arr2);
                    
                    
                    //swap(s1,s2);
                    xy=-1;
                    //cout << xy << endl;
                    break;
                }
            }
            
            for(int i = 0;i<s1;i++){                
                s = (arr2[s1-i-1]-arr1[s1-i-1]-c);
                c=0;
                if(s<0){
                    s=10+s;
                    c=1;
                }
                char x = s+'0';
                //cout << x << endl;
                z.push_back(x);
            }
            if(xy==1 && i1->get_sign()==-1){
                z.push_back('-');
            }
            else if(xy==-1 && i1->get_sign()==1){
                z.push_back('-');
            }
            
            
            z=reverse(z);
            //cout << z << endl;
            UnlimitedInt* ans = new UnlimitedInt(z);
            return ans;

        }


    }
}
string Unmult(int* arr, int j, int s1)
    {
        string x;
        for (int i = 0;i<s1;i++){            
        }
        int s;
        int c=0;
        for(int i = 0; i<s1; i++){
            s = (arr[s1-i-1]*j+c)%10;
            //cout << s << endl;
            c = int((arr[s1-i-1]*j+c))/10;
            char y = s+'0';
            x.push_back(y);

        }
        if (c>0){
            char y = c+'0';
            x.push_back(y);
        }
        x=reverse(x);
        return x;
    }
UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){
    int* arr1 = i1->get_array();
    int* arr2 = i2->get_array();
    int s1 = i1->get_size();
    int s2 = i2->get_size();
    string a = Unmult(arr1,arr2[s2-1],s1);
    if(i1->get_sign()!=i2->get_sign()){
        a="-"+a;
    }
    UnlimitedInt* ans = new UnlimitedInt(a);
    string k = "0";
    for(int j = 1;j<s2;j++){
        string a = Unmult(arr1,arr2[s2-1-j],s1);
        a+=k;
        k.push_back('0');
        if(i1->get_sign()!=i2->get_sign()){
            a="-"+a;
        }
        UnlimitedInt* temp = new UnlimitedInt(a);
        ans = add(ans,temp);
        delete temp;

    }
    
    //cout << ans->to_string() << endl;
    return ans;


}
UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){
    
    string z3 = i1->to_string();
    string z4 = i2->to_string();
    //cout << z4 << endl;
    int* arr2 = i2->get_array();
    int s1 = i1->get_size();
    int s2 = i2->get_size();
    if(i2->get_size()>i1->get_size()){
        return nullptr;
    }
    string z(z3.begin(),z3.begin()+s2);
    
    string tk2="";
    //cout << z << endl;

    for(int i = s2;i<s1+1;i++){
    
            
        for(int k = 0;k<11;k++){
            string temp = Unmult(arr2,k,s2);
            //cout << temp << endl;
            
            
            UnlimitedInt* temp1 = new UnlimitedInt(temp);
            //cout << temp1->to_string() << endl;
            UnlimitedInt* temp2 = new UnlimitedInt(z);
            //cout << temp2->to_string() << endl;
            //cout << sub(temp1,temp2)->get_sign() << endl;
            if(sub(temp1,temp2)->get_sign()==-1){
                string temp = Unmult(arr2,k-1,s2);
                //cout << temp << endl;
                UnlimitedInt* tk = new UnlimitedInt(temp);
                UnlimitedInt* temp1 = sub(tk,temp2);
                z.clear();
                //cout << temp1->to_string() << endl;
                z+= temp1->to_string();
                //cout << z << endl;
                char x = k-1+'0';
                //cout << x << endl;
                tk2.push_back(x);
                break;
                //cout << z << endl;

            }
          
        }
        //cout << z << endl;
        z.push_back(z3[i]);
        //cout << z3[i];
        //cout << z << endl;
        
    }
    
    if(i1->get_sign()!=i2->get_sign()){
        tk2="-"+tk2;
    }
    //cout << tk2 << endl;
    UnlimitedInt* ans = new UnlimitedInt(tk2);
    return ans;
}
UnlimitedInt* UnlimitedInt :: mod(UnlimitedInt* i1, UnlimitedInt* i2){
    string z1="";
    string z2 = "";
    string z3 = i1->to_string();
    string z4 = i2->to_string();
    int* arr2 = i2->get_array();
    int s1 = i1->get_size();
    int s2 = i2->get_size();
    if(i2->get_size()>i1->get_size()){
        return nullptr;
    }
    string z(z3.begin(),z3.begin()+s2);
    
    string tk2="";
    //cout << z << endl;

    for(int i = s2;i<s1+1;i++){
    
            
        for(int k = 0;k<11;k++){
            string temp = Unmult(arr2,k,s2);
            //cout << temp << endl;
            
            
            UnlimitedInt* temp1 = new UnlimitedInt(temp);
            //cout << temp1->to_string() << endl;
            UnlimitedInt* temp2 = new UnlimitedInt(z);
            //cout << temp2->to_string() << endl;
            //cout << sub(temp1,temp2)->get_sign() << endl;
            if(sub(temp1,temp2)->get_sign()==-1){
                string temp = Unmult(arr2,k-1,s2);
                //cout << temp << endl;
                UnlimitedInt* tk = new UnlimitedInt(temp);
                UnlimitedInt* temp1 = sub(tk,temp2);
                //cout << z << endl;
                z.clear();
                //cout << z << endl;
                
                // cout << temp << endl;
                // cout << temp1->to_string() << endl;
                z+= temp1->to_string();
                //cout << z << endl;
                char x = k-1+'0';
                //cout << x << endl;
                tk2.push_back(x);
                break;
                //cout << z << endl;

            }
          
        }
        //cout << z << endl;
        z.push_back(z3[i]);
        //cout << z3[i];
        //cout << z << endl;
        
    }
    z.pop_back();
    
    if(i1->get_sign()!=i2->get_sign()){
        tk2="-"+tk2;
    }
    // cout << tk2 << endl;
    // cout << z << endl;
    UnlimitedInt* ans = new UnlimitedInt(z);
    return ans;
}

