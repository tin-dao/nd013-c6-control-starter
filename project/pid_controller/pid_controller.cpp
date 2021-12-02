/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  kP = Kpi;
  kI = Kii;
  kD = Kdi;
  output_min = output_lim_mini;
  output_max = output_lim_maxi;
  prev_cte = 0.0;
  diff_cte = 0.0;
  int_cte = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  diff_cte = 0;
  if (delta_time > __DBL_EPSILON__) {
    diff_cte = (cte - prev_cte) / delta_time;
  }
  int_cte += cte * delta_time;
  prev_cte = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
  double control = -(kP * prev_cte + kI * int_cte + kD * diff_cte);
  
  if (control > output_max) {
    control = output_max;
  } else if (control < output_min) {
    control = output_min;
  }
  return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  delta_time = new_delta_time;
  return delta_time;
}