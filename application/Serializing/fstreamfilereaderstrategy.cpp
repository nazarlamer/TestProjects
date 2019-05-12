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
    data.posx  =  readInteger(stream);
    data.posy  =  readInteger(stream);
    data.status = readInteger(stream);
    data.zalegn = readInteger(stream);
    data.nomer =  readInteger(stream);
    data.kodv =   readInteger(stream);
    data.kodn =   readInteger(stream);
    data.kodab =  readInteger(stream);
    data.attr =   readInteger(stream);

    // 2 text string
    data.text = readText(stream, 102);
    data.textmnemo = readText(stream, 257);

    // last 9 fields
    data.tmnpx =   readInteger(stream);
    data.tmnpy =   readInteger(stream);
    data.idsql =   readInteger(stream);
    data.vvodiv =  readInteger(stream);
    data.vv1 =     readInteger(stream);
    data.vv2 =     readInteger(stream);
    data.vv3 =     readInteger(stream);
    data.vv4 =     readInteger(stream);
    data.tupzalegn = readInteger(stream);
}

void FStreamFileReaderStrategy::writeData(std::ofstream &stream, const Data &data) const
{

}

int FStreamFileReaderStrategy::readInteger(std::ifstream &stream)
{
    int buffer = 0;
    stream.read(reinterpret_cast<char*>(&buffer), sizeof (buffer));
    return buffer;
}

QString FStreamFileReaderStrategy::readText(std::ifstream &stream, size_t textLength)
{
    char charBuffer[textLength];
    stream.read(charBuffer, sizeof (charBuffer) / sizeof (char));
    return QString::fromLocal8Bit(charBuffer).trimmed();
}

}
