#include "tempTrender.hpp"
#include <string>
#include <iostream>

#include <TF1.h> 
#include <TH1.h> 
#include <TGraph.h> 
#include <TStyle.h> 
#include <TMath.h> 
#include <TFrame.h> 
#include <TCanvas.h>

using namespace std;

void project() {
	string path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Boras.csv";
	tempTrender boras(strdup(path.c_str()));
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Falsterbo.csv";
	tempTrender falsterbo(strdup(path.c_str()));
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Falun.csv";
	tempTrender falun(strdup(path.c_str()));
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Karlstad.csv";
	tempTrender karlstad(strdup(path.c_str()));
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Lulea.csv";
	tempTrender lulea(strdup(path.c_str()));
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Lund.csv";
	tempTrender lund(strdup(path.c_str()));
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Soderarm.csv";
	tempTrender soderarm(strdup(path.c_str()));
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Umea.csv";
	tempTrender umea(strdup(path.c_str()));	
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/Visby.csv";
	tempTrender visby(strdup(path.c_str()));
	TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

    c1->SetFillColor(42);
    c1->SetGrid();
	
	int n=100;
	double year[100];
	double avgTemperature[100];
	int i=0;
	
	n=boras.getNumberOfYears();
	for(i=0;i<n;i++)
	{
		year[i]=double(boras.getStartYear()+i);
	}
	boras.getAverageTemperatureEachYear(avgTemperature);
	
	for(i=0;i<n;)
	{
		if(avgTemperature[i]<-274)
		{
			n--;
			for(int j=i;j<n;j++)
			{
				year[j]=year[j+1];
				avgTemperature[j]=avgTemperature[j+1];
			}
		}
		else
		{
			i++;
		}
	}
	
    TGraph* gr1 = new TGraph(n,year,avgTemperature);
	gr1->SetLineColor(2);
	gr1->SetLineWidth(4);
	gr1->SetMarkerColor(4);
	gr1->SetMarkerStyle(21);
	gr1->SetTitle("Average temperature");
	gr1->GetXaxis()->SetTitle("year");
	gr1->GetYaxis()->SetTitle("average temperature, degrees Celsius");
	gr1->Draw("ACP");

	// TCanvas::Update() draws the frame, after which one can change it
	c1->Update();
	c1->GetFrame()->SetFillColor(21);
	c1->GetFrame()->SetBorderSize(12);
	c1->Modified();
}
