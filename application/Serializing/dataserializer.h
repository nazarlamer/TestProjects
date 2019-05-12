#ifndef DATASERIALIZER_H
#define DATASERIALIZER_H

#include "data.h"
#include <vector>

namespace Serializing
{

enum class SerializingMode
{
    QStringMode,
    CharMode // for reading old files
};

class DataSerializer
{
public:
    explicit DataSerializer(const std::vector<Data> &dataConteiner = {});

    bool contains(const Data &data) const;
    void addData(const Data &data);
    void removeData(const Data &data);
    void writeDataToFile(const QString &fileName) const;
    void readDataFromFile(const QString &fileName);
    Data getDataAt(size_t index) const;
    size_t count() const;
    void clearData();
    std::vector<Data> getData() const;
    void setSerializingMode(SerializingMode mode);

private:
    void readDataFromFile(QDataStream &stream, size_t count);
    void writeData(QDataStream &stream, const Data &data) const;
    void readDataImpl(QDataStream &stream, Data &data);
    void readOldDataImpl(QDataStream &stream, Data &data);

private:
    std::vector<Data> _serializedData;
    SerializingMode _mode{SerializingMode::QStringMode};
};

}

#endif // DATASERIALIZER_H
