#include "stdafx.h"
#include "DB.h"

void DB::Set(const std::string & name, const std::string & value)
{
	map[name] = value;
}

const std::string * DB::Get(const std::string & name)
{
	auto it = map.find(name);

	if (it == map.end())
	{
		return nullptr;
	}
	else
	{
		return &(it->second);
	}
}

void DB::Unset(const std::string & name)
{
	map.erase(name);
}

size_t DB::NumWithValue(const std::string & value)
{
	size_t count = 0;

	for (const auto& pair : map)
	{
		if (pair.second == value)
		{
			count++;
		}
	}

	return count;
}

bool DB::operator==(const DB & other)
{
	return map == other.map;
}
