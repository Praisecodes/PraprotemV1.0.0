#include "Window.h"

Window* wind = nullptr;

void OpenFileFunction(HWND);
void SaveFileFunction(HWND);

LRESULT CALLBACK MainProc(HWND hwnd, UINT mas, WPARAM wp, LPARAM lp)
{
    switch (mas)
    {
    case WM_CREATE:
        wind->Update(hwnd);
        break;

    case WM_DRAWITEM:
    {
        LPDRAWITEMSTRUCT lpds = (DRAWITEMSTRUCT*)lp;

        HWND window = lpds->hwndItem;
        HDC color = lpds->hDC;

        if (window == wind->Header)
        {
            SetBkMode(color, TRANSPARENT);
        }

        if (window == wind->MinimizeBtn)
        {
            SetBkColor(color, RGB(60, 60, 60));
            SetTextColor(color, RGB(0, 0, 255));

            ExtTextOut(color, (lpds->rcItem.left), (lpds->rcItem.top), ETO_CLIPPED | ETO_OPAQUE, 
                &lpds->rcItem, L"0", strlen("0"), NULL);
        }

        if (window == wind->CloseBtn)
        {
            SetBkColor(color, RGB(60, 60, 60));
            SetTextColor(color, RGB(255, 0, 0));

            ExtTextOut(color, (lpds->rcItem.left), (lpds->rcItem.top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"x", strlen("x"), NULL);
        }
        if (window == wind->ReturnBtn)
        {
            int Left = (15 * wind->SideBtnsWidth) / 100;
            int Top = (5 * wind->SideBtnsHeight) / 100;

            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"O", strlen("O"), NULL);
        }

        if (window == wind->EditorBtn)
        {
            int Left = (15 * wind->SideBtnsWidth) / 100;
            int Top = (5 * wind->SideBtnsHeight) / 100;

            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"4", strlen("4"), NULL);
        }

        if (window == wind->ProjectsBtn)
        {
            int Left = (15 * wind->SideBtnsWidth) / 100;
            int Top = (5 * wind->SideBtnsHeight) / 100;

            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"R", strlen("R"), NULL);
        }

        if (window == wind->LeaveBtn)
        {
            int Left = (15 * wind->SideBtnsWidth) / 100;
            int Top = (5 * wind->SideBtnsHeight) / 100;

            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"[", strlen("["), NULL);
        }

        if (window == wind->MidProjectBtn)
        {
            int Left = (6 * wind->MidBtnWidth) / 100;
            int Top = (20 * wind->MidBtnHeight) / 100;

            SetBkColor(color, RGB(60, 60, 60));
            SetTextColor(color, RGB(63, 72, 204));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"PROJECTS", strlen("PROJECTS"), NULL);
        }

        if (window == wind->MidEditorBtn)
        {
            int Left = (15 * wind->MidBtnWidth) / 100;
            int Top = (20 * wind->MidBtnHeight) / 100;

            SetBkColor(color, RGB(60, 60, 60));
            SetTextColor(color, RGB(63, 72, 204));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"EDITOR", strlen("EDITOR"), NULL);
        }

        if (window == wind->MidLeaveBtn)
        {
            int Left = (20 * wind->MidBtnWidth) / 100;
            int Top = (20 * wind->MidBtnHeight) / 100;

            SetBkColor(color, RGB(60, 60, 60));
            SetTextColor(color, RGB(63, 72, 204));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE,
                &lpds->rcItem, L"LEAVE", strlen("LEAVE"), NULL);
        }

        if (window == wind->Identifier)
        {
            SetBkMode(color, TRANSPARENT);
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left), (lpds->rcItem.top), NULL,
                &lpds->rcItem, L"Praprotem v1.0.0", strlen("Praprotem v1.0.0"), NULL);
        }

        if (window == wind->LogoLeftHand)
        {
            SetBkMode(color, TRANSPARENT);
            SetTextColor(color, RGB(255, 255, 0));

            ExtTextOut(color, (lpds->rcItem.left), (lpds->rcItem.top), NULL,
                &lpds->rcItem, L"E", strlen("E"), NULL);
        }

        if (window == wind->LogoRightHand)
        {
            SetBkMode(color, TRANSPARENT);
            SetTextColor(color, RGB(255, 255, 0));

            ExtTextOut(color, (lpds->rcItem.left), (lpds->rcItem.top), NULL,
                &lpds->rcItem, L"D", strlen("D"), NULL);
        }

        if (window == wind->Logo)
        {
            SetBkMode(color, TRANSPARENT);
            SetTextColor(color, RGB(255, 255, 0));

            ExtTextOut(color, (lpds->rcItem.left), (lpds->rcItem.top), NULL,
                &lpds->rcItem, L"PRAPROTEM", strlen("PRAPROTEM"), NULL);
        }

        if (window == wind->AboutBtn)
        {
            SetBkColor(color, RGB(60, 60, 60));
            SetTextColor(color, RGB(255, 255, 255));
            int Left = (15 * wind->AboutBtnWidth) / 100;
            int Top = (25 * wind->AboutBtnHeight) / 100;

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE ,
                &lpds->rcItem, L"About", strlen("About"), NULL);
        }

        if (window == wind->NewFileBtn)
        {
            int Top = (10 * wind->IconBtnsHeight) / 100, Left = (17 * wind->IconBtnsWidth) / 100;
            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left+Left), (lpds->rcItem.top), ETO_CLIPPED | ETO_OPAQUE, 
                &lpds->rcItem, L"2", strlen("2"), NULL);
        }

        if (window == wind->OpenFileBtn)
        {
            ExtTextOut(color, 0, 0, ETO_OPAQUE, &lpds->rcItem, NULL, NULL, NULL);

            DrawState(color, NULL, NULL, (LPARAM)wind->icon_openFile, NULL, 0, 0, ((100 * wind->IconBtnsWidth) / 100),
                ((100 * wind->IconBtnsHeight) / 100), DST_BITMAP);
        }

        if (window == wind->SaveFileBtn)
        {
            ExtTextOut(color, 0, 0, ETO_CLIPPED | ETO_OPAQUE, &lpds->rcItem, NULL, NULL, NULL);

            DrawState(color, NULL, NULL, (LPARAM)wind->icon_saveFile, NULL, 0, 0, ((100 * wind->IconBtnsWidth) / 100),
                ((100 * wind->IconBtnsHeight) / 100), DST_BITMAP);
        }

        if (window == wind->BoldFontBtn)
        {
            int Top = (10 * wind->IconBtnsHeight) / 100, Left = (27 * wind->IconBtnsWidth) / 100;

            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE, &lpds->rcItem,
                L"B", strlen("B"), NULL);
        }

        if (window == wind->UnderlineFontBtn)
        {
            int Top = (10 * wind->IconBtnsHeight) / 100, Left = (27 * wind->IconBtnsWidth) / 100;

            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top), ETO_CLIPPED | ETO_OPAQUE, &lpds->rcItem,
                L"U", strlen("U"), NULL);
        }

        if (window == wind->ItalizeFontBtn)
        {
            int Top = (10 * wind->IconBtnsHeight) / 100, Left = (27 * wind->IconBtnsWidth) / 100;

            SetBkColor(color, RGB(127, 127, 127));
            SetTextColor(color, RGB(255, 255, 255));

            ExtTextOut(color, (lpds->rcItem.left + Left), (lpds->rcItem.top + Top), ETO_CLIPPED | ETO_OPAQUE, &lpds->rcItem,
                L"I", strlen("I"), NULL);
        }

        DrawEdge(color, &lpds->rcItem, 0, BF_SOFT);
        return TRUE;
    }
        break;

    case WM_COMMAND:
    {
        switch (wp)
        {
            case Close:
            {
                PostQuitMessage(0);
                wind->Endprocess();
            }
            break;

            case Minimize:
            {
                ShowWindow(wind->MainWindow, SW_MINIMIZE);
            }
            break;

            case Leave:
            {
                if (MessageBox(hwnd, L"Are you sure you want to leave??", L"Confirm Exit", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
                {
                    PostQuitMessage(0);
                    wind->Endprocess();
                }
            }
            break;

            case EditorBtnPushed:
            {
                if (wind->HomeSectionActive == true)
                {
                    wind->DestroyHomeControls(wind->MidProjectBtn, wind->MidEditorBtn, wind->MidLeaveBtn);
                }
                else {
                    if (wind->ProjectSectionActive == true)
                    {

                    }
                }
                wind->ShowEditorSection(hwnd);
                EnableWindow(wind->EditorBtn, FALSE);
            }
            break;

            case ProjectsBtnPushed:
            {
                if (wind->EditorSectionActive == true)
                {
                    wind->DestroyEditorControls(wind->IconPanel, wind->Editor, wind->ProjectPanel, wind->NewFileBtn,
                        wind->OpenFileBtn, wind->SaveFileBtn, wind->BoldFontBtn, wind->UnderlineFontBtn, wind->ItalizeFontBtn);
                }
                else {
                    if (wind->HomeSectionActive == true) {
                        wind->DestroyHomeControls(wind->MidProjectBtn, wind->MidEditorBtn, wind->MidLeaveBtn);
                    }
                }
                wind->CreateProjectsSection(hwnd);
                EnableWindow(wind->ProjectsBtn, FALSE);
                EnableWindow(wind->EditorBtn, TRUE);
            }
            break;
            
            case ReturnBtnPushed:
            {
                if (wind->EditorSectionActive == true)
                {
                    wind->DestroyEditorControls(wind->IconPanel, wind->Editor, wind->ProjectPanel, wind->NewFileBtn,
                        wind->OpenFileBtn,wind->SaveFileBtn,wind->BoldFontBtn,wind->UnderlineFontBtn,wind->ItalizeFontBtn);
                }
                else {
                    if (wind->ProjectSectionActive == true)
                    {
                    }
                }
                wind->CreateHomeSection(hwnd);
                EnableWindow(wind->EditorBtn, TRUE);
                EnableWindow(wind->ProjectsBtn, TRUE);
            }
            break;

            case OpenFileBtnPushed:
            {
                OpenFileFunction(hwnd);
            }
            break;

            case SaveFileBtnPushed:
            {
                SaveFileFunction(hwnd);
            }
            break;

            case BoldFontBtnPushed:
            {
                if (wind->Bold == false)
                {
                    wind->Bold = true;
                }
                else {
                    if (wind->Bold == true)
                    {
                        wind->Bold = false;
                    }
                }
                char AvailableText[10000];

                GetWindowTextA(wind->Editor, AvailableText, 10000);
                int lengthOfAvailableText = strlen(AvailableText);

                if(wind->Bold == true)
                {
                    HFONT BoldEditorFont = CreateFont(((4 * wind->EditorHeight) / 100), 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE,
                        DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Belwe Bd"));

                    SendMessage(wind->Editor, WM_SETFONT, (WPARAM)BoldEditorFont, MAKELPARAM(true,0));
                }
                else{
                    HFONT nBoldEditorFont = CreateFont(((4 * wind->EditorHeight) / 100), 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE,
                        DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Belwe Bd"));

                    SendMessage(wind->Editor, WM_SETFONT, (WPARAM)nBoldEditorFont, MAKELPARAM(true, 0));
                }
            }
            break;

            case UnderlineFontBtnPushed:
            {

            }
            break;

            case ItalizeFontBtnPushed:
            {

            }
            break;
        }
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        wind->Endprocess();
        break;

    default:
        return DefWindowProc(hwnd, mas, wp, lp);
        if (!(wind->HomeSectionActive == true))
        {
            EnableWindow(wind->ReturnBtn, TRUE);
        }
        else {
            EnableWindow(wind->ReturnBtn, FALSE);
        }
        break;
    }

    return 0;
}

bool Window::Create()
{
    WNDCLASS wc = {};

    wc.hbrBackground = CreateSolidBrush(RGB(60, 60, 60));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc = MainProc;
    wc.lpszClassName = L"name";

    RegisterClass(&wc);

    if (!wind)
    {
        wind = this;
    }

    MainWindow = CreateWindowEx(0, L"name", L"Praprotem v1.0.0", WS_POPUPWINDOW | WS_VISIBLE, 0, 0, WIDTH, HEIGHT,
        NULL, NULL, NULL, NULL);

    IsRunning = true;
    HomeSectionActive = true;
    return true;
}

bool Window::isRunning()
{
    return IsRunning;
}

bool Window::Show()
{
    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    Sleep(0);
    return true;
}

bool Window::Endprocess()
{
    IsRunning = false;
    return IsRunning;
}

void Window::DestroyHomeControls(HWND hwnd1, HWND hwnd2, HWND hwnd3)
{
    DestroyWindow(hwnd1);
    DestroyWindow(hwnd2);
    DestroyWindow(hwnd3);
}

void Window::DestroyProjectControls(HWND hwnd1, HWND hwnd2, HWND hwnd3, HWND hwnd4)
{
}

void Window::DestroyEditorControls(HWND hwnd1, HWND hwnd2, HWND hwnd3, HWND hwnd4,HWND hwnd5,HWND hwnd6,HWND hwnd7,
    HWND hwnd8,HWND hwnd9)
{
    DestroyWindow(hwnd1);
    DestroyWindow(hwnd2);
    DestroyWindow(hwnd3);
    DestroyWindow(hwnd4);
    DestroyWindow(hwnd5);
    DestroyWindow(hwnd6);
    DestroyWindow(hwnd7);
    DestroyWindow(hwnd8);
    DestroyWindow(hwnd9);
}

void OpenFileFunction(HWND hwnd)
{
    OPENFILENAMEA OpenFile;

    char filename[10000];

    ZeroMemory(&OpenFile, sizeof(OPENFILENAMEA));

    OpenFile.lStructSize = sizeof(OPENFILENAMEA);
    OpenFile.hwndOwner = hwnd;
    OpenFile.lpstrFile = filename;
    OpenFile.lpstrFile[0] = '\0';
    OpenFile.nMaxFile = 10000;
    OpenFile.lpstrFilter = "Praprotem File (.ptem)\0*.ptem\0";
    OpenFile.nFilterIndex = 1;

    GetOpenFileNameA(&OpenFile);
}

void SaveFileFunction(HWND hwnd)
{
    OPENFILENAMEA SaveFile;

    char filename[10000];

    ZeroMemory(&SaveFile, sizeof(OPENFILENAMEA));

    SaveFile.lStructSize = sizeof(OPENFILENAMEA);
    SaveFile.hwndOwner = hwnd;
    SaveFile.lpstrFile = filename;
    SaveFile.lpstrFile[0] = '\0';
    SaveFile.nMaxFile = 10000;
    SaveFile.lpstrFilter = "Praprotem File (.ptem)\0*.ptem\0";
    SaveFile.nFilterIndex = 1;

    GetSaveFileNameA(&SaveFile);
}
