/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

// Value to handle divide by 0.
#define DBL_EPSILON 1e-9

class PID {
public:

   /**
   * TODO: Create the PID class
   **/

    /*
    * Errors
    */
   double prev_cte; 
   double diff_cte;
   double int_cte;

    /*
    * Coefficients
    */
   double kP;
   double kI;
   double kD;

    /*
    * Output limits
    */
   double output_min;
   double output_max;
  
    /*
    * Delta time
    */
   double delta_time;

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
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


