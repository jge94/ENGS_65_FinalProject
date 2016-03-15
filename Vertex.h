
#ifndef VERTEX
#define VERTEX

/**
 * A vertex of a graph.
 */
template <class V>
class Vertex<V> 
{
	public:
	  /** Returns the element associated with the vertex. */
	  virtual V getElement();
};

#endif