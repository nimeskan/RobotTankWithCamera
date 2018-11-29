
%One revolution on the left motor
[status] = RobotCarMotorControl(0,1220,0,0);

pause(10);

%One revolution on the right motor
[status] = RobotCarMotorControl(0,0,0,1220);
