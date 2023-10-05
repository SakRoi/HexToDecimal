#include <stdio.h>

int atoi(char s[]);
int lower(int c);
int hexPower(int exponent); //own modified implementation of power due to being too lazy to fix missing cmath lib on my current computer.
int hexLetterConverter(int c);
int hexNumberConverter(int c);
int lengthOfHexadecimal(char s[], int start);
int hexValueCalculator(int pos, int hex);
int convertHex(char s[], int start);

int main(int argc, char *argv[])
{
    if (argc < 2 && argc > 3){
        printf("Too many or too few arguments, give a hex number either with or without 0x");
        return 1;
    }
    char *hex = argv[1];
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')){
        printf("%d\n", convertHex(hex, 2));
    } else {
        printf("%d\n", convertHex(hex, 0));
    }

    return 0;
}

int convertHex(char s[], int i)
{
    int value = 0;
    char current = ' ';
    int hexLength = lengthOfHexadecimal(s, i);
        for (; hexLength != 0 ; ++i){
            current = lower(s[i]);
            if (current >= 'a') {
                value += hexValueCalculator(hexLength - 1, hexLetterConverter(current));
            } else {
                value += hexValueCalculator(hexLength - 1,  hexNumberConverter(current));
            }
            --hexLength;
        }
    return value;
}

int lengthOfHexadecimal(char s[], int startIndex)
{
    int length = 0;
    for (int i = startIndex; s[i] != '\0' && s[i] != '\n'; ++i){
        ++length;
    }
    return length;
}

int lower(int c){
    //turns the ASCII letter to it's lowercase form, needed for the letter to number conversion.
    if (c >= 'A' && c <= 'Z'){
        return c + 'a' - 'A'; //this turns the letter lowercase
    } else {
        return c;
    }
}

int hexLetterConverter(int c)
{
    //converts letters into their numerical counterparts using ASCII values.
    int converted = 0;
    switch (c)
    {
    case 97: //ASCII value for lower case a, the following cases are b-f
        converted = 10;
        break;
    case 98:
        converted = 11;
        break;
    case 99:
        converted = 12;
        break;
    case 100:
        converted = 13;
        break;
    case 101:
        converted = 14;
        break;
    case 102:
        converted = 15;
        break;
    default:
        converted = c;
        break;
    }
    return converted;
}

int hexValueCalculator(int pos, int hex)
{
    int i = hexPower(pos);
    return hex * i;
}

int hexPower(int exponent)
{
    int v = 1;
    if (exponent == 0){
        return v;
    }
    for (int i = 0; i < exponent; ++i){
        v *= 16;
    }
    return v;
}   

int hexNumberConverter(int c)
{
    return c - '0';
}