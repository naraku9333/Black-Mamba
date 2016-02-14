#pragma once
#include <vector>
#include <Resource.hpp>
#include <SFML/Graphics.hpp>
#include <BodyPart.hpp>
#include <map>
#include <random>

namespace snake
{		
	class Snake final : public virtual sf::Drawable
	{
		std::vector<BodyPart> body;
		BodyPart head;
		sf::Vector2f position;
		const sf::Vector2f offset{ 0, 16 };

	public:
		Snake();

		void turn(Dir d);

		void move();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::FloatRect getGlobalBounds() const;

		void set_rand_position();
	};
}
