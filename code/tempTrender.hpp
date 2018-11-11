#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string.h>
#include "read.hpp"
#include "averages.hpp"

//using namespace std;

class tempTrender{
	private:
	double data[100][366];
	double averageTemperatureEachYear[100];
	double averageTemperatureDeviation[100];
	
	protected:	
	int numberOfYears;
	int startYear;
	char* filename;
<<<<<<< HEAD
	double discTresh;
	double discFlag;
	double averageTemperatureValue;
	//measures to discard are assigned with the temperature=discFlag.
	//for filtering: if(temperature<discTresh){discard}
=======
	float discTresh;
	float discFlag;
	float averageTemperatureEachYear[100];
	float averageTemperatureDeviation[100];
	float averageTemperatureValue;
	
>>>>>>> 9d3825ea2d4e6e8912191169849c3788633eaefa
	
	public:
	tempTrender(char* filePath)
	{
		filename = filePath;
<<<<<<< HEAD
		discTresh = -274.0;
		discFlag = -275.0;
=======
		startYear=0;
		discFlag = -275.0;//measures to discard are assigned with the temperature=discFlag.
		discTresh = -274.0;//for filtering: if(temperature<discTresh){discard}
>>>>>>> 9d3825ea2d4e6e8912191169849c3788633eaefa
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<366;j++)
			{
				data[i][j]=0.0;
			}
		}
	
		readData(filename, data, numberOfYears, startYear, discFlag);
		averageTemperature(data, numberOfYears, discTresh, averageTemperatureEachYear);
		averageTemperatureValue = averageValue(averageTemperatureEachYear, numberOfYears);
		deviation(averageTemperatureEachYear, numberOfYears, averageTemperatureValue, averageTemperatureDeviation);
	}; //Construct using the specified file
	~tempTrender() {} //Destructor
	
	//void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	//void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	//void tempPerDay(); //Make a histogram of the average temperature of each day of the year
	//void hotCold(); //Make a histogram of the hottest and coldest day of the year
	//void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year
	double getDiscTresh(){return discTresh;}
	double getDiscFlag(){return discFlag;}
	double getAverageTemperature()
	{
		return averageTemperatureValue;
	}
	int getStartYear()
	{
		return startYear;
	}
	int getNumberOfYears()
	{
		return numberOfYears;
	}
	void getAverageTemperatureEachYear(double array[])
	{
		for(int i; i<numberOfYears;i++)
		{
			array[i]=averageTemperatureEachYear[i];
		}
		return;
	}
	void getAverageTemperatureDeviation(double array[])
	{
		for(int i; i<numberOfYears;i++)
		{
			array[i]=averageTemperatureDeviation[i];
		}
		return;
	}
};

class Uppsala : public tempTrender{
	private:
	double data[300][366];
	double averageTemperatureEachYear[300];
	double averageTemperatureDeviation[300];
	public:
	Uppsala(char* filePath):tempTrender(filePath)
	{
		filename = filePath;
		discTresh = -274.0;
		discFlag = -275.0;
		for(int i=0;i<300;i++)
		{
			for(int j=0;j<366;j++)
			{
				data[i][j]=0.0;
			}
		}
	
		readUppsala(filename, data, numberOfYears, startYear,discFlag);
		averageTemperature(data, numberOfYears, discTresh, averageTemperatureEachYear);
		averageTemperatureValue = averageValue(averageTemperatureEachYear, numberOfYears);
		deviation(averageTemperatureEachYear, numberOfYears, averageTemperatureValue, averageTemperatureDeviation);
	}; //Construct using the specified file
	
	
};
#endif
