#pragma once 
#include <iostream>
using namespace std;

#include <ctime>  

//随机数类  
const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;
class RandomNumber
{
private:
	//当前种子  
	unsigned long randSeed;
public:
	void RandonNumber(unsigned long s = 0);//构造函数，默认值0表示由系统自动产生种子  
	unsigned short Random(unsigned long n);//产生0：n-1之间的随机整数  
	double fRandom(void);//产生[0,1)之间的随机实数  
};

void RandomNumber::RandonNumber(unsigned long s)//产生种子  
{
	if (s == 0)
		randSeed = time(0);//用系统时间产生种子  
	else
		randSeed = s;//由用户提供种子  
}
unsigned short RandomNumber::Random(unsigned long n)//产生0：n-1之间的随机整数  
{
	randSeed = multiplier * randSeed + adder;
	return (unsigned short)((randSeed >> 16) % n);
}
double RandomNumber::fRandom(void)//产生[0,1)之间的随机实数  
{
	return Random(maxshort) / double(maxshort);
}