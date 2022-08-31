#include <iostream>
#include <vector>

using namespace std;

struct wirnik {

	int indeks;
	bool ifNotch = true;
	int obroty = 0;
	int poz = 0;
	vector<int> wsp;
	vector<int> powrot;
	vector<int> notch;
};

struct reflektor {

	int indeks;
	vector<int> wsp;
};

long int potega(long int podstawa, int wykladnik)
{
	int wynik = 1;

	for (int i = 0; i < wykladnik; i++)
		wynik *= podstawa;

	return wynik;
}

int getint()
{
	vector<int> liczba;
	char temp;
	int wynik = 0;

	temp = getchar();
	while (temp != ' ' && temp != '\n')
	{
		liczba.push_back(temp - '0');
		temp = getchar();
	}

	for (int i = 0; i < liczba.size(); i++)
	{
		wynik += liczba[i] * potega(10, liczba.size() - i - 1);
	}


	return wynik;
}

void check_notch(vector<wirnik>& wybraneWir, int n, int ileW)
{
	int ileNotch = 0;
	bool step = false;
	int przed = 0;
	/*
	if (wczes)
	{
		wybraneWir[1].obroty++;

		ileNotch = wybraneWir[1].notch.size();
		if (ileW > 2 && wybraneWir[1].ifNotch == true)
		{
			for (int i = 0; i < ileNotch; i++)
			{
				if (wybraneWir[1].notch[i] == ((n + wybraneWir[1].obroty + wybraneWir[0].poz) % n) + 1)
				{
					wybraneWir[2].obroty++;
					doubleStep = true;
					break;
					//sprawdzam czy 2 na notchu
				}
			}
		}
	}
	*/

	ileNotch = wybraneWir[1].notch.size();
	if (ileW > 2 && wybraneWir[1].ifNotch == true && wybraneWir[1].obroty > 0)
	{
		for (int i = 0; i < ileNotch; i++)
		{
			if (((wybraneWir[1].notch[i] - 1) % n) == 0) 
			{
				przed = n;
			}
			else 
			{
				przed = (wybraneWir[1].notch[i] - 1) % n;
			}
			if (przed == ((wybraneWir[1].obroty + wybraneWir[1].poz) % n) + 1)
			{
				step = true;
				break;
				//sprawdzam czy 2 stoi przed notchem 
			}
		}
	}

	if (step != true)
	{
		ileNotch = 0;
		ileNotch = wybraneWir[0].notch.size();

		for (int i = 0; i < ileNotch; i++)
		{
			if (wybraneWir[0].notch[i] == ((wybraneWir[0].obroty + wybraneWir[0].poz) % n) + 1)
			{
				// obrocenie 2 wirnika

				wybraneWir[1].obroty++;
				break;
				// koniec obrotu
			}
		}
	}
	else
	{
		// obrocenie 2,3 wirnika

		wybraneWir[2].obroty++;
		wybraneWir[1].obroty++;

		// obrocenie 2,3 wirnika
	}
}

int main()
{
	int n = 0, maxWir = 0, maxRef;
	int temp, li;
	vector<wirnik> wskazniki;
	vector<reflektor> wskaznikiRef;
	//vector<int> tym;

	// wirniki
	scanf_s("%d", &n);
	scanf_s("%d", &maxWir);
	//cout << n;
	//cout << maxWir;

	for (int i = 0; i < maxWir; i++)
	{
		wirnik tmp;

		/*
		for (int j = 1; j <= temp * 2 + 1; j++)
		{
			cin >> li;
			tmp.wsp.push_back(li - j);
		}
		*/
		/*
		p = 1;
		while (temp != '\n')
		{
			while (temp != ' ')
			{
				tmp.wsp.push_back(temp - p);
				temp = getchar();
			}
			p++;

			if (temp != '\n')
				temp = getchar() - '0';
		}
		*/
		for (int j = 1; j <= n; j++)
		{
			scanf_s("%d", &temp);
			tmp.wsp.push_back(temp - j);
		}

		//powrot

		for (int k = 1; k <= n; k++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j + tmp.wsp[j - 1] == k)
				{
					temp = -tmp.wsp[j - 1];
					tmp.powrot.push_back(temp);
				}
			}
		}

		//powrot

		// notch

		scanf_s("%d", &temp);

		if (temp == 0)
		{
			tmp.ifNotch = false;
		}

		/*
		while (temp != '\n')
		{
			if (temp != ' ')
			{
				tmp.notch.push_back(temp);
				temp = getchar();
			}

			if (temp != '\n')
				temp = getchar() - '0';
		}
		*/

		for (int j = 0; j < temp; j++)
		{
			scanf_s("%d", &li);
			/*
			if (li == 1)
			{
				li = 5;
			}
			*/
			tmp.notch.push_back(li);
		}

		// notch

		tmp.indeks = i;

		wskazniki.push_back(tmp);

	}
	/*
	for (int i = 0; i < maxWir; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<wskazniki[i].wsp[j];
		}
		cout << endl;
	}
	*/

	// wirniki


	// reflektory

	scanf_s("%d", &maxRef);

	for (int i = 0; i < maxRef; i++)
	{
		reflektor tempo;

		for (int j = 1; j <= n; j++)
		{
			//temp = getint();
			scanf_s("%d", &temp);
			tempo.wsp.push_back(temp);
		}

		tempo.indeks = i;

		wskaznikiRef.push_back(tempo);
	}

	/*
	for (int i = 0; i < maxRef; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << wskaznikiRef[i].wsp[j];
		}
	}
	*/

	//reflektory


	// zadania

	bool doubleStep = false;
	int ileZadan, ileW, indeksW, poz, pozW, indeksR, m, ileKod, koniec, prev, wyjscie;
	vector<int> kodIn;
	vector<int> kodOut;
	vector<wirnik> wybraneWir;
	//int pierwszyEl[2];


	scanf_s("%d", &ileZadan);

	for (int i = 0; i < ileZadan; i++)
	{
		//wczytywanie ustawien wirnik/reflektor

		scanf_s("%d", &ileW);

		for (int i = 0; i < ileW; i++)
		{
			scanf_s("%d", &indeksW);
			scanf_s("%d", &poz);

			// pierwszy wirnik

			if (i == 0)
			{
				pozW = poz % n;

				//pierwszyEl[0] = pozW + 1;
			}

			// pierwszy wirnik

			// drugi wirnik

			else if (i == 1)
			{
				pozW = poz - 1;

				//pierwszyEl[1] = pozW + 1;
			}

			// drugi wirnik

			// jesli nie jest to pierwszy wirnik

			else
			{
				pozW = poz - 1;
			}

			// jesli nie jest to pierwszy wirnik

			wybraneWir.push_back(wskazniki[indeksW]);

			m = wybraneWir.size();
			wybraneWir[m - 1].poz = pozW;
			if (pozW != 0)
			{
				for (int i = 0; i < n; i++)
				{
					wybraneWir[m - 1].wsp[i] = wskazniki[indeksW].wsp[(i + pozW) % n];
					wybraneWir[m - 1].powrot[i] = wskazniki[indeksW].powrot[(i + pozW) % n];
				}
			}

		}

		//indeksR = getint();
		scanf_s("%d", &indeksR);

		// koniec wczytywania

		// wypiswanie wyrnik/reflektor 
		/*
		for (int i = 0; i < ileW; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << wybraneWir[i].wsp[j];
				cout << ' ';
			}
			cout << endl;
		}

		for (int i = 0; i < n; i++)
		{
			cout << wskaznikiRef[indeksR].wsp[i];
			cout << ' ';
		}
		*/
		// wypisywania


		// wpisywanie kodu do zakodowania

		scanf_s("%d", &temp);
		while (temp != 0)
		{
			kodIn.push_back(temp);
			//temp = getint();
			scanf_s("%d", &temp);
		}

		// koniec wpisywania kodu do zakodowania

		// wypis zakodowany kod

		ileKod = kodIn.size();
		for (int i = 0; i < ileKod; i++)
		{
			koniec = kodIn[i];

			for (int j = 0; j < ileW; j++)  // kierunek -> reflektor
			{
				pozW = wybraneWir[j].obroty;

				koniec = koniec + wybraneWir[j].wsp[(pozW + koniec - 1) % n];

				if (koniec <= 0)
				{
					koniec = n + koniec;
				}
				if (koniec >= n + 1)
				{
					koniec = koniec - n;
				}
			}

			koniec = wskaznikiRef[indeksR].wsp[koniec - 1]; //reflektor

			for (int j = ileW - 1; j >= 0; j--) // kierunek <- reflektor
			{
				/*
				for (int k = 1; k < n + 1; k++)
				{
					pozW = wybraneWir[j].obroty;

					wyjscie = k + wybraneWir[j].wsp[(pozW + k - 1) % n];

					if (wyjscie <= 0)
					{
						wyjscie = n + wyjscie;
					}
					if (wyjscie >= n + 1)
					{
						wyjscie = wyjscie - n;
					}

					if (wyjscie == koniec)
					{
						koniec = k;
						break;
					}
				}
				*/
				pozW = wybraneWir[j].obroty;

				koniec = koniec + wybraneWir[j].powrot[(pozW + koniec - 1) % n];

				if (koniec <= 0)
				{
					koniec = n + koniec;
				}
				if (koniec >= n + 1)
				{
					koniec = koniec - n;
				}

			}

			kodOut.push_back(koniec); // zakodowanie liczby

			// obrocenie 1 wirnika

			/*
			if (doubleStep)
			{
				wybraneWir[0].obroty++;
				//pierwszyEl[0]++;

				wybraneWir[1].obroty++;
				//pierwszyEl[1]++;

				doubleStep = false;
			}
			else
			{
				wybraneWir[0].obroty++;
				//pierwszyEl[0]++;
			}
			*/

			wybraneWir[0].obroty++;

			// obrocenie 1 wirnika

			// sprawdzam notch 1,2 wirnik

			if (ileW > 1 && wybraneWir[0].ifNotch == true)
			{
				check_notch(wybraneWir, n, ileW);
			}

			// sprawdzam notch 1,2 wirnik
		}
		for (int i = 0; i < ileKod; i++)
		{
			//cout << kodOut[i] << ' ';
			printf("%d", kodOut[i]);
			printf(" ");
		}
		//cout << endl;
		printf("\n");

		// wypis zakodowany kod


		// czyszcze wektory
		wybraneWir.clear();
		kodIn.clear();
		kodOut.clear();
		// czyszcze wektory
	}

	return 0;
}