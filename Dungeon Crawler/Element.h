#pragma once

class Element
{
public:

	Element() {}

	Element(int w_, int h_) : w(w_), h(h_)
	{ 
		angle = 0;
	}

	Element(int w_, int h_, double angle_) : w(w_), h(h_), angle(angle_)
	{ }

	int w, h;
	double angle;

	virtual void draw(int x, int y) = 0;
};