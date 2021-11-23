
#include <iostream>
#include<fstream>
#include<string>
#include <chrono>
using namespace std;

// linkedlist functions

double time1 = 0;
struct node {
	int value;
	int power;
	node * next;
};


node * createlist( node * ptr1, int v, int p ) {
	node* tmp = ptr1;
	node * n = new node;
	n->value = v;
	n->power = p;
	n->next = NULL;
	
	if (ptr1 == NULL) {
		ptr1 = n;
		tmp = n;
	}
	else {

		while (ptr1 -> next != NULL) {
			ptr1 = ptr1->next;
		}
		ptr1->next = n;
	}
	ptr1 = tmp;
	return ptr1;
}

void traverse(node * ptr2, int link) {
	node* tmp1 = ptr2;
	while (ptr2!= NULL) {
		cout<<link<<"->" << ptr2->value << "->" << ptr2->power << endl;
	    ptr2 = ptr2->next;
	}
	ptr2 = tmp1;
}

auto linkaddition(node ** head, int columns, int rows, string s3) {
	int comparisons = 0;
	node * n1 = NULL;
	node * tmp;
	for (int u = 0; u < columns; ++u) {
		n1 = createlist(n1, 0, u);
	}
	tmp = n1;
	auto begin = std::chrono::high_resolution_clock::now();
	for (int g = 0; g < rows ; ++g) {
		if (head[g] == NULL) {
			continue;
	 }

		while (head[g] != NULL) {
			while (n1 != NULL) {
				++comparisons;
				if (head[g]->power == n1->power) {
					n1->value = head[g]->value + n1->value;
				}
				n1 = n1->next;
			}
			n1 = tmp;
			head[g] = head[g]->next;
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	time1 = (elapsed.count() * 1e-9);

	ofstream MyFile1("additionresultlinkedlist.txt", ios_base::app);
	MyFile1 << s3;
	MyFile1 << "\n";
	while(n1!=NULL){
		MyFile1 << n1->value << " ";
		n1 = n1->next;
	}
	MyFile1 << "\n";
	n1 = tmp;
	return  comparisons;
}



// matrix functions

void print(int ** arr , int x1, int y1) {
	for (int z = 0; z < x1; ++z) {
		for (int u = 0; u < y1; ++u) {
			cout << arr[z][u]<< " ";
		}
		cout << endl;
	}

}

auto matrixaddandwrite(int** arr, int x1, int y1, string s2) {
	int **addarray = new int* [1];
	for (int i = 0; i < 1; i++) {
		addarray[i] = new int[y1];
	}
	for (int z = 0; z < y1; ++z) {
		addarray[0][z] = 0;
	}
	auto begin = std::chrono::high_resolution_clock::now();
	for (int z = 0; z < x1; ++z) {
		for (int u = 0; u < y1; ++u) {
			addarray[0][u] = addarray[0][u] + arr[z][u];
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	print(addarray, 1, y1);

	ofstream MyFile("additionresultmatrix.txt", ios_base::app);
	MyFile << s2;
	MyFile << "\n";
	for(int z = 0; z < y1; ++z) {
		MyFile << addarray[0][z]<<" ";
	}
	MyFile << "\n";
	return  elapsed.count() * 1e-9;
}

void displayinfo(int poly, int var, int nozero, string filename, string datastruct, double total_time, int comp) {
	cout << "------------------------------------------------------------------" << endl;
    cout << " this is the file name:" << filename << endl;
	cout << " these are the total number of polynomials:" << poly << endl;
	cout << " these are the total number of variables:" << var << endl;
	cout << " these are the total number of non-zero values:" << nozero << endl;
	cout << " this the data structure used:" << datastruct<< endl;
	cout << " this is the total time allotted:" << total_time << endl;
	cout << " these are the total number of comparisons for linkedlist:" << comp << endl;
	cout << "-------------------------------------------------------------------" << endl;
}





int main()

{
	int choice = 0;
	cout << "please input 0 for linkedlist as a datastructure or 1 for matrix as a datastructure" << endl;
	cin >> choice;
   string filename[12] = { "example1-10x5.txt", "example1-20x10.txt", "example1-50x100.txt", "example1-200x50.txt", "example2-10x5.txt", "example2-20x10.txt","example2-50x100.txt", "example2-200x50.txt", "example3-10x5.txt", "example3-20x10.txt","example3-50x100.txt","example3-200x50.txt" };



   if (choice == 0) {
	   //linkedlist part of the assignment.
	   int zero1 = 0;
	   int x1 = 0;
	   int z1 = 0;
	   int z2 = 0;
	   int count2 = 0;
	   int fpower = 0;
	   int row = 0;
	   node** heads;

	   for (int t = 0; t < 12; ++t) {
		   ifstream readfile(filename[t]);
		   while (readfile >> x1) {
			   if (count2 == 0) {
				   z1 = x1;
			   }
			   else if (count2 == 1) {
				   z2 = x1;
			   }
			   else {
				   break;
			   }
			   ++count2;
		   }
		   cout << z1 << endl;
		   cout << z2 << endl;

		   heads = new node * [z1];

		   for (int v = 0; v < z1; ++v) {
			   heads[v] = NULL;
		   }

		   if (x1 > 0) {
			   heads[row] = createlist(heads[row], x1, 0);
			   zero1++;
		   }
		  

		   fpower++;

		   while (readfile >> x1) {
			   if (x1 > 0) {
				   heads[row] = createlist(heads[row], x1, fpower);
				   zero1++;
			   }
			   fpower++;

			   if (fpower > (z2 - 1) && row < (z1 - 1)) {
				   fpower = 0;
				   row++;
			   }
		   }
		   
		   int p1 = 0;
		   fpower = 0;
		   row = 0;
		   count2 = 0;
		   p1 = linkaddition(heads, z2, z1, filename[t]);
		   displayinfo(z1, z2, zero1, filename[t], "linkedlist", time1, p1);
		   zero1 = 0;
	   }
   }
   else if (choice == 1) {

	   // matrix part of the assignment.
	   int zeroes = 0;
	   int x = 0;
	   int count = 0;
	   int x1 = 0;
	   int y1 = 0;
	   int** array1;
	   for (int t = 0; t < 12; ++t) {
	   	ifstream readfile(filename[t]);
	   	cout << filename[t] << endl;

	   	while (readfile >> x) {
	   		if (count == 0) {
	   			x1 = x;
	   		}
	   		else if (count == 1) {
	   			y1 = x;
	   		}
	   		else {
	   			break;
	   		}
	   		++count;
	   	}

	   	cout << x1 << endl;
	   	cout << y1 << endl;

	   	array1 = new int* [x1];
	   	for (int i = 0; i < x1; i++) {
	   		array1[i] = new int[y1];
	   	}
	   	int z = 0;
	   	int u = 0;
	   	if (x > 0) {
	   		zeroes++;
	   	}
	   	array1[z][u] = x;
	   	++u;
	   	while (readfile >> x) {
	   		if (u < y1) {
	   			array1[z][u] = x;
	   			++u;
	   			if (x > 0) {
	   				zeroes++;
	   			}
	   		}
	   		if (u == y1 && z < x1) {
	   			u = 0;
	   			++z;
	   		}
	   	}
	   	//print(array1, x1, y1);
	   	double p;
	   	p = matrixaddandwrite(array1, x1, y1,filename[t]);
	   	displayinfo(x1, y1, zeroes, filename[t], "matrix" , p,0);
	   	count = 0;
	   	zeroes = 0;
	   	readfile.close();
	   }
   }
	return 0;
}

