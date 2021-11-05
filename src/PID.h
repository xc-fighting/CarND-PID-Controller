#ifndef PID_H
#define PID_H
#include <iostream>
using namespace std;
class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

 private:
  /**
   * PID Errors
   */
  // cte directly * tau_p
  double p_error;
  // i_error should be a sum of cte * tau_i
  double i_error;
  // diff of cte from i-1 -> i * tau_d
  double d_error;
  // store previous cte
  double prev_cte;
  // store total cte
  double total_cte;

  // check whether first time
  bool first_time;

  /**
   * PID tau values
   */ 
  double tau_p;
  double tau_i;
  double tau_d;
};

#endif  // PID_H