#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace snake
{
	class Fruit : public sf::Sprite
	{
	public:
		std::string type;
		int value;
		Fruit(std::string s, int v, sf::Texture& t) : sf::Sprite(t), type(s), value(v)
		{

		}
	};
}
