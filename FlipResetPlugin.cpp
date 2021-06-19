#include "FlipResetPlugin.h"
#include "bakkesmod\wrappers\GameObject\CarComponent\CarComponentWrapper.h"
#include "bakkesmod\wrappers\GameObject\CarComponent\DoubleJumpComponentWrapper.h"
#include "bakkesmod\wrappers\GameObject\CarComponent\FlipCarComponentWrapper.h"

BAKKESMOD_PLUGIN(FlipResetPlugin, "Flip Reset Plugin", "0.1", PLUGINTYPE_FREEPLAY)

void FlipResetPlugin::onLoad()
{
	gameWrapper->HookEvent("Function TAGame.Vehicle_TA.GetNumWheelWorldContacts", [this](std::string eventName) {
		onWheelContact();
	});

	gameWrapper->RegisterDrawable(std::bind(&FlipResetPlugin::render, this, std::placeholders::_1));
}

void FlipResetPlugin::onUnload()
{

}

void FlipResetPlugin::onWheelContact()
{
	CarWrapper car = gameWrapper->GetLocalCar();

	hasFlip = car.HasFlip();
}

void FlipResetPlugin::render(CanvasWrapper canvas)
{
	if (!gameWrapper->IsInGame() || gameWrapper->IsPaused())
		return;
	
	Vector2 size = canvas.GetSize();

	Vector2 drawLoc = { size.X * 0.90, size.Y * 0.895 };

	canvas.SetPosition(drawLoc);
	canvas.SetColor(255, 255, 255, 255);

	if (hasFlip)
	{
		float scale = size.X / 853;
		canvas.DrawString("FLIP", scale, scale);
	}
}


