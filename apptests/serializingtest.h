#ifndef SERIALIZINGTEST_H
#define SERIALIZINGTEST_H

#include <gtest/gtest.h>
#include <QFile>
#include "Serializing/data.h"
#include "Serializing/dataserializer.h"

const QString fileName{"serializedDataFile"};

Serializing::Data makeTestData(int multiplier, const QString &firstName, const QString & secondName)
{
    const int initValue = multiplier;
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

TEST(SerializingTest, writeDataToFile_fileExist)
{
    Serializing::DataSerializer serializer;

    QFile file{fileName};
    if (file.exists())
        file.remove();

    EXPECT_FALSE(file.exists());

    serializer.addData(makeTestData(10, "Test", "Data"));
    serializer.writeDataToFile(fileName);

    EXPECT_TRUE(file.exists());
    file.remove();
}

TEST(SerializingTest, writeAdnReadDataFromFile_dataAreReadCorrect)
{
    Serializing::DataSerializer serializer;

    serializer.addData(makeTestData(10, "Hello", "world"));
    serializer.addData(makeTestData(20, "First", "Project"));

    EXPECT_EQ(serializer.count(), 2);

    QFile file{fileName};
    if (file.exists())
        file.remove();

    serializer.writeDataToFile(fileName);
    const size_t dataCount = serializer.count();
    serializer.clearData();

    EXPECT_EQ(serializer.count(), 0);

    serializer.readDataFromFile(fileName, dataCount);
    EXPECT_EQ(serializer.count(), dataCount);

    const Serializing::Data restoredData1 = serializer.getDataAt(0);
    EXPECT_EQ(restoredData1.attr, 10);
    EXPECT_EQ(restoredData1.text, "Hello");
    EXPECT_EQ(restoredData1.textmnemo, "world");
    EXPECT_EQ(restoredData1.tmnpx, 10);

    const Serializing::Data restoredData2 = serializer.getDataAt(1);
    EXPECT_EQ(restoredData2.attr, 20);
    EXPECT_EQ(restoredData2.text, "First");
    EXPECT_EQ(restoredData2.textmnemo, "Project");
    EXPECT_EQ(restoredData2.tmnpx, 20);
    file.remove();
}

#endif // SERIALIZINGTEST_H