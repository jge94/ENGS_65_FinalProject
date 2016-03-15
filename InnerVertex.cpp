
//---------------- nested Vertex class ----------------
/** A vertex of an adjacency map graph representation. */

#include <iostream>
#include <string>

using namespace std;

template <class V>
class InnerVertex<V>: Vertex<V> 
{
private:
  V element;
  Position<Vertex<V>> pos;
  Map<Vertex<V>, Edge<E>> outgoing, incoming;

public:
  /** Constructs a new InnerVertex instance storing the given element. */
  InnerVertex(V elem, boolean graphIsDirected) {
    element = elem;
    outgoing = new ProbeHashMap<>();
    if (graphIsDirected)
      incoming = new ProbeHashMap<>();
    else
      incoming = outgoing;    // if undirected, alias outgoing map
  }

  /** Validates that this vertex instance belongs to the given graph. */
  bool validate(Graph<V,E> graph) {
    return (AdjacencyMapGraph.this == graph && pos != null);
  }

  /** Returns the element associated with the vertex. */
  V getElement() { return element; }

  /** Stores the position of this vertex within the graph's vertex list. */
  void setPosition(Position<Vertex<V>> p) { pos = p; }

  /** Returns the position of this vertex within the graph's vertex list. */
  Position<Vertex<V>> getPosition() { return pos; }

  /** Returns reference to the underlying map of outgoing edges. */
  Map<Vertex<V>, Edge<E>> getOutgoing() { return outgoing; }

  /** Returns reference to the underlying map of incoming edges. */
  Map<Vertex<V>, Edge<E>> getIncoming() { return incoming; }
} //------------ end of InnerVertex class ------------