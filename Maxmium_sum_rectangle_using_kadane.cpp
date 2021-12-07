#include <iostream>
#include <climits>
#include<string>
#include<fstream>
#include <sstream>
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
		if (MAX <= sum) {
			MAX = sum;
			high = n;
		}
		if (sum < 0) {
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
	int x;
	string arr;
	int col;
	int row;
	int count=0;
	

	ifstream readfile ("input.txt");
	
	readfile>>x;
	col=row=x;
	int *array = new int[x*x];

	//creating the array from the file
	//reading the file without using ,
	readfile >> arr;
	stringstream ss(arr);
	
	 for (int i; ss >> i;) {
       array[count]=i;
       count++;
        if (ss.peek() == ',')
            ss.ignore();
    
    }

 int **array2 = new int*[col];
 
 for (int u = 0; u < col; ++u) {
		array2[u] = new int[row];
	}
 int count2=0;
for (int z = 0; z < row; ++z) {
		for (int i = 0; i < col; ++i) {
			 array2[z][i]= array[count2];
			 ++count2;
		}
	}


	print(array2, col);

	int max_size1 = max_sum_rectangle(array2, col, row);
	cout << "this is the maximum value within this rectangle:" << max_size1 <<endl;

}


