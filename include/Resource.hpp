#pragma once

#include <fstream>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

template <typename T>
class Resource
{	
public:
	static T& get(std::string name)
	{
		static std::map<std::string, T> resources;
		if (resources.find(name) == resources.end())
		{
			T t;
			t.loadFromFile(name);
			resources[name] = std::move(t);
		}
		return resources[name];
	}
};
