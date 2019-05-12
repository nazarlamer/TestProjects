#ifndef DATASERIALIZER_H
#define DATASERIALIZER_H

#include "data.h"
#include <vector>

namespace Serializing
{

class DataSerializer
{
public:
    explicit DataSerializer(const std::vector<Data> &dataConteiner = {});

    bool contains(const Data &data) const;
    void addData(const Data &data);
    void removeData(const Data &data);
    void writeDataToFile(const QString &file) const;
    void readDataFromFile(const QString &file, size_t count);
    Data getDataAt(size_t index) const;
    size_t count() const;
    void clearData();
    std::vector<Data> getData() const;

private:
    void writeData(QDataStream &stream, const Data &data) const;
    void readData(QDataStream &stream, Data &data);

private:
    std::vector<Data> _serializedData;
};

}

#endif // DATASERIALIZER_H
