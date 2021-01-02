#include <stdio.h>
#include <regex.h>
#include <assert.h>

void print_regexec_result(int return_value) {
    if (return_value == 0) {
        printf("Pattern found.\n");
    } else if (return_value == REG_NOMATCH) {
        printf("Pattern not found.\n");
    } else {
        printf("An error occurred.\n");
    }
}

int main() {
    regex_t regex;
    assert(regcomp(&regex, "ice", 0) == 0);
    regmatch_t match_position;
    print_regexec_result(regexec(&regex, "icecream", 0, &match_position, 0));
    // FIXME (rm_so,rm_eo) is always (0, 0), how to get the match start and match end
    printf("(%lld, %lld)\n", match_position.rm_so, match_position.rm_eo);
//    assert(regcomp(&regex, "^[+-]?[0-9]+", REG_EXTENDED) == 0); // REG_EXTENDED = 1
//    print_regexec_result(regexec(&regex, "4193 with words", 0, NULL, 0));
//    print_regexec_result(regexec(&regex, "words and 987", 0, NULL, 0));
//    print_regexec_result(regexec(&regex, "3.1415926", 0, NULL, 0));
    return 0;
}
