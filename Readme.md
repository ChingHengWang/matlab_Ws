# Readme.md

work from 11/17 to 11/23
## ISSUE
1. DC motor identification model function
2. Kalman filter to reduce incremental nois

## ID 
DC motor model is

num=[0.002]
den=[15.384 3.185 1]

this model according to

		file: /home/zach/matlab_ws/id_test/sinwave_source/data/low_f_amp_250_w_0.5_40_sT_0.02_v2

test situation is

input spec
1. PWM 
2. Amp 150 ?
3. frequency from 0 to 15 ?

## conculusion
1. complete simple model id
2. use 1 order and 2 order method and the same result
3. matlab/simulink result and real result still not the same , because the discrete situation still not work well in matlab by my knowledge.
4. kalman filter can do obviously result
