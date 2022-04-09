#include "api.h"
using namespace pros;
inline pros::Controller controller (E_CONTROLLER_MASTER);

//Drive Train Motors
inline Motor leftFront (5, E_MOTOR_GEARSET_18, true); //(Port, gearset, reversed)
inline Motor leftBack (1, E_MOTOR_GEARSET_18, true);

inline Motor rightFront (19, E_MOTOR_GEARSET_18, false);
inline Motor rightBack (20, E_MOTOR_GEARSET_18, false);
