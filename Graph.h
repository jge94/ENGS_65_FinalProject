
#ifndef _GRAPH_
#define _GRAPH_

//-----------------------------------------------------------------------

#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

/**
 * An abstract class for a graph structure. A graph can be declared as either directed or undirected.
 * In the case of an undirected graph, methods outgoingEdges and incomingEdges return the same collection,
 * and outDegree and inDegree return the same value.
 *
 * Every vertex stores an element of type V (possibly null).
 * Every edge stores an element of type E (possibly null).
 *
 */

// Data structure for an Iterable

template<class T, class U>
struct Iterable
{
    T front;
    U end;

    Iterable(T begin, U ending)
    {
      front = begin;
      end = ending;
    }

    T front()
    {
        return front;
    }

    U end()
    {
        return end;
    }
};


template <class V, class E>
class Graph<V,E>
{
  public:
    /** Returns the number of vertices of the graph */
    virtual int numVertices();

    /** Returns the number of edges of the graph */
    virtual int numEdges();

    /** Returns the vertices of the graph as an iterable collection */
    virtual Iterable<Vertex<V>> vertices();         // maybe a list?

    /** Returns the edges of the graph as an iterable collection */
    virtual Iterable<Edge<E>> edges();

    /**
     * Returns the number of edges leaving vertex v.
     * Note that for an undirected graph, this is the same result
     * returned by inDegree
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    virtual int outDegree(Vertex<V> v);
    //throws IllegalArgumentException

    /**
     * Returns the number of edges for which vertex v is the destination.
     * Note that for an undirected graph, this is the same result
     * returned by outDegree
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    virtual int inDegree(Vertex<V> v);
    //throws IllegalArgumentException

    /**
     * Returns an iterable collection of edges for which vertex v is the origin.
     * Note that for an undirected graph, this is the same result
     * returned by incomingEdges.
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    virtual Iterable<Edge<E>> outgoingEdges(Vertex<V> v);
    //throws IllegalArgumentException

    /**
     * Returns an iterable collection of edges for which vertex v is the destination.
     * Note that for an undirected graph, this is the same result
     * returned by outgoingEdges.
     * @throws IllegalArgumentException if v is not a valid vertex
     */
    virtual Iterable<Edge<E>> incomingEdges(Vertex<V> v);
    //throws IllegalArgumentException

    /** Returns the edge from u to v, or null if they are not adjacent. */
    virtual Edge<E> getEdge(Vertex<V> u, Vertex<V> v);
    //throws IllegalArgumentException

    /**
     * Returns the vertices of edge e as an array of length two.
     * If the graph is directed, the first vertex is the origin, and
     * the second is the destination.  If the graph is undirected, the
     * order is arbitrary.
     */
    virtual Vertex<V>[] endVertices(Edge<E> e);
    //throws IllegalArgumentException

    /** Returns the vertex that is opposite vertex v on edge e. */
    virtual Vertex<V> opposite(Vertex<V> v, Edge<E> e);
    //throws IllegalArgumentException

    /** Inserts and returns a new vertex with the given element. */
    virtual Vertex<V> insertVertex(V element);

    /**
     * Inserts and returns a new edge between vertices u and v, storing given element.
     *
     * @throws IllegalArgumentException if u or v are invalid vertices, or if an edge already exists between u and v.
     */
    virtual Edge<E> insertEdge(Vertex<V> u, Vertex<V> v, E element);
    //throws IllegalArgumentException

    /** Removes a vertex and all its incident edges from the graph. */
    virtual void removeVertex(Vertex<V> v);
    //throws IllegalArgumentException

    /** Removes an edge from the graph. */
    virtual void removeEdge(Edge<E> e);
    //throws IllegalArgumentException
};


#endif
