#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "DBRunner.h"
#include "DB.h"

using namespace std;

// https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
vector<string> split(const char *str, char c = ' ')
{
	vector<string> result;

	do
	{
		const char *begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(string(begin, str));
	} while (0 != *str++);

	return result;
}

void DBRunner::RunCommands(std::istream& input, std::ostream & output)
{
	stack<DB> dbs;
	
	dbs.push(DB());

	for (std::string line; std::getline(input, line);)
	{
		DB& db = dbs.top();

		vector<string> tokens = split(line.c_str(), ' ');

		if (tokens.size() == 0)
		{
			continue;
		}
		
		const string& command = tokens[0];
		if (command == "SET")
		{
			db.Set(tokens[1], tokens[2]);
		}
		else if (command == "GET")
		{
			const string* v = db.Get(tokens[1]);
			if (v)
			{
				output << *v << endl;
			}
			else
			{
				output << "NULL" << endl;
			}
		}
		else if (command == "UNSET")
		{
			db.Unset(tokens[1]);
		}
		else if (command == "NUMWITHVALUE")
		{
			output << db.NumWithValue(tokens[1]) << endl;
		}
		else if (command == "END")
		{
			return;
		}
		else if (command == "BEGIN")
		{
			dbs.push(db);
		}
		else if (command == "ROLLBACK")
		{
			if (dbs.size() == 1)
			{
				output << "NO TRANSACTION" << endl;
			}
			else
			{
				dbs.pop();
			}
		}
		else if (command == "COMMIT")
		{
			if (dbs.size() == 1)
			{
				output << "NO TRANSACTION" << endl;
			}
			else
			{
				DB good(dbs.top());

				while (!dbs.empty())
				{
					dbs.pop();
				}

				dbs.push(good);
			}
		}
	}
}
