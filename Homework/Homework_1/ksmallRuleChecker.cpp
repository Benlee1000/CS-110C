#ifndef KSMALL_RULE_CHECKER_CPP
#define KSMALL_RULE_CHECKER_CPP

#include <fstream>
#include <string>
#include <iostream>
#include "ksmallRuleChecker.hpp"

using namespace std;

#include <string>
using namespace std;

ksmallRuleChecker::ksmallRuleChecker() {
}

int ksmallRuleChecker::checkString(string fileName, string searchWord) {
	int lineCount = 0;
	ifstream file(fileName);
	if (!file.is_open())
	{
			cout << "Failed to open file!\n";
			return -1;
	}

	string fileLine;
	while (getline(file, fileLine))
	{
		lineCount++;
		if (fileLine.find(searchWord) != std::string::npos)
		{
				cout << fileLine << "\n";
				return lineCount;
		}
	}
	file.close();
	return -1;
}

#endif /* KSMALL_RULE_CHECKER_CPP */