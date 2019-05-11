#include <iostream>
#include <fstream>
#include <QDataStream>
#include <QFile>
#include "mydata.h"

int main()
{
    const MyProject::MyData myData{35, "John", "Smitt"};
    std::cout << "Console out: " << myData << std::endl;

    // file out:
    std::ofstream ofs{"myFileData.txt"}; // lock this file at binary folder
    if (ofs.is_open()) {
        ofs << myData;
        std::cout << "Console out: " << "FILE REC" << std::endl;
    }

    QFile file( "d:\\Askmem_3\\NV\\data\\vv.dat" );
        if(file.open( QFile::ReadOnly ) )
        {

            QByteArray iContents = file.readAll();
            std::cout << "Console out: " << iContents[0] << std::endl;
            unsigned short i = (unsigned char) iContents.at(432);
            std::cout << "Console out: " << i << std::endl;
            file.seek(0);
            QByteArray block = file.read(4);



            if(file.seek(4) )
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
        }else {
            std::cout << "Console out: " << "NO FILE" << std::endl;
        }
}
