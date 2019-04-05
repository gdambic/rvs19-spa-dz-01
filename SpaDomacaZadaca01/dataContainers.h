#pragma once

struct position {
private:
	int x;
	int y;

public:
	position* get()
	{
		return this;
	}

	int get_x() 
	{
		return x;
	}

	int get_y()
	{
		return y;
	}

	void set(int valX, int valY) 
	{
		x = valX;
		y = valY;
	}

	void set_x(int val)
	{
		x = val;
	}

	void set_y(int val)
	{
		y = val;
	}
};
