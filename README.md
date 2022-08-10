# printf

# The awesome printf() function

**printf** - formatted output conversion, display character to stdout.

## Author

**printf()** is written and maintained by **Victor Doledji** (@gmail.com) and **Samadou Ouro-agorouko** (souroagorouko@gmail.com).

## How to use it ?

* First all, clone this repositoy to your local machine.
* Then create a c file like "main.c" at the root of your folder.
* write the main function to test our printf fucntion.
* Run "gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c && ./printf" to compile and run.

## Description
The **printf()** function produce output according to a *format* as described below. Also, write output to *stdout*, the standard output stream.

The  **printf()** function write the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of ***stdarg(3)*** are converted for output.

### Format of the format string

The format string is a character string, beginning and ending inits  initial shift state, if any. The format string is composed of zero or more  directives:  ordinary  characters  (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.
Each conversion specification is introduced by the character % and ends with conversion specifier.

### Conversion specifiers
A character that specifies the type of conversion to be applied. The conversion specifiers and their meaning are:
-  **d, i**: The **_int_** argument should be signed decimal notation, and the resulting number is written.
-  **c**: The **_int_** argument is converted to a char, and the resulting character is written.
-  **s**: The **_const char_** * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up  to  (but not including) a terminating null byte ('\0').
- **%**: A '**%**' is written. No argument is converted. The complete conversion specification is '**%%**'.

### int print_format (const char *format, ...)
This function gets a format to be printed and a variadic arguments list, next to check if the
format is valid or invalid and according with the verification the resulting output is written to the standard output stream and returns the format length.


## Return Value


Upon successful return, the **printf()** function return the number of characters printed (excluding the null byte used to end output to strings).

If an output error is encountered, a negative value is returned.