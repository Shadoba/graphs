#include "graphs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


AdjacencyList::~AdjacencyList(){}
//	int i=0,j=0; //iteratory

//AdjacencyList::AdjacencyList(std::ifstream & AList)
//{
//	std::string CheckPeaks; //Zmienna string przetrzymujaca pierwszy wiersz pliku
//	m_PeakCount = 0;
//
//	//-------------------------OPERACJE WCZYTYWANIA I ANALIZY PLIKU-----------------------------
//	std::getline(AList, CheckPeaks); //Pobranie zawartoœci pliku
//	int tmp, tmp2=0, tmp3;
//	AList.seekg(0);
//    while (CheckPeaks.length()!=0)
//	{
//	    m_PeakCount++;
//        m_List.resize(PeakCount);
//        tmp = CheckPeaks.length()/2+1;
//        tmp2 += CheckPeaks.length();
//
//	    for(int i=0; i<tmp; i++)
//        {
//            AList>>tmp3;
//            m_List[m_PeakCount-1].push_back(tmp3);
//        }
//        std::getline(AList, CheckPeaks); //Pobranie zawartoœci pliku
//        AList.seekg(tmp2);
//	}
//}
AdjacencyList::AdjacencyList(std::ifstream& AList)
{
	std::string tmp;
	unsigned int it;
	m_NodeCount=0;
	while(!AList.eof())
    {
		std::getline(AList, tmp);
		m_NodeCount++;
		m_List.resize(m_NodeCount);
		for( it=0 ; it < tmp.length() ; it+=2 )
        {
			m_List[m_NodeCount-1].push_back( atoi( &tmp[it] ) );
		}
	}
}

AdjacencyList::AdjacencyList(IncidanceMatrix & IMatrix){

	m_List.resize(IMatrix.getPeakCount());
	m_NodeCount=IMatrix.getPeakCount();
	int k;
	k=IMatrix.getEdgeCount();
	int i,j,fir,sec;
	fir=-1;
	sec=0;
	for(i=0;i<k;i++)
    {
		for(j=0;j<m_NodeCount;j++){
			if((IMatrix.getMatrix())[j][i]==1){
				if(fir==-1){fir=j;}
				sec=j;

			}
		}
		m_List[fir].push_back(sec+1);
		m_List[sec].push_back(fir+1);

		fir=-1;
		sec=-1;
	}

};

int AdjacencyList::getNodeCount(){
	return m_NodeCount;
};


vector<vector<int> >& AdjacencyList::getList(){

	return m_List;

};
