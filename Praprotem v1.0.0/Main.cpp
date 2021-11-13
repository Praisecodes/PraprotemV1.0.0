#include "App.h"


int WINAPI WinMain(_In_ HINSTANCE hinst, _In_opt_ HINSTANCE, _In_ LPSTR args, _In_ int nCmdShow)
{
	App app;

	app.Create();
	
	if (app.isRunning())
	{
		app.Show();
	}
	else {
		app.Endprocess();
	}

	return 0;
}
