void revolution(int revl, int revr) {
    dxl.torqueOff(DXL_ID);//turn off torque to change operation mode
    dxl2.torqueOff(DXL_ID2);//turn off torque to change operation mode
    dxl.setOperatingMode(DXL_ID, OP_EXTENDED_POSITION);//sets operation mode to extended position
    dxl2.setOperatingMode(DXL_ID2, OP_EXTENDED_POSITION);//sets operation mode to extended position
    dxl.torqueOn(DXL_ID);//turn torque on
    dxl2.torqueOn(DXL_ID2); //turn torque on
    
    int32_t current_posl, current_posr;//creates two variables for the current position of the motors

    current_posr = dxl.getPresentPosition(DXL_ID);//gets current position of the right motor
    current_posl = dxl2.getPresentPosition(DXL_ID2);//gets current position of the right motor

    int32_t goal_posr = current_posr + (long)4096*revr, goal_posl = current_posl + (long)4096*revl;//sets the goal position based on the number of revolutions

    Serial.print("posr: ");
    Serial.println(current_posr);  
    Serial.print("posl: ");
    Serial.println(current_posl);
    Serial.print("4096*revr: ");
    Serial.println((long)4096*10);
    Serial.print("4096*revl: ");
    Serial.println((long)4096*10);

    Serial.print("SUM1: ");
    Serial.println((long)(current_posr + (long)4096*revr));
    Serial.print("SUM2: ");
    Serial.println((long)(current_posl + (long)4096*revr));


    Serial.print("delta r: ");
    Serial.println(goal_posr - current_posr);  
    Serial.print("delta l: ");
    Serial.println(goal_posl - current_posl);

    dxl.setGoalPosition(DXL_ID, goal_posr);//sets the REAL goal position adding it current position
    dxl2.setGoalPosition(DXL_ID2, goal_posl);//sets the REAL goal position adding it current position
    
    while(abs(dxl.getPresentPosition(DXL_ID, UNIT_RAW) - goal_posr) > 10 || abs(dxl2.getPresentPosition(DXL_ID2, UNIT_RAW) - goal_posl) > 10) {
    }

    digitalWrite(22, 1);

    Serial.print("real pos 1: ");
    Serial.println(dxl.getPresentPosition(DXL_ID));  
    Serial.print("real pos 2: ");
    Serial.println(dxl2.getPresentPosition(DXL_ID2));


    // if (go_back) {
    //     dxl.torqueOff(DXL_ID);
    //     dxl2.torqueOff(DXL_ID2);
    //     dxl.setOperatingMode(DXL_ID, OP_VELOCITY);
    //     dxl2.setOperatingMode(DXL_ID2, OP_VELOCITY);
    //     dxl.torqueOn(DXL_ID);
    //     dxl2.torqueOn(DXL_ID2);
    // }

}