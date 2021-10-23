#include "PriorityQueue.h"
#include "Ticket.cpp"

class DependencyGraph {
private:
  int **adjMat;
  static const int INF = 9999999;
  int numberVertices;
  int size;

public:
  Ticket **vertices;

  DependencyGraph(int size) {
    this->size = size;
    numberVertices = 0;

    vertices = new Ticket *[size];

    adjMat = new int *[size];
    for (int i = 0; i < size; i++) {
      adjMat[i] = new int[size];

      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          adjMat[i][j] = INF;
        }
      }
    }
  }

  void AddEdge(int start, int end, int weight) {
    cout << start << endl;
    adjMat[start][end] = weight;
  }
  void AddVertex(Ticket *vertex) {
    vertices[numberVertices] = vertex;
    numberVertices++;
  }

  void Display() {
    cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI" << endl;
    for (int i = 0; i < size; i++) {
      cout << vertices[i]->name << endl;
      for (int j = 0; j < size; j++) {
        cout << adjMat[i][j] << "\t";
        cout << endl;
      }
    }
  }
  PriorityQueue<Ticket> *GetAdjacentVertices(Ticket *vertex) {
    PriorityQueue<Ticket> *adjacent =
        new PriorityQueue<Ticket>(numberVertices);
    for (int j = 0; j < numberVertices; j++)
      if (adjMat[vertex->key][j] != INF)
        adjacent->Insert(vertices[j]);
    return adjacent;
  }

  int GetNumberVertices() { return numberVertices; }
};