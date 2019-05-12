#ifndef QDATASTREAMFILEREADERSTRATEGY_H
#define QDATASTREAMFILEREADERSTRATEGY_H

#include "filereader.h"

namespace Serializing
{

class QDataStreamFileReaderStrategy : public FileReaderStrategy
{
public:

    // FileReaderStrategy interface
public:
    std::vector<Data> readData(const QString &fileName) override;
    void writeData(const QString &fileName, const std::vector<Data> &data) const override;

private:
    void readDataFromFile(QDataStream &stream, size_t count);
    void readData(QDataStream &stream, Data &data);
    void writeData(QDataStream &stream, const Data &data) const;

private:
    std::vector<Data> _data;
};

}

#endif // QDATASTREAMFILEREADERSTRATEGY_H
