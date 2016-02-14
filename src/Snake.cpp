#include <Snake.hpp>

namespace snake
{
	Snake::Snake() : head(Resource<sf::Texture>::get("data/head.png"), Dir::N),
		body(5, { Resource<sf::Texture>::get("data/body_part.png"), Dir::N })
	{
		set_rand_position();
	}

	void Snake::turn(Dir d)
	{
		if (d != head.direction && d != -head.direction)
		{
			auto r = head.getRotation();
			if (head.direction == Dir::N && d == Dir::E ||
				head.direction == Dir::S && d == Dir::W ||
				head.direction == Dir::E && d == Dir::S ||
				head.direction == Dir::W && d == Dir::N)
				r += 90.f;
			else r += -90.f;
			head.setRotation(r);

			head.direction = d;
		}
	}

	void Snake::move()
	{
		head.move();
		for (auto& b : body) b.move();

		for (std::size_t i = body.size() - 1; i > 0; --i) body[i].direction = body[i - 1].direction;
		body[0].direction = head.direction;
	}

	void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		target.draw(head, states);

		for (auto& t : body)
		{
			target.draw(t, states);
		}
	}

	sf::FloatRect Snake::getGlobalBounds() const
	{
		return head.getGlobalBounds();
	}

	void Snake::set_rand_position()
	{
		static std::uniform_int_distribution<std::mt19937::result_type> dist_x(1, 1000 - 16), dist_y(30, 800 - 16);
		static std::mt19937 rng{ std::random_device()() };

		auto p = sf::Vector2f{ static_cast<float>(dist_x(rng)), static_cast<float>(dist_y(rng)) };
		head.setPosition(p);
		p += sf::Vector2f{ 0, 4 };
		head.direction = Dir::N;
		head.setRotation(0);

		for (auto& t : body)
		{
			t.direction = Dir::N;
			t.setPosition(p + offset);
			p = t.getPosition();
		}
	}
}
