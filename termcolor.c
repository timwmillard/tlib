/**
 * 
 * 

8 bit Colors
Black: \u001b[30m
Red: \u001b[31m
Green: \u001b[32m
Yellow: \u001b[33m
Blue: \u001b[34m
Magenta: \u001b[35m
Cyan: \u001b[36m
White: \u001b[37m

16 bit Colors
Bright Black: \u001b[30;1m
Bright Red: \u001b[31;1m
Bright Green: \u001b[32;1m
Bright Yellow: \u001b[33;1m
Bright Blue: \u001b[34;1m
Bright Magenta: \u001b[35;1m
Bright Cyan: \u001b[36;1m
Bright White: \u001b[37;1m

Reset
Reset: \u001b[0m

*/

#include <stdio.h>

void term_color_red()
{
  printf("\033[1;31m");
}

void term_color_yellow()
{
  printf("\033[1;33m");
}

void term_color_reset ()
{
  printf("\033[0m");
}