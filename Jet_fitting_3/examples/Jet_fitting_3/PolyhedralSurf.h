#ifndef _POLYHEDRALSURF_H_
#define _POLYHEDRALSURF_H_

#include <boost/property_map.hpp>
#include <boost/graph/properties.hpp>

#include <CGAL/Cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>

#include <algorithm>
#include <vector>
#include <list>

#include <stdlib.h>
#include <stdio.h>




//----------------------------------------------------------------
// A redefined items class for the Polyhedron_3 with a refined vertex
// class that contains a member for the normal vector and a refined
// facet with a normal vector instead of the plane equation (this is
// an alternative solution instead of using Polyhedron_traits_with_normals_3).
//----------------------------------------------------------------

template < class Refs, class Tag, class Pt, class FGeomTraits > 
class My_vertex:public CGAL::HalfedgeDS_vertex_base < Refs, Tag, Pt >
{
typedef typename FGeomTraits::Point_3 Point_3;

public:
 My_vertex(const Point_3 & pt):
   CGAL::HalfedgeDS_vertex_base < Refs, Tag, Point_3 > (pt){}
  My_vertex()    {}

};

//----------------------------------------------------------------
// Facet with normal and possibly more types. types are recovered
//from the FGeomTraits template arg
//----------------------------------------------------------------
template < class Refs, class Tag, class FGeomTraits >
class My_facet:public CGAL::HalfedgeDS_face_base < Refs, Tag >
{
public:
 typedef typename FGeomTraits::Vector_3 Vector_3;

protected:
  Vector_3 normal;
  //int ring_index;

public:
  const Vector_3& get_unit_normal() const { return normal; }
  Vector_3& get_unit_normal() { return normal; }

  //My_facet(): ring_index(-1) {}
  //void setNormal(Vector_3  n) { normal = n; }
//   //this is for collecting i-th ring neighbours
//   void setRingIndex(int i) { ring_index = i; }
//   int getRingIndex() { return ring_index; }
//   void resetRingIndex() { ring_index = -1; }
};


template <class TPoly>
class Facet_PM : 
  public boost::put_get_helper<typename TPoly::Traits::Vector_3, Facet_PM<TPoly> >
{
public: 

  //read_write
  typedef boost::read_write_property_map_tag category;
  typedef typename TPoly::Facet key_type;
  typedef typename TPoly::Traits::Vector_3 value_type;
  typedef typename TPoly::Traits::Vector_3& reference;
  
  Facet_PM() {}
  reference operator[](key_type f) const {return f.get_unit_normal();}
};

//XFC: we should have Facet instead of Vertex!
namespace boost{
  enum vertex_attribute_t        { vertex_attribute        = 1111 };
  //BOOST_INSTALL_PROPERTY(facet, attribute);
  BOOST_INSTALL_PROPERTY(vertex, attribute);

};

template <class TPoly> 
Facet_PM<TPoly> get(boost::vertex_attribute_t, TPoly& P) {return Facet_PM<TPoly>();}



//----------------------------------------------------------------
// Halfedge
//----------------------------------------------------------------
 //  int ring_index;
//   My_halfedge(): ring_index(-1) {}
//   void setRingIndex(int i) {	ring_index = i;    }
//   int getRingIndex() {return ring_index;    }
//   void resetRingIndex() {ring_index = -1;    }

template < class Refs, class Tprev, class Tvertex, class Tface>
class My_halfedge:public CGAL::HalfedgeDS_halfedge_base < Refs, Tprev, Tvertex, Tface >
{
public:
  double len;
public:
  My_halfedge(): len(-1) {}
  double& get_length()  { return len; }
};

//property map associated to the half edge
template <class TPoly>
class HEdge_PM : 
  public boost::put_get_helper<double, HEdge_PM<TPoly> >
{
public: 

  //read_write
  typedef boost::read_write_property_map_tag category;
  typedef typename TPoly::Halfedge key_type;
  typedef typename TPoly::Traits::FT value_type;
  typedef typename TPoly::Traits::FT& reference;
  
  HEdge_PM() {}
  reference operator[](key_type h) const {return h.len;}
};


//use the std edge_weight_t tag...
template <class TPoly> 
HEdge_PM<TPoly> get(boost::edge_weight_t, TPoly& P) {return HEdge_PM<TPoly>();}


//NOTE: for a lvalue_property_map
  //lvalue
//   typedef boost::lvalue_property_map_tag category;
//   typedef typename TPoly::Halfedge key_type;
//   typedef typename TPoly::Traits::FT value_type;
//   typedef typename TPoly::Traits::FT& reference;//lvalue

//   HEdge_PM() {}
//   reference operator[](key_type h) const {return h.len;}//lvalue



//------------------------------------------------
// Wrappers [Vertex, Face, Halfedge]
//------------------------------------------------
struct Wrappers_VFH:public CGAL::Polyhedron_items_3 {
  // wrap vertex
  template < class Refs, class Traits > struct Vertex_wrapper {
    typedef struct {
    public:
      typedef typename Traits::Point_3 Point_3;
    } FGeomTraits;
    typedef typename Traits::Point_3 Point_3;
    typedef My_vertex < Refs, CGAL::Tag_true, Point_3, FGeomTraits > Vertex;
  };

  // wrap face
  //NOTE: [HDS, Face] renamed [Polyhedron, Facet]
  template < class Refs, class Traits > struct Face_wrapper {
    //typedef typename Traits::Vector_3 Vector_3;
    //all types needed by the facet...
    typedef struct {
    public:
      typedef typename Traits::Vector_3 Vector_3;
    } FGeomTraits;
    //custom type instantiated...
    typedef My_facet < Refs, CGAL::Tag_true, FGeomTraits > Face;
  };

  // wrap halfedge
  template < class Refs, class Traits > struct Halfedge_wrapper {
   typedef My_halfedge < Refs,
      CGAL::Tag_true,
      CGAL::Tag_true, CGAL::Tag_true>  Halfedge;
  };
};

//------------------------------------------------
//PolyhedralSurf
//------------------------------------------------


typedef double                DFT;
typedef CGAL::Cartesian<DFT>  Data_Kernel;
typedef CGAL::Polyhedron_3 < Data_Kernel, Wrappers_VFH > Polyhedron;
typedef Data_Kernel::Vector_3 Vector_3;

class PolyhedralSurf:public Polyhedron {
public:
  PolyhedralSurf() {}
};

#endif
