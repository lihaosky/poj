requirement
You are going to compute the area of a special kind of polygon. 
One vertex of the polygon is the origin of the orthogonal coordinate system. 
From this vertex, you may go step by step to the following vertexes of the polygon until back to the initial vertex. 
For each step you may go North, West, South or East with step length of 1 unit, 
or go Northwest, Northeast, Southwest or Southeast with step length of square root of 2. 
The first line of input is an integer t (1 <= t <= 20), the number of the test polygons. 
Each of the following lines contains a string composed of digits 1-9 describing 
how the polygon is formed by walking from the origin. Here 8, 2, 6 and 4 represent North, South, East and West,
while 9, 7, 3 and 1 denote Northeast, Northwest, Southeast and Southwest respectively. 
Number 5 only appears at the end of the sequence indicating the stop of walking. 
You may assume that the input polygon is valid which means that the endpoint is always the start point 
and the sides of the polygon are not cross to each other.Each line may contain up to 1000000 digits.


ps::area1.cpp is a refined program which dissipate less momery, but the running time may be long when the number is very large.