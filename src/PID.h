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
  double Kp;
  double Kd;
  double Ki;
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
  void Init(double Kp, double Kd, double Ki);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);


/*
* Updates the throttle control for the car basing current speed, CTE, and Delta_CTE:
*/
double UpdateThrottle( double cte, double speed, double throttle);


  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
