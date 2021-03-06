#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    FILE        *inputFile;
    FILE        *outputFile;
    char        *inputBuf;
    unsigned int bufLength;
    unsigned int i;
    int          fileChar;
    char        *constPos;
    char        *valuePos;
    unsigned int uValuePos;
    unsigned int version;
    unsigned int digit;
    unsigned int verMajor;
    unsigned int verMinor;
    unsigned int verPatch;
    unsigned int verHotfix;

    char        *inputPath = argv[1];
    char        *outputPath = argv[2];
    char        *versionConst = argv[3];
    char        *name = argv[4];
    char        *description = argv[5];
    char        *filename = argv[6];

    if (argc < 2)
    {
        printf("%s\n", "TODO: Usage.");
    }
    else
    {
        inputFile = fopen(inputPath, "r");
        if (inputFile == NULL)
        {
            printf("Unable to open input file: %s\n", inputPath);
            return 1;
        }
        bufLength = 0U;
        while (fgetc(inputFile) != EOF)
        {
            bufLength++;
        }
        if (fclose(inputFile) == EOF)
        {
            printf("Unable to close input file: %s\n", inputPath);
            return 2;
        }

        inputFile = fopen(inputPath, "r");
        if (inputFile == NULL)
        {
            printf("Unable to open input file: %s\n", inputPath);
            return 3;
        }
        inputBuf = malloc(sizeof(char* ) * (bufLength + 1U));
        for (i = 0U; i < bufLength; i++)
        {
            fileChar = fgetc(inputFile);
            if (fileChar == EOF)
            {
                printf("Unexpected end of file: %s\n", inputPath);
                return 4;
            }
            inputBuf[i] = (char)fileChar;
        }
        inputBuf[bufLength] = '\0';

        if (fclose(inputFile) == EOF)
        {
            printf("Unable to close input file: %s\n", inputPath);
            return 5;
        }

        constPos = strstr(inputBuf, versionConst);
        if (constPos == NULL)
        {
            printf("Unable to find const: %s\n", versionConst);
            return 6;
        }

        valuePos = strstr(constPos, "0x");
        if (valuePos == NULL)
        {
            printf("Unable to find value of const %s\n", versionConst);
            return 7;
        }

        version = 0U;
        for (i = 2U; i <= 7U; i++)
        {
            digit = i - 2U;
            switch (valuePos[i])
            {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                {
                    uValuePos = valuePos[i];
                    version = version + (uValuePos - 0x30U) *
                     (0x1U << (4U * (5U - digit)));
                    break;
                }
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                {
                    uValuePos = valuePos[i];
                    version = version + (uValuePos - 0x41U) *
                     (0x1U << (4U * (5U - digit)));
                    break;
                }
                default:
                {
                    printf("Unexpected symbol %c\n", valuePos[i]);
                    return 8;
                }
            }
        }

        verMajor = (version &  0x00FF0000) >> 16;
        verMinor = (version &  0x0000FF00) >> 8;
        verPatch = version &   0x000000FF;
        verHotfix = (version & 0xFF000000) >> 24;

        outputFile = fopen(outputPath, "w");
        if (outputFile == NULL)
        {
            printf("Unable to open output file: %s\n", outputPath);
            return 9;
        }

        fprintf(outputFile, "%s\n", "#include <winver.h>");
        fprintf(outputFile, "%s\n", "VS_VERSION_INFO VERSIONINFO");
        fprintf(outputFile, "FILEVERSION %u,%u,%u,%u\n", verMajor, verMinor,
         verPatch, verHotfix);
        fprintf(outputFile, "PRODUCTVERSION %u,%u,%u,%u\n", verMajor, verMinor,
         verPatch, verHotfix);
        fprintf(outputFile, "%s\n", "FILEFLAGSMASK  	VS_FFI_FILEFLAGSMASK");
        fprintf(outputFile, "%s\n", "FILEFLAGS      	VS_FF_PRERELEASE");
        fprintf(outputFile, "%s\n", "FILEOS         	VOS_NT_WINDOWS32");
        if (strcmp(name, "Marathoner") == 0)
            fprintf(outputFile, "%s\n", "FILETYPE       	VFT_APP");
        else if (strcmp(name, "Launcher") == 0)
            fprintf(outputFile, "%s\n", "FILETYPE       	VFT_APP");
        else
            fprintf(outputFile, "%s\n", "FILETYPE       	VFT_DLL");
        fprintf(outputFile, "%s\n", "FILESUBTYPE    	VFT2_UNKNOWN");
        fprintf(outputFile, "%s\n", "BEGIN");
            fprintf(outputFile, "%s\n", "BLOCK \"StringFileInfo\"");
            fprintf(outputFile, "%s\n", "BEGIN");
                fprintf(outputFile, "%s\n", "BLOCK \"040904E4\""); /* 040904E4 */
                fprintf(outputFile, "%s\n", "BEGIN");
                    fprintf(outputFile, "%s\n",
                     "VALUE \"CompanyName\", \"Vasiliy Edomin\"");
                    fprintf(outputFile, "VALUE \"FileDescription\", \"%s\"\n",
                     description);
                    fprintf(outputFile,
                     "VALUE \"FileVersion\", \"%u,%u,%u,%u\"\n", verMajor,
                     verMinor, verPatch, verHotfix);
                    fprintf(outputFile, "VALUE \"InternalName\", \"%s\"\n",
                     name);
                    fprintf(outputFile, "%s\n",
                     "VALUE \"LegalCopyright\", \"(C) 2016-2017 Vasiliy "
                     "Edomin\"");
                    fprintf(outputFile, "VALUE \"OriginalFilename\", \"%s\"\n",
                     filename);
                    fprintf(outputFile, "VALUE \"ProductName\", \"%s\"\n",
                     name);
                    fprintf(outputFile,
                     "VALUE \"ProductVersion\", \"%u,%u,%u,%u\"\n", verMajor,
                     verMinor, verPatch, verHotfix);
                fprintf(outputFile, "%s\n", "END");
            fprintf(outputFile, "%s\n", "END");

            fprintf(outputFile, "%s\n", "BLOCK \"VarFileInfo\"");
            fprintf(outputFile, "%s\n", "BEGIN");
                fprintf(outputFile, "%s\n",
                 "VALUE \"Translation\", 0x0409, 1252");
            fprintf(outputFile, "%s\n", "END");
        fprintf(outputFile, "%s\n", "END");

        if (fclose(outputFile) == EOF)
        {
            printf("Unable to close output file: %s\n", outputPath);
            return 5;
        }

        free(inputBuf);
    }

    return 0;
}
