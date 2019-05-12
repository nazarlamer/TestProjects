#include <QDebug>
#include <QFile>
#include <QDataStream>

#include <fstream>

int main()
{
    const QString testFile{"test.dat"};
    std::ifstream fstream(testFile.toStdString(), std::ios::binary|std::ios::in);
    int value = 0;
    if (fstream.is_open())
    {
        fstream.read(reinterpret_cast<char*>(&value), sizeof(int));
        qDebug() << value;
    }
}
