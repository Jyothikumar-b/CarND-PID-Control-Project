# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Objective
To drive the car in simulater using the PID controller. The followingsteps are followed to accomplish the objective.
> 1. Initialize the hyper parameter
> 2. Update CTE value for each time stamp
> 3. Covert the PID output to steering value
> 4. Fine tune hyper parameter

## Effect of Hyper parameter Kp,Ki,Kd
1. **Propotionality Constant (Kp) :**
The propotionality control helps to make adjustment that is propotional to the error at the given moment. This helps to change the output towards the set value and a larger Kp would help in reduction of the rise time while resulting in a larger overshoot.
2. **Integral Constant (Ki) :**
The intergral control makes adjustment to the value by taking all the values (i.e sum of all past errors) into consideration. This minimizes the steady state error and helps to achieve the set point without much oscillations. This also help in overcoming of the system bias.
3. **Differential Constant (Kd) :**
The differential control makes control action based on the change of error (Sometimes we consider change in input directly). This helps in reducing overshoot of our model. Thereby, we can able to achieve the steady state with small time.

**Final Hyperparameters:**

The final parameter tuning was done by trying out various values and adjusting them based on my understanding of the controllers. I tried out various parameters such as:

// Only with propotional controller
  kp=1.0;
  ki=0;
  kd=0;

 //Only with differential controller
  kp=0;
  ki=0;
  kd=1.0;
  
 //combination of Kp,Kd
  kp=0.5;
  ki=0;
  kd=0.5;
  
 //combination of Kp,Ki #1
  kp=0.3;
  ki=0.8;
  kd=0;
  
  //combination of Kp,Kd #2
  kp=0.15;
  ki=0;
  kd=0.8;*/

While the individual controller by themself couldn't control the car throughout the track. The combination of Kp,Kd or Kp,Ki had a tough time maintaining it in the center and while going off roads at a few places as well. By adding a Ki, with a very small value,  I was able to run the car properly on the center of the road and make it reach the center in a short amount of time.

//combination of Kp,Kd,Ki(to converge faster)
  kp=0.15;
  ki=0.005;
  kd=0.8;

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.
