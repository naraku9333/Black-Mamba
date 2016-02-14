#include <FruitFactory.hpp>

namespace snake
{
	FruitFactory::FruitFactory() :
		apple("apple", 10, Resource<sf::Texture>::get("data/apple.png")),
		cherry("cherry", 25, Resource<sf::Texture>::get("data/cherry.png")),
		gold_apple("gold apple", 100, Resource<sf::Texture>::get("data/gold_apple.png")),
		dist_x(1, 1000 - 16), dist_y(30, 800 - 16)
	{

	}

	std::vector<Fruit> FruitFactory::get(std::uint32_t nfruits)
	{
		static std::mt19937 rng{ std::random_device()() };

		//std::size_t nfruits = (level < 4) ? level : level / 2;
		std::vector<Fruit> fruits(nfruits, apple);

		if (nfruits % 3 == 0) fruits.emplace_back(gold_apple);
		for (std::size_t i = 0; i < fruits.size(); ++i)
			fruits[i].setPosition(dist_x(rng), dist_y(rng));

		return fruits;
	}
}
