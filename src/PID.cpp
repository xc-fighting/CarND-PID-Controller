#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {
   
   cout<<"Contruct PID Controller"<<endl;
}

PID::~PID() {
 
   cout<<"Destruct PID Controller"<<endl;
}

void PID::Init(double tau_p, double tau_i, double tau_d) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->tau_p = tau_p;
  this->tau_i = tau_i;
  this->tau_d = tau_d;
  this->prev_cte = 0;
  this->total_cte = 0;
  this->first_time = true;
}

void PID::UpdateError(double cte) {
    /**
      * TODO: Update PID errors based on cte.
     */
    // update p,i,e error
    // first calculate p
    double P = cte * (-tau_p);
    double cte_diff = 0;
    if( first_time == true ) {
        cte_diff = 0;
        first_time = false;
        prev_cte = cte;
    }
    else {
        cte_diff = cte - prev_cte;
        prev_cte = cte;
    }

    double D = cte_diff * (-tau_d);

    total_cte += cte;
    double I = total_cte * (-tau_i);

    this->p_error = P;
    this->i_error = I;
    this->d_error = D;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return p_error + i_error + d_error;  // TODO: Add your total error calc here!
}