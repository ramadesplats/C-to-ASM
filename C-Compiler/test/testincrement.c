int f(int a, int b){
    return a+b;
}

int main(){
    int c = 10;
    int d = 24;
    int e;
    
    c++;
    printf(c);

    ++d;
    printf(d);
    
    e = f(c,d);
    printf(e);
    
}
