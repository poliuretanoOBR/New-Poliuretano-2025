void revolution(int revl, int revr) {
    dxl.torqueOff(DXL_ID);
    dxl2.torqueOff(DXL_ID2);
    dxl.setOperatingMode(DXL_ID, OP_EXTENDED_POSITION);
    dxl2.setOperatingMode(DXL_ID2, OP_EXTENDED_POSITION);
    dxl.torqueOn(DXL_ID);
    dxl2.torqueOn(DXL_ID2);
    // Set a goal position (e.g., 8192, which is 2 full rotations for a 12-bit encoder)
    int32_t goal_positionr = abs(dxl.getPresentPosition(DXL_ID, UNIT_RAW)) + 4096*revr;
    int32_t goal_positionl = -abs(dxl2.getPresentPosition(DXL_ID2, UNIT_RAW)) - 4096*revl;
    dxl.setGoalPosition(DXL_ID, goal_positionr, UNIT_RAW);
    dxl2.setGoalPosition(DXL_ID2, goal_positionl, UNIT_RAW);
}
