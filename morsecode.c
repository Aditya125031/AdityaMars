#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct 
{
    const char *code;
    char letter;
}morsemap;
const morsemap morselib[] = {
    {".-", 'A'},{"-...", 'B'},{"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'},
    {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
    {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'},
    {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},
    {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'},
    {"/", ' '}, {"", ' '}
};//morse codes for alphabets and numbers which i picked from internet
const int morselibsize = sizeof(morselib)/sizeof(morsemap);
char morse_to_char(const char *morse) //compares the given morse code with the morselib until it finds a match
{
    for (int i=0;i<morselibsize;i++) 
    {
        if (strcmp(morse,morselib[i].code) == 0) {
            return morselib[i].letter;
        }
    }
    return 'unknown';
}
void decode_morse(char *morse_message) 
{
    char word[10]={0};
    int wordindex=0;
    
    for (int i=0; morse_message[i]!='\0';i++) {
        if (morse_message[i] == ' ' || morse_message[i] == '/') {
            if (wordindex>0) 
            {
                word[wordindex] ='\0';
                putchar(morse_to_char(word));
                wordindex=0;
            }
            if (morse_message[i]=='/') {
                putchar(' ');
            }
        } else 
        {
            if (wordindex<sizeof(word)-1) 
            {
                word[wordindex]=morse_message[i];
                wordindex++;
            }
        }
    }
    if (wordindex>0) {//loop for any letters remaining
        word[wordindex]='\0';
        putchar(morse_to_char(word));
    }
    putchar('\n');
}
int main() 
{
    char *morse_code;
    scanf("%[^\n]",morse_code);
    printf("Decoding Morse: %s\n", morse_code);
    printf("Result: ");
    decode_morse(morse_code);
    return 0;
}
