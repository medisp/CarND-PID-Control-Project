#include <vector>
#ifndef PID_H
#define PID_H

using namespace std;
class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  vector<double> dparams;
  vector<double> params; 
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(vector<double> params, vector<double> dparams);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte, double i_error);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
