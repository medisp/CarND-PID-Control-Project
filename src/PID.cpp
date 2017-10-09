#include <vector>
#include "PID.h"
#include <iostream>
#include <math.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Kd, double Ki) { //vector<double> params, vector<double> dparams) {
	// initialize constants for steering modification
	// twiddle algorithm?
	// Kp = first constant, Kd = derivative constant, Ki = integral constant
	Kp = Kp;
	Kd = Kd;
	Ki = Ki;
	//params = params;
	//dparams = dparams;
	p_error = 0.0;
	d_error = 0.0;	
	i_error = 0.0;
}

void PID::UpdateError(double cte) {
	// error terms to modify the cte necessary to change the steering angle
	d_error = (cte - p_error);

	p_error = cte;
	i_error += cte*0.9; 	
	if (cte <1 && cte > -1) {i_error=0.0;}
}

double PID::UpdateThrottle(double cte, double speed, double throttle_control) {
	// after a threshold error and delta_error, reduce throttle,

	if (fabs(cte) > 0.2 && fabs(d_error) > 0.1 && speed > 8) {
		throttle_control = 0.08; // acceptable minimum safe speed
	} 
	else {
		throttle_control *=1.1;
		//setting a max speed (gotta drive friendly right?)
		if(throttle_control>0.16){throttle_control=0.16;} 
	}
	return throttle_control ;
}

double PID::TotalError() {
	//Kp = 0.018;
	//Kd = 0.18;
	//Ki = 0.0;
	Kp = 0.16;
	Kd = 1.7;
	Ki = 0.0;
	
	std::cout << "p_error = " << p_error << std::endl;
	std::cout << "d_error = " << d_error << std::endl;
	std::cout << "i_error = " << i_error << std::endl;


return ((-Kp * p_error) - (Kd * d_error) - (Ki * i_error));

//p_error + d_error + i_error;  // I don't know what this is for

}











