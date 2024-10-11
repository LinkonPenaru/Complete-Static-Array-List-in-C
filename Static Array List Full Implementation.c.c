#include<stdio.h>
#include<stdlib.h>

void Bubble_sort(int arr[], int counter)
{
    for(int i = 0; i< counter-1; i++)
    {
        for(int j = 0; j < counter-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                //swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }

    for(int i = 0; i< counter; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n, choice, pos, new_val, s_val, i, flag, counter = 0, bin_count = 0;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    while(1)
    {
err:
        printf("\n\n1.Print Entire array (index 0 to len) \n2.Access a specific index\n3.Update the value of a specific index\n4.Linear Search\n5.Insert new value at a specific index\n6.Delete from an index\n7.Delete n'th occurrence of a value\n8.Bubble Sort the existing array\n9.Binary Search on the array\n10.EXIT");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            if(counter == 0)
            {
                printf("There are no elements in the array. Insert Element first.");
                goto err;
            }

            for(int i = 0; i<counter; i++)
            {
                printf("%d ", arr[i]);
            }

        }
        else if(choice==2)
        {
            if(counter == 0)
            {
                printf("There are no elements in the array. Insert Element first.");
                goto err;
            }

            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            if(counter <= pos)
            {
                printf("No elements.\n");
                goto err;
            }
            printf("\nThe val at index %d: %d", pos, arr[pos]);
        }


        else if(choice==3)
        {
            if(counter == 0)
            {
                printf("There are no elements in the array. Insert Element first.");
                goto err;
            }

            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            if(counter <= pos)
            {
                printf("No values to update.\n");
                goto err;
            }
            printf("\nEnter the new value: ");
            scanf("%d", &new_val);
            arr[pos]=new_val;
            printf("The new val at index %d: %d", pos, arr[pos]);
        }


        else if(choice==4)
        {
            if(counter == 0)
            {
                printf("There are no elements in the array. Insert Element first.");
                goto err;
            }

            printf("Enter the value to search: ");
            scanf("%d",&s_val);
            flag = 0;
            int count = 0;
            for(int i = 0; i < counter; i++)
            {
                if(arr[i] == s_val)
                {

                    printf("Value %d found at index %d\n", s_val, count);


                }
                count++;
            }

            if(count == 0)
            {
                printf("Value not found.");
            }

        }

        else if(choice==5)
        {

            if(counter >= n)
            {
                printf("Sorry, the array size is full.\nYou can only update the values !!\n\n");
                goto err;
            }

            printf("\nEnter the value to insert: ");
            scanf("%d", &new_val);
            printf("\nEnter the position (index) to insert: ");
            scanf("%d", &pos);

            if (pos > counter || pos < 0)
            {
                printf("Invalid index. Available index 0 to %d\n", counter);
                goto err;
            }

            else if(pos > counter)
            {
                arr[pos] = new_val;
            }

            for(int i = counter; i >= pos; i--)
            {
                arr[i+1] = arr[i];
            }
            arr[pos] = new_val;
            counter++; // Track the length
        }

        else if(choice==6)
        {
            if(counter == 0)
            {
                printf("There are no element in the array. Insert Element first.");
                goto err;
            }
            printf("\nEnter the position (index) to delete from: ");
            scanf("%d", &pos);

            if(pos >= counter)
            {
                printf("Invalid position");
                goto err;
            }

            for(int i = pos; i <= counter; i++)
            {
                arr[i] = arr[i+1];
            }
            counter--; // Updating the length size.

        }

        else if(choice == 7)
        {
            if(counter == 0)
            {
                printf("There are no element in the array. Insert Element first.");
                goto err;
            }

            int value, occurrence;
            printf("Enter the val: ");
            scanf("%d", &value);
            printf("\nEnter the occurrence from the End: ");
            scanf("%d", &occurrence);
            int count_occur = 0;
            for(int i = counter-1; i >= 0; i--)
            {
                if(arr[i] == value)
                {
                    count_occur++;
                    if(count_occur == occurrence)
                    {
                        for(int j = i; j < counter-1; j++)
                        {
                            arr[j] = arr[j+1];
                        }
                        counter--;
                    }
                }
            }

            if(count_occur< occurrence)
            {
                printf("Value not found or occurrence is too high\n");
            }
            else
            {
                for(int i = 0; i < counter; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }

        }
        else if(choice == 8)
        {
            if(counter == 0)
            {
                printf("There are no element in the array. Insert Element first.");
                goto err;
            }
            Bubble_sort(arr, counter);
            bin_count = 1;

        }
        else if(choice == 9)
        {
            if(counter == 0)
            {
                printf("There are no element in the array. Insert Element first.");
                goto err;
            }
            int a[n]; // This is our copy array
            for(int i = 0; i < counter; i++)
            {
                a[i] = arr[i];
            }

            if(bin_count != 1)
            {
                printf("Data have been sorted in ascending order.\n");
                Bubble_sort(a,counter);
            }
            int data;
            printf("\nEnter the data you want to find: ");
            scanf("%d", &data);
            int l,r,mid;
            l = 0;
            r = counter-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(data == arr[mid])
                {
                    printf("Data %d found\n", data);
                    break;
                }
                else if(data > arr[mid])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            if(l>r)
            {
                printf("Data does not exist");
            }
        }
        else if(choice==10)
            break;
        else
        {
            printf("\nWrong Choice. Enter again.\n\n");
            goto err;
        }

    }
    return 0;
}
