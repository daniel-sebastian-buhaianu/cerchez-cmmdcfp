#include <iostream>
#define Dim 20
using namespace std;
typedef int Vector[Dim];
Vector DivA, DivB, OrdA, OrdB;
int CatiA, CatiB;
void Descompune(int, int &, Vector, Vector);
int Putere(int, int);
int cmmdc();
int main()
{
	int a, b;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	Descompune(a, CatiA, DivA, OrdA);
	Descompune(b, CatiB, DivB, OrdB);
	cout << "cmmdc(" << a << ", " << b << ") = " << cmmdc();
	return 0;
}
void Descompune(int x, int & nx, Vector DivX, Vector OrdX)
{
	int d = 2;
	nx = 0;
	while (d*d <= x)
	{
		if (!(x % d))
		{
			DivX[++nx] = d;
			while (!(x % d))
			{
				x /= d;
				OrdX[nx]++;
			}
		}
		d++;
	}
	if (x > 1)
	{
		DivX[++nx] = x;
		OrdX[nx] = 1;
	}
}
int Putere(int x, int y)
{
	int i, P = 1;
	for (i = 1; i <= y; i++)
	{
		P *= x;
	}
	return P;
}
int cmmdc()
{
	int i = 1, j = 1, c = 1;
	while((i <= CatiA) && (j <= CatiB))
	{
		if (DivA[i] == DivB[j])
		{
			c *= Putere(DivA[i], OrdA[i] < OrdB[j] ? OrdA[i] : OrdB[j]);
			i++, j++;
		}
		else if (DivA[i] < DivB[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return c;
}
