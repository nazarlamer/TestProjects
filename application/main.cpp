#include <QDebug>
#include "Serializing/dataserializer.h"
#include "Serializing/fstreamfilereaderstrategy.h"

#include <fstream>
#include <memory>

int main()
{
    const QString dataFile{"vv.dat"};
    Serializing::DataSerializer serializer{std::make_unique<Serializing::FStreamFileReaderStrategy>()};
    serializer.readDataFromFile(dataFile);

    for (const Serializing::Data &data : serializer.getData())
        Serializing::DataSerializer::printData(data);
}
