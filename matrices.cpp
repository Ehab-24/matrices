#include<iostream>
#include<fstream>

using namespace std;



void Options_List() {

	cout << "1. Merge two arrays.\n"
		<< "2. Order of the array.\n"
		<< "3. Transpose of Matrix.\n\n"
		<< char(26) << " Select an option";
}


//QUESTION # 2:-
void Load(ifstream& fin, int*& arr) {

	int x;
	fin >> x;
	arr = new int[x + 1];
	arr[0] = x;
	for (int i = 1; i <= arr[0]; i++)
		fin >> arr[i];
}

int* Merge(const int* const& arr1, const int* const& arr2) {
	int j = 1, k = 1, * arr3 = new int[arr1[0] + arr2[0] + 1];
	arr3[0] = arr1[0] + arr2[0];

	for (int i = 1; i <= arr3[0]; i++) {
		if (arr1[j] > arr2[k]) {
			arr3[i] = arr1[j];
			j++;
		}
		else {
			arr3[i] = arr2[k];
			k++;
		}
	}
	return arr3;
}

void Display(const int* const& arr) {

	for (int i = 1; i <= arr[0]; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void main1(char* FileName) {

	ifstream fin(FileName);
	int* arr1 = nullptr, * arr2 = nullptr, * arr3 = nullptr;

	Load(fin, arr1);
	Load(fin, arr2);

	arr3 = Merge(arr1, arr2);

	Display(arr3);
}




//QUESTION # 3:-
void copy(int* a, int* b) {
	for (int i = 1; i <= b[0]; i++)
		a[i] = b[i];
}

void IncreaseSize(int*& arr, int& size, int val) {

	int* HA = new int[size + 1];
	HA[0] = size;
	copy(HA, arr);
	HA[size] = val;
	delete[] arr;
	arr = HA;
	size++;
}

void Input(ifstream& fin, int*& arr) {

	int size = 1, val;
	arr = new int[size];
	fin >> val;
	while (val != -1) {
		arr[0] = size;
		IncreaseSize(arr, size, val);
		fin >> val;
	}
}

const char* IsSorted(const int* const& arr) {
	bool asc = true, dsc = true;

	for (int i = 1; i + 1 <= arr[0]; i++) {
		if (asc && arr[i] > arr[i + 1])
			asc = false;
		else if (arr[i] < arr[i + 1])
			dsc = false;

		if (!asc && !dsc)
			return "Not Sorted";
	}
	if (asc)
		return "Ascending";
	if (dsc)
		return "Descending";
}

void Display(const char* const& arr) {

	for (int i = 0; arr[i] != '\0'; i++)
		cout << arr[i];
	cout << endl;
}

void main2(char* FileName) {

	ifstream fin(FileName);
	int* arr = nullptr;
	const char* rslt;

	Input(fin, arr);

	rslt = IsSorted(arr);

	Display(rslt);
}


//QUESTION # 4:-
void Init(int**& Mat, int& rows, int& cols, const char* filename) {
	ifstream fin(filename);
	fin >> rows >> cols;
	Mat = new int* [rows];

	for (int i = 0; i < rows; i++) {

		Mat[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			fin >> Mat[i][j];
	}
}

void SelfTranspose(int**& M, int& rows, int& cols) {

	swap(rows, cols);
	int** TM = new int* [rows];

	for (int i = 0; i < rows; i++) {

		TM[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			TM[i][j] = M[j][i];
	}

	delete[]M;
	M = TM;
}

void Display(int** const M, const int rows, const int cols) {
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << M[i][j] << ' ';

		cout << endl;
	}
}

void main3(char* FileName) {

	int** Matrix = nullptr, Rows = 0, Cols = 0;
	char c = 26;

	Init(Matrix, Rows, Cols, FileName);

	cout << '\n' << c << " Matrix After Reading from File and before Transpose...\n";
	Display(Matrix, Rows, Cols);

	SelfTranspose(Matrix, Rows, Cols);

	cout << '\n' << c <<" Matrix After Transpose...\n";
	Display(Matrix, Rows, Cols);
}



int main() {

	int option;

	char FileName[100];
	cout << "Enter the text file Name: ";
	cin >> FileName;
	cout << '\n';

	Options_List();
	
	do {
		cin >> option;
		switch (option) {
			
		case 1:
			main1(FileName);
			return 0;

		case 2:
			main2(FileName);
			return 0;

		case 3:
			main3(FileName);
			return 0;
		
		default:
			if(option != 0)
				cout << "Pyare Madni Bhai, ENTER AGAIN!!!\n\n";
		}
	} while (option < 1 || option > 3);
}