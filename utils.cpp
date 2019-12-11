#include "utils.h"

#include <QFile>
#include <QTextStream>

namespace Utils {

QVector<QString> readTextData(QString filename){
    QFile file(filename);
    QVector<QString> data;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return data;

    // keeps newline char in string
//    while (!file.atEnd()) {
//        QByteArray line = file.readLine();
//        data.push_back(line);
//    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        data.push_back(line);
    }

    return data;
}

}
