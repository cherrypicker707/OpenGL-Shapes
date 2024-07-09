// Project headers
#include "file.h"

// Standard library headers
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

const char *getFileContent(const char *path)
{
    FILE *file = fopen(path, "r");
    assert(file);

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc((length + 1) * sizeof(char));
    fread(content, sizeof(char), length, file);

    fclose(file);

    content[length] = '\0';

    return content;
}
