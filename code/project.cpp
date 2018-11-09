#include "tempTrender.hpp"
#include <string>

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
	path="/home/courseuser/rootproject/Climate-Back-to-Root/datasets/uppsala_tm_1722-2013.dat";
	Uppsala uppsala(strdup(path.c_str()));
	
	
}
