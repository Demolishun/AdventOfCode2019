#include "day01.h"

#include <QDebug>
#include <algorithm>

int calcFuel(int mass){
    return mass/3 - 2;
}
int calcFuelR(int mass, int accum=0){
    int fuel = calcFuel(mass);
    if(fuel <= 0)
        return accum;
    return calcFuelR(fuel, accum+fuel);
}

void Day01Main(int argc, char *argv[]){
    auto data = Utils::readTextData(":/Day01_input.txt");

//    for(auto str: data){
//        qInfo() << str;
//    }

    QVector<int> masses;
    std::transform(data.begin(), data.end(), std::back_inserter(masses), [](QString str){
        return str.toInt();
    });

//    for(auto mass: masses){
//        qInfo() << mass;
//    }

    QVector<int> fuels;
    std::transform(masses.begin(), masses.end(), std::back_inserter(fuels), calcFuel);
    int totalFuel = std::accumulate(fuels.begin(), fuels.end(), int(0));

    qInfo() << totalFuel;

    QVector<int> fuels2;
//    std::transform(masses.begin(), masses.end(), std::back_inserter(fuels2), [](int val){
//        return calcFuelR(val);
//    });
    std::transform(masses.begin(), masses.end(), std::back_inserter(fuels2), std::bind(calcFuelR,std::placeholders::_1,0));
    int totalFuel2 = std::accumulate(fuels2.begin(), fuels2.end(), int(0));

    qInfo() << totalFuel2;
}
