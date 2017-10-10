#include "graphs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

AdjacencyList::~AdjacencyList(){}

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

AdjacencyList::AdjacencyList(IncidanceMatrix & IMatrix)
{
	m_List.resize(IMatrix.getPeakCount());
	m_NodeCount=IMatrix.getPeakCount();
	int k;
	k=IMatrix.getEdgeCount();
	int i,j,fir,sec;
	fir=-1;
	sec=0;
	for(i=0;i<k;i++)
 	{
		for(j=0;j<m_NodeCount;j++)
		{
			if((IMatrix.getMatrix())[j][i]==1)
			{
				if(fir==-1){fir=j;}
				sec=j;
			}
		}
		m_List[fir].push_back(sec+1);
		m_List[sec].push_back(fir+1);

		fir=-1;
		sec=-1;
	}

}

int AdjacencyList::getNodeCount()
{
	return m_NodeCount;
}

vector<vector<int> >& AdjacencyList::getList()
{
	return m_List;
}
