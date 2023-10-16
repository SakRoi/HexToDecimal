#include <stdio.h>

int atoi(char s[]);
int lower(int c);
int hexPower(int exponent); //own modified implementation of power due to being too lazy to fix missing cmath lib on my current computer.
int hexLetterConverter(int c);
int hexNumberConverter(int c);
int lengthOfHexadecimal(char s[], int start);
int hexValueCalculator(int pos, int hex);
int convertHex(char s[], int start, int end);
int isHexValid(char s[], int start, int end);

int main(int argc, char *argv[])
{
    int hexLength = 0, start = 0;

    if (argc < 2 && argc > 3){
        printf("Too many or too few arguments, give a hex number either with or without 0x");
        return 1;
    }

    char *hex = argv[1];

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')){
        start = 2;
    }
        
    hexLength = lengthOfHexadecimal(hex, start);
    if (!isHexValid(hex, start, hexLength)){
        printf("Hex isn't valid\n");
        return 1;
    } 
    else {
        printf("%d\n", convertHex(hex, start, hexLength));
    }

    return 0;
}

int isHexValid(char s[], int i, int hexLength)
{
    /*
    Goes through all the valuable digits in the hex, 
    returning a 0 (false) if it has a character not valid in the hexadecimal numerical system
    and returning a 1 (true) if it has only valid characters
    */
    for (; hexLength != 0; ++i){
        switch (s[i])
        {
        case 48: //ASCII value for 0, the following cases are 1-9
        --hexLength;
        break;
        case 49:
        --hexLength;
        break;
        case 50:
        --hexLength;
        break;
        case 51:
        --hexLength;
        break;
        case 52:
        --hexLength;
        break;
        case 53:
        --hexLength;
        break;
        case 54:
        --hexLength;
        break;
        case 55:
        --hexLength;
        break;
        case 56:
        --hexLength;
        break;
        case 57: //9
        --hexLength;
        break;
        case 65: //ASCII value for upper case a, the following cases are b-f
        --hexLength;
        break;
        case 66:
        --hexLength;
        break;
        case 67:
        --hexLength;
        break;
        case 68:
        --hexLength;
        break;
        case 69:
        --hexLength;
        break;
        case 70: //upper case f
        --hexLength;
        break;
        case 97: //ASCII value for lower case a, the following cases are b-f
        --hexLength;
        break;
        case 98:
        --hexLength;
        break;
        case 99:
        --hexLength;
        break;
        case 100:
        --hexLength;
        break;
        case 101:
        --hexLength;
        break;
        case 102: //lower case f
        --hexLength;
        break;
        default:
        return 0; //the hex isn't valid
        break;
        }
    }
    return 1; //the hex is valid
}

int convertHex(char s[], int i, int hexLength)
{
    int value = 0;
    char current = ' ';
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