#include <SFML/Graphics.hpp>
#include <Snake.hpp>
#include <FruitFactory.hpp>

bool check_collision(const snake::Snake& s, const snake::Fruit& f);
bool off_board(const snake::Snake& s, const sf::RenderWindow& w);

int main()
{
	using namespace snake;

	Snake snake;
	auto score = 0u;
	auto level = 1u;
	auto lives = 3;

	sf::RenderWindow window{ {1000, 800}, "Black Mamba!" };
	window.setFramerateLimit(10);

	auto background = sf::Color{ 0, 128, 0 };
	FruitFactory f;
	auto fruits = f.get(level);

	sf::Font font;
	font.loadFromFile("data/Sansation.ttf");

	sf::Text end_msg("                Game Over!                \nPress esc to quit, p to replay", font, 50);
	end_msg.setPosition(500 - end_msg.getLocalBounds().width / 2, 400 - end_msg.getLocalBounds().height / 2);

	while (window.isOpen())
	{
		sf::Event event;
		Dir snake_direction = Dir::N;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Left)
				{
					snake.turn(Dir::W);
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					snake.turn(Dir::E);
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					snake.turn(Dir::N);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					snake.turn(Dir::S);
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				if (event.key.code == sf::Keyboard::P)
				{
					if (lives <= 0)
					{
						lives = 3;
						score = 0;
						level = 1;
						snake.set_rand_position();
						fruits.clear();
					}
				}
			}
		}

		if (fruits.empty()) fruits = f.get(++level);
		window.clear(background);
		window.draw(sf::Text("Score: " + std::to_string(score), font));
		snake.move();
		if (off_board(snake, window))
		{
			if (--lives > 0)
			{
				snake.set_rand_position();
			}
			else
			{				
				window.draw(end_msg);
			}
		}

		for (auto it = fruits.begin(); it != fruits.end(); )
		{
			if (check_collision(snake, *it))
			{
				score += it->value;
				it = fruits.erase(it);
			}
			else
			{
				window.draw(*it);
				++it;
			}
		}
		window.draw(snake);
		window.display();		
	}
}

bool off_board(const snake::Snake& s, const sf::RenderWindow& w)
{
	if (s.getGlobalBounds().top < 30 || s.getGlobalBounds().left < 0 || 
		s.getGlobalBounds().left + 16 > 1000 || s.getGlobalBounds().top + 16 > 800)
		return true;
	return false;
}

bool check_collision(const snake::Snake& s, const snake::Fruit& f)
{
	if (s.getGlobalBounds().intersects(f.getGlobalBounds()))
		return true;
	return false;
}
