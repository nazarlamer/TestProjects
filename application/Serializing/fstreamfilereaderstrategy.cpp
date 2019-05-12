#include "fstreamfilereaderstrategy.h"
#include <fstream>
#include <string>

namespace Serializing
{

std::vector<Data> FStreamFileReaderStrategy::readData(const QString &fileName)
{
    std::ifstream fstream(fileName.toStdString(), std::ios::binary|std::ios::in);
    if (fstream.is_open())
    {
        _data.clear();
        int dataLength = 26;
//        fstream.read(reinterpret_cast<char*>(&dataLength), sizeof(int));
        readDataFromFile(fstream, dataLength);
        return _data;
    }

    return {};
}

void FStreamFileReaderStrategy::writeData(const QString &fileName,
                                          const std::vector<Data> &data) const
{

}

void FStreamFileReaderStrategy::readDataFromFile(std::ifstream &stream, int count)
{
    for (int i = 0; i < count; ++i)
    {
        Data data;
        readData(stream, data);
        _data.push_back(data);
    }
}

void FStreamFileReaderStrategy::readData(std::ifstream &stream, Data &data)
{
//    int buffer[9] = {0}; // first 9 fields
//    stream.read(reinterpret_cast<char*>(&buffer), 9);

//    data.posx  =  buffer[0];
//    data.posy  =  buffer[1];
//    data.status = buffer[2];
//    data.zalegn = buffer[3];
//    data.nomer =  buffer[4];
//    data.kodv =   buffer[5];
//    data.kodn =   buffer[6];
//    data.kodab =  buffer[7];
//    data.attr =   buffer[8];

//    // 2 text string
//    char charBuffer1[100];
//    char charBuffer2[255];
//    stream.read(charBuffer1, 100);
//    stream.read(charBuffer2, 255);
//    data.text = QString::fromUtf8(charBuffer1);
//    data.textmnemo = QString::fromUtf8(charBuffer2);

//    for (int &i : buffer)
//        i = 0;
//    // last 9 fields
//    stream.read(reinterpret_cast<char*>(&buffer), 9);
//    data.tmnpx =    buffer[0];
//    data.tmnpy =    buffer[1];
//    data.idsql =    buffer[2];
//    data.vvodiv =   buffer[3];
//    data.vv1 =      buffer[4];
//    data.vv2 =      buffer[5];
//    data.vv3 =      buffer[6];
//    data.vv4 =      buffer[7];
//    data.tupzalegn = buffer[8];


    int buffer = 0;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.posx  =  buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.posy  =  buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.status = buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.zalegn = buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.nomer =  buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.kodv =   buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.kodn =   buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.kodab =  buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.attr =   buffer;

    // 2 text string
    char charBuffer1[100];
    char charBuffer2[255];
    stream.read(charBuffer1, 100);
    stream.read(charBuffer2, 255);
    data.text = QString::fromLocal8Bit(charBuffer1);
    data.textmnemo = QString::fromLocal8Bit(charBuffer2);

    // last 9 fields
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.tmnpx =    buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.tmnpy =    buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.idsql =    buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.vvodiv =   buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.vv1 =      buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.vv2 =      buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.vv3 =      buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.vv4 =      buffer;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (int));
    data.tupzalegn = buffer;
}

void FStreamFileReaderStrategy::writeData(std::ofstream &stream, const Data &data) const
{

}

}
