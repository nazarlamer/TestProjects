#include <QString>
#include "Serializing/dataserializer.h"
#include "Serializing/data.h"
#include <iostream>
#include <fstream>
#include <QDataStream>
#include <QFile>
#include <QTextCodec>
#include<QDebug>
using namespace std;

struct DataStryct
{
    int posx;
    int posy;
    int status;
    int zalegn;
    int nomer;
    int kodv;
    int kodn;
    int kodab;
    int attr;
    char text [102];
    char textmnemo [257];
    int tmnpx;
    int tmnpy;
    int idsql;
    int vvodiv;
    int vv1;
    int vv2;
    int vv3;
    int vv4;
    int tupzalegn;
};

Serializing::Data makeData(int multiplier, const QString &firstName, const QString & secondName)
{
    int initValue = multiplier;
    Serializing::Data data;

    data.posx = initValue;
    data.posy = initValue;
    data.status = initValue;
    data.zalegn = initValue;
    data.nomer = initValue;
    data.kodv = initValue;
    data.kodn = initValue;
    data.kodab = initValue;
    data.attr = initValue;
    data.text = firstName;
    data.textmnemo = secondName;
    data.tmnpx = initValue;
    data.tmnpy = initValue;
    data.idsql = initValue;
    data.vvodiv = initValue;
    data.vv1 = initValue;
    data.vv2 = initValue;
    data.vv3 = initValue;
    data.vv4 = initValue;
    data.tupzalegn = initValue;

    return data;
}

int main()
{
    std::cout << "Console out: " << "RUN" << std::endl;

    ifstream inFile;
    int value1;

    inFile.open("d:\\QT_projects\\SimpleFileWriting\\TestReadFile\\test.dat");
    if (!inFile)
    {
            cout << "\nError opening file.\n";
            return 13;
    }

    inFile.read((char*)&value1, sizeof(value1));
    cout << "VALUE1 " << value1 << std::endl;

    inFile.close();
}
