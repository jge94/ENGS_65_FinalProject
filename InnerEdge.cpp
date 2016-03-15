//---------------- nested InnerEdge class ----------------
/** An edge between two vertices. */
template <class E>
class InnerEdge<E> : Edge<E> 
{
  private:
    E element;
    Position<Edge<E>> pos;
    Vertex<V>[] endpoints;

  public:
    /** Constructs InnerEdge instance from u to v, storing the given element. */
    InnerEdge(Vertex<V> u, Vertex<V> v, E elem) {
      element = elem;
      endpoints = (Vertex<V>[]) new Vertex[]{u,v};  // array of length 2
    }

    /** Returns the element associated with the edge. */
    E getElement() { return element; }

    /** Returns reference to the endpoint array. */
    Vertex<V>[] getEndpoints() { return endpoints; }

    /** Validates that this edge instance belongs to the given graph. */
    bool validate(Graph<V,E> graph) {
      return AdjacencyMapGraph.this == graph && pos != null;
    }

    /** Stores the position of this edge within the graph's vertex list. */
    void setPosition(Position<Edge<E>> p) { pos = p; }

    /** Returns the position of this edge within the graph's vertex list. */
    Position<Edge<E>> getPosition() { return pos; }
} //------------ end of InnerEdge class ------------