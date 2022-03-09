#include <QCoreApplication>
#include <QDebug>

int compare(int a, int b) {
    return ((a & 0x00FF0000) - (b & 0x00FF0000)) > 0 ? 1 :
           ((a & 0x00FF0000) - (b & 0x00FF0000)) < 0 ? -1 : 0;
}


struct Res {
    int resA;
    int resB;
    Res() : resA(0), resB(0) {}
};

struct Res compInt(int a, int b) {
    struct Res tempRes;

    unsigned char *pA = (unsigned char*)&a;

    for (int i = 0; i < 4; i++) {
        unsigned char *pB = (unsigned char*)&b;
        for (int j = 0; j < 4; j++) {
            qDebug() << *pA << " " << *pB;
            if (*pA == *pB) {
                tempRes.resA++;
            }
            pB++;
        }
        pA++;
    }

    return tempRes;
}

void printSym() {
    for (int i = 0; i < 256; i++) {
        qDebug() << (int)i << " - " << (char)i;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    compInt(0x78219802, 0x789901FF);

    return a.exec();
}
