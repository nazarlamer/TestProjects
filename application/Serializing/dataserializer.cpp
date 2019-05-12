#include "dataserializer.h"
#include "filereader.h"
#include <QDebug>

namespace Serializing
{

DataSerializer::DataSerializer(std::unique_ptr<FileReaderStrategy> fileReader)
    : _fileReader(std::move(fileReader))
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
    _fileReader->writeData(fileName, _serializedData);
}

void DataSerializer::readDataFromFile(const QString &fileName)
{
    _serializedData = _fileReader->readData(fileName);
}

Data DataSerializer::getDataAt(size_t index) const { return _serializedData.at(index); }

size_t DataSerializer::count() const { return _serializedData.size(); }

void DataSerializer::clearData() { _serializedData.clear(); }

void DataSerializer::printData(const Data &data)
{
    qDebug() << data.posx
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

std::vector<Data> DataSerializer::getData() const { return _serializedData; }

}
