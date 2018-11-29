function [z] = CalculateDualCameraObjectDistance(cameraOffsetsInXDir, r1, r2, lambda1, lambda2)
u1 = -0.0000028*(r1 - 640/2)
u2 = -0.0000028*(r2 - 640/2)

z = cameraOffsetsInXDir/(u1/lambda1 - u2/lambda2);
