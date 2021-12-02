# Steer and Throttle plots

![](project/plots/steer_plot.png)

![](project/plots/throttle_plot.png)

Control outputs are in opposite direction with signal errors. This is because the controller want to minimize the defined errors. Control magnitudes are much less than errors because Proportional values (kP) are less than 1.

# Effect of PID parameters
Each part of the PID affects the control command in different ways:
- Proportional term (kP) will correct current error, I used small values of kP to reduce oscillation
- Integral term (kI) will correct residual error over time and avoid system bias. However, I used very small kI values so they are not clearly depicted in the plots.
- Derivative term (kD) helps to reduce overshooting by damping the rate of error change. In the plots, kD help to stabilize control signals.

# Automatically tune PID parameters
Twiddle algorithm could be used to optimize PID parameters by iterating on a set of control parameter: making incremental changes when an improvement is detected and reduce the magnitude of the changes when there is no better output value.

In this project, we could use mean absolute values of steer error and throttle error from start position to stop position as evaluation function.

# Pros and Cons of PID (a model free controller)
- Pros: simple and could be applied for many different control problems without modifications. Require small computing footprint to calculate control outputs makes it suitable for realtime systems.
- Cons: has very limited number of parameters so that finding a good combination may not always possible. In addition, PID does NOT leverage domain specific knowledge to optimize the control performance such as vehicle physical characteristics (vehicle model, friction properties, etc.)

# (Optional) Improve PID controller
We could improve the PID controller by:
- Reduce control cycle time (delta t). Working cycle with duration 1 second is too big for controlling vehicle.
- Choose different parameter values for different cases such as accelerate, brake, overtake, etc.)
- Compensate current acceleration and current direction when calculating control signals.
