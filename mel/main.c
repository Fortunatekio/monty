#include "monty.h"
/**
 *main entry point of our program
 *@rgc: argument count
 *@argv: argument vector
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}

processFile(argv[1]);

return (0);
}