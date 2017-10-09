# Reflections: PID Control Project

## PID Components

### P

The P Component has been used to make a direct influence on steering behavior based on the Cross-Track Error of the vehicles current position. This relates to the displacement from the expected position of the car that is then used to turn the vehicle towards the expected position. This is often done with coefficients that help gauge the influence this portion has on steering control. For this implementation, the coefficient Kp was set to 0.16 that allowed a good level of influence of error on steering.

### D

The D Component of a PID controller is the difference between previous CTE and current Error. How this is influential is in making decisions on how to lessen or further steer based on the previous timesteps influence on error. If there is a small difference between previous error and not, then this term isnt going to influence steering much, however should an unexpected turn be seen in the vehicle's track, the difference is large and helps the vehicle respond accordingly. For this implementation the coefficient Kd was set to 1.7 after testing various values.

### I

The I Component of a PID controller is the summed total error of the vehicle's driving. This allows to account for systemic bias. One example is if the steering controllers aren't accurate but the error is still known with the integration of all error. For this implementation, there wasnt systemic error in the simulator so this term was not used.




## Choosing Hyperparameters

This was the most crucial and important part of the project's implementation in deciding the influence of direct error on the track, delta error from the action taken and having these two systems work together.
It was largely an exercise in performing twiddle algorithm manually (lol) and trying to understand the benefit and drivability of the car on the simulator! 
I started with seeing what small values worked or did not work and increased in orders of magnitude.
for Kp I first started in .001 range, and moved to .01 and then .1 ranges.

After an acceptable performance with Kp alone, I did the same with the influence of Kd and decided on these values:
Kp = 0.16;
Kd = 1.7;

## Additional thoughts and future work

From sheer boredom of watching the car try and fail on the track during hyperparameter manual twiddling,
I decided to implement a pseudo-PID for throttle control.
The basis of this was to use the CTE and Delta-CTE and current speed to influence throttle changes.
The main logic checked values of CTE Delta-CTE and speed above a threshold to influence slowing down the car to the minimum safe speed ~8 mph. Otherwise if all is well and error is low, the car will be allowed to speed up to a maximum speed of ~18 mph. This helps with making the car finish the simulator lap in less time as well as adding sophistication to the controller.


Future work will involve implementing twiddle and a flag for when twiddling is necessary to influence the hyperparameters. My only worry is how to make this portion survive wicked turns and safely perform.

It was a pleasure working on this project and thank you for your time,
Sai Prateek Medi




 
