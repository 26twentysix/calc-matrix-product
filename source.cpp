#include <iostream>
#include <iomanip>
using namespace std;

void MatrixProduct(double** a, double** b, size_t rowsA, size_t colsB, size_t colsA) {
	double** c;
	size_t i, j, k;
	c = new double* [rowsA];
	for (i = 0; i < rowsA; i++) {
		c[i] = new double[colsB];
		for (j = 0; j < colsB; j++) {
			c[i][j] = 0;
			for (k = 0; k < colsA; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	cout << "Матрица произведения" << endl;
	for (i = 0; i < rowsA; i++) {
		for (j = 0; j < colsB; j++) {
			cout << setw(5) << c[i][j];
		}
		cout << endl;
	}
}

int main() {
	size_t rowsA, rowsB, colsA, colsB, i, j;
	double** a, ** b;
	setlocale(0, "");
	cout << "Введите количество строк и столбцов первой матрицы: ";
	cin >> rowsA >> colsA;
	cout << "Введите количество строк и столбцов второй матрицы: ";
	cin >> rowsB >> colsB;
	if (colsA != rowsB) {
		cout << "Эти матрицы нельзя перемножать";
		return 0;
	}
	a = new double* [rowsA];
	cout << "Введите элементы первой матрицы" << endl;
	for (i = 0; i < rowsA; i++) {
		a[i] = new double[colsA];
		for (j = 0; j < colsA; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
	for (i = 0; i < rowsA; i++) {
		for (j = 0; j < colsA; j++) {
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
	b = new double* [rowsB];
	cout << "Введите элементы второй матрицы" << endl;
	for (i = 0; i < rowsB; i++) {
		b[i] = new double[colsB];
		for (j = 0; j < colsB; j++) {
			cout << "b[" << i << "][" << j << "]= ";
			cin >> b[i][j];
		}
	}
	for (i = 0; i < rowsB; i++) {
		for (j = 0; j < colsB; j++) {
			cout << setw(5) << b[i][j];
		}
		cout << endl;
	}
	MatrixProduct(a, b, rowsA, colsB, colsA);
	return 0;
}
