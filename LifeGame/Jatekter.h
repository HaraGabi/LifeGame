#pragma once

#include <string>
#include <vector>

#define NYILT_PEREMFELTETEL 0
#define PERIODIKUS_PEREMFELTETEL 1
#define ELO_HATAR 2

namespace std
{
	class Jatekter
	{
	public:
		Jatekter() = default;
		Jatekter(int mode);
		Jatekter(vector<double> my_matrix, int sor, int oszlop);
		~Jatekter();
		void leptess();
		void FilebaIras(string filename);
		int n = 3;
		int mode = NYILT_PEREMFELTETEL;
	private:
		vector<double> matrix;
		int sor = 3;
		int oszlop = 3;
		int countIfAlive(int kocka)
	};
}

