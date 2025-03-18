void revolution(int revl, int revr) {
    // Set a goal position (e.g., 8192, which is 2 full rotations for a 12-bit encoder)
    int32_t goal_positionr = abs(dxl.getPresentPosition(DXL_ID, UNIT_RAW)) + 4096*revr;
    int32_t goal_positionl = -abs(dxl.getPresentPosition(DXL_ID, UNIT_RAW)) - 4096*revl;
    dxl.setGoalPosition(DXL_ID, goal_positionr, UNIT_RAW);
    dxl2.setGoalPosition(DXL_ID2, goal_positionl, UNIT_RAW);

    // DEBUG_SERIAL.print("Goal Position Set: ");
    // DEBUG_SERIAL.println(goal_position);
}