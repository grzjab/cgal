// ======================================================================
//
// Copyright (c) 1997-2001 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
//
// release       : 
// release_date  : 2002, March 20
//
// file          : include/CGAL/Optimisation/Access_coordinates_begin_d.h
// package       : Optimisation_basic (3.8.12)
// maintainer    : Sven Sch�nherr <sven@inf.ethz.ch>
//
// revision      : $Revision$
// revision_date : $Date$
//
// author(s)     : Sven Sch�nherr <sven@inf.ethz.ch>
// coordinator   : ETH Z�rich (Bernd G�rtner <gaertner@inf.ethz.ch>)
//
// implementation: dD data accessor `coordinates'
// ======================================================================

#ifndef CGAL_OPTIMISATION_ACCESS_COORDINATES_BEGIN_D_H
#define CGAL_OPTIMISATION_ACCESS_COORDINATES_BEGIN_D_H

// includes
#  include <CGAL/Kernel_d/Interface_classes.h>
#  include <CGAL/Kernel_d/Point_d.h>

CGAL_BEGIN_NAMESPACE

// Class declaration
// =================
template < class R_ >
class Access_coordinates_begin_d;

// Class interface
// ===============
template < class R_ >
class Access_coordinates_begin_d {
  public:
    // self
    typedef  R_                         R;
    typedef  Access_coordinates_begin_d<R>
                                        Self;

    // types
    typedef  typename R::Point_d        Point;
    typedef  const typename R::RT *     Coordinate_iterator;

    // unary function class types
    typedef  Coordinate_iterator        result_type;
    typedef  Point                      argument_type;

    // creation
    Access_coordinates_begin_d( ) { }

    // operations
private:
    Coordinate_iterator
    access( const Point& p, Cartesian_tag) const 
    { return p.cartesian_begin(); }
  
    Coordinate_iterator
    access( const Point& p, Homogeneous_tag) const 
    { return p.homogeneous_begin(); }
  
  
public:
    Coordinate_iterator
    operator() ( const Point& p) const { 
      typename R::Rep_tag tag;
#if defined(__sun) && defined(__SUNPRO_CC)
    // to avoid a warning "tag has not yet been assigned a value"
    typedef typename R::Rep_tag Rep_tag;
    tag = Rep_tag();
#endif // SUNPRO
      return access(p, tag);
    }
};

CGAL_END_NAMESPACE

#endif // CGAL_OPTIMISATION_ACCESS_COORDINATES_BEGIN_D_H

// ===== EOF ==================================================================
