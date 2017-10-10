#include "graphs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


int IncidanceMatrix::getEdgeCount(){
	return m_EdgeCount;
}

vector<vector<int> >& IncidanceMatrix::getMatrix(){

	return m_Matrix;

};
IncidanceMatrix::~IncidanceMatrix()
{
	//m_Matrix.~vector();
}

int IncidanceMatrix::getPeakCount(){
	return m_PeakCount;
}

IncidanceMatrix::IncidanceMatrix(std::ifstream &Imatrix){
		int i=0; /*iteratory*/
	std::string CheckPeaks; /*tymczasowy string sluzacy do zliczenia ilosci wierzcholkow*/

/////////////BADANIE////PLIKU//////////////////////////////////////////////////////////////////

	std::getline(Imatrix, CheckPeaks); /*pobiera pierwszy wiersz z pliku*/

	//sprawdza czy plik czy ma zawartosc
	if(CheckPeaks.length()==0){std::perror("Plik jest pusty.");} //wrocmy
		else {
			m_PeakCount=1;
			m_EdgeCount=0;
		}

	//Zliczanie liczby wêz³ow
	m_EdgeCount=CheckPeaks.length()/2+1;
	if(m_EdgeCount==0){std::perror("Graf bezkrawêdziowy.");}


//////////////SCIAGANIE////MACIERZY/////////////////////////////////////////////////////////
	//Ustawienie fstream na pocz¹tek pliku
	Imatrix.seekg(0);
	//Zwiêkszenie liczby wierszy
	//Wczytanie  i zwiêszkenie liczby kolumn


	while(!Imatrix.eof()){
		m_Matrix.resize(m_PeakCount);
		m_Matrix[m_PeakCount-1].resize(m_EdgeCount);
		for (i=0;i<m_EdgeCount;i++){Imatrix >> m_Matrix[m_PeakCount-1][i];}
		m_PeakCount++;

	}
	m_PeakCount--;

}

//Konstruktor konwertuj¹cy macierz s¹siedztwa na macierz incydencji

IncidanceMatrix::IncidanceMatrix(AdjacencyMatrix & AMatrix){
	m_PeakCount=AMatrix.getPeakCount();
	m_EdgeCount=AMatrix.getEdgeCount();
	m_Matrix.resize(m_PeakCount);
	int i,j,k;
	k=0;
	for (i=0;i<m_PeakCount;i++)
    {
        m_Matrix[i].resize(m_EdgeCount);
    for(j=0; j<m_EdgeCount; j++) m_Matrix[i][j]=0;
    }
	for (i=0;i<m_PeakCount;i++){
		for(j=i;j<m_PeakCount;j++){
			if ((AMatrix.getMatrix())[i][j]==1){
				m_Matrix[i][k]=1;
				m_Matrix[j][k]=1;
				k++;
			}
		}
	}
}
