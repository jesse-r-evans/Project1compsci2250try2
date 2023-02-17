//Jesse Evans
//COMPSCI 2250
//2 Feb 2023 - 10 Feb 2023

//Part 1
/*Part 1) In the first part of this program, start by prompting the user for the size of arrays
to work with (accept any values from 1 to 52). You will write several functions that work with
integer arrays. Start by writing a function (initialize_array) that takes in an array and fills
it with sequential whole numbers (0,1,2 and so on) up to the size of the array.  After
initialization, display the array and then call a function that creates a NEW array by shuffling
(algorithm given at the bottom of this document) the current one and returning that new array
through the return statement. By shuffling, I mean the original contents of the array will be in
random locations after the call. So, after this function call, you will have a second array with
the numbers shuffled and the original array unchanged. Display the contents of both arrays after
the function call.*/

//Part 2
/*Part 2) In this part you will write two functions that take in an array and create subarrays
from it. One function will go through the array, count up the number of odd numbers in the array.
It will then dynamically create a new array, fill it up with the odd integers in the array and
then return the size of this array through one of the parameters. The second function will do the
same for the even numbers in the array.  Display the original array before making your function
calls to split the array, then display all 3 arrays afterwards.*/

//Part 3
/*Part 3) Finally, write a function that takes in two integer arrays and their sizes. This
function should then create and allocate an array inside the function of the same size as the
largest of these two arrays. The function should then go through both arrays starting at the lowest
index. At each index, compare their values and put the highest of these values in the 3rd array
that we created. If one array isn’t large enough, the other array will always win at those indices.
Output this array. Sort this 3rd array using selection sort and then output the results to the screen
again. This array does not need to be returned to the main body.*/

//Part 4
/*Part 4) Write a main body that feeds each of the parts to each other, one after another. So start by
creating a shuffled array. Then split it up with calls to createOddArray and createEvenArray. Then send
it to array_war and sort the resulting array.*/

//Call libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Prototype Functions
	//Part 1 functions
		void initialize_array(int[], int);
		int* shuffle_array(const int[], int);
		void print_array(const int[], int);
	//Part 2 functions
		int* createOddArray(const int[], int, int&);
		int* createEvenArray(const int[], int, int&);
	//Part 3 Functions
		void array_war(int*, int, int*, int);
		void sort_array(int*, int);
	//Extra Functions
		void swap(int&, int&);

//Main 
int main()
{
	int size;
	//In the first part of this program start by prompting the user for the size of the array from 1 to 52
	cout << "Please enter the size of the array between 1 and 52 elements.\n";
	cin >> size;
	//Check array size.
	while (size < 1 || size > 52)
	{
		cout << "You entered an invalid number.\n";
		cout << "Please enter the size of the array from 1 to 52 elements.\n";
		cin >> size;
	}
	int* original = new int[size];//Original array
	int* shuffled = new int[size];//Shuffled Array
	

//Calls the initialize array function, which fills the array with sequential numbers 0-51
	initialize_array(original, size); 
//Print the initialized array.
	cout << "The initialized array is:\n";
		print_array(original, size); //Prints the initialized array

/*Calls the shuffle_array function,inputs the initialized array, and the size,
and returns a shuffled array.*/
	shuffled = shuffle_array(original, size);

//Prints the new shuffled array.
	cout << "The Shuffled Array is:\n";
		print_array(shuffled, size);


//Calls the create odd array function
	int oddSize = 0;
	int* oddptr = &oddSize;
	int* oddArray = new int[oddSize];
	oddArray = createOddArray(shuffled, size, oddSize);
	//Display the odd array
		cout << "This is the odd array: \n";
		print_array(oddArray, oddSize);
		cout << endl;

//Calls the create even array function
	int evenSize = 0;
	int* evenptr = &evenSize;
	int* evenArray = new int[evenSize];
	evenArray = createEvenArray(shuffled, size, evenSize);
	//Display the even array
		cout << "This is the even array: \n";
		print_array(evenArray, evenSize);
		cout << endl;

//Start the ArrayWar
	array_war(evenArray, evenSize, oddArray, oddSize);
return 0;
}

/***************************************************************************************************************************************/
//Initialize Part1 Functions
	//initialize_array function

void initialize_array(int array[],int size )//This function needs to take an array and fill it with sequential whole numbers.
{
	for (int i = 0; i < size; i++)
	{
		array[i] = i; //Fills each element with the value related to the position of that element.
	}
}

//shuffle_array function
int* shuffle_array(const int array[], int size)
{
	//Prototype Swap function
	void swap(int, int);
	int* shuffled_array = new int[size];
	unsigned seed = time(0);
	srand(seed);
	const int MAX_VALUE = size - 1;
	const int MIN_VALUE = 0;

	for (int i = 0; i < size; i++)//Array duplicator
	{
		shuffled_array[i] = array[i];
	}
	/*This loop creates a randomized array by generating random numbers and 
	swaping the location with the index number.*/

	for (int i = 0; i < size; i++)
	{
		//Generate random numbers
		int randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE; //From Program 3-26 in the book.
		
		int temp;

		//Swap
		temp = shuffled_array[randomNumber];
		shuffled_array[randomNumber] = shuffled_array[i];
		shuffled_array[i] = temp;
	}	
	return shuffled_array;
}


//print_array function
void print_array(const int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

/***************************************************************************************************************************************/
//Initialize Part 2 Functions
	//Odd Array Function

/*This function takes in the original array and counts the number of odd numbers in that array.
It then takes those odd numbers and returns an array of only the odd numbers.*/
int* createOddArray(const int array[], int size, int& oddArraySize)
{
	int j = 0;
	int* oddArray = new int[oddArraySize];
	int* tempArray = new int[size];
	for (int i = 0; i < size; i++)//duplicates the original array into a temp array.
	{
		tempArray[i] = array[i];	
	}
	for (int i = 0; i < size; i++)//Adds the number of odd numbers.
	{
		if (tempArray[i] % 2 == 1)
		{
			oddArraySize++;
		}
	}
	for (int i = 0;i < size; i++)
	{
		if (tempArray[i] % 2 == 1)
		{
			oddArray[j] = tempArray[i];
			j++;
		}
	}
	return oddArray;
}

//Even Array Function

/*This function takes in the original array and counts the number of even numbers in that array.
It then takes those even numbers and returns an array of only the even numbers.*/
int* createEvenArray(const int array[], int size, int& evenArraySize)
{
	int j = 0;
	int* evenArray = new int[evenArraySize];
	int* tempArray = new int[size];
	for (int i = 0; i < size; i++)//duplicates the original array into a temp array.
	{
		tempArray[i] = array[i];
	}
	for (int i = 0; i < size; i++)//Adds the number of even numbers.
	{
		if (tempArray[i] % 2 == 0)
		{
			evenArraySize++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (tempArray[i] % 2 == 0)
		{
			evenArray[j] = tempArray[i];
			j++;
		}
	}
	return evenArray;
}

/***************************************************************************************************************************************/
// Part 3 Functions
	//array war function
	void array_war(int* array1, int array1size, int* array2, int array2size)
	{
		int warSize = 0;
		int* warArray = new int[warSize];

	//Get the size of the warArray array
		if (array1size > array2size)
		{
			warSize = array1size;
		}
		if (array2size > array1size)
		{
			warSize = array2size;
		}
		if (array1size = array2size)
		{
			warSize = array1size;
		}

	//Compare both arrays and put the larger number in the warArray array
		for (int i = 0; i < warSize; i++)
		{
			if (array1[i] > array2[i])
			{
				warArray[i] = array1[i];
			}
			else
			{
				warArray[i] = array2[i];
			}
		}
	//Print the array fight winner.	
		cout << "The array fight winners were:\n";
		print_array(warArray, warSize);
		cout << endl;
		sort_array(warArray, warSize);
	}

	//Sort Array Function - from program 8-5 in the book.
	void sort_array(int* array, int size)
	{
		int minIndex, minValue;

		for (int start = 0; start < (size - 1); start++)
		{
			minIndex = start;
			minValue = array[start];
			for (int index = start + 1; index < size; index++)
			{
				if (array[index] < minValue)
				{
					minValue = array[index];
					minIndex = index;
				}
			}
			swap(array[minIndex], array[start]);
		}
		cout << "The Sorted Array Fight Winners Were:\n";
		print_array(array, size);
	}

	/*This function swaps a and b in memory. From program 8-5 in the book*/
	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}