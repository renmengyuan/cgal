// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
// 
// release       :
// release_date  :
// 
// file          : include/CGAL/Arithmetic_filter/predicates/Regular_triangulation_rtH2.h
// package       : Interval_arithmetic
// author(s)     : Sylvain Pion <Sylvain.Pion@sophia.inria.fr>
//
// coordinator   : INRIA Sophia-Antipolis (<Mariette.Yvinec@sophia.inria.fr>)
// ======================================================================

// This file is automatically generated by the script
// examples/Interval_arithmetic/filtered_predicate_converter.

#ifndef CGAL_ARITHMETIC_FILTER_REGULAR_TRIANGULATION_RTH2_H
#define CGAL_ARITHMETIC_FILTER_REGULAR_TRIANGULATION_RTH2_H

CGAL_BEGIN_NAMESPACE

inline
Oriented_side
power_testH2_SAF(
    const Static_filter_error &phx,
    const Static_filter_error &phy,
    const Static_filter_error &phw,
    const Static_filter_error &pwt,
    const Static_filter_error &qhx,
    const Static_filter_error &qhy,
    const Static_filter_error &qhw,
    const Static_filter_error &qwt,
    const Static_filter_error &rhx,
    const Static_filter_error &rhy,
    const Static_filter_error &rhw,
    const Static_filter_error &rwt,
    const Static_filter_error &thx,
    const Static_filter_error &thy,
    const Static_filter_error &thw,
    const Static_filter_error &twt,
    double & epsilon_0)
{
  typedef Static_filter_error RT;

    RT dphx = phx*phw;
    RT dphy = phy*phw;
    RT dphw = square(phw);
    RT dpz = square(phx) + square(phy) - pwt*dphw;

    RT dqhx = qhx*qhw;
    RT dqhy = qhy*qhw;
    RT dqhw = square(qhw);
    RT dqz = square(qhx) + square(qhy) - qwt*dqhw;

    RT drhx = rhx*rhw;
    RT drhy = rhy*rhw;
    RT drhw = square(rhw);
    RT drz = square(rhx) + square(rhy) - rwt*drhw;

    RT dthx = thx*thw;
    RT dthy = thy*thw;
    RT dthw = square(thw);
    RT dtz = square(thx) + square(thy) - twt*dthw;

    return Oriented_side(sign_of_determinant4x4_SAF(dphx, dphy, dpz, dphw,
	                                        dqhx, dqhy, dqz, dqhw,
	                                        drhx, drhy, drz, drhw,
	                                        dthx, dthy, dtz, dthw,
		epsilon_0));
}

inline
Oriented_side
power_testH2_SAF(
    const Restricted_double &phx,
    const Restricted_double &phy,
    const Restricted_double &phw,
    const Restricted_double &pwt,
    const Restricted_double &qhx,
    const Restricted_double &qhy,
    const Restricted_double &qhw,
    const Restricted_double &qwt,
    const Restricted_double &rhx,
    const Restricted_double &rhy,
    const Restricted_double &rhw,
    const Restricted_double &rwt,
    const Restricted_double &thx,
    const Restricted_double &thy,
    const Restricted_double &thw,
    const Restricted_double &twt,
    const double & epsilon_0)
{
  typedef Restricted_double RT;

    RT dphx = phx*phw;
    RT dphy = phy*phw;
    RT dphw = square(phw);
    RT dpz = square(phx) + square(phy) - pwt*dphw;

    RT dqhx = qhx*qhw;
    RT dqhy = qhy*qhw;
    RT dqhw = square(qhw);
    RT dqz = square(qhx) + square(qhy) - qwt*dqhw;

    RT drhx = rhx*rhw;
    RT drhy = rhy*rhw;
    RT drhw = square(rhw);
    RT drz = square(rhx) + square(rhy) - rwt*drhw;

    RT dthx = thx*thw;
    RT dthy = thy*thw;
    RT dthw = square(thw);
    RT dtz = square(thx) + square(thy) - twt*dthw;

    return Oriented_side(sign_of_determinant4x4_SAF(dphx, dphy, dpz, dphw,
	                                        dqhx, dqhy, dqz, dqhw,
	                                        drhx, drhy, drz, drhw,
	                                        dthx, dthy, dtz, dthw,
		epsilon_0));
}

inline
Oriented_side
power_testH2(
    const Static_adaptatif_filter &phx,
    const Static_adaptatif_filter &phy,
    const Static_adaptatif_filter &phw,
    const Static_adaptatif_filter &pwt,
    const Static_adaptatif_filter &qhx,
    const Static_adaptatif_filter &qhy,
    const Static_adaptatif_filter &qhw,
    const Static_adaptatif_filter &qwt,
    const Static_adaptatif_filter &rhx,
    const Static_adaptatif_filter &rhy,
    const Static_adaptatif_filter &rhw,
    const Static_adaptatif_filter &rwt,
    const Static_adaptatif_filter &thx,
    const Static_adaptatif_filter &thy,
    const Static_adaptatif_filter &thw,
    const Static_adaptatif_filter &twt)
{
  bool re_adjusted = false;
  static double SAF_bound = -1.0;
  static double SAF_epsilon_0;

  // Check the bounds.  All arguments must be <= SAF_bound.
  if (	fabs(phx.value()) > SAF_bound ||
	fabs(phy.value()) > SAF_bound ||
	fabs(phw.value()) > SAF_bound ||
	fabs(pwt.value()) > SAF_bound ||
	fabs(qhx.value()) > SAF_bound ||
	fabs(qhy.value()) > SAF_bound ||
	fabs(qhw.value()) > SAF_bound ||
	fabs(qwt.value()) > SAF_bound ||
	fabs(rhx.value()) > SAF_bound ||
	fabs(rhy.value()) > SAF_bound ||
	fabs(rhw.value()) > SAF_bound ||
	fabs(rwt.value()) > SAF_bound ||
	fabs(thx.value()) > SAF_bound ||
	fabs(thy.value()) > SAF_bound ||
	fabs(thw.value()) > SAF_bound ||
	fabs(twt.value()) > SAF_bound)
  {
re_adjust:
      // Re-adjust SAF_bound.
      SAF_bound = std::max(0.0, fabs(phx.value()));
      SAF_bound = std::max(SAF_bound, fabs(phy.value()));
      SAF_bound = std::max(SAF_bound, fabs(phw.value()));
      SAF_bound = std::max(SAF_bound, fabs(pwt.value()));
      SAF_bound = std::max(SAF_bound, fabs(qhx.value()));
      SAF_bound = std::max(SAF_bound, fabs(qhy.value()));
      SAF_bound = std::max(SAF_bound, fabs(qhw.value()));
      SAF_bound = std::max(SAF_bound, fabs(qwt.value()));
      SAF_bound = std::max(SAF_bound, fabs(rhx.value()));
      SAF_bound = std::max(SAF_bound, fabs(rhy.value()));
      SAF_bound = std::max(SAF_bound, fabs(rhw.value()));
      SAF_bound = std::max(SAF_bound, fabs(rwt.value()));
      SAF_bound = std::max(SAF_bound, fabs(thx.value()));
      SAF_bound = std::max(SAF_bound, fabs(thy.value()));
      SAF_bound = std::max(SAF_bound, fabs(thw.value()));
      SAF_bound = std::max(SAF_bound, fabs(twt.value()));

      // recompute the epsilons: "just" call it over Static_filter_error.
      // That's the tricky part that might not work for everything.
      (void) power_testH2_SAF(
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		SAF_epsilon_0);

      // TODO: We should verify that all epsilons have really been updated.
  }

  try  // Try the epsilon variant of the predicate.
  {
    return power_testH2_SAF(
		Restricted_double(phx.value()),
		Restricted_double(phy.value()),
		Restricted_double(phw.value()),
		Restricted_double(pwt.value()),
		Restricted_double(qhx.value()),
		Restricted_double(qhy.value()),
		Restricted_double(qhw.value()),
		Restricted_double(qwt.value()),
		Restricted_double(rhx.value()),
		Restricted_double(rhy.value()),
		Restricted_double(rhw.value()),
		Restricted_double(rwt.value()),
		Restricted_double(thx.value()),
		Restricted_double(thy.value()),
		Restricted_double(thw.value()),
		Restricted_double(twt.value()),
		SAF_epsilon_0);
  }
  catch (Restricted_double::unsafe_comparison)
  {
    // It failed, we re-adjust once.
    if (!re_adjusted) {
      re_adjusted = true;
      goto re_adjust;
    }
    // This scheme definitely fails => exact computation (filtered_exact<> ?).
    return power_testH2(
		phx.exact(),
		phy.exact(),
		phw.exact(),
		pwt.exact(),
		qhx.exact(),
		qhy.exact(),
		qhw.exact(),
		qwt.exact(),
		rhx.exact(),
		rhy.exact(),
		rhw.exact(),
		rwt.exact(),
		thx.exact(),
		thy.exact(),
		thw.exact(),
		twt.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/*  */
Oriented_side
power_testH2(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &phx,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &phy,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &phw,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &pwt,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qhx,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qhy,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qhw,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qwt,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &rhx,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &rhy,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &rhw,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &rwt,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &thx,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &thy,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &thw,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &twt)
{
  CGAL_assertion(Interval_nt_advanced::want_exceptions);
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Oriented_side result = power_testH2(
		phx.interval(),
		phy.interval(),
		phw.interval(),
		pwt.interval(),
		qhx.interval(),
		qhy.interval(),
		qhw.interval(),
		qwt.interval(),
		rhx.interval(),
		rhy.interval(),
		rhw.interval(),
		rwt.interval(),
		thx.interval(),
		thy.interval(),
		thw.interval(),
		twt.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return power_testH2(
		phx.exact(),
		phy.exact(),
		phw.exact(),
		pwt.exact(),
		qhx.exact(),
		qhy.exact(),
		qhw.exact(),
		qwt.exact(),
		rhx.exact(),
		rhy.exact(),
		rhw.exact(),
		rwt.exact(),
		thx.exact(),
		thy.exact(),
		thw.exact(),
		twt.exact());
  }
}

inline
Oriented_side
power_testH2_SAF(
    const Static_filter_error &phx,
    const Static_filter_error &phy,
    const Static_filter_error &phw,
    const Static_filter_error &pwt,
    const Static_filter_error &qhx,
    const Static_filter_error &qhy,
    const Static_filter_error &qhw,
    const Static_filter_error &qwt,
    const Static_filter_error &thx,
    const Static_filter_error &thy,
    const Static_filter_error &thw,
    const Static_filter_error &twt,
    double & epsilon_0,
    double & epsilon_1)
{
  typedef Static_filter_error RT;

    
    
    RT pa, qa, ta;

    if (phx * qhw != qhx * phw )
    {
	pa = phx*phw;
	qa = qhx*qhw;
	ta = thx*thw;
    }
    else
    {   
	pa = phy*phw;
	qa = qhy*qhw;
	ta = thy*thw;
    }

    RT dphw = square(phw);
    RT dpz = square(phx) + square(phy) - pwt*dphw;

    RT dqhw = square(qhw);
    RT dqz = square(qhx) + square(qhy) - qwt*dqhw;

    RT dthw = square(thw);
    RT dtz = square(thx) + square(thy) - twt*dthw;

    return Oriented_side(CGAL::compare_SAF(pa, qa,
		epsilon_0) *
	                 sign_of_determinant3x3_SAF(pa, dpz, dphw,
				                qa, dqz, dqhw,
				                ta, dtz, dthw,
		epsilon_1));
}

inline
Oriented_side
power_testH2_SAF(
    const Restricted_double &phx,
    const Restricted_double &phy,
    const Restricted_double &phw,
    const Restricted_double &pwt,
    const Restricted_double &qhx,
    const Restricted_double &qhy,
    const Restricted_double &qhw,
    const Restricted_double &qwt,
    const Restricted_double &thx,
    const Restricted_double &thy,
    const Restricted_double &thw,
    const Restricted_double &twt,
    const double & epsilon_0,
    const double & epsilon_1)
{
  typedef Restricted_double RT;

    
    
    RT pa, qa, ta;

    if (phx * qhw != qhx * phw )
    {
	pa = phx*phw;
	qa = qhx*qhw;
	ta = thx*thw;
    }
    else
    {   
	pa = phy*phw;
	qa = qhy*qhw;
	ta = thy*thw;
    }

    RT dphw = square(phw);
    RT dpz = square(phx) + square(phy) - pwt*dphw;

    RT dqhw = square(qhw);
    RT dqz = square(qhx) + square(qhy) - qwt*dqhw;

    RT dthw = square(thw);
    RT dtz = square(thx) + square(thy) - twt*dthw;

    return Oriented_side(CGAL::compare_SAF(pa, qa,
		epsilon_0) *
	                 sign_of_determinant3x3_SAF(pa, dpz, dphw,
				                qa, dqz, dqhw,
				                ta, dtz, dthw,
		epsilon_1));
}

inline
Oriented_side
power_testH2(
    const Static_adaptatif_filter &phx,
    const Static_adaptatif_filter &phy,
    const Static_adaptatif_filter &phw,
    const Static_adaptatif_filter &pwt,
    const Static_adaptatif_filter &qhx,
    const Static_adaptatif_filter &qhy,
    const Static_adaptatif_filter &qhw,
    const Static_adaptatif_filter &qwt,
    const Static_adaptatif_filter &thx,
    const Static_adaptatif_filter &thy,
    const Static_adaptatif_filter &thw,
    const Static_adaptatif_filter &twt)
{
  bool re_adjusted = false;
  static double SAF_bound = -1.0;
  static double SAF_epsilon_0;
  static double SAF_epsilon_1;

  // Check the bounds.  All arguments must be <= SAF_bound.
  if (	fabs(phx.value()) > SAF_bound ||
	fabs(phy.value()) > SAF_bound ||
	fabs(phw.value()) > SAF_bound ||
	fabs(pwt.value()) > SAF_bound ||
	fabs(qhx.value()) > SAF_bound ||
	fabs(qhy.value()) > SAF_bound ||
	fabs(qhw.value()) > SAF_bound ||
	fabs(qwt.value()) > SAF_bound ||
	fabs(thx.value()) > SAF_bound ||
	fabs(thy.value()) > SAF_bound ||
	fabs(thw.value()) > SAF_bound ||
	fabs(twt.value()) > SAF_bound)
  {
re_adjust:
      // Re-adjust SAF_bound.
      SAF_bound = std::max(0.0, fabs(phx.value()));
      SAF_bound = std::max(SAF_bound, fabs(phy.value()));
      SAF_bound = std::max(SAF_bound, fabs(phw.value()));
      SAF_bound = std::max(SAF_bound, fabs(pwt.value()));
      SAF_bound = std::max(SAF_bound, fabs(qhx.value()));
      SAF_bound = std::max(SAF_bound, fabs(qhy.value()));
      SAF_bound = std::max(SAF_bound, fabs(qhw.value()));
      SAF_bound = std::max(SAF_bound, fabs(qwt.value()));
      SAF_bound = std::max(SAF_bound, fabs(thx.value()));
      SAF_bound = std::max(SAF_bound, fabs(thy.value()));
      SAF_bound = std::max(SAF_bound, fabs(thw.value()));
      SAF_bound = std::max(SAF_bound, fabs(twt.value()));

      // recompute the epsilons: "just" call it over Static_filter_error.
      // That's the tricky part that might not work for everything.
      (void) power_testH2_SAF(
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		Static_filter_error(SAF_bound),
		SAF_epsilon_0,
		SAF_epsilon_1);

      // TODO: We should verify that all epsilons have really been updated.
  }

  try  // Try the epsilon variant of the predicate.
  {
    return power_testH2_SAF(
		Restricted_double(phx.value()),
		Restricted_double(phy.value()),
		Restricted_double(phw.value()),
		Restricted_double(pwt.value()),
		Restricted_double(qhx.value()),
		Restricted_double(qhy.value()),
		Restricted_double(qhw.value()),
		Restricted_double(qwt.value()),
		Restricted_double(thx.value()),
		Restricted_double(thy.value()),
		Restricted_double(thw.value()),
		Restricted_double(twt.value()),
		SAF_epsilon_0,
		SAF_epsilon_1);
  }
  catch (Restricted_double::unsafe_comparison)
  {
    // It failed, we re-adjust once.
    if (!re_adjusted) {
      re_adjusted = true;
      goto re_adjust;
    }
    // This scheme definitely fails => exact computation (filtered_exact<> ?).
    return power_testH2(
		phx.exact(),
		phy.exact(),
		phw.exact(),
		pwt.exact(),
		qhx.exact(),
		qhy.exact(),
		qhw.exact(),
		qwt.exact(),
		thx.exact(),
		thy.exact(),
		thw.exact(),
		twt.exact());
  }
}

#ifndef CGAL_CFG_NO_EXPLICIT_TEMPLATE_FUNCTION_ARGUMENT_SPECIFICATION
template < class CGAL_IA_CT, class CGAL_IA_ET, class CGAL_IA_CACHE >
#endif
/*  */
Oriented_side
power_testH2(
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &phx,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &phy,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &phw,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &pwt,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qhx,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qhy,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qhw,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &qwt,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &thx,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &thy,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &thw,
    const Filtered_exact <CGAL_IA_CT, CGAL_IA_ET, CGAL_IA_CACHE> &twt)
{
  CGAL_assertion(Interval_nt_advanced::want_exceptions);
  FPU_CW_t backup = FPU_get_and_set_cw(FPU_cw_up);
  try
  {
    Oriented_side result = power_testH2(
		phx.interval(),
		phy.interval(),
		phw.interval(),
		pwt.interval(),
		qhx.interval(),
		qhy.interval(),
		qhw.interval(),
		qwt.interval(),
		thx.interval(),
		thy.interval(),
		thw.interval(),
		twt.interval());
    FPU_set_cw(backup);
    return result;
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    FPU_set_cw(backup);
    return power_testH2(
		phx.exact(),
		phy.exact(),
		phw.exact(),
		pwt.exact(),
		qhx.exact(),
		qhy.exact(),
		qhw.exact(),
		qwt.exact(),
		thx.exact(),
		thy.exact(),
		thw.exact(),
		twt.exact());
  }
}

CGAL_END_NAMESPACE

#endif // CGAL_ARITHMETIC_FILTER_REGULAR_TRIANGULATION_RTH2_H
