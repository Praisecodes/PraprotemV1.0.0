#pragma once
#include "Window.h"

class App:public Window
{
public:
	virtual void Update(HWND) override;
	virtual void BitmapCreate() override;
	virtual void ShowEditorSection(HWND) override;
	virtual void CreateHomeSection(HWND) override;

	//App class methods
	void AppHeaderCreate(HWND);
	void SideButtonsCreate(HWND);

private:
};
