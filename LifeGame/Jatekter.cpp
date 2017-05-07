#include "Jatekter.h"
#include <fstream>

namespace std
{
	std::Jatekter::Jatekter()
	{
	}


	std::Jatekter::Jatekter(int mode)
	{
		this->mode = mode;
	}

	Jatekter::Jatekter(vector<double> my_matrix, int sor, int oszlop)
	{
		this->matrix = my_matrix;
		this->sor = sor;
		this->oszlop = oszlop;
	}

	Jatekter::~Jatekter()
	{
	}

	int Jatekter::countIfAlive(int kocka)
	{
		bool szelen_van = kocka % oszlop == 0 ? true : false;
		bool tetejen_van = kocka < oszlop ? true : false;
		bool aljan_van = kocka > (matrix.size() - oszlop) ? true : false;
		bool sarkon_van = szelen_van && (tetejen_van || aljan_van);
		int szomszedok_szama = 0;
		if (mode == NYILT_PEREMFELTETEL)
		{
			if (sarkon_van)
			{
				if (kocka == 0)
				{
					szomszedok_szama += matrix.at(kocka + 1);
					szomszedok_szama += matrix.at(oszlop + 1);
					szomszedok_szama += matrix.at(oszlop + 2);
				}
				else if (kocka == oszlop)
				{
					szomszedok_szama += matrix.at(oszlop - 1);
					szomszedok_szama += matrix.at(2 * oszlop);
					szomszedok_szama += matrix.at(2 * oszlop - 1);
				}
				else if (kocka == (matrix.size() - oszlop))
				{
					szomszedok_szama += matrix.at(matrix.size() - 2 * oszlop);
					szomszedok_szama += matrix.at(matrix.size() - 2 * oszlop + 1);
					szomszedok_szama += matrix.at(kocka + 1);
				}
				else if (kocka == matrix.size())
				{
					szomszedok_szama += matrix.at(kocka - 2 * oszlop);
					szomszedok_szama += matrix.at(kocka - 2 * oszlop - 1);
					szomszedok_szama += matrix.at(kocka - 1);
				}
			}
			else if (tetejen_van)
			{
				szomszedok_szama += matrix.at(kocka + 1);
				szomszedok_szama += matrix.at(kocka - 1);
				szomszedok_szama += matrix.at(kocka + oszlop);
				szomszedok_szama += matrix.at(kocka + oszlop - 1);
				szomszedok_szama += matrix.at(kocka + oszlop + 1);
			}
			else if (aljan_van)
			{
				szomszedok_szama += matrix.at(kocka + 1);
				szomszedok_szama += matrix.at(kocka - 1);
				szomszedok_szama += matrix.at(kocka - oszlop);
				szomszedok_szama += matrix.at(kocka - oszlop - 1);
				szomszedok_szama += matrix.at(kocka - oszlop + 1);
			}
			else if (szelen_van)
			{
				szomszedok_szama += 3;
			}
			else
			{
				szomszedok_szama += 3;
			}
		}
		else if (mode == PERIODIKUS_PEREMFELTETEL)
		{

		}
		else if (mode == ELO_HATAR)
		{

		}
	}

	void std::Jatekter::leptess()
	{
		for (int i = 0; i < sor; ++i)
		{
			for (int j = 0; j < oszlop; ++j)
			{

			}
		}
	}

	void std::Jatekter::FilebaIras(string filename)
	{
		ofstream file(filename);
		for (unsigned int i = 0; i < this->matrix.size(); ++i)
		{
			file << matrix.at(i) << "\t";
			if (i == this->oszlop)
			{
				file << "\n";
			}
		}
		file.close();
	}
}

