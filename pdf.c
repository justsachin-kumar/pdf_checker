#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    //check for usage , must be 2 command line argument
    if (argc != 2)
    {
        printf("Please provide only one filename\n");
        return 1;
    }
    //open file
    FILE *input = fopen(argv[1], "r");

    //create buffer for file
    uint8_t buffer[4];

    //create an array of signature bytes
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    // ready first 4 bytes from the file
    fread(buffer, sizeof(uint8_t), 4, input);
    // could have close the file here cause once reading the memory is tored in buffer!!!
    
    // check the first 4 byte again signature bytes
    for (int i = 0; i < 4; i++)
    {
        if (signature[i] != buffer[i])
        {
            printf("this is not a PDF!\n");
            return 0;
        }
    }
    //sucess!
    printf("It is a PDF!\n");

    //close the fiel!!!
    fclose(input);

    return 0;
}
