#include <windows.h>
#include <shellapi.h>

/* Benign lab payload. rundll32.exe <dll>,Start calls this.
   Visible proof-of-execution: opens the default browser to a
   (benign) YouTube URL. No persistence, no network beyond that
   one ShellExecute, no file I/O. Swap the URL or use calc.exe
   if you prefer something offline. */
__declspec(dllexport) void CALLBACK Start(HWND hwnd, HINSTANCE hinst, LPSTR lpCmdLine, int nCmdShow)
{
    (void)hwnd; (void)hinst; (void)lpCmdLine; (void)nCmdShow;
    ShellExecuteA(NULL, "open",
                  "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
                  NULL, NULL, SW_SHOWNORMAL);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    (void)hinstDLL; (void)fdwReason; (void)lpvReserved;
    return TRUE;
}
