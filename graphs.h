#ifndef __graphs_h__
#define __graphs_h__
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <wx/msgdlg.h>
#include "wx_pch.h"

using namespace std;

class IncidanceMatrix;
class AdjacencyList;
class AdjacencyMatrix
{
	private:

		vector<vector<int> > m_Matrix;
		int m_PeakCount;

	public:

		//--------------------------KONSTRUKTORY-----------------------------
		~AdjacencyMatrix();                				//Destruktor domyślny
		AdjacencyMatrix();
		AdjacencyMatrix(std::ifstream & AMatrix);      	//Konstruktor tworzący macierz Sąsiedztwa z pliku
		AdjacencyMatrix(AdjacencyList & AList);			//Konstruktor konwertujący listę sąsiedztwa do macierzy sąsiedztwa
		//--------------------------METODY-----------------------------
		int **getAdjacencyMatrixPointer();         		//Fkcja zwracająca wskaźnik na macierz
		int getPeakCount();
		int getEdgeCount();
		vector<vector<int> >& getMatrix();				//Fkcja zwracająca liczbę węzłow
		static void GenarateRandomGraph_N_L(AdjacencyMatrix &AM, int i, double l);
		void Clear();
};

class IncidanceMatrix
{
	private:

		vector<vector<int> > m_Matrix;
		int m_PeakCount;
		int m_EdgeCount;
	public:

		//--------------------------KONSTRUKTORY-----------------------------
		~IncidanceMatrix();                			//Destruktor domyślny
		IncidanceMatrix() : m_PeakCount(0) {}
		IncidanceMatrix(std::ifstream &IMatrix); 	//Konstruktor tworzący macierz Incydencje z pliku
		IncidanceMatrix(AdjacencyMatrix & AMatrix);	//Konstruktor konwertujący macierz sąsiedztwa na macierz incydencji
		//--------------------------METODY-----------------------------
		int **getIncidanceMatrixPointer();          //Fkcja zwracająca wskaźnik na macierz
		int getPeakCount();                         //Fkcja zwracająca liczbę węzłow
		int getEdgeCount();							//Fkcja zwracająca liczbę krawędzi
		vector<vector<int> >& getMatrix();			//Fkcja zwaracająca Macierz Incydencji
};

class AdjacencyList
{
	private:

		vector<vector<int> > m_List;
		int m_NodeCount;

	public:

		//--------------------------KONSTRUKTORY-----------------------------
		~AdjacencyList();                			//Destruktor domyślny
		AdjacencyList(std::ifstream & AList);     //Konstruktor tworzący listę sąsiedztwa z pliku
		AdjacencyList() : m_NodeCount(0) {}
		AdjacencyList(IncidanceMatrix & IMatrix);	//Konstruktor konwertujący macierz incydencji na listę sąsiedztwa
		//--------------------------METODY-----------------------------
		int **getAdjacencyMatrixPointer();          //Fkcja zwracająca wskaźnik na macierz
		int getNodeCount();                         //Fkcja zwracająca liczbę węzłów
		vector<vector<int> >& getList();			//Fkcja zwaracająca Listę Sąsiedztwa
};


#endif
