int main(){
    int a;
    int b = 13;
    int c = b++;
    
    a = 5+b++;
    print(a);
    
    if (b++<14){
        c = 20;
    }else{
        c = 21;
    }
    
    printf(c);//20
    printf(b);//14
}
