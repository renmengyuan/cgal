#ifndef CGAL_VORONOI_DIAGRAM_2_VALIDITY_TESTERS_H
#define CGAL_VORONOI_DIAGRAM_2_VALIDITY_TESTERS_H 1

#include <CGAL/Voronoi_diagram_adaptor_2/basic.h>
#include <cstdlib>
#include <algorithm>
#include <CGAL/Triangulation_utils_2.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Finder_classes.h>


CGAL_BEGIN_NAMESPACE

CGAL_VORONOI_DIAGRAM_2_BEGIN_NAMESPACE

//=========================================================================
//=========================================================================


template<class VDA, class Base_it>
class Edge_validity_tester
{
  // tests whether a halfedge has as face a face with zero area.
 private:
  const VDA* vda_;

 private:
  typedef Triangulation_cw_ccw_2                CW_CCW_2;
  // Base_it is essentially VDA::Edges_iterator_base
  typedef Base_it                               Edges_iterator_base;
  typedef typename VDA::Halfedge_handle         Halfedge_handle;
  typedef typename VDA::Face_degeneracy_tester  Face_degeneracy_tester;

 public:
  Edge_validity_tester(const VDA* vda = NULL) : vda_(vda) {}

  bool operator()(const Edges_iterator_base& eit) const {
    CGAL_assertion( !vda_->edge_tester()(vda_->dual(), eit->dual_edge()) );

    int cw_i = CW_CCW_2::cw( eit->dual_edge().second );
    int ccw_i = CW_CCW_2::ccw( eit->dual_edge().second );

    CGAL_assertion
      ( !vda_->face_tester()( vda_->dual(), vda_->edge_tester(),
			      eit->dual_edge().first->vertex(ccw_i) ) );

    if (  !vda_->face_tester()( vda_->dual(), vda_->edge_tester(),
				eit->dual_edge().first->vertex(cw_i) )   ) {
      return false;
    }

    Halfedge_handle he(eit);
    Halfedge_handle he_opp = eit->opposite();

    CGAL_assertion( he_opp->opposite() == he );

    return he->face()->dual_vertex() < he_opp->face()->dual_vertex();
  }
};


//=========================================================================
//=========================================================================


template<class VDA>
class Vertex_validity_tester
{
 private:
  const VDA* vda_;

 private:
  typedef typename VDA::Dual_face_handle     Dual_face_handle;
  typedef typename VDA::Dual_faces_iterator  Dual_faces_iterator;

 public:
  Vertex_validity_tester(const VDA* vda = NULL) : vda_(vda) {}

  bool operator()(const Dual_faces_iterator& fit) const {
    Dual_face_handle f(fit);
    Dual_face_handle fvalid = Find_valid_vertex<VDA>()(vda_,f);
    return f != fvalid;
  }
};


//=========================================================================
//=========================================================================

CGAL_VORONOI_DIAGRAM_2_END_NAMESPACE

CGAL_END_NAMESPACE

#endif // CGAL_VORONOI_DIAGRAM_2_VALIDITY_TESTERS_H
