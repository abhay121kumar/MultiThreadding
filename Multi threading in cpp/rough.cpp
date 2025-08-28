#include <iostream>
using namespace std;
int main()
{
    int p = (int)malloc(sizeof(int) * 10);
    if (!p)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    free(p);
    free(p);
    return 0;
    
}

// int main() { int a = 5, b = 10; int result = a++ * ++b; printf("result = %d\n", result); return 0; }

// int main() { int x; int y = 10; if( x = 0 ) { printf("%d", y); } return 0; }

// int main() { int p = (int)malloc(sizeof(int)); *p = 100; free(p); printf("%d\n", *p); return 0; }

// int main() { int x =10; { int x =20; pf("%d", x); } pf("%d", x); }

// int main() { static int x =10; { static int x =20; pf("%d", x); } pf("%d", x); }