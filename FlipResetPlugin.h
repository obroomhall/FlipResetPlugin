#pragma once
#pragma comment(lib, "pluginsdk.lib")
#include "bakkesmod/plugin/bakkesmodplugin.h"

class FlipResetPlugin : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	bool hasFlip;
	virtual void onLoad();
	virtual void onUnload();
	void onWheelContact();
	void render(CanvasWrapper canvas);
};
