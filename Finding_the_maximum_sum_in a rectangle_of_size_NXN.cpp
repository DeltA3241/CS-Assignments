
#include <iostream>
#include <climits>
using namespace std;




bool check_pos (int arr[], int s) {

	for (int z = 0; z < s; ++z) {
		if (arr[z] > 0) {
			return false;
		}
	}

	return true;


}
int kadane(int arr[],int s) {
	int MAX = INT_MIN;

	int low = 0;
	int high = 0;
	int sum = 0;

	if (check_pos(arr, s)) {
		int maxi = arr[0];
		for (int z = 1; z < s; ++z) {
			if (arr[z] > maxi) {
				maxi = arr[z];
			}
		}
		return maxi;
	}

	for (int n = 0; n < s; ++n) {
		if (sum == 0) {
			low = n;
		}
		sum = sum + arr[n];
		if (MAX < sum) {
			MAX = sum;
			high = n;
		}
		if (sum <
			0) {
			sum = 0;
		}



	}


	return MAX;




}

int max_sum_rectangle(int** arr, int columns, int rows) {
	int left=0;
	int right=0;
	int sum=0;
	int MAX2 = INT_MIN;
	for (left = 0; left < columns; ++left) {

		int* temp = new int[columns];
		for (int s = 0; s < columns; ++s) {
			temp[s] = 0;
		}

		for (right = left; right < columns; ++right) {

			for (int u = 0; u < columns; ++u) {
				temp[u] = arr[u][right] + temp[u];
			}
			sum = kadane(temp, columns);

			if (MAX2 < sum) {
				MAX2 = sum;
			}

		}
	}
	return MAX2;
}

void print(int** arr, int s) {
	for (int z = 0; z < s; ++z) {
		for (int i = 0; i < s; ++i) {
			cout << arr[z][i] << " ";
		}
		cout << endl;
	}

}
int main()
{
	int max_size = 0;
	int col;
	int row;
	int dim;

	cout << "please input the dimension of the square matrix" << endl;
	cin >> dim;
	col = row = dim;
	int ** array = new int*[row];
	for (int u = 0; u < col; ++u) {
		array[u] = new int[row];
	}
	for (int z = 0; z < row; ++z) {
		for (int i = 0; i < col; ++i) {
			cout << "please input the value for the matrix"<<"(" << z << ","<<i<<")"<<endl;
			cin >> array[z][i];
		}
	}

	


	print(array, col);

	int max_size1 = max_sum_rectangle(array, col, row);

	cout << "this is the maximum value within this rectangle:" << max_size1 <<endl;

}


