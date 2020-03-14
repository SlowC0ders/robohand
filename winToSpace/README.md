There is programm for convering window coordinates to space coordinates. 
Programm must start with arguments such as (1st - programm's exe name) 2d - "-i" 3d - input's file path 4th - "-o" 5th - output file's name 6th (mode) - "-wintospace";
Structure of the acceptable parametrs (input):
File 'input.txt' (argumment 2) must have few properties such as Ax1, Ay1, Bx1, By1, Cx1, Cy1, Dx1, Dy1, objwinX, objwinY - x and y space coordinates for A, B, C, D and object (for it is necessary to calculate world coordinates) respectively;
Structure of the outgoin parametrs (output):
File 'output.txt' (argumment 4) must have two properties such as  objsX objsY - x and y world coordinates for object respectively.