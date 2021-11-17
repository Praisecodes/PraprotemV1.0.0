#pragma once
#include <Windows.h>

constexpr auto Close = 1;
constexpr auto Minimize = 2;
constexpr auto Leave = 3;
constexpr auto EditorBtnPushed = 4;
constexpr auto ProjectsBtnPushed = 5;
constexpr auto ReturnBtnPushed = 6;
constexpr auto NewFileBtnPushed = 7;
constexpr auto OpenFileBtnPushed = 8;
constexpr auto SaveFileBtnPushed = 9;
constexpr auto BoldFontBtnPushed = 10;
constexpr auto UnderlineFontBtnPushed = 11;
constexpr auto ItalizeFontBtnPushed = 12;

class Window
{
public:
	HWND Header, Icon, LogoBg, Identifier, MinimizeBtn, CloseBtn, MainWindow,
		ReturnBtn, EditorBtn, ProjectsBtn, LeaveBtn, MidProjectBtn, MidEditorBtn, MidLeaveBtn, LogoLeftHand, LogoRightHand,
		Logo, AboutBtn;

	//Window Handlers for the Editor Section
	HWND IconPanel, ProjectPanel, Editor, NewFileBtn, OpenFileBtn, SaveFileBtn, BoldFontBtn, UnderlineFontBtn,
		ItalizeFontBtn;

	//BitMap handlers for icons display
	HBITMAP icon_picture, icon_saveFile, icon_openFile;

	//App will be fullscreen by default
	int HEIGHT = GetSystemMetrics(SM_CYSCREEN);
	int WIDTH = GetSystemMetrics(SM_CXSCREEN);

	//Calculations for perfect placement
	int SideBtnsHeight = (12 * HEIGHT) / 100, SideBtnsWidth = (7 * WIDTH) / 100;
	int SideBtnsX = ((93 * WIDTH) / 100);
	int MidBtnHeight = (15 * HEIGHT) / 100, MidBtnWidth = (20 * WIDTH) / 100, MidProjectBtnX = (40 * WIDTH) / 100;
	int HeaderHeight = (18 * HEIGHT) / 100; int HeaderWidth = WIDTH;
	int IconHeight = (40 * HeaderHeight) / 100; int IconWidth = IconHeight;
	int IdentifierHeight = (20 * HeaderHeight) / 100, IdentifierWidth = (15 * HeaderWidth) / 100;
	int LogoBgHeight = (70 * HeaderHeight) / 100; int LogoBgWidth = (50 * HeaderWidth) / 100;
	int LogoLeftHandHeight = (70 * HeaderHeight) / 100, LogoLeftHandWidth = (16 * LogoBgWidth) / 100;
	int LogoHeight = (70 * HeaderHeight) / 100, LogoWidth = (68 * LogoBgWidth) / 100;
	int LogoRightHandHeight = (70 * HeaderHeight) / 100, LogoRightHandWidth = (16 * LogoBgWidth) / 100;
	int IconPanelHeight = (8 * HEIGHT) / 100, IconPanelWidth = WIDTH;
	int ProjectPanelHeight = (74 * HEIGHT) / 100, ProjectPanelWidth = (20 * WIDTH) / 100;
	int EditorHeight = (74 * HEIGHT) / 100, EditorWidth = (72 * WIDTH) / 100;
	int MinimizeBtnHeight = (30 * HeaderHeight) / 100, MinimizeBtnWidth = MinimizeBtnHeight;
	int CloseBtnHeight = MinimizeBtnHeight, CloseBtnWidth = CloseBtnHeight;
	int AboutBtnHeight = (8 * HEIGHT) / 100, AboutBtnWidth = SideBtnsWidth;
	int IconBtnsWidth = (5 * WIDTH) / 100, IconBtnsHeight = (8 * HEIGHT) / 100;

	//Window Class methods
	bool Create();
	bool isRunning();
	bool Show();
	bool Endprocess();
	void DestroyHomeControls(HWND, HWND, HWND);
	void DestroyProjectControls(HWND, HWND, HWND, HWND);
	void DestroyEditorControls(HWND, HWND, HWND, HWND, HWND, HWND, HWND, HWND, HWND);

	//Inheritable method (pure virtual functions)
	virtual void Update(HWND) = 0;
	virtual void BitmapCreate() = 0;
	virtual void ShowEditorSection(HWND) = 0;
	virtual void CreateHomeSection(HWND) = 0;
	virtual void CreateProjectsSection(HWND) = 0;

	//Checking which part is open
	bool EditorSectionActive = false, HomeSectionActive = false, ProjectSectionActive = false;

	bool Bold = false;

protected:
	bool IsRunning;
	
};
