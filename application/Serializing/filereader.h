#ifndef FILEREADER_H
#define FILEREADER_H

#include "data.h"
#include <vector>

namespace Serializing
{

class FileReaderStrategy
{
public:
    virtual ~FileReaderStrategy() = default;
    virtual std::vector<Data> readData(const QString &fileName) = 0;
    virtual void writeData(const QString &fileName, const std::vector<Data> &data) const = 0;
};

}

#endif // FILEREADER_H
