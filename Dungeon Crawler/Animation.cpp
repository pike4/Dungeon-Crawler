#include "Animation.h"
#include "Graphics.h"

Animation::Animation(int w_, int h_, int speed_) : Element(w_, h_)
{
	speed = speed_;
	angle = 0;
}

void Animation::draw(int x, int y)
{
	Graphics::applyTexture(x, y, w, h, angle, frames[frameIndex]);

	if (frameTimer.hasElapsed(speed))
	{
		frameTimer.updateTime();
		frameIndex = (frameIndex + 1) % frames.size();
	}
}