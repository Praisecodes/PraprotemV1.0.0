#include "App.h"
#include <string>

void App::Update(HWND hwnd)
{
	BitmapCreate();
	AppHeaderCreate(hwnd);
	SideButtonsCreate(hwnd);
	CreateHomeSection(hwnd);
}

void App::AppHeaderCreate(HWND hwnd)
{
	int LogoBgY = (15 * HeaderHeight) / 100, LogoBgX = (25 * HeaderWidth) / 100;
	int MinimizeBtnX = (94 * HeaderWidth) / 100, MinimizeBtnY = 0;
	int CloseBtnX = (97 * HeaderWidth) / 100, CloseBtnY = 0;
	int IdentifierX = (5 * HeaderWidth) / 100;
	int LogoLeftHandX = (25 * HeaderWidth) / 100, LogoLeftHandY = (15 * HeaderHeight) / 100;
	int LogoX = (33 * HeaderWidth) / 100, LogoY = (15 * HeaderHeight) / 100;
	int LogoRightHandX = (67 * HeaderWidth) / 100, LogoRightHandY = (15 * HeaderHeight) / 100;

	HFONT IdentifierFont = CreateFont(((90 * IdentifierHeight) / 100), 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Calibri"));

	HFONT RightAndLeftFont = CreateFont(((120 * LogoRightHandHeight) / 100), 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Wingdings 2"));

	HFONT LogoFont = CreateFont(((113 * LogoHeight) / 100), 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Calibri"));

	HFONT MinimizeFont = CreateFont(((90 * MinimizeBtnHeight) / 100), 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Webdings"));

	HFONT CloseFont = CreateFont(((94 * CloseBtnHeight) / 100), 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Wingdings"));

	Header = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_OWNERDRAW, 0, 0, HeaderWidth,
		HeaderHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);

	Icon = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, 0, 0, IconWidth,
		IconHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(Icon, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)icon_picture);

	LogoBg = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, LogoBgX, LogoBgY,
		LogoBgWidth, LogoBgHeight, Header, NULL, (HINSTANCE)GetWindowLong(Header, GWLP_HINSTANCE), NULL);

	MinimizeBtn = CreateWindowEx(0, L"BUTTON", L"0", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, MinimizeBtnX, MinimizeBtnY,
		MinimizeBtnWidth, MinimizeBtnHeight, hwnd, (HMENU)Minimize, (HINSTANCE)GetWindowLong(Header, GWLP_HINSTANCE), NULL);
	SendMessage(MinimizeBtn, WM_SETFONT, (WPARAM)MinimizeFont, MAKELPARAM(TRUE, 0));

	CloseBtn = CreateWindowEx(0, L"BUTTON", L"x", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, CloseBtnX, CloseBtnY,
		CloseBtnWidth, CloseBtnHeight, hwnd, (HMENU)Close, (HINSTANCE)GetWindowLong(Header, GWLP_HINSTANCE), NULL);
	SendMessage(CloseBtn, WM_SETFONT, (WPARAM)CloseFont, MAKELPARAM(TRUE, 0));

	Identifier = CreateWindowEx(0, L"STATIC", L"Praprotem v1.0.0", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW,
		IdentifierX, 0, IdentifierWidth, IdentifierHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(Identifier, WM_SETFONT, (WPARAM)IdentifierFont, MAKELPARAM(TRUE, 0));

	LogoLeftHand = CreateWindowEx(0, L"STATIC", L"E", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW,
		LogoLeftHandX, LogoLeftHandY, LogoLeftHandWidth, LogoLeftHandHeight, hwnd, NULL,
		(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(LogoLeftHand, WM_SETFONT, (WPARAM)RightAndLeftFont, MAKELPARAM(TRUE, 0));

	Logo = CreateWindowEx(0, L"STATIC", L"PRAPROTEM", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW,
		LogoX, LogoY, LogoWidth, LogoHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(Logo, WM_SETFONT, (WPARAM)LogoFont, MAKELPARAM(TRUE, 0));

	LogoRightHand = CreateWindowEx(0, L"STATIC", L"D", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW,
		LogoRightHandX, LogoRightHandY, LogoRightHandWidth, LogoRightHandHeight,hwnd, NULL,(HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(LogoRightHand, WM_SETFONT, (WPARAM)RightAndLeftFont, MAKELPARAM(TRUE, 0));
}

void App::SideButtonsCreate(HWND hwnd)
{
	int ReturnBtnY = (30 * HEIGHT) / 100, EditorBtnY = (43 * HEIGHT) / 100, ProjectsBtnY = (56 * HEIGHT) / 100,
		LeaveBtnY = (69 * HEIGHT) / 100, AboutBtnX = SideBtnsX, AboutBtnY = (92*HEIGHT)/100;

	HFONT ReturnBtnFont = CreateFont(((94 * SideBtnsHeight) / 100), 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Wingdings 3"));

	HFONT EditorBtnFont = CreateFont(((94 * SideBtnsHeight) / 100), 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Wingdings"));

	HFONT ProjectBtnFont = CreateFont(((94 * SideBtnsHeight) / 100), 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Wingdings 2"));

	HFONT LeaveBtnFont = CreateFont(((94 * SideBtnsHeight) / 100), 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Wingdings 3"));

	HFONT AboutBtnFont = CreateFont(((55 * AboutBtnHeight) / 100), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Arial Narrow"));

	ReturnBtn = CreateWindowEx(0, L"BUTTON", L"O", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW, SideBtnsX, ReturnBtnY,
		SideBtnsWidth, SideBtnsHeight, hwnd, (HMENU)ReturnBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(ReturnBtn, WM_SETFONT, (WPARAM)ReturnBtnFont, MAKELPARAM(TRUE, 0));

	EditorBtn = CreateWindowEx(0, L"BUTTON", L"4", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW, SideBtnsX, EditorBtnY,
		SideBtnsWidth, SideBtnsHeight, hwnd, (HMENU)EditorBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(EditorBtn, WM_SETFONT, (WPARAM)EditorBtnFont, MAKELPARAM(TRUE, 0));

	ProjectsBtn = CreateWindowEx(0, L"BUTTON", L"R", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW, SideBtnsX, ProjectsBtnY,
		SideBtnsWidth, SideBtnsHeight, hwnd, (HMENU)ProjectsBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(ProjectsBtn, WM_SETFONT, (WPARAM)ProjectBtnFont, MAKELPARAM(TRUE, 0));

	LeaveBtn = CreateWindowEx(0, L"BUTTON", L"[", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW, SideBtnsX, LeaveBtnY,
		SideBtnsWidth, SideBtnsHeight, hwnd, (HMENU)Leave, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(LeaveBtn, WM_SETFONT, (WPARAM)LeaveBtnFont, MAKELPARAM(TRUE, 0));

	AboutBtn = CreateWindowEx(0, L"BUTTON", L"ABOUT", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, AboutBtnX,
		AboutBtnY, AboutBtnWidth, AboutBtnHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(AboutBtn, WM_SETFONT, (WPARAM)AboutBtnFont, MAKELPARAM(TRUE, 0));
}

void App::CreateHomeSection(HWND hwnd)
{
	HomeSectionActive = true;
	ProjectSectionActive = false;
	EditorSectionActive = false;

	int MidProjectBtnY = (34 * HEIGHT) / 100, MidEditorBtnY = (49 * HEIGHT) / 100, MidLeaveBtnY = (64 * HEIGHT) / 100;

	HFONT MidBtnFont = CreateFont(((55 * MidBtnHeight) / 100), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Palatino Linotype"));

	MidProjectBtn = CreateWindowEx(0, L"BUTTON", L"PROJECTS", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | WS_BORDER, MidProjectBtnX,
		MidProjectBtnY, MidBtnWidth, MidBtnHeight, hwnd, (HMENU)ProjectsBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(MidProjectBtn, WM_SETFONT, (WPARAM)MidBtnFont, MAKELPARAM(TRUE, 0));

	MidEditorBtn = CreateWindowEx(0, L"BUTTON", L"EDITOR", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | WS_BORDER, MidProjectBtnX,
		MidEditorBtnY, MidBtnWidth, MidBtnHeight, hwnd, (HMENU)EditorBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE),
		NULL);
	SendMessage(MidEditorBtn, WM_SETFONT, (WPARAM)MidBtnFont, MAKELPARAM(TRUE, 0));

	MidLeaveBtn = CreateWindowEx(0, L"BUTTON", L"LEAVE", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW | WS_BORDER, MidProjectBtnX,
		MidLeaveBtnY, MidBtnWidth, MidBtnHeight, hwnd, (HMENU)Leave, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(MidLeaveBtn, WM_SETFONT, (WPARAM)MidBtnFont, MAKELPARAM(TRUE, 0));
}

void App::BitmapCreate()
{
	icon_picture = (HBITMAP)LoadImage(NULL, L"Praprotem Logo2.bmp", IMAGE_BITMAP, ((100*IconWidth)/100),
		((100*IconHeight)/100), LR_LOADFROMFILE);

	icon_saveFile = (HBITMAP)LoadImage(NULL, L"SaveFile Image.bmp", IMAGE_BITMAP, ((100 * IconBtnsWidth) / 100),
		((100 * IconBtnsHeight) / 100), LR_LOADFROMFILE);

	icon_openFile = (HBITMAP)LoadImage(NULL, L"OpenFile Image.bmp", IMAGE_BITMAP, ((100 * IconBtnsWidth) / 100),
		((100 * IconBtnsHeight) / 100), LR_LOADFROMFILE);
}

void App::ShowEditorSection(HWND hwnd)
{
	EditorSectionActive = true;
	HomeSectionActive = false;
	ProjectSectionActive = false;

	int IconPanelY = (18 * HEIGHT) / 100, IconBtnsY = (18 * HEIGHT) / 100;
	int ProjectPanelY = (26 * HEIGHT) / 100;
	int EditorX = (20 * WIDTH) / 100, EditorY = (26 * HEIGHT) / 100;
	int NewFileBtnX = (20 * WIDTH) / 100, OpenFileBtnX = (27 * WIDTH) / 100, SaveFileBtnX = (34 * WIDTH) / 100,
		BoldFontBtnX = (41 * WIDTH) / 100, UnderlineFontBtnX = (48 * WIDTH) / 100, ItalizeFontBtnX = (55 * WIDTH) / 100;

	HFONT EditorFont = CreateFont(((4 * EditorHeight) / 100), 0, 0, 0, FW_EXTRALIGHT, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Belwe Bd"));

	HFONT NewFileBtnFont = CreateFont(((105 * IconBtnsHeight) / 100), 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Wingdings"));

	HFONT BoldFontBtnFont = CreateFont(((90 * IconBtnsHeight) / 100), 0, 0, 0, FW_EXTRABOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Impact"));

	HFONT UnderlineFontBtnFont = CreateFont(((90 * IconBtnsHeight) / 100), 0, 0, 0, FW_LIGHT, FALSE, TRUE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Arial Narrow"));

	HFONT ItalizeFontBtnFont = CreateFont(((90 * IconBtnsHeight) / 100), 0, 0, 0, FW_LIGHT, TRUE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Belwe Lt BT"));

	IconPanel = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_OWNERDRAW,
		0, IconPanelY, IconPanelWidth, IconPanelHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE),NULL);

	ProjectPanel = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_OWNERDRAW,
		0, ProjectPanelY, ProjectPanelWidth, ProjectPanelHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);

	Editor = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
		EditorX, EditorY, EditorWidth, EditorHeight, hwnd, NULL, NULL, NULL);
	SendMessage(Editor, WM_SETFONT, (WPARAM)EditorFont, MAKELPARAM(TRUE, 0));

	NewFileBtn = CreateWindowEx(0, L"BUTTON", L"2", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
		NewFileBtnX, IconBtnsY, IconBtnsWidth, IconBtnsHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE), NULL);
	SendMessage(NewFileBtn, WM_SETFONT, (WPARAM)NewFileBtnFont, MAKELPARAM(TRUE, 0));

	OpenFileBtn = CreateWindowEx(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
		OpenFileBtnX, IconBtnsY, IconBtnsWidth, IconBtnsHeight, hwnd, (HMENU)OpenFileBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);

	SaveFileBtn = CreateWindowEx(0, L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
		SaveFileBtnX, IconBtnsY, IconBtnsWidth, IconBtnsHeight, hwnd, (HMENU)SaveFileBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);

	BoldFontBtn = CreateWindowEx(0, L"BUTTON", L"B", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
		BoldFontBtnX, IconBtnsY, IconBtnsWidth, IconBtnsHeight, hwnd, (HMENU)BoldFontBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(BoldFontBtn, WM_SETFONT, (WPARAM)BoldFontBtnFont, MAKELPARAM(TRUE, 0));

	UnderlineFontBtn = CreateWindowEx(0, L"BUTTON", L"U", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
		UnderlineFontBtnX, IconBtnsY, IconBtnsWidth, IconBtnsHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(UnderlineFontBtn, WM_SETFONT, (WPARAM)UnderlineFontBtnFont, MAKELPARAM(TRUE, 0));

	ItalizeFontBtn = CreateWindowEx(0, L"BUTTON", L"I", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
		ItalizeFontBtnX, IconBtnsY, IconBtnsWidth, IconBtnsHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
	SendMessage(ItalizeFontBtn, WM_SETFONT, (WPARAM)ItalizeFontBtnFont, MAKELPARAM(TRUE, 0));
}

void App::CreateProjectsSection(HWND hwnd)
{
	ProjectSectionActive = true;
	EditorSectionActive = false;
	HomeSectionActive = false;

	int AllProjectsStaticX = 0, AllProjectsStaticY = (18 * HEIGHT) / 100;
	int AllProjectsPanelX = 0, AllProjectsPanelY = (26 * HEIGHT) / 100;

	AllProjectsStatic = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_OWNERDRAW, AllProjectsStaticX, AllProjectsStaticY,
		AllProjectsStaticWidth, AllProjectsStaticHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE), NULL);

	AllProjectsPanel = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_OWNERDRAW, AllProjectsPanelX, AllProjectsPanelY,
		AllProjectsPanelWidth, AllProjectsPanelHeight, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE), NULL);

	DeleteButton = CreateWindowEx(0, L"BUTTON", L"+", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, 0, 0,
		0, 0, hwnd, (HMENU)DeleteBtnPushed, (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE), NULL);
}
