#include <windows.h>
/* inclui o arquivo de cabeçalho windows.h, que contém declarações 
para todas as funções da API do Windows, tipos de dados e constantes 
necessárias para criar aplicações Windows.*/

// Protótipo da função de tratamento de mensagens da janela
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
/*Declara um protótipo para a função de procedimento da janela. 
Esta função é chamada pela API do Windows para tratar mensagens direcionadas para a janela, 
como cliques do mouse, movimentos, fechamento da janela, etc.*/


char szClassName[] = "WindowsApp";

/*WinMain é o ponto de entrada para uma aplicação Windows, 
equivalente à função main em programas C padrão. 
Esta função é chamada pelo sistema operacional quando a aplicação é iniciada.*/
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl; /*Define uma estrutura que contém informações sobre a classe da janela. Esta estrutura é usada para registrar a classe da janela e definir algumas propriedades importantes, como o estilo da janela, o ícone, o cursor e a função de procedimento da janela.*/

    // Estrutura de definição da janela
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	/*Registra a classe da janela com a API do Windows. 
	Se o registro falhar, o programa termina imediatamente.*/
    if (!RegisterClassEx(&wincl))
        return 0;

    // Criação da janela
    /*Cria uma janela usando a classe registrada. 
	Define o estilo da janela, o título, as dimensões e outros parâmetros importantes.*/
    hwnd = CreateWindowEx(
        0,
        szClassName,
        "Clique do Mouse Detector",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        544,
        375,
        HWND_DESKTOP,
        NULL,
        hThisInstance,
        NULL
    );
	
	/*ShowWindow exibe a janela na tela em um estado especificado (nCmdShow). 
	UpdateWindow força a janela a se redesenhar.*/
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Loop de mensagens
    /*O loop de mensagens é fundamental em aplicações Windows. 
	Ele aguarda por mensagens do sistema, como eventos de entrada do usuário, 
	e despacha essas mensagens para a função de procedimento da janela apropriada.*/
    while (GetMessage(&messages, NULL, 0, 0)) {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

// Função de tratamento de mensagens
/*Trata as mensagens enviadas para a janela. WM_LBUTTONDOWN e WM_RBUTTONDOWN 
são tratados para detectar cliques nos botões esquerdo e direito do mouse, respectivamente. 
WM_DESTROY é usado para terminar o loop de mensagens e fechar a aplicação.*/
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_LBUTTONDOWN:
            MessageBox(hwnd, "Clique esquerdo detectado!", "Evento do Mouse", MB_OK | MB_ICONINFORMATION);
            break;
        case WM_RBUTTONDOWN:
            MessageBox(hwnd, "Clique direito detectado!", "Evento do Mouse", MB_OK | MB_ICONINFORMATION);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
