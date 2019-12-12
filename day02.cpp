#include "day02.h"

#include <QDebug>
#include <algorithm>

void Day02Main(int argc, char *argv[])
{
    auto data = Utils::readTextData(":/Day02_input.txt");

    if(!data.length()){
        qInfo() << "No data";
        return;
    }

    QStringList opsStr = data[0].split(QString(","));

    QVector<int> program;
    for(auto op: opsStr){
        program.push_back(op.toInt());
    }
    program[1] = 12;
    program[2] = 2;

    QMap<int,std::function<int(int,int)>> opcodes;
    // add
    opcodes[1] = [](int a, int b)->int{
        return a + b;
    };
    // mult
    opcodes[2] = [](int a, int b)->int{
        return a * b;
    };

    int steps = 0;
    for(auto xiter = program.begin(); xiter != program.end(); ++steps){
        const int op = *xiter++;
        if(op == 99){
            qInfo() << "program complete";
            break;
        }
        int a = *xiter++;
        int b = *xiter++;
        int ptr = *xiter++;

        qInfo() << steps << op << a << b << ptr;

        if(op == 1 || op == 2){
            program[ptr] = opcodes[op](a,b);
        }else{
            qInfo() << "program fault unknown op:" << op;
            break;
        }
    }

    qInfo() << "program pos 0:" << program[0];
}
