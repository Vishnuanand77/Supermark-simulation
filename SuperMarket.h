#define MAX_SIZE 5
int items[MAX_SIZE];
//Heapify function is to arrange the data according to the binary heap algorithm
void heapify(int a[],int , int );

//printHeap function prints the heap in array representation.
//This is for programmer's representation only. It may be used in the function.
//If so, It is for DEMO ONLY
void printHeap(int a[], int);

//Sorts the heap array
void heapSort(int a[], int);

//Display the contents of the heap in order of items and how much "Quantity" of each product is left
void displayitems(int);

//Function for the customer to make a purchase of any of the available items
void buyitem(int);

//Function to display the remaining shelf life of the items
void displayexpiry(int);

//Function to check if any item is beyond or at the end of it's shelf life
void checkExpiry(int a[]);

//Simulates the passing of a day. Each product's expiry date is decremented by 1
void gotonextday(int a[], int);

//Creates a heap data structure.
void makeHeap(int a[]);


//Displays the main menu with all the options for a customer
void menu(int);


