#include "EXTERN.h"
#include "perl.h"

#if EMSCRIPTEN
#include <emscripten.h>
#endif

char * perl_eval(char * str) {
    PerlInterpreter *my_perl;
    char *embedding[] = { "", "-e", "0" };
    int argc = 3;
    char ** casted_embedded = (char **) embedding;
    PERL_SYS_INIT3(&argc,&casted_embedded,(char ***)NULL);
    my_perl = perl_alloc();
    perl_construct(my_perl);
    perl_parse(my_perl, NULL, 3, embedding, (char **)NULL);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

    SV * ret = eval_pv(str, TRUE);
    char * ret_str = SvPV_nolen(ret);
    printf("%s", ret_str);

    perl_destruct(my_perl);
    perl_free(my_perl);
    PERL_SYS_TERM();

    return ret_str;
}

int main(int argc, char **argv) {
    perl_eval("print 'Hello World'");
}
