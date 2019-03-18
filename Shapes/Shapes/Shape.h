#pragma once

class Shape
{
public:
	Shape();
	~Shape();

	virtual void Draw(int width, int height);

	virtual void Draw(int height);

private:
	int width;
	int height;
};

