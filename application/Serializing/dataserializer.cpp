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

    out << _serializedData.size();
    for (const auto &data : _serializedData)
        writeData(out, data);
}

void DataSerializer::readDataFromFile(const QString &fileName)
{
    QFile file{fileName};
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    // read data length first
    int dataLength = 0;
    in >> dataLength;
    readDataFromFile(in, static_cast<size_t>(dataLength));
}

void DataSerializer::readDataFromFile(QDataStream &stream, size_t count)
{
    for (size_t i = 0; i < count; ++i)
    {
        Data data;
        if (_mode == SerializingMode::CharMode)
            readOldDataImpl(stream, data);
        else
            readDataImpl(stream, data);

        addData(data);
    }
}

Data DataSerializer::getDataAt(size_t index) const { return _serializedData.at(index); }

size_t DataSerializer::count() const { return _serializedData.size(); }

void DataSerializer::clearData() { _serializedData.clear(); }

std::vector<Data> DataSerializer::getData() const { return _serializedData; }

void DataSerializer::setSerializingMode(SerializingMode mode)
{
    _mode = mode;
}

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

void DataSerializer::readDataImpl(QDataStream &stream, Data &data)
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

void DataSerializer::readOldDataImpl(QDataStream &stream, Data &data)
{
    stream >> data.posx
           >> data.posy
           >> data.status
           >> data.zalegn
           >> data.nomer
           >> data.kodv
           >> data.kodn
           >> data.kodab
           >> data.attr;


    char* raw;
    uint length;
    stream.readBytes(raw, length);
//    QByteArray rawText;
//    stream.readRawData(rawText.data(), 99);
//    data.text = QString::fromUtf8(rawText);
//    rawText.clear();

//    stream.readRawData(rawText.data(), 254);
//    data.textmnemo = QString::fromUtf8(rawText);

    stream >> data.tmnpx
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
