//if the lowest value is blue and the highest value is green and blue > 600 detects room3 at the silver line
void DetectRoom() {
  readLED();
  int deltal = higher(rl, gl, bl) - lower(rl, gl, bl);
  int deltar = higher(rr, gr, br) - lower(rr, gr, br);
  //if ((rl > 850 && rr > 850 && gl > 850 && gr > 850 && bl > 850 && br > 850 && deltar > 12 && deltal > 12) || (els < 50 && ls < 50 && rs < 50 && ers < 50 && ms < 600))detec++;
  if(els < 250 && ls < 250 && ms < 500 && rs < 250 && ers < 250)detec++;
  else {
    if(detec>=5)detec-=10;
    else detec=0;
  }
  Serial.println(detec);

  if(detec >= 25 && ram <= 1)
  {
    walk_distance(-7.0);
    //Troom();
    Nroom();
  }
}

void NPU_DetectRoom(){
  array_read();//reads the  value of the array sensor
  if(els < 200 && ls < 200 && rs < 200 && ers < 200 && ms < 200)s++;//if the robot got its sensors in white sums 2 do s
  else {Serial.println("REF");array_print();s--;}//else subtracts 1 from s
  if(s<0)s=0;//if s is lower than 0 then s is than 0
  if(s>40){//room 3
    // while (els < 400 && ls < 400 && rs < 400 && ers < 400 && ms < 400) {
    //   walk(-SWL, -SWR);
    // } 
    freeze(10);
    walk_distance(-20.0);
    New_Room();
  }
}

void touch(int lim_p) 
{
  unsigned long flag_p = millis();
  while (digitalRead(TOUCH1) || digitalRead(TOUCH2) )// Until the two sensors touch the wall
  {
    Serial.print(digitalRead(TOUCH1));
    Serial.println(digitalRead(TOUCH2));
    walk(-1023,-1023); // while the back buttons dont touch the wall make the robot go back
    if(!digitalRead(TOUCH1))walk(0, -1023); // while the left back button doesn´t touch the wall walk with the left motor 
    if(!digitalRead(TOUCH2))walk(-1023, 0); // while the right back button doesn´t touch the wall walk with the right motor
    delay(15);
    if(millis() - flag_p > lim_p)break;
  }
  freeze(100);
}