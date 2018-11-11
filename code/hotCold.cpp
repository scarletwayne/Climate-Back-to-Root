#include "randDegGen.cpp"
#include <fstream>
#include <iostream>
#include <TCanvas.h>
#include <TH1.h>
#include <TMath.h>
#include <algorithm>

int findHot(float degs[][366],int yearIndex);
int findCold(float degs[][366], int yearIndex);
void plotHotCold(int hottestArr[], int coldestArr[], int totYears);


void hotCold()
{
	int totYears=300;
	float degMatr[totYears][366];
	randDegGen(degMatr,totYears); //will be replaced by function filling the matrix with the actual data
	int hottest[totYears]; int coldest[totYears];
	
	for(int yearIndex=0;yearIndex<totYears;yearIndex++)
	{
		//findCold(DegMatr, yearIndex);
		hottest[yearIndex]=1+distance(&degMatr[yearIndex][0] , max_element( &degMatr[yearIndex][0], &degMatr[yearIndex][365] ));
		coldest[yearIndex]=findCold(degMatr, yearIndex);
		//OBS: after this point, we will use Jan01 = 1 (not 0 anymore)
	}
	
	plotHotCold(hottest, coldest, totYears);
	
}


int findHot(float degs[][366],int yearIndex)
{
	return 1+distance(max_element( &degs[yearIndex][0], &degs[yearIndex][365] ),&degs[yearIndex][0]);
}

int findCold(float degs[][366], int yearIndex)
{
	int coldestTillNow=0;
	for(int dayIndex=1; dayIndex<366; dayIndex++)
	{
		if(degs[yearIndex][dayIndex]<-274) continue; //discard day right away
		if(degs[yearIndex][dayIndex]<degs[yearIndex][coldestTillNow]) coldestTillNow=dayIndex;
	}
	return (coldestTillNow++);
}

void plotHotCold( int hottest[], int coldest[], int totYears )
{
	TH1I* meanTempHistHot = new TH1I("hottest days", "frequentness of hottest days;number of day in year;counts", 366, 1, 367);
	TH1I* meanTempHistCold= new TH1I("coldest days", "frequentness of coldest days;number of day in year;counts", 366, 1, 367);
	TCanvas* hotColdCanv = new TCanvas("hottest-coldest", "frequency of hottest and coldest days", 1280, 720);
	for(int yearIndex=0; yearIndex<totYears; yearIndex++)
	{
		meanTempHistHot->Fill(hottest[yearIndex]);
		meanTempHistCold->Fill(coldest[yearIndex]);
	}
	meanTempHistHot->SetFillColor(2); meanTempHistCold->SetFillColor(4);
	meanTempHistHot->Draw("BL"); meanTempHistCold->Draw("BC SAME");
	
	meanTempHistHot->Fit("gaus","Q","C");
	
	
	/*for coldest days fit: 
	 *first make new histogram (that is not drawn) with coldest days shifted and fit to these values
	 *then don't draw the fit directly but retrieve the parameters
	 *then use the parameters to make two new functions which are identical to the fit functions but use the appropiate ranges for the boundaries
	*/ 
}
