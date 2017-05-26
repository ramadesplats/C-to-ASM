

int f(int a, int b){
    a=a+13;
    printf(a);
}

int g(int b){
    // error a=4;
    b = b+15;
    f(b,55);
    b = b+11;
    printf(b);
}


int main(){
    int a;
    int b = 13;
    int *p, *h;
    
    //fonction
    g(b);
   
   
    p=&a;
    *h=a;
    a=a+15;
    
    printf(p);
    printf(h);
    //pointeur warning
    h=*p;
    p=3;
    a=&b;   
}
