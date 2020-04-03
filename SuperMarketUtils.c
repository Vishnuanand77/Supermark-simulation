#include<stdio.h>
#include <stdlib.h>
#include "SuperMarket.h"





//Number of items in inventory
int Nbanana= 10;
int Nmango= 10;
int Nmilk= 15;
int Ncheese=15;
int Nbutter=10;


//Number of days left to expiry
int banana=5;
int mango= 3;
int milk=6;
int cheese= 7;
int butter=10;


//Heap implementation

void heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If left child is smaller than root
    if (l < n && arr[l] > arr[smallest])
        smallest = l;

    // If right child is smaller than smallest so far
    if (r < n && arr[r] > arr[smallest])
        smallest = r;

    // If smallest is not root
    if (smallest != i) {
       int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

void printHeap(int arr[], int n)
{
    printf("\n\n\t\t\t...Stats for nerds: \n");
    printf("\t\t\tArray representation of heap with expiry dates:\n");
    printf("\n\t\t\t");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\t\t\t...\n");
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        //Call min heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void displayitems(int n)
{
    printf("\t\t\tWelcome to the inventory, this is all we have: \n");
    printf("\t\t\t1)Banana: %d pieces\n", Nbanana);
    printf("\t\t\t2)Mango: %d pieces\n", Nmango );
    printf("\t\t\t3)Milk: %d packets\n", Nmilk);
    printf("\t\t\t4)Cheese: %d packets\n", Ncheese);
    printf("\t\t\t5)Butter: %d packets\n", Nbutter);
    if(Nbanana<=0)
    {
        printf("\n\t\t\tBanana unavailable\n");
        banana=0;menu(n);
    }
    if(Nmango<=0)
    {
        printf("\n\t\t\tMango unavailable\n");
        mango=0;menu(n);
    }
    if(Nmilk<=0)
    {
        printf("\n\t\t\tMilk unavailable\n");
        milk=0;menu(n);
    }
    if(Ncheese<=0)
    {
        printf("\n\t\t\tCheese unavailable\n");
        cheese=0;
        menu(n);
    }
    if(Nbutter<=0)
    {
        printf("\n\t\t\tButter unavailable\n");
        butter=0;
        menu(n);
    }
    else
        menu(n);
}

void buyitem(int n)
{
    //This function displays the remaining quantity of items in our supermarket and handles the case if anything is sold out.
    printf("\n\n\t\t\tWelcome to the inventory, this is all we have: \n");
    while(1)
    {
    printf("\t\t\t1)Banana: %d pieces\n", Nbanana);
    printf("\t\t\t2)Mango: %d pieces\n", Nmango );
    printf("\t\t\t3)Milk: %d packets\n", Nmilk);
    printf("\t\t\t4)Cheese: %d packets\n", Ncheese);
    printf("\t\t\t5)Butter: %d packets\n", Nbutter);
    if(banana<=0)
    {
        printf("\n\t\t\tBanana unavailable\n");
    }
    if(mango<=0)
    {
        printf("\n\t\t\tMango unavailable\n");
    }
    if(milk<=0)
    {
        printf("\n\t\t\tMilk unavailable\n");
    }
    if(cheese<=0)
    {
        printf("\n\t\t\tCheese unavailable\n");
    }
    if(butter<=0)
    {
        printf("\n\t\t\tButter unavailable\n");
    }

    else{
        printf("\n\t\t\tEnter 6 to exit the buy menu!\n\n");
        printf("\t\t\tEnter choice: ");
        char choicetwo;
        scanf(" %c", &choicetwo);
        if(!(choicetwo>='1' && choicetwo<='6'))
        {
            printf("\n\t\t\tInvalid Request.\n\t\t\t Try again or press 6 to go back to main menu\n\n"); continue;
        }
        switch(choicetwo)
        {
            case('1'):if(Nbanana!=0 && banana!=0 ) {Nbanana--; buyitem(n);} else{printf("\n\t\t\t Banana unavailable\n");}
                    break;
            case('2'): if(Nmango!=0 && mango!=0){ Nmango--; buyitem(n);} else{printf("\n\t\t\t Mango unavailable\n");}
                    break;
            case('3'): if(Nmilk!=0) {Nmilk--;buyitem(n);} else{printf("\n\t\t\t Milk unavailable\n");}
                    break;
            case('4'): if(Ncheese!=0) {Ncheese--;buyitem(n);} else{printf("\n\t\t\t Cheese unavailable\n");}
                    break;
            case('5'): if(Nbutter!=0) {Nbutter--;buyitem(n);} else{printf("\n\t\t\t Butter unavailable\n");}
                    break;
            case('6'): menu(n);  break;
        }
    }
    }
    printf("\t\t\tAvailable items: \n");
    displayitems(n);
}

void displayexpiry(int n)
{
    //Display the number of days remaining for the product to expire
    printf("\n\t\t\tExpiry dates left on the inventory: \n");
    printf("\t\t\t1)Banana: %d days\n", banana);
    printf("\t\t\t2)Mango: %d days\n", mango );
    printf("\t\t\t3)Milk: %d days\n", milk);
    printf("\t\t\t4)Cheese: %d days\n", cheese);
    printf("\t\t\t5)Butter: %d days\n", butter);
    menu(n);
}

void checkExpiry(int items[])
{
    //When gotonextday is called, other than the array values, we want the variables to lose a value of 1 too. So the following few lines does that.
    banana--;
    mango--;
    milk--;
    butter--;
    cheese--;
    if(banana<=0)
    {
        printf("\n\t\t\tBanana unavailable\n");
    }
    if(mango<=0)
    {
        printf("\n\t\t\tMango unavailable\n");
    }
    if(milk<=0)
    {
        printf("\n\t\t\tMilk unavailable\n");
    }
    if(cheese<=0)
    {
        printf("\n\t\t\tCheese unavailable\n");
    }
    if(butter<=0)
    {
        printf("\n\t\t\tButter unavailable\n");
    }
}

void gotonextday(int items[], int size)
{
    checkExpiry(items);
    displayexpiry(size);
    //Everytime you go to next day, decrement all values and check for 0
    int i;
    for(i=0;i<size;i++)
    {
        items[i]--;
    }
    heapSort(items,size);
    if(items[0]==0)
    {
        for(i=0;i<size;i++)
        {
            items[i]=items[i+1];
        }

        size--;
        heapSort(items,size);
        printHeap(items, size);
    }
    else if(size <=0)
    {
        printf("We are out of freshness sir!");
    }
    else
        printHeap(items,size);
    menu(size);
}

void makeHeap(int arr[])
{
    //Very trivial assignment of array elements with variable values.
    arr[0] = banana;
    arr[1]= mango;
    arr[2]= milk;
    arr[3]= cheese;
    arr[4]= butter;
}

void menu(int n)
{

    while(1)
    {
    char choice;
    printf("\n\n\t\t\tWelcome to PES Grocery store simulator!\n");
    printf("\t\t\t#############################################\n");
    printf("\t\t\tPlease select from the following menu: \n");
    printf("\t\t\t1) Display items\n");
    printf("\t\t\t2) Buy an item\n");
    printf("\t\t\t3) Display item expiry dates\n");
    printf("\t\t\t4) Go to the next day->->->\n");
    printf("\t\t\t5) Exit\n");
    printf("\t\t\t############################################\n");
    printf("\t\t\tEnter your choice: ");
    scanf(" %c",&choice);
    if(!(choice>='1'&& choice<='5'))
    {
        printf("\n\t\t\tOops! Invalid Request\n"); continue;
    }
    switch(choice)
    {
        case('1'): displayitems(n);
                break;
        case('2'): buyitem(n);
                break;
        case('3'): displayexpiry(n);
                break;
        case('4'): gotonextday(items, n);
                break;
        case('5'): exit(0);
        default: break;
    }

   }

}
