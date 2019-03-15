/* -*- c++ -*- ----------------------------------------------------------*/

#ifdef FIX_CLASS

FixStyle(velocity,FixVelocity)

#else

#ifndef MPM_FIX_VELOCITY_H
#define MPM_FIX_VELOCITY_H

#include "fix.h"
#include "var.h"
#include <vector>

class FixVelocity : public Fix {
 public:
  FixVelocity(class MPM *, vector<string>);
  ~FixVelocity();
  void setmask();
  void init();
  void setup();
  
  void initial_integrate() {};
  void post_update_grid_state();
  void post_grid_to_point() {};
  void post_advance_particles() {};
  void post_velocities_to_grid();
  void final_integrate() {};

private:
  class Var xvalue, yvalue, zvalue;    // Set velocities in x, y, and z directions.
  bool xset, yset, zset;               // Does the fix set the x, y, and z velocities of the group?
};

#endif
#endif

