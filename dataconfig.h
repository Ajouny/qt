#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QVector>
#include <QMap>

class DataConfig : public QObject
{
    Q_OBJECT
public:
    explicit DataConfig(QObject *parent = nullptr);
    QMap<int, QVector<QVector<int>>> mData;

signals:

};

#endif // DATACONFIG_H
