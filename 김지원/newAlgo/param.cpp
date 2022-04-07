#include <cstdio>

void b(int a){
    a=2;
}

void b2(int & a){
    a=2;
}

void b3(int * a){
    *a = 3;
}

int main(){
    int a = 1;
    b(a);   
    printf("%d\n", a)
    b2(a);
    printf('%d\n', a);
    b3(a);
    printf("%d\n", a);
    return 0;
}