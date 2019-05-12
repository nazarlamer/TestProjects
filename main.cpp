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
    std::cout << "Console out: " << "asdasdasd" << std::endl;

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);   // we will serialize the data into the file
    out << QString("the answer is");   // serialize a string
    out << (qint32)42;        // serialize an integer
    file.close();

    QFile file2("file.dat");
    file2.open(QIODevice::ReadOnly);
    QDataStream in(&file2);    // read the data serialized from the file
    QString str;
    qint32 a;
    in >> str >> a;           // extract "the answer is" and 42
    qDebug() << a;
    qDebug() << str;

    QFile file1( "D:\\QT_projects\\test.dat" );
        if(file1.open( QFile::ReadOnly ) )
        {

            QDataStream in(&file1);

            //in.setVersion(5);

            qDebug() << in.version();
            qint32 a;

            in >> a;
            qDebug() << a;
            /*file.seek(0);
            QDataStream in(&file);

            //int str = outFile.readString();

            in.readBytes(raw, length);

            QString str;
            qint32 a;
            in >> str >> a;           // extract "the answer is" and 42
            qDebug() << a;
            */
            /*
            qDebug() << "Hello World";
            QByteArray data = file.read(4);

            qint32 value = data.toInt();
            std::cout << "Console out: " << value << std::endl;
            */

            //std::cout << "Console out: " << str << std::endl;
            /*
            QDataStream data(&file);
            data.setByteOrder(QDataStream::LittleEndian);
            QVector<qint16> i;
            while(!data.atEnd()) {
            qint16 x;
            data >> x;
            */
            /*
            QByteArray iContents = file.readAll();
            std::cout << "Console out: " << iContents[0] << std::endl;
            unsigned short i = (unsigned char) iContents.at(432);
            std::cout << "Console out: " << i << std::endl;
            file.seek(0);
            QByteArray block = file.read(4);


            if(file.seek(0) )
            {
                char * dataRead = new char[ sizeof( qint32 ) ];
                qint64 numBytesRead = file.read(dataRead, sizeof( qint32 ) );

                if( numBytesRead == sizeof( qint32 ) )
                {
                    QByteArray dataBytes(dataRead);

                    bool ok = false;
                    qint32 value = dataBytes.toInt( &ok ); // "value" ends up 0

                    if(ok)
                    {
                        int cout = value; // never gets here
                        std::cout << "Console out: " << cout << std::endl;
                    }else {
                        std::cout << "Console out: " << "NOT JR" << std::endl;
                    }
                }
            }
            */

        }else {
            std::cout << "Console out: " << "NO FILE" << std::endl;
        }
        /*
            qDebug() << in.version();
        std::fstream myfile("D:\\QT_projects\\test.dat", std::ios_base::in);
        qint32 aa;

            while (myfile >> aa)
            {
printf("%f ", aa);
                qDebug() << aa;
            }

*/
        DataStryct aaa;
        char jjj [1];
        std::cout << "Console out 2: " << "NO TITLE" << std::endl;

        ifstream inFile;
        int value1;


        inFile.open("d:\\Askmem_3\\NV\\data\\vv.dat");
        if (!inFile)
        {
            cout << "\nError opening file.\n";
            return 13;
        }
        //inFile >> value1;
        cout << "SIZE OF RECORD " << sizeof(aaa) << std::endl;
        //inFile.read((char*)&value1, sizeof(value1));
        //cout << "VALUE1 " << value1 << std::endl;
        // cout << "VALUE1 POZ" << inFile.tellg() << std::endl;
        //inFile.read((char*)&value1, sizeof(value1));
        //cout << "VALUE1 " << value1 << std::endl;
        //cout << "VALUE1 POZ" << inFile.tellg() << std::endl;

        //inFile.seekg(432);
        cout << "VALUE1 POZ " << inFile.tellg() << std::endl;
        inFile.read((char*)&aaa, sizeof(aaa));
        cout << "VALUE1 POZ " << inFile.tellg() << std::endl;
        cout << "VALUE1 " << aaa.posx << std::endl;
        cout << "VALUE1 " << aaa.text << std::endl;
        cout << "VALUE1 " << aaa.textmnemo << std::endl;
        inFile.seekg(432);
        inFile.read((char*)&aaa, sizeof(aaa));
        cout << "VALUE1 POZ " << inFile.tellg() << std::endl;
        cout << "VALUE1 " << aaa.posx << std::endl;
        cout << "VALUE1 " << aaa.text << std::endl;
        cout << "VALUE1 " << aaa.textmnemo << std::endl;
        cout << "Проба кирилиця " << aaa.textmnemo << std::endl;
        //cout << "POZ " << inFile.tellg() << std::endl;
        //inFile.read((char*)&aaa, sizeof(aaa));
        //cout << "POZ " << inFile.tellg() << std::endl;
        //inFile.read((char*)&aaa, sizeof(aaa));
        //cout << "SIZE OF RECORD " << sizeof(aaa);
        // cout << "POZ " << inFile.peek() << std::endl;

        while(!inFile.eof()){
              //inFile.read((char*)&aaa, sizeof(aaa));
              //cout << aaa.posx << std::endl;
              //cout << aaa.text << std::endl;
        }
        //cout << aaa.posx << std::endl;
        //cout << aaa.text << std::endl;
        //inFile.read((char*)&jjj, sizeof(jjj));
        /*
        for (int var = 300; var < 500; ++var) {
            inFile.seekg(var);
            inFile.read((char*)&aaa, sizeof(aaa));
            cout << "SEEK-"<< var << "--" << aaa.posx << std::endl;
            cout << aaa.text << std::endl;
        }
        */
        //inFile.seekg(432);
        //inFile.read((char*)&aaa, sizeof(aaa));
        //cout << aaa.posx << std::endl;

        inFile.close();

    /*
    Serializing::DataSerializer serializer;
    const QString fileName{"d:\\Askmem_3\\NV\\data\\vv1.dat"};

    serializer.addData(makeData(10, "Hello", "world"));
    serializer.addData(makeData(20, "First", "Project"));

    serializer.writeDataToFile(fileName);
    const size_t dataCount = serializer.count();
    serializer.clearData();

    Q_ASSERT(serializer.count() == 0);

    const size_t dataCount = 1;
    serializer.readDataFromFile(fileName, dataCount);
    Q_ASSERT(serializer.count() == dataCount);

    const Serializing::Data restoredData = serializer.getDataAt(0);
    std::cout << "Console out: " << restoredData.posx << std::endl;

    Q_ASSERT(restoredData.attr == 10);
    Q_ASSERT(restoredData.text == "Hello");
    Q_ASSERT(restoredData.textmnemo == "world");
    Q_ASSERT(restoredData.tmnpx == 10);

    const Serializing::Data restoredData2 = serializer.getDataAt(1);
    Q_ASSERT(restoredData2.attr == 20);
    Q_ASSERT(restoredData2.text == "First");
    Q_ASSERT(restoredData2.textmnemo == "Project");
    Q_ASSERT(restoredData2.tmnpx == 20);
    */
}
