#include <BodyPart.hpp>

namespace snake
{
	BodyPart::BodyPart(sf::Texture& t, Dir d) : direction(d)
	{
		setTexture(t);
		setOrigin(8, 12);
	}
	void BodyPart::move()
	{
		Sprite::move(offsets[direction]);
	}
}
