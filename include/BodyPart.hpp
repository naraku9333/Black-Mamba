#pragma once
#include <SFML/Graphics.hpp>
#include <map>

namespace snake
{
	enum Dir { N = -1, S = 1, E = -2, W = 2 };
	static std::map<Dir, sf::Vector2f> offsets{
		{ Dir::N,{ 0, -16 } },{ Dir::S,{ 0, 16 } },
		{ Dir::E,{ 16, 0 } },{ Dir::W,{ -16, 0 } }
	};

	class BodyPart : public virtual sf::Sprite
	{
	public:
		Dir direction;

		BodyPart(sf::Texture& t, Dir d);

		void move();
	};
}
