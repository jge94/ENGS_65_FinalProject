#ifndef ADJ_MAP_GRAPH
#define ADJ_MAP_GRAPH

template <class V, class E>
class AdjacencyMapGraph<V,E>: public Graph<V,E> 
{
  private:
    bool isDirected;
    Vertex<V>* vertices = new Vertex<V>[1000];
    Edge<E>* edges = new Edge<E>[1000];
    // PositionalList<Vertex<V>> vertices = new LinkedPositionalList<>();
    // PositionalList<Edge<E>> edges = new LinkedPositionalList<>();

    InnerVertex<V> validate(Vertex<V> v);
    InnerEdge<E> validate(Edge<E> e);

  public:
    /**
     * Constructs an empty graph.
     * The parameter determines whether this is an undirected or directed graph.
     */
    AdjacencyMapGraph(boolean directed);

    /** Returns the number of vertices of the graph */
    int numVertices();

    /** Returns the vertices of the graph as an iterable collection */
    Vertex<V>* vertices() { return vertices; }

    /** Returns the number of edges of the graph */
    int numEdges();

    /** Returns the edges of the graph as an iterable collection */
    Edge<E>* edges() { return edges; }

    /**
     * Returns the number of edges for which vertex v is the origin.
     * Note that for an undirected graph, this is the same result
     * returned by inDegree(v).
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    int outDegree(Vertex<V> v);
        // throws IllegalArgumentException 

    /**
     * Returns an iterable collection of edges for which vertex v is the origin.
     * Note that for an undirected graph, this is the same result
     * returned by incomingEdges(v).
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    Edge<E>* outgoingEdges(Vertex<V> v);
 // throws IllegalArgumentException 

    /**
     * Returns the number of edges for which vertex v is the destination.
     * Note that for an undirected graph, this is the same result
     * returned by outDegree(v).
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    int inDegree(Vertex<V> v);
     // throws IllegalArgumentException 

    /**
     * Returns an iterable collection of edges for which vertex v is the destination.
     * Note that for an undirected graph, this is the same result
     * returned by outgoingEdges(v).
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    Edge<E>* incomingEdges(Vertex<V> v);
     // throws IllegalArgumentException 

    /** Returns the edge from u to v, or null if they are not adjacent. */
    Edge<E> getEdge(Vertex<V> u, Vertex<V> v);

    /**
     * Returns the vertices of edge e as an array of length two.
     * If the graph is directed, the first vertex is the origin, and
     * the second is the destination.  If the graph is undirected, the
     * order is arbitrary.
     */
    Vertex<V>[] endVertices(Edge<E> e);

    /** Returns the vertex that is opposite vertex v on edge e. */
    Vertex<V> opposite(Vertex<V> v, Edge<E> e);

    /** Inserts and returns a new vertex with the given element. */
    Vertex<V> insertVertex(V element);

    /**
     * Inserts and returns a new edge between vertices u and v, storing given element.
     *
     * @throws IllegalArgumentException if u or v are invalid vertices, or if an edge already exists between u and v.
     */
    Edge<E> insertEdge(Vertex<V> u, Vertex<V> v, E element);

    /** Removes a vertex and all its incident edges from the graph. */
    void removeVertex(Vertex<V> v);

    /** Removes an edge from the graph. */
    void removeEdge(Edge<E> e);

    /**
     * Returns a string representation of the graph.
     * This is used only for debugging; do not rely on the string representation.
     */
    char* print();
};

#endif