#ifndef FCIQMC_HELPER_HEADER_H
#define FCIQMC_HELPER_HEADER_H

#include "global.h"
#include <vector>
#include "overlaptensor.h"
#include "boost/shared_ptr.hpp"
#include "StateInfo.h"
#include "Operators.h"
#include "wavefunction.h"

namespace SpinAdapted{

//the MPS is stored in the left canonical form
//LLLLL..LC 
class MPS{
  std::vector< std::vector<Matrix> > SiteTensors; //these are the L matrices
  Wavefunction w; //the last wavefunction

 public:
  static int sweepIters;
  static bool spinAdapted;

  MPS(int stateindex); 
  MPS(std::vector<bool>& occ);
  std::vector<Matrix>& getSiteTensors(int i) {return SiteTensors[i];}
  const std::vector<Matrix>& getSiteTensors(int i) const {return SiteTensors[i];}
  const Wavefunction& getw() const {return w;}
};

 double calculateOverlap (const MPS& a, const MPS& b);

}

#endif
