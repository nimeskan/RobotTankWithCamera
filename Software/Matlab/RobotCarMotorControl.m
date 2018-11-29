function [status] = RobotCarMotorControl(leftDir, leftDist, rightDir, rightDist)
status = 0;
leftDistBytes = typecast(uint32(leftDist), 'uint8');
rightDistBytes = typecast(uint32(rightDist), 'uint8');

leftDistTopByte = leftDistBytes(2);
leftDistBotByte = leftDistBytes(1);
rightDistTopByte = rightDistBytes(2);
rightDistBotByte = rightDistBytes(1);

client = tcpclient('192.168.0.20', 14000);
data = uint8([1, leftDir, leftDistTopByte, leftDistBotByte, rightDir, rightDistTopByte, rightDistBotByte]);
%whos data
write(client, data)
client.BytesAvailable
read(client)
clear client
status = 1;
