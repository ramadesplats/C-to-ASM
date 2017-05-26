int f(int *h, const int c){
    int p;
    int x;
    p = h;
    x = c;
    printf(p);
}

int main(){
    int *h;
    int a;
    const int c = 5;
    h = &a;
    f(h,c);
}
