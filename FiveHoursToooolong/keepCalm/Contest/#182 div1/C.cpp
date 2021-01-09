#include <stdio.h>
// others
int main() {
    int i;
    for (i = 0; i < 9; i++) printf("%d\?\?<>%d\n", i, i + 1);
    puts("9\?\?>>\?\?0\n\?\?0<>10");
    for (i = 0; i <= 9; i++) printf("\?%d>>%d\?\n", i, i);
    puts("\?>>\?\?\n>>\?");
}