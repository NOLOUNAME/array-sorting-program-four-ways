#include <stdio.h>
#include <stdlib.h>

int input(int *arr, int n);
void print(int *arr, int n);

void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);
void quickSort(int *arr, int left, int right);
void merge_sort(int *arr, int *brr, int left, int right);

int main()
{
    int flag=0;
    int choice;
    int length;
    int number;
    int a[10];
    int b[10];
    printf("Введите размер массива: ");
    scanf("%d", &length);

    // Заполнение массива случайными значениями
    input(a,length);
    // Главный цикл программы
    while (flag == 0) {
        // Вывод меню
        printf("\nМеню:\n");
        printf("1 - Сортировка пузырьком\n");
        printf("2 - Сортировка вставками\n");
        printf("3 - Быстрая сортировка\n");
        printf("4 - Сортировка слиянием\n");
        printf("5 - Вывод массива\n");
        printf("6 - Вывод элемента массива\n");
        printf("7 - Создать новый массив\n");
        printf("8 - Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bubbleSort(a, length);
                printf("Массив отсортирован по возрастанию методом пузырька.\n");
                break;
            case 2:
                insertionSort(a, length);
                printf("Массив отсортирован по возрастанию методом вставок.\n");
                break;
            case 3:
                quickSort(a, 0, length-1);
                printf("Массив отсортирован по возрастанию методом быстрой сортировки.\n");
                break;
            case 4:
                merge_sort(a, b, 0, length - 1);
                printf("Массив отсортирован по возрастанию методом сортировки слиянием.\n");
                break;
            case 5:
                print(a,length);
                break;
            case 6:
                printf("Введите введите элемент массива: ");
                scanf("%d", &number);
                printf("%d элемент массива: %d", number, a[number]);
                break;
            case 7:
                printf("Введите новый размер массива: ");
                scanf("%d", &length);
                input(a,length);
                printf("Новый массив создан.\n");
                break;
            case 8:
                printf("До свидания!\n");
                flag = 1;
                break;
            default:
                printf("Некорректный ввод. Попробуйте еще раз.\n");
        }
    }
    return flag;
}

// Фунция сортировки пузырьком

void bubbleSort(int *arr, int n) {
    int temp,i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Сортировка вставками

void insertionSort(int *arr, int n) {
    int key,i,j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Функция быстрой сортировки

void quickSort(int *arr, int left, int right){
    int i = left, j = right;
    int temp, pivot = arr[ (left+right)/2 ];

    while (i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
            j--;
        }

    }
    if (left < j) quickSort (arr, left, j);
    if (i < right) quickSort (arr, i, right);
}

// Сортировка слиянием

void merge_sort(int *arr, int *brr, int left, int right){
    int i = left, j = right;

    if (j <= i) {
        return;     // the subsection is empty or a single element
    }
    int mid = (i + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    merge_sort(arr,brr,i,mid);
    //merge_sort(i, mid, arr, b);     // sort the left sub-array recursively
    merge_sort(arr, brr, mid + 1, j);
    //merge_sort(mid + 1, j, arr, b);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            brr[k] = arr[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            brr[k] = arr[pointer_left];
            pointer_left++;
        } else if (arr[pointer_left] < arr[pointer_right]) {        // pointer left points to smaller element
            brr[k] = arr[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            brr[k] = arr[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from b[] to a[]
        arr[k] = brr[k];
    }
}

// Функция заполнения массивов
//input
int input(int *arr, int length) {
    int flag = 0;
    for (int i = 0; i < length; i++) {
        if (scanf("%d", (arr + i)) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

// Вывод элементов массива после сортировки

void print(int *arr, int lenght){
    for (int i = 0; i<lenght; i++) 
        printf("%d ", arr[i]);
}
