#include <MatrixMath.h>


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
int i=0;
void setup()
{
  Serial.begin(9600); 
  B[0][0]=1.0f;B[0][1]=0.0f;B[1][0]=1.0f;B[1][1]=0.0f;
   v[0]=0.0f;
   v[1]=1.0f; 

   for(int i=0;i<100;i++)
    Z[i]=3.0f+(float)((rand()%20)-10)/10;///(float)RAND_MAX;
  
  
   X[0][0]=0.0f; X[1][0]=0.0f;
   P[0][0]=1.0f; P[0][1]=0.0f; P[1][0]=0.0f; P[1][1]=1.0f;
   F[0][0]=1.0f; F[0][1]=0.1f; F[1][0]=0.0f; F[1][1]=1.0f;
   Q[0][0]=0.0001f; Q[0][1]=0.0f; Q[1][0]=0.0f; Q[1][1]=0.0001f;
   H[0][0]=1.0f; H[0][1]=0.0f;
   R[0][0]=2.0f;
  
   I[0][0]=1.0f;I[0][1]=0.0f;I[1][0]=0.0f;I[1][1]=1.0f;
  


   //Matrix.Print((float*)Z,100,1,"Z");
   /*
   Matrix.Print((float*)X, 2, 1, "X");

   Matrix.Print((float*)P, 2, 2, "P");
   Matrix.Print((float*)F, 2, 2, "F");
   Matrix.Print((float*)Q, 2, 2, "Q");
   Matrix.Print((float*)H, 1, 2, "H"); 
  */

 
}

void loop()
{
  

  while(i<100){
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
    K_TERM[0][0]=K[0][0]*(Z[i]- HX_[0][0]);
    K_TERM[1][0]=K[1][0]*(Z[i]- HX_[0][0]);
    Matrix.Add((float*) X_, (float*) K_TERM, 2, 1, (float*) X);

    Z_K[i]=X[0][0];
    //P=(eye(2)-K*H)*P_;
    Matrix.Multiply((float*)K, (float*)H, 2, 1, 2, (float*)KH);  
    Matrix.Subtract((float*) I, (float*) KH, 2, 2, (float*) P_TERM);  
    Matrix.Multiply((float*)P_TERM, (float*)P_, 2, 2, 2, (float*)P);
  
    i=i+1;
  }

  //Serial.println("\nZK\n"); 
  Matrix.Print((float*)Z_K, 100, 1, "Z_K");
  //Serial.println("\nZ\n");  
  Matrix.Print((float*)Z, 100, 1, "Z");  


  while(1);
}
