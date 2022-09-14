#include<iostream>
#include<cstring>
using namespace std;

void f(char* str, char del)
{
    int i, j, len;
    len = strlen(str);

    i=0;

    while(i<len) {

        // ignore repeated symbol chars.
        while (str[i] == del) i++;

        // find a sub-string from str[i] to the symbol char.
        j=i+1;

        while(str[j] != del && str[j] != '\0') j++;

        // mark the end symbol to found string
        str[j] = '\0';

        printf(" %s\t", &str[i]);
        i = j+1;
    }
}

int main()
{
    char str[] = "3312444364333334355";
    char d = '3';
    f(str, d);
    return 0;
}