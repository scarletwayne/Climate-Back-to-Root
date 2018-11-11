<<<<<<< HEAD
void averageTemperature(double temperature[][366], int numberOfYears, double treshold, double averageTemperatureArray[])
=======
void averageTemperature( float temperature[][366], int numberOfYears, float treshold, float averageTemperatureArray[] )
>>>>>>> 9d3825ea2d4e6e8912191169849c3788633eaefa
{
	int daysConsidered=366;
	for(int yearIndex=0;yearIndex<numberOfYears;yearIndex++)
	{
		averageTemperatureArray[yearIndex] = 0;
		for(int dayIndex=0;dayIndex<366;dayIndex++)
		{
<<<<<<< HEAD
			if(temperature[year][day]<-200)
			{
				daysConsidered--;
				continue;
			}			
			averageTemperatureArray[year]+=temperature[year][day];
		}
		if(daysConsidered==0)
		{
			averageTemperatureArray[year]=-275;
		}
		else
		{
			averageTemperatureArray[year]/=daysConsidered;
		}
=======
			if(temperature[yearIndex][dayIndex]<treshold) //if element has been set with discFlag
			{
				daysConsidered--; //decrement to compensate averaging because of missing element
				continue; //effectively discard element by not summing it up
			}
			averageTemperatureArray[yearIndex]+=temperature[yearIndex][dayIndex];
		}
		averageTemperatureArray[yearIndex]/=daysConsidered;
>>>>>>> 9d3825ea2d4e6e8912191169849c3788633eaefa
	}
	return;
}

<<<<<<< HEAD
double averageValue(double array[], int effectiveLength)
{
	double average=0;
	int n=effectiveLength;
	for(int i=0;i<effectiveLength;i++)
=======
float overallAverageValue( float array[], int effArrSpan )
{
	float average=0;
	for(int i=0; i<effArrSpan; i++)
>>>>>>> 9d3825ea2d4e6e8912191169849c3788633eaefa
	{
		if(array[i]<-274)
		{
			n--;
		}
		else
		{
			average+=array[i];
		}
	}
<<<<<<< HEAD
	average/=n;
	return average;
}

void deviation(double array[], int effectiveLength, double average, double deviationArray[])
=======
	average/=effArrSpan;
	return average;
}
/*
void residuals( float array[], int effArrSpan, float average, float residualsArray[] )
>>>>>>> 9d3825ea2d4e6e8912191169849c3788633eaefa
{
	for(int i=0;i<effArrSpan;i++)
	{
		residualsArray[i]=array[i]-average;
	}
	return;
}
*/


void averageTemperatureResidualsPlot ( float yearAvgArr[]/*meant to be the residuals*/, int effArrSpan, int startYear )
{
	TCanvas* meanTempCanv = new TCanvas("meanTemps", "mean temperature over all years recorded", 1280, 720);
	TH1F* meanTempHistHot= new TH1F("mean temperatures", "mean temperature over all years recorded;year;temperature (°C)", effArrSpan, startYear, startYear+effArrSpan);
	for(int yearIndex=0;yearIndex<effArrSpan; yearIndex++)
	{
		if(yearAvgArr[yearIndex]>0)
		{
			meanTempHistHot->Fill( yearIndex , yearAvgArr[yearIndex] ); //fill the hist accordingly
		}
		else
		{
			meanTempHistCold->Fill(yearIndex , yearAvgArr(yearIndex] );
		}
		meanTempHistHot->Draw("BCL"); meanTempHistCold->Draw("same");
	}
	
	
	
}

