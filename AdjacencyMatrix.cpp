#include "graphs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <random>
#include "time.h"
// AdjacencyMatrix::AdjacencyMatrix(int peakcount)
// {
	// m_PeakCount=peakcount;
/////////Tworzenie pustej macierzy////////////
	// m_Matrix=new int *[m_PeakCount];
	// for(int i=0; i<m_Peakcount; i++)
	// {
		// m_Matrix[i]=new int [m_PeakCount];
	// }
/////////Uzupe³nainie macierzy////////////////
	// std::cout<<"podawaj ilosc krawedzi dla wezlow: "<<std::endl;
	// for (int i=0; i<m_PeakCount; i++)
	// {
		// int p=0;
		// for (int j=p; i<m_PeakCount; j++)
		// {
			// std::cout<<i<<"-"<<2<<"		";
			// std::cin>>m_Matrix[i+1][j+1];
		// }
		// p++;
	// }
// }



AdjacencyMatrix::~AdjacencyMatrix()
{
    for(int i=0; i<m_PeakCount; i++)
    {
        m_Matrix[i].clear();
    }
    m_Matrix.clear();
    //m_Matrix.~vector();
}


int AdjacencyMatrix::getPeakCount(){
	return m_PeakCount;
}

int AdjacencyMatrix::getEdgeCount(){
	int n=this->getPeakCount();
	int edges=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){

				edges+=m_Matrix[i][j];

			}
		}
		return edges;
};

vector<vector<int> >& AdjacencyMatrix::getMatrix(){

	return m_Matrix;
};

AdjacencyMatrix::AdjacencyMatrix(std::ifstream & AMatrix)
{
	int i=0,j=0; //iteratory
	std::string CheckPeaks; //Zmienna string przetrzymujaca pierwszy wiersz pliku

	//-------------------------OPERACJE WCZYTYWANIA I ANALIZY PLIKU-----------------------------

	std::getline(AMatrix, CheckPeaks); //Pobranie zawartoœci pliku

	//Sprawdzenie czy plik nie jest pusty

	if(CheckPeaks.length()==0){std::perror("Plik jest pusty.");}
		else {m_PeakCount =1;}

	//Obliczenie liczby wêz³ów

	m_PeakCount+=CheckPeaks.length()/2;


	//----------------------------WCZYTANIE MACIERZY Z PLIKU--------------------------

	//Ustawienie fstream na pocz¹tek pliku
	AMatrix.seekg(0);
	//Poszerzenie macierzy o zadan¹ liczbê wierszy
	m_Matrix.resize(m_PeakCount);
	//Poszerzenie macierzy o zadan¹ liczbê kolumn oraz wczyranie danych z pliku
	for (i = 0; i < m_PeakCount; i++) {
		m_Matrix[i].resize(m_PeakCount);

		for (j = 0; j < m_PeakCount; j++) {
			AMatrix >> m_Matrix[i][j];
		}
	}

//	m_PeakCount = AMatrix[0].size();
//	m_Matrix.resize(m_PeakCount);
//	for (int i = 0; i < m_PeakCount; i++)
//    {
//        m_Matrix[i].resize(m_PeakCount);
//		for (int j = 0; j < m_PeakCount; j++)
//        {
//			m_Matrix[i][j] = AMatrix[i][j];
//		}
//	}


};

AdjacencyMatrix::AdjacencyMatrix()
{
    m_PeakCount=0;
}

AdjacencyMatrix::AdjacencyMatrix(AdjacencyList & AList){

	m_PeakCount=AList.getNodeCount();
	m_Matrix.resize(m_PeakCount);
	int i,j;
	for(i=0;i<m_PeakCount;i++){
		m_Matrix[i].resize(m_PeakCount);
		for(j=0;j<(int)(AList.getList())[i].size();j++){
			m_Matrix[i][(AList.getList())[i][j]-1]=1;
		}
	}

};

void AdjacencyMatrix::GenarateRandomGraph_N_L(AdjacencyMatrix & AM,int n, double l)
{
    srand(time(NULL));
    AM.m_PeakCount = n;
    AM.m_Matrix.resize(AM.m_PeakCount);
    for(int i=0; i<AM.m_PeakCount; i++)
    {
        AM.m_Matrix[i].resize(AM.m_PeakCount);
        for(int j =0 ; j<AM.m_PeakCount; j++)
        {
            AM.m_Matrix[i][j]=0;
        }
    }

    double P2;
    int MaximumEdge = AM.m_PeakCount*(AM.m_PeakCount-1)/2;
    if (l<0) l=-l;
    if (l<1)
    {
        for(int i=0; i<AM.m_PeakCount; i++)
        {
            for(int j=i+1; j<AM.m_PeakCount; j++)
            {
                P2 = (double)(std::rand()%(MaximumEdge+1))/(double)MaximumEdge;
                if (P2<=l)
                {
                    AM.m_Matrix[i][j]=1;
                    AM.m_Matrix[j][i]=1;
                }
            }
        }
    }
    else
    {
        int l2(l);
        FILE *fp;
         fp=fopen("fp", "w");

        if (l>MaximumEdge) l2 = MaximumEdge;
        double P;
        while (l2>0)
        {
            for(int i=0; i<AM.m_PeakCount; i++)
            {
                for(int j=i+1; j<AM.m_PeakCount; j++)
                {
                    P = ((double)MaximumEdge-l2)/(double)MaximumEdge;
                    P2 = ((std::rand()%(MaximumEdge)))/(double)MaximumEdge;
                    if (P2>=P && AM.m_Matrix[i][j]==0)
                    {
                        AM.m_Matrix[i][j]=1;
                        AM.m_Matrix[j][i]=1;
                       // MaximumEdge--;
                        l2--;
                        fprintf(fp,"%lf ", l2);
                        //if(l<0) break;
                    }
    //            if (l>0 && AM.m_Matrix[i][j]!=1)
    //                {AM.m_Matrix[i][j]=std::rand()%2; if(AM.m_Matrix[i][j]) l--;}
    //            else
    //                AM.m_Matrix[i][j]=0;
    //                AM.m_Matrix[j][i]=AM.m_Matrix[i][j];
                }
          //  if(l>0 && i==AM.m_PeakCount-1) i=0;
            }
        }
        fclose(fp);
    }

}

void AdjacencyMatrix::Clear()
{
    if (m_PeakCount>=1)
    {
        for(int i=0; i<m_PeakCount; i++)
        {
            m_Matrix[i].clear();
        }
        m_Matrix.clear();
    }
}

