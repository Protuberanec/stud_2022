#include <QCoreApplication>
#include <QDebug>
#include <windows.h>

//origin, grapher, gnuplot, excel, ....
//100\t1\t1\t1\t1\t1\n
//299\t4\t


void sort1(int* a, int _size) {}
void sort2(int* a, int _size) {}
void sort3(int* a, int _size) {}
void sort4(int* a, int _size) {}
void sort5(int* a, int _size) {}
void sort6(int* a, int _size) {}
void sort7(int* a, int _size) {}

void randomFill(int* a, int _size) {}
void durSortToFile(long int time, int _size, int numSort) {}
void nextSize() {}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int *my_array;

    for (int size = 100; size < 1000000; size++) {
        my_array = new int [size];
        randomFill(my_array, size);

        long int time = GetTickCount();
        sort1(my_array, size);
        time = GetTickCount() - time;
        durSortToFile(time, size, 1);

        randomFill(my_array, size);
        time = GetTickCount();
        sort2(my_array, size);
        time = GetTickCount() - time;
        durSortToFile(time, size, 2);


        nextSize();
        size += 100;
        delete [] my_array;
    }


    return a.exec();
}
