clear all; %#ok<CLALL>
clc;

testFilename = 'LeftView.jpg';
leftImage = imread(testFilename);
testFilename = 'RightView.jpg';
rightImage = imread(testFilename);

selectedPixel = GetPixelLoactionFromImage(leftImage, 'Step1: (CLEANER) Select a point on left cam image');
r1 = selectedPixel(1);
selectedPixel = GetPixelLoactionFromImage(rightImage, 'Step2: (CLEANER) Select a point on right cam image');
r2 = selectedPixel(1);

distanceOfCleaner = CalculateDualCameraObjectDistance(0.77, r2, r1, 0.00198, 0.00198)

selectedPixel = GetPixelLoactionFromImage(leftImage, 'Step1: (DEODORANT) Select a point on left cam image');
r1 = selectedPixel(1);
selectedPixel = GetPixelLoactionFromImage(rightImage, 'Step2: (DEODORANT) Select a point on right cam image');
r2 = selectedPixel(1);

distanceOfDeodorant = CalculateDualCameraObjectDistance(0.77, r2, r1, 0.00198, 0.00198)

selectedPixel = GetPixelLoactionFromImage(leftImage, 'Step1: (PROTEIN) Select a point on left cam image');
r1 = selectedPixel(1);
selectedPixel = GetPixelLoactionFromImage(rightImage, 'Step2: (PROTEIN) Select a point on right cam image');
r2 = selectedPixel(1);

distanceOfProtein = CalculateDualCameraObjectDistance(0.77, r2, r1, 0.00198, 0.00198)

selectedPixel = GetPixelLoactionFromImage(leftImage, 'Step1: (V8) Select a point on left cam image');
r1 = selectedPixel(1);
selectedPixel = GetPixelLoactionFromImage(rightImage, 'Step2: (V8) Select a point on right cam image');
r2 = selectedPixel(1);

distanceOfV8 = CalculateDualCameraObjectDistance(0.77, r2, r1, 0.00198, 0.00198)

disp(['Cleaner: ' num2str(distanceOfCleaner)])
disp(['Deodorant: ' num2str(distanceOfDeodorant)])
disp(['Protein: ' num2str(distanceOfProtein)])
disp(['V8: ' num2str(distanceOfV8)])


function [pixel_location] = GetPixelLoactionFromImage(imageObject, titleOfFig)
fig_obj = figure( 'units','normalized','outerposition',[0 0 1 1]);
set(fig_obj,'name', titleOfFig,'MenuBar', 'none', 'ToolBar', 'none');
image(imageObject,'Parent',gca);
set(gca,'fontsize', 18);
title(titleOfFig);
pixel_location = ginput(1);
close(fig_obj)
end
