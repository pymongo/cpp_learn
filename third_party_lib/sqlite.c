#include <sqlite3.h>
#include <stdio.h>

// check libsqlite3-dev whether install: ldconfig -p | grep libsqlite3
int main() {
    printf("sqlite3_dylib_version = %s\n", sqlite3_libversion());
    return 0;
}
