#ifndef FSTREAMFILEREADERSTRATEGY_H
#define FSTREAMFILEREADERSTRATEGY_H

#include "filereader.h"
#include <iosfwd>

namespace Serializing
{

class FStreamFileReaderStrategy : public FileReaderStrategy
{
public:

    // FileReaderStrategy interface
public:
    std::vector<Data> readData(const QString &fileName) override;
    void writeData(const QString &fileName, const std::vector<Data> &data) const override;

private:
    void readDataFromFile(std::ifstream &stream, int count);
    void readData(std::ifstream &stream, Data &data);
    void writeData(std::ofstream &stream, const Data &data) const;

private:
    std::vector<Data> _data;
};

}

#endif // FSTREAMFILEREADERSTRATEGY_H
