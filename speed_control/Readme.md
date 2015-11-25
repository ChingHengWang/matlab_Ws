# Readme.md

work from 11/17 to 11/23
## ISSUE
-1. Simple PID Test Simulation : pid_test
0. origin uno_serial_speed control : uno_serial
1. Test Matrix work : MatrixMath_test
2. Implement Kalman filter in arduino : arduino_kalman
3. Kalman filter to read encoder in arduino : arduino_kalman_getEnc_motor
4. Kalman filter to PID control speed : auduino_speed_cmd
5. Kalman filter to produce chirp signal for ID : arduno_sinwave_input_v2

## ID 
DC motor model is describe in 
		file : /home/zach/matlab_ws/speed_control/id_test/de_model.simulate.m

* num=[0.002]
* den=[15.384 3.185 1]

this model id data  is in

		file: /home/zach/matlab_ws/speed_control/id_test/sinwave_source/data/low_f_amp_250_w_0.5_40_sT_0.02_v2/record.txt

## ID step
0. burning the arudino code and set the cmd=2
the code is in

		file: /home/zach/matlab_ws/speed_control/id_test/sinwave_source/data/low_f_amp_250_w_0.5_40_sT_0.02_v2/arduino_sinwave_input_v2/arduino_sinwave_input_v2.ino

test situation is

id input spec
1. PWM 
2. Amp 150 
3. frequency from 0.1 to 15 


1. record the data
		$. cat /dev/ttyACM0 | tee record.txt

2. verify the setting
Form: record.txt
To:
sin_frequency_input.txt
pwm_input.txt
angular_speed_output.txt

		$. vim readfile.cpp 

		$. g++ readfile.cpp -o readfile 

		$. ./readfile

3. Bode plot and system identificaiton
file: /home/zach/matlab_ws/speed_control/id_test/sinwave_source/data/low_f_amp_250_w_0.5_40_sT_0.02_v2/myplot.m

sampling frequency 50Hz

		Fs=50;%50Hz

sampling time 0.02s

		Ts=0.02;

		t=Ts*(1:N);

		f=Fs*[0:N/2-1]/N;

		PWM_INPUT=abs(fft(pwm_input));

		PWM_INPUT=PWM_INPUT(1:N/2);

		figure;plot(f,20*log(PWM_INPUT));

		OUTPUT=abs(fft(angular_speed_output));

		OUTPUT=OUTPUT(1:N/2);

		figure;plot(f,20*log(OUTPUT));

		figure;plot(log(f),20*log((OUTPUT)./((PWM_INPUT))));

## conculusion
1. complete simple model id
2. use 1 order and 2 order method and the same result
3. matlab/simulink result and real result still not the same , because the discrete situation still not work well in matlab by my knowledge.
4. kalman filter can do obviously result


## Real trace
1. target=2
2. P=50 I=50 D=3
3. file: 
