template <typename T>    
void read(T &x) {    
    x = 0;    
    int f = 1;    
    char ch = getchar();    
    while (!isdigit(ch)) {    
        if (ch == '-') f = -1;    
        ch = getchar();    
    }    
    while (isdigit(ch)) {    
        x = x * 10 + (ch ^ 48);    
        ch = getchar();    
    }    
    x *= f;    
    return;    
}   