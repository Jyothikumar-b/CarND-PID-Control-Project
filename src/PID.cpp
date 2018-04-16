#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double p, double i, double d) {
	PID::Kp=p;
	PID::Ki=i;
	PID::Kd=d;
	PID::i_error=0;
	PID::d_error=0;
}

void PID::UpdateError(double cte) {
	PID::d_error=cte-p_error;
	PID::p_error=cte;
	PID::i_error=PID::i_error+cte;
}

double PID::TotalError() {
	return -(PID::Kp*PID::p_error + PID::Ki*PID::i_error + PID::Kd*PID::d_error);
}

