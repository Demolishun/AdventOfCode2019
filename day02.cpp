#include "day02.h"

#include <QDebug>
#include <algorithm>

void Day02Main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

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

    // make a backup program before beginning
    const QVector<int> rom = program;

    QMap<int,std::function<int(int,int)>> opcodes;
    // add
    opcodes[1] = [](int a, int b)->int{
        return a + b;
    };
    // mult
    opcodes[2] = [](int a, int b)->int{
        return a * b;
    };

    auto intcodeMachine = [](auto program, const auto opcodes, const int noun, const int verb){
        int steps = 0;
        program[1] = noun;
        program[2] = verb;
        for(auto xiter = program.begin(); xiter != program.end(); ++steps){
            const int op = *xiter++;
            if(op == 99){
                //qInfo() << "program complete";
                break;
            }

            int a;
            int b;
            int ptr;

            if((op == 1 || op == 2) && (program.end() - xiter >= 3)){
                a = program[*xiter++];
                b = program[*xiter++];
                ptr = *xiter++;
                //qInfo() << steps << op << a << b << ptr;

                program[ptr] = opcodes[op](a,b);
            }else{
                qInfo() << "program fault unknown op:" << op;
                break;
            }
        }

        return program[0];
    };

    // first run equals 3850704
    int output = intcodeMachine(program, opcodes, 12, 2);
    Q_ASSERT_X(output == 3850704, "intcode", "output not equal to 3850704");
    qInfo() << "program pos 0:" << output;

    // find output that equals 19690720
    int noun = 0;
    int verb = 0;

    // 2 variable search
    const int start = 0;
    const int finish = 99;
    const int find = 19690720;

    // naive 2 loop approach
    // "noun: 67, verb: 18, result: 120600, iterations: 9721"
    int iterations = 0;
    for(int n = start; n <= finish; n++){
        for( int v = start; v <= finish; v++){
            ++iterations;
            int test = intcodeMachine(rom, opcodes, n, v);
            //int test = intcodeMachine(rom, opcodes, v, n);  // same result if noun and verb reversed
            if(test == find){
                output = test;
                noun = n;
                verb = v;
                break;
            }
        }
    }

    if(output == find){
        //  final output
        qInfo() << QString("noun: %1, verb: %2, result: %3, iterations: %4").arg(noun).arg(verb).arg(100 * noun * verb).arg(iterations);
    }else{
        qInfo() << "Could not find noun and verb.";
    }

    // bind params for the programmed machine
    auto intcodeMachineProgrammed = std::bind(intcodeMachine, rom, opcodes, std::placeholders::_1, std::placeholders::_2);

    // binary find?
    auto testIntCode = [](const int noun, const int verb, const int match, auto func){
        return match == func(noun, verb);
    };

    qInfo() << "testing programmed intcode machine working:" << testIntCode(12,2,3850704,intcodeMachineProgrammed);

    std::function<int(int,int,const int,std::function<int(int)>)> binarySearch = [&](int lower, int upper, const int match, auto func){
        //qInfo() << lower << upper << match;
        if(func(lower) == match)
            return lower;
        if(func(upper) == match)
            return upper;
        const int mid = (upper + lower)/2;
        if(mid == lower || mid == upper)
            return -1;
        const int res = func(mid);
        if(res == match)
            return mid;
        else if(res > match)
            upper = mid;
        else
            lower = mid;
        return binarySearch(lower, upper, match, func);
    };

    qInfo() << binarySearch(0, 10, 6, [](int in){return in;});

    iterations = 0;
    int out;
    for(int n=start; n <= finish; n++){
        out = binarySearch(start, finish, find, [&, n](int v){
            qInfo() << n << v;
            ++iterations;
            return intcodeMachineProgrammed(n,v);
        });
    }

    qInfo() << out << iterations;
}
