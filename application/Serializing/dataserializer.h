#ifndef DATASERIALIZER_H
#define DATASERIALIZER_H

#include "data.h"
#include <vector>
#include <memory>

namespace Serializing
{

class FileReaderStrategy;

class DataSerializer
{
public:
    explicit DataSerializer(std::unique_ptr<FileReaderStrategy> fileReader);

    bool contains(const Data &data) const;
    void addData(const Data &data);
    void removeData(const Data &data);
    std::vector<Data> getData() const;
    Data getDataAt(size_t index) const;
    size_t count() const;

    void writeDataToFile(const QString &fileName) const;
    void readDataFromFile(const QString &fileName);

    void clearData();

public:
    static void printData(const Data &data);

private:
    std::vector<Data> _serializedData;
    std::unique_ptr<FileReaderStrategy> _fileReader;
};

}

#endif // DATASERIALIZER_H
