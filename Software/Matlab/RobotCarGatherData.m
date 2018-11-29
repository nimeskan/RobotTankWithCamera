function [status] = RobotCarGatherData()

Rightfilename = 'RightViewRaw.jpg';
[status, rightRawImageData, rightImageData] = RobotCarCameraView(Rightfilename);
figure;
imshow(rightRawImageData);
figure;
imshow(rightImageData);
imwrite(rightImageData, 'RightView.jpg');

%back from block
[status] = RobotCarMotorControl(1,300,1,300);

pause(3);
%Left Rotate
[status] = RobotCarMotorControl(1,400,0,400);

pause(3);
%forward
[status] = RobotCarMotorControl(0,1350,0,1350);

pause(8);
%Right Rotate
[status] = RobotCarMotorControl(0,400,1,400);

pause(3);
%forward to block
[status] = RobotCarMotorControl(0,400,0,405);


pause(4);

leftfilename = 'LeftViewRaw.jpg';
[status, leftRawImageData, leftImageData] = RobotCarCameraView(leftfilename);
figure;
imshow(leftRawImageData);
figure;
imshow(leftImageData);
imwrite(leftImageData, 'LeftView.jpg');


pause(8);
%back from block
[status] = RobotCarMotorControl(1,300,1,300);

pause(3);
%Right Rotate
[status] = RobotCarMotorControl(0,400,1,400);

pause(3);
%forward
[status] = RobotCarMotorControl(0,1350,0,1350);

pause(8);
%Left Rotate
[status] = RobotCarMotorControl(1,400,0,400);

pause(3);

%forward to block
[status] = RobotCarMotorControl(0,400,0,415);
 
pause(3);

status = 1