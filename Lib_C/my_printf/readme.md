all the flag:

Length modifier



Conversion specifiers

//%d, %i  =   input   int     output  decimal number//
//%o      =   input   int     output  octal number//
//%u      =   input   int     output  decimal number//
//%x, %X  =   input   int     output  hexadecimal//
//%e, %E  =   input   double  output  [-]d.ddde±dd//
//%f, %F  =   input   double  output  [-]ddd.ddd//
//%g, %G  =   input   double  output  %e or %f//
%a, %A  =   input   double  output  [-]0xh.hhhhp±d (h=hexadecimal)
//%c      =   input   int     output  unsigned char//
//%s      =   input   string  output  string//
//%p      =   input   void *  output  %#x or %#lx in hexadecimal//
// %n// 
%m      =   input           output  error message
%S      = affiche en exa ce qui ne peut pas etre afficher
//%%      =   input           ouput   %//


const struct operator OPERATORS_FUNCS[] = {{"+", &my_add}, {"-", &my_sub}, {"/", &my_div}, {"*", &my_mul}, {"%", &my_mod}, {"", &my_usage}};
