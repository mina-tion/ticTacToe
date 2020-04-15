#pragma once
namespace Graphic
{
	enum class Color
	{
		Red,
		Green,
		Blue
	};

	void setBaseColors();
	void setTextColor(Color);
	void topBorder();
	void bottomBorder();
	void innerBorder();
	void verticalBorder();
};

