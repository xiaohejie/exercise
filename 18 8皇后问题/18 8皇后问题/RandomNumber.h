#pragma once 
#include <iostream>
using namespace std;

#include <ctime>  

//�������  
const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;
class RandomNumber
{
private:
	//��ǰ����  
	unsigned long randSeed;
public:
	void RandonNumber(unsigned long s = 0);//���캯����Ĭ��ֵ0��ʾ��ϵͳ�Զ���������  
	unsigned short Random(unsigned long n);//����0��n-1֮����������  
	double fRandom(void);//����[0,1)֮������ʵ��  
};

void RandomNumber::RandonNumber(unsigned long s)//��������  
{
	if (s == 0)
		randSeed = time(0);//��ϵͳʱ���������  
	else
		randSeed = s;//���û��ṩ����  
}
unsigned short RandomNumber::Random(unsigned long n)//����0��n-1֮����������  
{
	randSeed = multiplier * randSeed + adder;
	return (unsigned short)((randSeed >> 16) % n);
}
double RandomNumber::fRandom(void)//����[0,1)֮������ʵ��  
{
	return Random(maxshort) / double(maxshort);
}