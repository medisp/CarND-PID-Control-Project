#include <vector>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(vector<double> params, vector<double> dparams) {
	// initialize constants for steering modification
	// twiddle algorithm?
	// Kp = first constant, Kd = derivative constant, Ki = integral constant

	params = params;
	dparams = dparams;
	p_error = 0;
	d_error = 0;	
	i_error = 0;
}

void PID::UpdateError(double cte, double i_error) {
	// error terms to modify the cte necessary to change the steering angle
	d_error = (cte-p_error);
	p_error = cte;
	i_error += i_error*0.9; 	
}

double PID::TotalError() {
	return p_error + d_error + i_error;  // I don't know what this is for

}











