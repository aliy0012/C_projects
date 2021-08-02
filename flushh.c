/*flush function to get rid of char stuck in scanf method*/
/*can be used after scanf method, to clean scanf buffer*/
int flushing()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return EXIT_SUCCESS;
}
