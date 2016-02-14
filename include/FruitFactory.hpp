#pragma once

#include <vector>
#include <Fruit.hpp>
#include <SFML/Graphics.hpp>
#include <Resource.hpp>
#include <random>
#include <utility>

namespace snake
{
	class FruitFactory
	{
		Fruit apple; //adds points
		Fruit cherry; //adds a body part and points
		Fruit gold_apple; //adds a life and points
		std::uniform_int_distribution<std::mt19937::result_type> dist_x, dist_y;

	public:
		FruitFactory();

		std::vector<Fruit> get(std::uint32_t nfruits);
	};
}
