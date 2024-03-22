#include "utils.h"

#include <windows.h>
#include <tchar.h>
#include <shlwapi.h>
#include <stdio.h>

constexpr int NO_PATH_ARG_ERR = 101;

int _tmain(int argc, TCHAR *argv[])
{

    if (argc < 2)
    {
        printf("Missing PATH argument\n");
        printUsage(argc == 0 ? TEXT("<unknown_exe_name>") : argv[0]);
        return NO_PATH_ARG_ERR;
    }

    _tprintf(TEXT("Target file is %s\n"), argv[1]);
    if (PathIsDirectory(argv[1])) {
        printf("   ...existed\n");
    } else {
        printf("   ...did not exist\n");
    }

    return 0;
}
