#include <stdio.h>
#include <sodium.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE 1024

int main (void){
    if (sodium_init() <0 ){
        /* panic! the library couldn't be initialized; it is not safe to use */
        return 1;
    }
    char inputPath[256];
    char outputPath[256];

    printf("Enter input file path: ");
    scanf("%255s", inputPath);

    printf("Enter output file path: ");
    scanf ("%255s", outputPath);

    FILE *inputFile = fopen(inputPath, "rb");
    FILE *outputFile = fopen(outputPath, "wb");

    if (inputFile == NULL || outputFile == NULL){
        printf("Error opening files.\n");
        return 1;
    }


    unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES];
    unsigned char header[crypto_secretstream_xchacha20poly1305_HEADERBYTES];
    unsigned char footer[crypto_secretstream_xchacha20poly1305_ABYTES];
    crypto_secretstream_xchacha20poly1305_state state;

    randombytes_buf(key, sizeof key);
    crypto_secretstream_xchacha20poly1305_init_push(&state, header, key);

    fwrite(header, 1, sizeof header, outputFile);


    int bytesRead;
    unsigned char inputBuffer[BUFFER_SIZE];
    unsigned char outputBuffer[BUFFER_SIZE + crypto_secretstream_xchacha20poly1305_ABYTES];

    int totalSteps = 20;
    int i;

    while ((bytesRead = fread(inputBuffer, 1, sizeof inputBuffer, inputFile))>0){
        float progress = (float)i / totalSteps;
        int barWidth = 50;
        int pos = barWidth * progress;

        printf("[");
        for (int j = 0; j < barWidth; j++){
            if (j < pos)
                printf("=");
            else if (j == pos)
                printf(">");
            else
                printf (" ");
        }

        printf("] %.2f%%\r", progress * 100);
        fflush(stdout);

        usleep(100000); // Sleep for 100ms

        crypto_secretstream_xchacha20poly1305_push(&state,
                                            outputBuffer, NULL,
                                            inputBuffer, (unsigned long long) bytesRead,
                                            NULL, 0, crypto_secretstream_xchacha20poly1305_TAG_MESSAGE);
        fwrite(outputBuffer, 1, bytesRead + crypto_secretstream_xchacha20poly1305_ABYTES, outputFile);     
    }
    fclose(inputFile);

    crypto_secretstream_xchacha20poly1305_push(&state,
                                            outputBuffer, NULL,
                                            NULL, 0,
                                            NULL, 0, crypto_secretstream_xchacha20poly1305_TAG_FINAL);
    fwrite(outputBuffer, 1, crypto_secretstream_xchacha20poly1305_ABYTES, outputFile);
    fclose(outputFile);

    printf("\nEncryption completed! \n");
    return 0;
}