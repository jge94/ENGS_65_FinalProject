#include <iostream>
#include <string>
#include "AdjacencyMapGraph.h"

using namespace std;

/**
 * An implementation for a graph structure using an adjacency map for each vertex.
 *
 * Every vertex stores an element of type V.
 * Every edge stores an element of type E.
 *
 * @author Jinnan Ge
 */

template <class V, class E>

/**
 * Constructs an empty graph.
 * The parameter determines whether this is an undirected or directed graph.
 */
AdjacencyMapGraph::AdjacencyMapGraph(boolean directed) 
{ 
  for(int i = 0; i<1000; i++)
  {
    vertices[i] = NULL;
    edge[i] = NULL;
  }

  isDirected = directed; 
}

/** Returns the number of vertices of the graph */
int AdjacencyMapGraph::numVertices() 
{
  int count = 0;
  for(int i = 0; i<1000; i++)
  {
    if(vertices[i] != NULL)
    {
      count++;
    }
  }
  return count;
  // return vertices.size(); 
}


/** Returns the number of edges of the graph */
int AdjacencyMapGraph::numEdges() 
{ 
  if(edges[i] != NULL)
    {
      count++;
    }
  }
  return count;
}；

/** Returns the edges of the graph as an iterable collection */
// Edge<E>* AdjacencyMapGraph::edges() { return edges; }

/**
 * Returns the number of edges for which vertex v is the origin.
 * Note that for an undirected graph, this is the same result
 * returned by inDegree(v).
 * @throws IllegalArgumentException if v is not a valid vertex
 */
template <class V, class E>
int AdjacencyMapGraph::outDegree(Vertex<V> v)
{
  InnerVertex<V> vert = validate(v);
  return vert.getOutgoing().size();
}
// throws IllegalArgumentException 

/**
 * Returns an iterable collection of edges for which vertex v is the origin.
 * Note that for an undirected graph, this is the same result
 * returned by incomingEdges(v).
 * @throws IllegalArgumentException if v is not a valid vertex
 */
template <class V, class E>
Edge<E>* AdjacencyMapGraph::outgoingEdges(Vertex<V> v)
{
  InnerVertex<V> vert = validate(v);
  return vert.getOutgoing().values();   // edges are the values in the adjacency map
}
// throws IllegalArgumentException 
/**
 * Returns the number of edges for which vertex v is the destination.
 * Note that for an undirected graph, this is the same result
 * returned by outDegree(v).
 * @throws IllegalArgumentException if v is not a valid vertex
 */
template <class V, class E>
int AdjacencyMapGraph::inDegree(Vertex<V> v)
{
  InnerVertex<V> vert = validate(v);
  return vert.getIncoming().size();
}
 // throws IllegalArgumentException 

/**
 * Returns an iterable collection of edges for which vertex v is the destination.
 * Note that for an undirected graph, this is the same result
 * returned by outgoingEdges(v).
 * @throws IllegalArgumentException if v is not a valid vertex
 */
template <class V, class E>
Edge<E>* AdjacencyMapGraph::incomingEdges(Vertex<V> v)
{
  InnerVertex<V> vert = validate(v);
  return vert.getIncoming().values();   // edges are the values in the adjacency map
}
 // throws IllegalArgumentException 

/** Returns the edge from u to v, or null if they are not adjacent. */
template <class V, class E>
Edge<E> AdjacencyMapGraph::getEdge(Vertex<V> u, Vertex<V> v)
{
  InnerVertex<V> origin = validate(u);
  return origin.getOutgoing().get(v);    // will be null if no edge from u to v
}
// throws IllegalArgumentException 

/**
 * Returns the vertices of edge e as an array of length two.
 * If the graph is directed, the first vertex is the origin, and
 * the second is the destination.  If the graph is undirected, the
 * order is arbitrary.
 */
template <class V, class E>
Vertex<V>[] AdjacencyMapGraph::endVertices(Edge<E> e) //throws IllegalArgumentException 
{
  InnerEdge<E> edge = validate(e);
  return edge.getEndpoints();
}

/** Returns the vertex that is opposite vertex v on edge e. */
template <class V, class E>
Vertex<V> AdjacencyMapGraph::opposite(Vertex<V> v, Edge<E> e)
                                             throws IllegalArgumentException 
{
  InnerEdge<E> edge = validate(e);
  Vertex<V>[] endpoints = edge.getEndpoints();
  if (endpoints[0] == v)
    return endpoints[1];
  else if (endpoints[1] == v)
    return endpoints[0];
  else
    throw new IllegalArgumentException("v is not incident to this edge");
}

/** Inserts and returns a new vertex with the given element. */
template <class V, class E>
Vertex<V> AdjacencyMapGraph::insertVertex(V element) {
  InnerVertex<V> v = new InnerVertex<>(element, isDirected);
  v.setPosition(vertices.addLast(v));
  return v;
}

/**
 * Inserts and returns a new edge between vertices u and v, storing given element.
 *
 * @throws IllegalArgumentException if u or v are invalid vertices, or if an edge already exists between u and v.
 */
template <class V, class E>
Edge<E> AdjacencyMapGraph::insertEdge(Vertex<V> u, Vertex<V> v, E element)
                                             throws IllegalArgumentException {
  if (getEdge(u,v) == null) {
    InnerEdge<E> e = new InnerEdge<>(u, v, element);
    e.setPosition(edges.addLast(e));
    InnerVertex<V> origin = validate(u);
    InnerVertex<V> dest = validate(v);
    origin.getOutgoing().put(v, e);
    dest.getIncoming().put(u, e);
    return e;
  } else
    throw new IllegalArgumentException("Edge from u to v exists");
}

/** Removes a vertex and all its incident edges from the graph. */
template <class V, class E>
void AdjacencyMapGraph::removeVertex(Vertex<V> v) throws IllegalArgumentException {
  InnerVertex<V> vert = validate(v);
  // remove all incident edges from the graph
  for (Edge<E> e : vert.getOutgoing().values())
    removeEdge(e);
  for (Edge<E> e : vert.getIncoming().values())
    removeEdge(e);
  // remove this vertex from the list of vertices
  vertices.remove(vert.getPosition());
  vert.setPosition(null);             // invalidates the vertex
}

/** Removes an edge from the graph. */
template <class V, class E>
void AdjacencyMapGraph::removeEdge(Edge<E> e)
{
  InnerEdge<E> edge = validate(e);
  // remove this edge from vertices' adjacencies
  
// Modification by Scot Drysdale to eliminate a casting exception on
// the following line:
//  InnerVertex<V>[] verts = (InnerVertex<V>[]) edge.getEndpoints();
  
  Vertex<V>[] verts = edge.getEndpoints();
  ((InnerVertex<V>)verts[0]).getOutgoing().remove(verts[1]);
  ((InnerVertex<V>)verts[1]).getIncoming().remove(verts[0]);
  // remove this edge from the list of edges
  edges.remove(edge.getPosition());
  edge.setPosition(null);             // invalidates the edge
}

template <class V, class E>
InnerVertex<V> AdjacencyMapGraph::validate(Vertex<V> v) {
  if (!(v instanceof InnerVertex)) throw new IllegalArgumentException("Invalid vertex");
  InnerVertex<V> vert = (InnerVertex<V>) v;     // safe cast
  if (!vert.validate(this)) throw new IllegalArgumentException("Invalid vertex");
  return vert;
}

template <class V, class E>
InnerEdge<E> AdjacencyMapGraph::validate(Edge<E> e) {
  if (!(e instanceof InnerEdge)) throw new IllegalArgumentException("Invalid edge");
  InnerEdge<E> edge = (InnerEdge<E>) e;     // safe cast
  if (!edge.validate(this)) throw new IllegalArgumentException("Invalid edge");
  return edge;
}

/**
 * Returns a string representation of the graph.
 * This is used only for debugging; do not rely on the string representation.
 */
char* AdjacencyMapGraph::print()
{
    char* sb = new char[];
    for (Vertex<V> v : vertices) {
      sb.append("Vertex " + v.getElement() + "\n");
      if (isDirected)
        sb.append(" [outgoing]");
      sb.append(" " + outDegree(v) + " adjacencies:");
      for (Edge<E> e: outgoingEdges(v))
        sb.append(String.format(" (%s, %s)", opposite(v,e).getElement(), e.getElement()));
      sb.append("\n");
      if (isDirected) {
        sb.append(" [incoming]");
        sb.append(" " + inDegree(v) + " adjacencies:");
        for (Edge<E> e: incomingEdges(v))
          sb.append(String.format(" (%s, %s)", opposite(v,e).getElement(), e.getElement()));
        sb.append("\n");
      }
    }
    return sb;
}