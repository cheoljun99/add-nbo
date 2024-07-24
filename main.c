#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Wrong input You must enter these inputs. ./ExecuteFile <file1> <file2>\n");
        return 1;
    }

    FILE* one;
    FILE* two;

    one = fopen("thousand.bin", "r");
    if (one == NULL) {
        fprintf(stderr, "Fail to open thousand.bin");
        return 1;
    }
    two = fopen("five-hundred.bin", "r");
    if (two == NULL) {
        fprintf(stderr, "Fail to open five-hundred.bin");
        return 1;
    }

    uint32_t num1;
    size_t read_size1 = fread(&num1, sizeof(uint32_t), 1, one);
    if (read_size1 != 1) {
        fprintf(stderr, "Could not read 4 bytes from thousand.bin\n");
        fclose(one);
        return 1;
    }
    //printf("%x \n", num1);
    num1 = ntohl(num1); // network byte is big endian so we must cunvert this to little endian
    //printf("%x \n", num1);
    uint32_t num2;
    size_t read_size2 = fread(&num2, sizeof(uint32_t), 1, two);
    if (read_size2 != 1) {
        fprintf(stderr, "Could not read 4 bytes from five-hundred.bin\n");
        fclose(two);
        return 1;
    }
    //printf("%x \n", num2);
    num2 = ntohl(num2); //network byte is big endian so we must cunvert this to little endian
    //printf("%x \n", num2);
    uint32_t sum = num1 + num2;
    printf("%u (0x%x) + %u (0x%x) = %u (0x%x)\n", num1, num1, num2, num2, sum, sum);

    
    return 0;





}