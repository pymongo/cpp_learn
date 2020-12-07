#include <stdio.h>

/* output:
*
**
***
****
*****
*/
int main() {
    // https://twitter.com/realCWKSC/status/1328713393277001729
    for (int i=0; i<5; i++) {
        printf("*****\n" + 4 - i);
    }
    return 0;
}
