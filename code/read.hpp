#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readData(char* filename, float dataArray[][366], int& numberOfYears, int& startYear, float discFlag)
{
	ifstream fileIn;
	fileIn.open(filename);
	
	char ch;
	char datum[4];
	string trash;
	
	while(fileIn>>ch)
	{
		if(ch=='D')
		{
			fileIn>>datum[0]>>datum[1]>>datum[2]>>datum[3];
			if(datum[0]=='a'&&datum[1]=='t'&&datum[2]=='u'&&datum[3]=='m')
			{
				getline(fileIn, trash);
				break;
			}
		}
	}
	
	bool startWriting=false, isGood=true;
	int year, year_index=0,day_index=0;
	string date="", new_date;
	float temperature;
	char quality;
	while(fileIn>>year)
	{
		getline(fileIn, new_date, ';');
		if(new_date=="-01-01"&&date=="")
		{
			startWriting=true;
			date=new_date;
			startYear=year;
		}
		if(date=="-12-31"&&new_date=="-01-01")
		{
			for(day_index;day_index<366;day_index++)
			{
				dataArray[year_index][day_index]=discFlag;
			}
			day_index=0;
			year_index++;
		}
		getline(fileIn, trash, ';');
		fileIn>>temperature>>ch>>quality;
		getline(fileIn, trash);
		if(date!=new_date)
		{
			if(isGood)
			{
				dataArray[year_index][day_index]=temperature/3;
			}
			else
			{
				dataArray[year_index][day_index]=discFlag;
			}
			day_index++;
			isGood=true;
		}
		if(startWriting)
		{
			dataArray[year_index][day_index]+=temperature;
			if(quality!='G')
			{
				isGood=false;
			}
		}
	}
	numberOfYears=year_index;
	fileIn.close();
	return;
}

void readUppsala(char* filename, float dataArray[][366], int& numberOfYears, int& startYear, float discFlag)
{
	ifstream fileIn;
	fileIn.open(filename);
	
	bool startWriting=false;
	int year,year_index=0,day_index=0,month,day,dataId;
	float temperature, other;
	
	while(fileIn>>year>>month>>day>>temperature>>other>>dataId)
	{
		if(month==1 && day==1 && !startWriting)
		{
			startWriting=true;
			startYear=year;
		}
		if(startWriting)
		{
			if(dataId==1)
			{
				dataArray[year_index][day_index]=temperature;
			}
			else
			{
				dataArray[year_index][day_index]=discFlag;
			}
			if(month==12&&day==31)
			{
				for(day_index;day_index<366;day_index++)
				{
					dataArray[year_index][day_index]=discFlag;
				}
				day_index=0;
				year_index++;
			}
		}
	}
	numberOfYears=year_index;
	fileIn.close();
	return;
}
