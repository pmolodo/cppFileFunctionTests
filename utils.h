#include <windows.h>
#include <tchar.h>
#include <stdio.h>

inline void printUsage(TCHAR *progName)
{
    _tprintf(TEXT("USAGE: %s PATH\n"), progName);
}

inline LPTSTR getErrorMessage(DWORD errcode) {
    LPTSTR lpMsgBuf;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errcode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );
    return lpMsgBuf;
}