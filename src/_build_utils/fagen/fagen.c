#include "fagen.h"

char *FagenCountSymbols(char *str, int *len)
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

char *FagenGetAvailability(char *str, const char **availability)
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

bool FagenCreateEmptyFile(const char *outputPath, const char *includeGuard)
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

int FagenGetFileLength(const char *filename)
{
    FILE *inputFile;
    int   bufLength;

    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Unable to open input file: %s\n", filename);
        return 0;
    }
    bufLength = 0;
    while (fgetc(inputFile) != EOF)
        bufLength++;
    if (fclose(inputFile) == EOF) {
        printf("Unable to close input file: %s\n", filename);
        return 0;
    }

    return bufLength;
}

char *FagenLoadFile(const char *inputPath, int bufLength)
{
    char *inputBuf = NULL;
    int   i;
    FILE *inputFile;
    int   fileChar;

    inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        printf("Unable to open input file: %s\n", inputPath);
        return NULL;
    }
    inputBuf = malloc(sizeof(char* ) * (bufLength + 1));
    if (inputBuf == NULL) {
        printf("%s\n", "Unable to allocate memory for input file's buffer");
        return NULL;
    }

    for (i = 0; i < bufLength; i++) {
        fileChar = fgetc(inputFile);
        if (fileChar == EOF) {
            printf("Unexpected end of file: %s\n", inputPath);
            free(inputBuf);
            return NULL;
        }
        inputBuf[i] = (char)fileChar;
    }
    inputBuf[bufLength] = '\0';

    if (fclose(inputFile) == EOF) {
        printf("Unable to close input file: %s\n", inputPath);
        free(inputBuf);
        return NULL;
    }

    return inputBuf;
}

int FagenProcessInputFile(const char *inputPath,
 functionAvailability_t **functionAvailability)
{
    int   bufLength;
    char *inputBuf = NULL;
    char *bufPos = NULL;
    int   funcsCount = 0;
    int   i;
    int   funcNameLen;

    bufLength = FagenGetFileLength(inputPath);
    inputBuf = FagenLoadFile(inputPath, bufLength);

    /* counting *fa comments */
    bufPos = inputBuf;
    while (bufPos[0] != '\0') {
        bufPos = strstr(bufPos, "/*fa ");
        if (bufPos == NULL)
            break;
        bufPos++;
        funcsCount++;
    }
    if (funcsCount == 0) {
        free(inputBuf);
        printf("%s\n", "*fa comments not found");
        return 0;
    }

    *functionAvailability = malloc(sizeof(functionAvailability_t) * funcsCount);
    if (*functionAvailability == NULL) {
        printf("%s\n", "Unable to allocate memory for functions' availability "
         "data array");
        free(inputBuf);
        return 0;
    }

    bufPos = inputBuf;
    for (i = 0; i < funcsCount; i++) {
        bufPos = strstr(bufPos, "/*fa ");
        bufPos += sizeof(char) * 5;
        bufPos = FagenCountSymbols(bufPos, &funcNameLen);
        (*functionAvailability)[i].name = malloc(sizeof(char) * funcNameLen + 1);
        if ((*functionAvailability)[i].name == NULL) {
            printf("%s\n", "Unable to allocate memory for function name");
            free(inputBuf);
            free(*functionAvailability);
            return 0;
        }
        strncpy((*functionAvailability)[i].name, bufPos, funcNameLen);
        (*functionAvailability)[i].name[funcNameLen] = '\0';
        bufPos += sizeof(char) * funcNameLen;

        bufPos = FagenGetAvailability(bufPos,
         &(*functionAvailability)[i].availability);
        if (strcmp((*functionAvailability)[i].availability, "MTR_FA_NO") == 0) {
            printf("Error: Incorrect availability for function %s\n",
             (*functionAvailability)[i].name);
            return 0;
        }

        bufPos++;
    }

    return funcsCount;
}

int main(int argc, char **argv)
{
    FILE                    *outputFile;
    char                    *inputBuf = NULL;
    int                      i;
    int                      j;
    int                     *funcsCount;
    int                      allFuncsCount = 0;
    functionAvailability_t **functionAvailability;
    char                    *inputPath;
    char                    *outputPath;
    char                    *platform;
    char                    *includeGuard = NULL;
    int                      outputPathLen;
    int                      inputFilesCount;

    UNUSED(platform);

    outputPath = argv[1];
    platform = argv[2];

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

    inputFilesCount = argc - 3;

    functionAvailability = malloc(
     sizeof(functionAvailability_t *) * inputFilesCount);
    if (functionAvailability == NULL) {
        printf("%s",
         "Error: Unable to allocate memory for functions' availability data\n");
        return 1;
    }

    funcsCount = malloc(sizeof(int) * inputFilesCount);

    for (i = 0; i < inputFilesCount; i++) {
        inputPath = argv[i + 3];
        funcsCount[i] = 0;
        funcsCount[i] = FagenProcessInputFile(inputPath,
         &functionAvailability[i]);
        allFuncsCount = allFuncsCount + funcsCount[i];
    }
    if (allFuncsCount == 0) {
        if (!FagenCreateEmptyFile(outputPath, includeGuard)) {
            printf("Error: Unable to open or close output file: %s\n",
             outputPath);
            return 2;
        }
        return 0;
    }

    outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file: %s\n", outputPath);
        return 3;
    }

    fprintf(outputFile, "#ifndef %s\n", includeGuard);
    fprintf(outputFile, "#define %s\n", includeGuard);
    fprintf(outputFile, "%s", "#include \"marathoner/marathoner.h\"\n");
    fprintf(outputFile, "#define FA_FUNCTIONS_COUNT %i\n", allFuncsCount);

    fprintf(outputFile, "%s", "mtrFa_t fa[] = {\n");

    for (j = 0; j < inputFilesCount; j++) {
        for (i = 0; i < funcsCount[j]; i++) {
            fprintf(outputFile, "%s", "    {\"");
            fprintf(outputFile,"%s", functionAvailability[j][i].name);
            fprintf(outputFile, "%s", "\", ");
            fprintf(outputFile,"%s}", functionAvailability[j][i].availability);
            if (j == inputFilesCount - 1) {
                if (i == funcsCount[j] - 1)
                    ;
                else
                    fprintf(outputFile, "%s", ",");
            } else
                fprintf(outputFile, "%s", ",");

            fprintf(outputFile, "%s", "\n");
        }
    }
    fprintf(outputFile, "%s", "};\n");
    fprintf(outputFile, "%s", "#endif\n");

    if (fclose(outputFile) == EOF) {
        printf("Error: Unable to close output file: %s\n", outputPath);
        return 4;
    }

    for (j = 0; j < inputFilesCount; j++) {
        for (i = 0; i < funcsCount[j]; i++)
            free(functionAvailability[j][i].name);
        free(functionAvailability[j]);
    }
    free(inputBuf);
    free(functionAvailability);

    return 0;
}
