#include <stdlib.h>

typedef struct String {
   char *str;
   int len;

} String;

String *string(char *str);

String *string_concat(String *str1, String *str2);
String *cstring_concat(char *str1, char *str2);
