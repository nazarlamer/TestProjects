#include "qdatastreamfilereaderstrategy.h"
#include <QFile>
#include <QDataStream>

namespace Serializing
{

std::vector<Data> QDataStreamFileReaderStrategy::readData(const QString &fileName)
{
    QFile file{fileName};
    file.open(QIODevice::ReadOnly);
    if (file.isOpen())
    {
        QDataStream in(&file);

        // read data length first
        size_t dataLength = 0;
        in >> dataLength;

        _data.clear();
        readDataFromFile(in, dataLength);
        return _data;
    }

    return {};
}

void QDataStreamFileReaderStrategy::writeData(const QString &fileName,
                                              const std::vector<Data> &data) const
{
    QFile file{fileName};
    file.open(QIODevice::WriteOnly);
    if (file.isOpen())
    {
        QDataStream out(&file);

        out << data.size();
        for (const auto &i : data)
            writeData(out, i);
    }
}

void QDataStreamFileReaderStrategy::readDataFromFile(QDataStream &stream, size_t count)
{
    for (size_t i = 0; i < count; ++i)
    {
        Data data;
        readData(stream, data);
        _data.push_back(data);
    }
}

void QDataStreamFileReaderStrategy::readData(QDataStream &stream, Data &data)
{
    stream >> data.posx
            >> data.posy
            >> data.status
            >> data.zalegn
            >> data.nomer
            >> data.kodv
            >> data.kodn
            >> data.kodab
            >> data.attr
            >> data.text
            >> data.textmnemo
            >> data.tmnpx
            >> data.tmnpy
            >> data.idsql
            >> data.vvodiv
            >> data.vv1
            >> data.vv2
            >> data.vv3
            >> data.vv4
            >> data.tupzalegn;
}

void QDataStreamFileReaderStrategy::writeData(QDataStream &stream, const Data &data) const
{
    stream << data.posx
           << data.posy
           << data.status
           << data.zalegn
           << data.nomer
           << data.kodv
           << data.kodn
           << data.kodab
           << data.attr
           << data.text
           << data.textmnemo
           << data.tmnpx
           << data.tmnpy
           << data.idsql
           << data.vvodiv
           << data.vv1
           << data.vv2
           << data.vv3
           << data.vv4
           << data.tupzalegn;
}

}
