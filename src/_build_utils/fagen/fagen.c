#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "marathoner/common.h"

typedef struct functionAvailability_t {
    char *name;
    const char *availability;
} functionAvailability_t;

char *availabilityConst[] = {"MTR_FA_NO", "MTR_FA_DUMMY", "MTR_FA_BUGGY",
 "MTR_FA_PARTIAL", "MTR_FA_YES"};

char defaultIncludeGuard[] = "FA_GENERATED_H";

char *CountSymbols(char *str, int *len)
{
    char *string = str;
    char *wordBegin;

    *len = 0;

    while (string[0] == ' ') {
        string++;
    }
    wordBegin = string;

    while ((string[0] != ' ') && (string[0] != '*')) {
        string++;
        (*len)++;
    }

    return wordBegin;
}

char *GetAvailability(char *str, const char **availability)
{
    char *string = str;

    *availability = availabilityConst[MTR_FA_NO];

    while (string[0] == ' ') {
        string++;
    }

    switch (string[0])
    {
        case 'd':
            *availability = availabilityConst[MTR_FA_DUMMY];
            break;
        case 'b':
            *availability = availabilityConst[MTR_FA_BUGGY];
            break;
        case 'p':
            *availability = availabilityConst[MTR_FA_PARTIAL];
            break;
        case 'y':
            *availability = availabilityConst[MTR_FA_YES];
            break;
        default:
            *availability = availabilityConst[MTR_FA_NO];
            break;
    }

    while ((string[0] != ' ') && (string[0] != '*')) {
        string++;
    }

    return string;
}

bool CreateEmptyFile(const char *outputPath, const char *includeGuard)
{
    FILE *outputFile;

    outputFile = fopen(outputPath, "w");
    if (outputFile == NULL)
        return false;

    fprintf(outputFile, "#ifndef %s\n", includeGuard);
    fprintf(outputFile, "#define %s\n", includeGuard);
    fprintf(outputFile, "%s", "#include \"marathoner/marathoner.h\"\n");
    fprintf(outputFile, "%s", "#define FA_FUNCTIONS_COUNT 0\n");

    fprintf(outputFile, "%s", "mtrFa_t fa[] = {};\n");
    fprintf(outputFile, "%s", "#endif\n");

    if (fclose(outputFile) == EOF)
        return false;

    return true;
}

int main(int argc, char **argv)
{
    FILE                   *inputFile;
    FILE                   *outputFile;
    int                     fileChar;
    char                   *inputBuf = NULL;
    int                     bufLength;
    int                     i;
    int                     funcsCount = 0;
    char                   *bufPos = NULL;
    functionAvailability_t *functionAvailability;
    int                     funcNameLen;
    char                   *inputPath = argv[1];
    char                   *outputPath = argv[2];
    char                   *platform = argv[3];
    char                   *includeGuard = NULL;
    int                     outputPathLen;

    UNUSED(platform);

    if (argc < 2)
    {
        printf("%s\n", "TODO: Usage.");
        return 1;
    }

    inputFile = fopen(inputPath, "r");
    if (inputFile == NULL)
    {
        printf("Unable to open input file: %s\n", inputPath);
        return 2;
    }
    bufLength = 0;
    while (fgetc(inputFile) != EOF)
    {
        bufLength++;
    }
    if (fclose(inputFile) == EOF)
    {
        printf("Unable to close input file: %s\n", inputPath);
        return 3;
    }

    inputFile = fopen(inputPath, "r");
    if (inputFile == NULL)
    {
        printf("Unable to open input file: %s\n", inputPath);
        return 4;
    }
    inputBuf = malloc(sizeof(char* ) * (bufLength + 1));
    if (inputBuf == NULL)
    {
        printf("%s\n", "Unable to allocate memory for input file's buffer");
        return 5;
    }

    for (i = 0; i < bufLength; i++)
    {
        fileChar = fgetc(inputFile);
        if (fileChar == EOF)
        {
            printf("Unexpected end of file: %s\n", inputPath);
            free(inputBuf);
            return 6;
        }
        inputBuf[i] = (char)fileChar;
    }
    inputBuf[bufLength] = '\0';

    if (fclose(inputFile) == EOF)
    {
        printf("Unable to close input file: %s\n", inputPath);
        free(inputBuf);
        return 7;
    }

    outputPathLen = strlen(outputPath);
    includeGuard = malloc(sizeof(char) * outputPathLen + 1);
    if (includeGuard == NULL) {
        printf("%s",
         "Unable to allocate memory for include guard. Using default include"
         " guard\n");
        includeGuard = defaultIncludeGuard;
    } else {
        strncpy(includeGuard, outputPath, outputPathLen);
        includeGuard[outputPathLen] = '\0';
        for (i = 0; i < outputPathLen; i++)
        {
            if ((includeGuard[i] == '.') || (includeGuard[i] == '/'))
                includeGuard[i] = '_';
        }
    }

    /* counting *fa comments */
    bufPos = inputBuf;
    while (bufPos[0] != '\0') {
        bufPos = strstr(bufPos, "/*fa ");
        if (bufPos == NULL)
            break;
        bufPos++;
        funcsCount++;
    }
    if (funcsCount == 0)
    {
        free(inputBuf);
        printf("%s\n", "*fa comments not found");
        if (!CreateEmptyFile(outputPath, includeGuard))
        {
            printf("Unable to open or close output file: %s\n", outputPath);
            return 8;
        }
        return 0;
    }

    functionAvailability = malloc(sizeof(functionAvailability_t) * funcsCount);
    if (functionAvailability == NULL) {
        printf("%s\n", "Unable to allocate memory for functions' availability "
         "data array");
        free(inputBuf);
        return 9;
    }

    bufPos = inputBuf;
    for (i = 0; i < funcsCount; i++)
    {
        bufPos = strstr(bufPos, "/*fa ");
        bufPos += sizeof(char) * 5;
        bufPos = CountSymbols(bufPos, &funcNameLen);
        functionAvailability[i].name = malloc(sizeof(char) * funcNameLen + 1);
        if (functionAvailability[i].name == NULL)
        {
            printf("%s\n", "Unable to allocate memory for function name");
            free(inputBuf);
            free(functionAvailability);
            return 10;
        }
        strncpy(functionAvailability[i].name, bufPos, funcNameLen);
        functionAvailability[i].name[funcNameLen] = '\0';
        bufPos += sizeof(char) * funcNameLen;

        bufPos = GetAvailability(bufPos, &functionAvailability[i].availability);
        if (strcmp(functionAvailability[i].availability, "MTR_FA_NO") == 0)
        {
            printf("Error: Incorrect availability for function %s\n",
             functionAvailability[i].name);
            return 11;
        }

        bufPos++;
    }

    outputFile = fopen(outputPath, "w");
    if (outputFile == NULL)
    {
        printf("Unable to open output file: %s\n", outputPath);
        return 12;
    }

    fprintf(outputFile, "#ifndef %s\n", includeGuard);
    fprintf(outputFile, "#define %s\n", includeGuard);
    fprintf(outputFile, "%s", "#include \"marathoner/marathoner.h\"\n");
    fprintf(outputFile, "#define FA_FUNCTIONS_COUNT %i\n", funcsCount);

    fprintf(outputFile, "%s", "mtrFa_t fa[] = {\n");
    for (i = 0; i < funcsCount; i++)
    {
        fprintf(outputFile, "%s", "    {\"");
        fprintf(outputFile,"%s", functionAvailability[i].name);
        fprintf(outputFile, "%s", "\", ");
        fprintf(outputFile,"%s}", functionAvailability[i].availability);
        if (i < funcsCount - 1)
            fprintf(outputFile, "%s", ",");
        fprintf(outputFile, "%s", "\n");
    }
    fprintf(outputFile, "%s", "};\n");
    fprintf(outputFile, "%s", "#endif\n");

    if (fclose(outputFile) == EOF)
    {
        printf("Unable to close output file: %s\n", outputPath);
        return 13;
    }

    for (i = 0; i < funcsCount; i++)
        free(functionAvailability[i].name);
    free(inputBuf);
    free(functionAvailability);
    return 0;
}
