#include <QCoreApplication>

int compare(int a, int b) {
    return ((a & 0x00FF0000) - (b & 0x00FF0000)) > 0 ? 1 :
           ((a & 0x00FF0000) - (b & 0x00FF0000)) < 0 ? -1 : 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);




    return a.exec();
}
