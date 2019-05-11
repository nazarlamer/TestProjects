#include <QString>
#include "Serializing/dataserializer.h"
#include "Serializing/data.h"

Serializing::Data makeData(int multiplier, const QString &firstName, const QString & secondName)
{
    int initValue = 1 * multiplier;
    Serializing::Data data;

    data.posx = initValue;
    data.posy = initValue;
    data.status = initValue;
    data.zalegn = initValue;
    data.nomer = initValue;
    data.kodv = initValue;
    data.kodn = initValue;
    data.kodab = initValue;
    data.attr = initValue;
    data.text = firstName;
    data.textmnemo = secondName;
    data.tmnpx = initValue;
    data.tmnpy = initValue;
    data.idsql = initValue;
    data.vvodiv = initValue;
    data.vv1 = initValue;
    data.vv2 = initValue;
    data.vv3 = initValue;
    data.vv4 = initValue;
    data.tupzalegn = initValue;

    return data;
}

int main()
{
    Serializing::DataSerializer serializer;
    const QString fileName{"storedData"};

    serializer.addData(makeData(10, "Hello", "world"));
    serializer.addData(makeData(20, "First", "Project"));

    serializer.writeDataToFile(fileName);
    const size_t dataCount = serializer.count();
    serializer.clearData();

    Q_ASSERT(serializer.count() == 0);

    serializer.readDataFromFile(fileName, dataCount);
    Q_ASSERT(serializer.count() == dataCount);

    const Serializing::Data restoredData = serializer.getDataAt(0);
    Q_ASSERT(restoredData.attr == 10);
    Q_ASSERT(restoredData.text == "Hello");
    Q_ASSERT(restoredData.textmnemo == "world");
    Q_ASSERT(restoredData.tmnpx == 10);

    const Serializing::Data restoredData2 = serializer.getDataAt(1);
    Q_ASSERT(restoredData2.attr == 20);
    Q_ASSERT(restoredData2.text == "First");
    Q_ASSERT(restoredData2.textmnemo == "Project");
    Q_ASSERT(restoredData2.tmnpx == 20);
}
