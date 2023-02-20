#include <headers/fhandle.hpp>
#include <headers/globals.hpp>
#include <headers/vector.hpp>
#include <headers/matrix.hpp>
#include <headers/constants.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int ftask(const char *taskfile)
{
	ifstream infile;
	std::string string, keywords, temp;
	double value_d;
	double value_i;
	int i = 0;
	long long tempi;
	infile.open(taskfile);

	if (infile.is_open()){
		while(getline(infile,string)){
			istringstream sstream(string);
			sstream >> keywords;
			if(keywords == "filename_trans") 	sstream >> filename_trans;


			if(keywords == "use_randv") 	sstream >> use_randv;
			if(keywords == "initv") 	sstream >> initv.x >>initv.y>>initv.z;

			if(keywords == "numberofions") 	sstream >> numberofions;
			if(keywords == "radiusofions") 	sstream >> radiusofions;
			if(keywords == "mass_Da") 	sstream >> mass_Da;
			if(keywords == "q_net") 	sstream >> q_net;

			if(keywords == "nstep_trans") 	sstream  >> nstep_trans;
			if(keywords == "dt_trans") 	sstream  >> dt_trans;
			if(keywords == "nstep_trans_save") 	sstream >> nstep_trans_save;
			if(keywords == "nstep_trans_show") 	sstream >> nstep_trans_show;

			if(keywords == "bUeff") 	sstream  >> bUeff;
			if(keywords == "Urf") 	sstream  >> Urf;
			if(keywords == "frf") 	sstream  >> frf;
			if(keywords == "Uac") 	sstream  >> Uac;	
			if(keywords == "fac") 	sstream  >> fac;	

			if(keywords == "damp1") 	sstream  >> damp1;	
			if(keywords == "damp2") 	sstream  >> damp2;	
			
			if(keywords == "temperature") 	sstream  >> temperature;
			
			if(keywords == "seed") 	sstream  >> seed;

			i++;
		}
		infile.clear();
		infile.close();
		if(1)
		{
			cout<<"filename_trans"<<"\t"<<filename_trans<<endl;

			cout<<"initv"<<"\t"<<initv.x<<","<<initv.y<<","<<initv.z<<endl;
			cout<<"use_randv"<<"\t"<<use_randv<<endl;

			cout<<"numberofions"<<"\t"<<numberofions<<endl;
			cout<<"radiusofions"<<"\t"<<radiusofions<<endl;
			cout<<"mass_Da"<<"\t"<<mass_Da<<endl;
			cout<<"q_net"<<"\t"<<q_net<<endl;

		
			cout<<"nstep_trans"<<"\t"<<nstep_trans<<endl;
			cout<<"dt_trans"<<"\t"<<dt_trans<<endl;
			cout<<"nstep_trans_save"<<"\t"<<nstep_trans_save<<endl;	
			cout<<"nstep_trans_show"<<"\t"<<nstep_trans_show<<endl;	

			cout<<"Urf"<<"\t"<<Urf<<endl;
			cout<<"frf"<<"\t"<<frf<<endl;
			cout<<"Uac"<<"\t"<<Uac<<endl;
			cout<<"fac"<<"\t"<<fac<<endl;

			cout<<"damp1"<<"\t"<<damp1<<endl;
			cout<<"damp2"<<"\t"<<damp2<<endl;

			cout<<"temperature"<<"\t"<<temperature<<endl;

			cout<<"seed"<<"\t"<<seed<<endl;
		}

		return 0;
	}
	return 1;
}
