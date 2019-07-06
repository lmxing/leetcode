
#include "../my_include.h"
#include "../my_util.h"

vector<string> split_str(string str, char split)
{
	vector<string> result;
	int left = 0;
	int right = str.length() - 1;
	while(left <= right && str[left] == split) left++;
	while(left <= right) {
		int tmp = left;
		while(left <= right && str[left] != split) left++;
		result.push_back(str.substr(tmp, left - tmp));
		while(left <= right && str[left] == split) left++;
	}
	print(result);
	return result;
}

void wordPattern(string str, string pattern)
{
	vector<string> str_split = split_str(str, ',');
	unordered_map<char, string> map;
	if (str_split.size() != pattern.length()) {
		std::cout << "not pattern" << std::endl;
		return;
	}
	for(int i =0; i < pattern.length(); ++i) {
		auto iter = map.find(pattern[i]);
		if (iter == map.end()) {
			map[pattern[i]] = str_split[i];
		} else if (iter->second != str_split[i]) {
			std::cout << "not pattern" << std::endl;
			return;
		}
	}
	print<char, string>(map);
	std::cout << "ok" << std::endl;
}
int main()
{
	string str;
	string pattern;
	cin >> str;
	cin >> pattern;
	wordPattern(str, pattern);
	return 1;
}
