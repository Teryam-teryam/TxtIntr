#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h> // для getopt
#include <cstdlib>  // для std::stod
#include <cstring>

using namespace std;

double CalcHeight(double angle, double speed)
{
    const float g = 9.81; // ускорение свободного падения
    const float pi = 3.14; // число Пи
    double Radians = angle * (pi / 180.0);
    double h = (speed * speed * sin(Radians) * sin(Radians)) / (2 * g);
    return h;
}

double CalcDistance(double angle, double speed)
{
    const float g = 9.81; // ускорение свободного падения
    const float pi = 3.14; // число Пи
    double Radians = angle * (pi / 180.0);
    double d = (speed * speed * sin(2 * Radians)) / g;
    return d;
}

void PrintHelp()
{
    cout << "-h help" << endl;
    cout << "-H <угол> <начальная_скорость>    Вычисляет максимальную высоту, при данном угле и начальной скорости" << endl;
    cout << "-D <угол> <начальная_скорость>    Вычисляет максимальную дальность, при данном угле и начальной скорости" << endl;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    	{
        	PrintHelp();
        	return 1;
    	}
  
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-H") == 0)
    	{
        	PrintHelp();
        	return 0;
    	}

    int opt;
    while ((opt = getopt(argc, argv, "AD")) != -1)
    	{
        	switch (opt)
        		{
            		case 'A':				//altitude, а не Height потому что h и H вызывают справку
                		if (argc != 4)
                			{
                    			PrintHelp();
                    			return 1;
                			}
                		cout << "Высота = " << CalcHeight(stod(argv[2]), stod(argv[3])) << endl;
                		return 0;
            		case 'D':
                		if (argc != 4)
                			{
                    			PrintHelp();
                    			return 1;
                			}
                		cout << "Дальность = " << CalcDistance(stod(argv[2]), stod(argv[3])) << endl;
                		return 0;
            		case '?':
                		PrintHelp();
                		return 1;
        		}
    	}

    return 0;
}
