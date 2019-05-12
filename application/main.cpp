#include <QDebug>
#include <memory>
#include "Serializing/dataserializer.h"
#include "Serializing/fstreamfilereaderstrategy.h"

int main()
{
    const QString dataFile{"vv.dat"};
    Serializing::DataSerializer serializer{std::make_unique<Serializing::FStreamFileReaderStrategy>()};
    serializer.readDataFromFile(dataFile);

    for (const Serializing::Data &data : serializer.getData())
        Serializing::DataSerializer::printData(data);
}
