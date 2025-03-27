//pid control function
void PIDwalk(float a) {

  //local pid variables
  double p=0, i=0, d=0, u=0, error=0;
  

  //difference between left and right reflectance sensors
  error = (els*WE + ls*WI - ers*WE - rs*WI)/3.86;


  //proportional
  p = error*KP;

  //integral with limit (wind-up)
  i += (error-previous_error)*KI;
  if (i < MIN_INTEGRAL || i > MAX_INTEGRAL)i=0;
  
  //time passed by each run
  unsigned long delta_time = millis() - flag;
  
  //debug
  //Serial.println(delta_time);
  
  //derivative (error / delta time
  d = ((error - previous_error) * KD) / ((float)delta_time);

  //auxiliar variable for counting time
  flag = millis();

  //error previous of each run
  previous_error = error;

  //not using i or d
  i=0;
  //d=0;

  //actual correction
  u = p + i + d;

  //debug
  //Serial.println(u);
  //Serial.println(error);
  
  //limits u by motor values
  if (u < U_MIN)u = U_MIN;
  if (u > U_MAX)u = U_MAX;

  //debug
  //Serial.print("u = ");
  //Serial.println(u);
  
  //if middle sensor and internal sensor of any side is on black, walk straight
  if ((ms > MIDDLE_BLACK && ers > BLACK) || (ms > MIDDLE_BLACK && els > BLACK))
  {
    u=0;
  }
  
  //debug for when motor reverts
  if (u == 530.0 || u == -530.0) digitalWrite(22, 1);
  else digitalWrite(22, 0);
  Serial.println(u);
  //walks
  if (u > 0)
  {
    
    walk((265-u)*a, 265*a);
  }
  else
  {
    walk(265*a, (265+u)*a);
    
  }
}
