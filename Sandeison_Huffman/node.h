#ifndef NODE_H
#define NODE_H


#include <QtCore>
#include <QByteArray>
#include <QString>
#include <QBitArray>
#include <iostream>


class Node
{
public:

    int frequency;
    QByteArray character;
    QByteArray newBits;
    Node* left;
    Node* right;

    Node();
};

#endif // NODE_H
