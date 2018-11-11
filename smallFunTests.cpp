#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //for atoi() and atof()
#include <stdio.h>
#include <string.h>

#include <TF1.h> // 1d function class
#include <TMath.h>	 // math functions
#include <TRandom.h> // random number generator
#include <TGraph.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TMath.h>
#include <TAxis.h>

using namespace std;

void histTest()
{
	TH1I* intHist = new TH1I ("", "Test", 5, 1, 5+1);
	for(int i=-1;i<10;i++) intHist->Fill(i,i);
	intHist->SetBarOffset(4.2);
	
	TCanvas* meanTempCanv = new TCanvas("meanTemps", "mean temperature over all years recorded", 1280, 720);
	intHist->SetFillColor(2);

	//TAxis* offset= new TAxis(30, 0, 15);
	intHist->fHistFillColor(2);
    intHist->Draw("BCL");
}


