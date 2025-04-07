#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class List
{
public:
    Node *head = NULL;

    void insertNode(int value)
    {
        Node *newNode = new Node{value};
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted value: " << value << endl;
            return;
        }

        Node *current = head;
        while (current->next && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            cout << "Value not found in list.\n";
        }
        else
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Deleted value: " << value << endl;
        }
    }

    void displayList()
    {
        Node *temp = head;
        cout << "Linked List: ";
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int partition(int arr[], int st, int end)
{
    int pivot = arr[st];
    int count = 0;
    for (int i = st + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = st + count;
    swap(arr[st], arr[pivotIndex]);

    int i = st, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i], arr[j]);
    }
    return pivotIndex;
}

void QuickSort(int arr[], int st, int end)
{
    if (st >= end)
        return;
    int pivotIndex = partition(arr, st, end);
    QuickSort(arr, st, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, end);
}

void NewMerge(int arr[], int st, int end)
{
    int mid = st + (end - st) / 2;
    int length1 = mid - st + 1;
    int length2 = end - mid;

    int *array1 = new int[length1];
    int *array2 = new int[length2];

    int newIndex = st;
    for (int i = 0; i < length1; i++)
        array1[i] = arr[newIndex++];
    for (int i = 0; i < length2; i++)
        array2[i] = arr[newIndex++];

    newIndex = st;
    int index1 = 0, index2 = 0;
    while (index1 < length1 && index2 < length2)
    {
        if (array1[index1] < array2[index2])
        {
            arr[newIndex++] = array1[index1++];
        }
        else
        {
            arr[newIndex++] = array2[index2++];
        }
    }
    while (index1 < length1)
        arr[newIndex++] = array1[index1++];
    while (index2 < length2)
        arr[newIndex++] = array2[index2++];
}

void MergeSort(int arr[], int st, int end)
{
    if (st >= end)
        return;
    int mid = st + (end - st) / 2;
    MergeSort(arr, st, mid);
    MergeSort(arr, mid + 1, end);
    NewMerge(arr, st, end);
}

int binarySearch(int arr[], int n, int key)
{
    int st = 0, end = n - 1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            st = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    List ll;
    int arr[100], n = 0;
    int choice, val, searchVal;

    do
    {
        cout << "\n******** MENU ********\n";
        cout << "1. Insert into Linked List\n";
        cout << "2. Delete from Linked List\n";
        cout << "3. Display Linked List\n";
        cout << "4. Input Array\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Binary Search\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            ll.insertNode(val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            ll.deleteNode(val);
            break;
        case 3:
            ll.displayList();
            break;
        case 4:
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter array elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            break;
        case 5:
            MergeSort(arr, 0, n - 1);
            cout << "Array after Merge Sort: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        case 6:
            QuickSort(arr, 0, n - 1);
            cout << "Array after Quick Sort: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> searchVal;
            {
                int index = binarySearch(arr, n, searchVal);
                if (index != -1)
                    cout << "Element found at index: " << index << endl;
                else
                    cout << "Element not found." << endl;
            }
            break;
        case 8:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
