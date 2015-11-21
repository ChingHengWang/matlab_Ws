#include <MatrixMath.h>

//#include <Metro.h>

#include "SoftwareSerial.h";

#define encoder0PinA  2
#define encoder0PinB  3

#define motorIn1 6
#define InA 4
#define InB 5

#define LOOPTIME 50
float looptime=0.02;
int pinAState = 0;
int pinAStateOld = 0;
int pinBState = 0;
int pinBStateOld = 0;

const int Tx = 11;
const int Rx = 10; 

char commandArray[3];
byte sT = 0;  //send start byte
byte sH = 0;  //send high byte
byte sL = 0;  //send low byte
byte sP = 0;  //send stop byte

byte rT = 0;  //receive start byte
byte rH = 0;  //receive high byte
byte rL = 0;  //receive low byte
byte rP = 0;  //receive stop byte

SoftwareSerial mySerial(Rx, Tx);

volatile long Encoderpos = 0;
volatile long unknownvalue = 0;
static long EncoderposPre = 0;   

volatile int lastEncoded = 0;
unsigned long lastMilli = 0;                    // loop timing 
//long dT = 0;
double dT=0.0;
double dT4=0.0;
double omega_target = 2.0;
double omega_actual = 0;
double omega_actual_filter=0;

int PWM_val = 0;                                // (25% = 64; 50% = 127; 75% = 191; 100% = 255)
int CPR = 52;                                   // encoder count per revolution
int gear_ratio = 65.5; 
int actual_send = 0;
int target_receive = 0;


volatile double error=0;
double d_error=0; 
double last_error=0;   
double sum_error=0;     
double pidTerm = 0;     
 
float Kp = 50;
float Ki = 50;
float Kd = 3;
int k=0;
   

//id

double w=0.5;
double theta=0;
double total_theta=0;
int N=2;
int wave_count=0;
//kalman filter
float X[2][1];float X_[2][1];
float P[2][2];float P_[2][2];
float F[2][2];float F_TRAN[2][2];
float Q[2][2];float FP[2][2];float FPF_TRAN[2][2];
float H[1][2];float HP_[1][2];float H_TRAN[2][1];float P_H_TRAN[2][1];float HP_H_TRAN[1][1];float HP_H_TRAN_ADD_R[1][1];
float HX_[1][1];
float K[2][1];float K_TERM[2][1];float KH[2][2];
float P_TERM[2][2];
float R[1][1];
float I[2][2];


void setup() { 
   pinMode(encoder0PinA, INPUT); 
   digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
   pinMode(encoder0PinB, INPUT); 
   digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
  
   attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
   attachInterrupt(1, doEncoder, CHANGE);
   pinMode(Rx, INPUT); pinMode(Tx, OUTPUT);
   pinMode(InA, OUTPUT); 
   pinMode(InB, OUTPUT); 
   mySerial.begin (19200);
   Serial.begin (19200);

   X[0][0]=0.0f; X[1][0]=0.0f;
   P[0][0]=1.0f; P[0][1]=0.0f; P[1][0]=0.0f; P[1][1]=1.0f;
   F[0][0]=1.0f; F[0][1]=0.5f;//sampling time is 0.1s 
   F[1][0]=0.0f; F[1][1]=1.0f;
   Q[0][0]=0.00001f; Q[0][1]=0.0f; Q[1][0]=0.0f; Q[1][1]=0.00001f;
   H[0][0]=1.0f; H[0][1]=0.0f;
   R[0][0]=0.1f;
  
   I[0][0]=1.0f;I[0][1]=0.0f;I[1][0]=0.0f;I[1][1]=1.0f;
  
 
} 

void loop() 
{       
 
  if((millis()-lastMilli) >= looptime*1000)   
     {                                    // enter tmed loop
        dT = (double)(millis()-lastMilli)/1000;
        lastMilli = millis();

                                                       // calculate speed
        getMotorData();    
        omega_actual_filter=KalmanFilter((float)omega_actual);
 
        
        //PWM_val = (updatePid(omega_target, omega_actual_filter));                       // compute PWM value from rad/s 
        error = omega_target - omega_actual_filter; 
        sum_error = sum_error + error * dT;
        d_error = (double)(error - last_error) / dT;
        pidTerm = Kp * error+ Ki * sum_error+ Kd * d_error;                          
        last_error = error;  
        //PWM_val= constrain((double)pidTerm, -255, 255);
        
        theta=fmod(w*k*looptime,2*PI);
        PWM_val=250*sin(theta);

        pwmCmd();
        k=k+1;        
        total_theta=total_theta+w*1*looptime; 
        wave_count=floor(total_theta/(2*PI));
        w=0.5+wave_count*0.5;
        printMotorInfoMatlab();
     }
}

float KalmanFilter(float observe_Z){
    float estimate_Z=0;
    //Serial.println(i);
    //X_=F*X;
    Matrix.Multiply((float*)F, (float*)X, 2, 2, 1, (float*)X_);
    //P_=F*P*F'+Q;
    Matrix.Multiply((float*)F, (float*)P, 2, 2, 2, (float*)FP);    
    Matrix.Transpose((float*)F, 2, 2, (float*)F_TRAN);
    Matrix.Multiply((float*)FP, (float*)F_TRAN, 2, 2, 2, (float*)FPF_TRAN);  
    Matrix.Add((float*) FPF_TRAN, (float*) Q, 2, 2, (float*) P_);
    //K=P_*H'/(H*P_*H'+R);
    Matrix.Transpose((float*) H, 1, 2, (float*) H_TRAN);    
    Matrix.Multiply((float*)P_, (float*)H_TRAN, 2, 2, 1, (float*)P_H_TRAN);  
    Matrix.Multiply((float*)H, (float*)P_, 1, 2, 2, (float*)HP_); 
    Matrix.Multiply((float*)HP_, (float*)H_TRAN, 1, 2, 1, (float*)HP_H_TRAN);   
    Matrix.Add((float*) HP_H_TRAN, (float*) R, 1, 1, (float*) HP_H_TRAN_ADD_R);
    K[0][0]=P_H_TRAN[0][0]/HP_H_TRAN_ADD_R[0][0];
    K[1][0]=P_H_TRAN[1][0]/HP_H_TRAN_ADD_R[0][0];
    //X=X_+K*(Z(i)-H*X_);
    Matrix.Multiply((float*)H, (float*)X_, 1, 2, 1, (float*)HX_);
    K_TERM[0][0]=K[0][0]*(observe_Z- HX_[0][0]);
    K_TERM[1][0]=K[1][0]*(observe_Z- HX_[0][0]);
    Matrix.Add((float*) X_, (float*) K_TERM, 2, 1, (float*) X);
    estimate_Z=X[0][0];
    //P=(eye(2)-K*H)*P_;
    Matrix.Multiply((float*)K, (float*)H, 2, 1, 2, (float*)KH);  
    Matrix.Subtract((float*) I, (float*) KH, 2, 2, (float*) P_TERM);  
    Matrix.Multiply((float*)P_TERM, (float*)P_, 2, 2, 2, (float*)P);
    return estimate_Z;
  
  }

void pwmCmd(){
            if (PWM_val <= 0)   { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, LOW);  digitalWrite(InB, HIGH); }
            if (PWM_val > 0)    { analogWrite(motorIn1,abs(PWM_val));  digitalWrite(InA, HIGH);   digitalWrite(InB, LOW);}
  }

void getMotorData()  
{                                   
  //converting ticks/s to rad/s
  //omega_actual = 4.5;
  omega_actual = ((Encoderpos - EncoderposPre)*((double)1/dT))*(double)(2*PI)/(CPR*gear_ratio);  //ticks/s to rad/s
  EncoderposPre = Encoderpos;                 
}

double updatePid(double targetValue,double currentValue)   
{   
                                                 // PID correction

                      
  error = targetValue - currentValue; 
  sum_error = sum_error + error * dT;
  d_error = (double)(error - last_error) / dT;
  pidTerm = Kp * error+ Ki * sum_error+ Kd * d_error;                          
  last_error = error;  
   
  //Serial.print(" omega_actual_filter:"); Serial.print(omega_actual_filter);
  return constrain(int(pidTerm/0.04039215686), -255, 255);
}


void doEncoder() {
//   Encoderpos++;
  pinAState = digitalRead(2);
  pinBState = digitalRead(3);

  if (pinAState == 0 && pinBState == 0) {
    if (pinAStateOld == 1 && pinBStateOld == 0) // forward
      Encoderpos ++;
    if (pinAStateOld == 0 && pinBStateOld == 1) // reverse
      Encoderpos --;
  }
  if (pinAState == 0 && pinBState == 1) {
    if (pinAStateOld == 0 && pinBStateOld == 0) // forward
      Encoderpos ++;
    if (pinAStateOld == 1 && pinBStateOld == 1) // reverse
      Encoderpos --;
  }
  if (pinAState == 1 && pinBState == 1) {
    if (pinAStateOld == 0 && pinBStateOld == 1) // forward
      Encoderpos ++;
    if (pinAStateOld == 1 && pinBStateOld == 0) // reverse
      Encoderpos --;
  }

  if (pinAState == 1 && pinBState == 0) {
    if (pinAStateOld == 1 && pinBStateOld == 1) // forward
      Encoderpos ++;
    if (pinAStateOld == 0 && pinBStateOld == 0) // reverse
      Encoderpos --;
  }
  pinAStateOld = pinAState;
  pinBStateOld = pinBState;
}

void printMotorInfo()  
{                                                                      
   //Serial.print(" omega_target:"); Serial.print(omega_target);
   //Serial.print(" omega_actual:"); Serial.print(omega_actual);
   Serial.print(" omega_actual_filter:"); Serial.print(omega_actual_filter);
   Serial.print(" kd_term:"); Serial.print(Kd * d_error); 
   Serial.print(" kp_term:"); Serial.print(Kp * error);
   //Serial.print(" dT:"); Serial.print(dT);
   Serial.print(" error:"); Serial.print(error);
     
   Serial.println();

}

void printMotorInfo2()  
{       
   Serial.print(" PWM_val:"); Serial.print(PWM_val);
   Serial.print(" k:"); Serial.print(k);
   Serial.print(" theta:"); Serial.print(theta);
   Serial.print(" toatal_theta:"); Serial.print(total_theta);
   Serial.print(" w:"); Serial.print(w);   
   Serial.print(" wave_count:"); Serial.print(wave_count); 
   //Serial.print(" pidTerm:"); Serial.print(pidTerm);
  //Serial.print(" last_error:"); Serial.print(last_error*1000);
  //Serial.print(" d_error:"); Serial.print(d_error);
  //Serial.print(" kp_term:"); Serial.print(Kp * error);
  //Serial.print(" ki_term:"); Serial.print(Ki * sum_error);
  //Serial.print(" kd_term:"); Serial.println(Kd * d_error); 
  Serial.print(" dT:"); Serial.println(dT);
  
}

void printMotorInfoMatlab()  
{                                                                      
   Serial.print(" ");                  
   Serial.print(w);
   Serial.print(" ");                  
   Serial.print(PWM_val);
   Serial.print(" ");                  
   Serial.print(omega_actual_filter);

   //Serial.print(" ");                  
   //Serial.print(dT);
 
   Serial.println();

}
