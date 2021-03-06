#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include<vector>
#include "BodyForce.h"
#include "Damping.h"
#include "Boundary.h"

class Environment {
public:
  
  void initialize() {

    // initialize all body forces
    for (uint b = 0; b < bodyForces.size(); b++) {
      bodyForces[b]->initialize();
    } // for b = ...

    // initialize all damping forces
    for (uint d = 0; d < dampingForces.size(); d++) {
      dampingForces[d]->initialize();
    } // for d = ...

    // initialize all boundaries
    for (uint b = 0; b < boundaries.size(); b++) {
      boundaries[b]->initialize();
    } // for b = ...

  } // initialize()

  void timeIntegrate(float dt) {

    // timeIntegrate all bodyForces
    for (uint b = 0; b < bodyForces.size(); b++) {
      bodyForces[b]->timeIntegrate(dt);
    } // for b = ...

    // timeIntegrate all dampingForces
    for (uint d = 0; d < dampingForces.size(); d++) {
      dampingForces[d]->timeIntegrate(dt);
    } // for d = ...

    // timeIntegrate all boundaries
    for (uint b = 0; b < boundaries.size(); b++) {
      boundaries[b]->timeIntegrate(dt);
    } // for b = ...

  } // timeIntegrate()
  
  std::vector<BodyForce*> bodyForces;
  std::vector<Damping*>   dampingForces;
  std::vector<Boundary*>  boundaries;
}; // Environment

#endif // ENVIRONMENT_H
