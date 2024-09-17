#include <windows.h>
#include <stdio.h>

// Callback para tratar eventos de teclado
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT *p = (KBDLLHOOKSTRUCT *)lParam;
            printf("Key pressed: %d\n", p->vkCode);
            // Processar evento de escaneamento aqui
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    // Configurar um hook de teclado global
    HHOOK keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (keyboardHook == NULL) {
        printf("Failed to install hook!\n");
        return 1;
    }

    // Loop de mensagens para manter o hook ativo
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Remover o hook quando terminar
    UnhookWindowsHookEx(keyboardHook);
    return 0;
}
