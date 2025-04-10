#include "mktxt.h"
int main()
{
	std::string characters{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz" };
	std::random_device rd{};
	std::mt19937_64 rng{ rd() };
	std::uniform_int_distribution<int> name_length_dist{ 8, 16 };
	std::uniform_int_distribution<int> name_dist{ 0, static_cast<int>(characters.size()) - 1 };
	std::string text_file_name(name_length_dist(rng), '?');
	for (char& c : text_file_name)
	{
		c = characters[name_dist(rng)];
	}
	std::ofstream text_file{ text_file_name + ".txt" };
	if (text_file.is_open())
		text_file.close();
	return 0;
}
