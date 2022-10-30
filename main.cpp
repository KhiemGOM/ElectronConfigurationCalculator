#include <bits/stdc++.h>

using namespace std;

enum sub_shell
{
	s, p, d, f
};

class orbital
{
public:
	int energy_level, e = 0;
	sub_shell sub;

	[[nodiscard]] int max_electron() const
	{
		if (sub == s)
		{
			return 2;
		}
		if (sub == p)
		{
			return 6;
		}
		if (sub == d)
		{
			return 10;
		}
		if (sub == f)
		{
			return 14;
		}
		return 0;
	}

	orbital(int e, sub_shell s) : energy_level(e), sub(s)
	{};

	orbital(int e, sub_shell s, int elec) : energy_level(e), sub(s), e(elec)
	{};

	bool operator<(orbital other) const
	{
		if (energy_level != other.energy_level)
		{
			return energy_level < other.energy_level;
		}
		return sub < other.sub;
	}
};

int main()
{
	orbital order[24] {orbital(1, s), orbital(2, s), orbital(2, p), orbital(3, s), orbital(3, p), orbital(4, s),
	                   orbital(3, d), orbital(4, p), orbital(5, s), orbital(4, d), orbital(5, p), orbital(6, s),
	                   orbital(4, f), orbital(5, d), orbital(6, p), orbital(7, s), orbital(5, f), orbital(6, d),
	                   orbital(7, p), orbital(8, s), orbital(6, f), orbital(7, d), orbital(8, p), orbital(9, s)};
	string ssorder = "spdf";
	while (true)
	{
		set<orbital> r;
		int a;
		cin >> a;
		if (a == 0)
		{
			return 0;
		}
		for (auto &s: order)
		{
			if (a > s.max_electron())
			{
				a -= s.max_electron();
				s.e = s.max_electron();
				r.insert(s);
			}
			else
			{
				s.e = a;
				a = 0;
				r.insert(s);
				break;
			}
		}
		for (auto &s: r)
		{
			cout << s.energy_level << ssorder[s.sub] << s.e  << ": ";
			for (int i = 1; i <= s.max_electron() / 2; i++)
			{
				if (s.e >= i)
				{
					cout << "^";
					if (s.e >= i + s.max_electron() / 2)
					{
						cout << "v";
					}
					else
					{
						cout << " ";
					}
					cout << " ";
				}
				else
				{
					break;
				}
			}
			cout << endl;
		}
		if (a > 0)
		{
			cout << "More...\n";
		}
	}
}