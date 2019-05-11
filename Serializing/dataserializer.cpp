#include "dataserializer.h"
#include <algorithm>
#include <QDataStream>
#include <QFile>

namespace Serializing
{

DataSerializer::DataSerializer(const std::vector<Data> &dataConteiner)
    : _serializedData(dataConteiner)
{
}

bool DataSerializer::contains(const Data &data) const
{
    return false; // TODO: add implementation later
}

void DataSerializer::addData(const Data &data) { _serializedData.push_back(data); }

void DataSerializer::removeData(const Data &data)
{
//    if (contains(data))
        // TODO: add removing implemantation later
}

void DataSerializer::writeDataToFile(const QString &fileName) const
{
    QFile file{fileName};
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    for (const auto &data : _serializedData)
        writeData(out, data);
}

void DataSerializer::readDataFromFile(const QString &fileName, size_t count)
{
    QFile file{fileName};
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    for (size_t i = 0; i < count; ++i)
    {
        Data data;
        readData(in, data);
        addData(data);
    }
}

Data DataSerializer::getDataAt(size_t index) const { return _serializedData.at(index); }

size_t DataSerializer::count() const { return _serializedData.size(); }

void DataSerializer::clearData() { _serializedData.clear(); }

std::vector<Data> DataSerializer::getData() const { return _serializedData; }

void DataSerializer::writeData(QDataStream &stream, const Data &data) const
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

void DataSerializer::readData(QDataStream &stream, Data &data)
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

}
