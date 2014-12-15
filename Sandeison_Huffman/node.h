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
    QBitArray newBits;
    Node* left;
    Node* right;

    Node();
};

#endif // NODE_H
