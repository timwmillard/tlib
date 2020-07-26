#include <stdlib.h>

typedef struct TString {
   char *str;
   int len;

} TString;

TString *tstring(char *str);

TString *tstring_concat(TString *str1, TString *str2);
TString *cstring_concat(char *str1, char *str2);
