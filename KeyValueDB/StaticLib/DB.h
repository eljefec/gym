#pragma once

#include <string>
#include <unordered_map>

using namespace std;

class DB
{
public:
	void Set(const std::string& name, const std::string& value);

	const std::string* Get(const std::string& name);

	void Unset(const std::string& name);

	size_t NumWithValue(const std::string& value);

	bool operator==(const DB& other);

private:
	unordered_map<string, string> map;
};