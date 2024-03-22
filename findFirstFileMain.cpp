#include "utils.h"

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

constexpr int NO_PATH_ARG_ERR = 101;
constexpr int UNKNOWN_ERR = 201;
constexpr int FOUND_NO_FILES_ERR = 202;

int _tmain(int argc, TCHAR *argv[])
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;

    if (argc < 2)
    {
        printf("Missing PATH argument\n");
        printUsage(argc == 0 ? TEXT("<unknown_exe_name>") : argv[0]);
        return NO_PATH_ARG_ERR;
    }

    _tprintf(TEXT("Target file is %s\n"), argv[1]);
    hFind = FindFirstFile(argv[1], &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        auto err = GetLastError();
        if (err == ERROR_FILE_NOT_FOUND) {
            printf("Found no files\n");
            return FOUND_NO_FILES_ERR;
        }
        _tprintf(TEXT("FindFirstFile failed (%d: %s) \n"), err, getErrorMessage(err));
        return UNKNOWN_ERR;
    }
    else
    {
        _tprintf(TEXT("The first file found is %s\n"),
                 FindFileData.cFileName);
        FindClose(hFind);
    }
    return 0;
}
