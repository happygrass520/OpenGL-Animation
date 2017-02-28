
/*Camera Controls*/
'k' = rotates counter-clockwise around x-axis
'i' = rotates clock-wise around x-axis
'j' = rotates counter-clockwise around y-axis
'l' = rotates clockwise around y-axis
'm' = rotates counter-clockwise around z-axis
'n' = rotates clockwise around z-axis

right mouse button = click, hold, and move mouse up or down to zoom in or out, respectively.  

------------------------------------------------------------------------

/*Motor Function Controls*/
'w' = rotate head left
'W' = rotate head right

'e' = rotate front of body left
'E' = rotate front of body right

'q' = rotate front of body up
'Q' = rotate front of body down

'a' = tilt camera in the desired direction, then press and hold this key to make the insect walk. 

------------------------------------------------------------------------

/*Bonus Problems Implemented*/
--> Basic Walking motion
--> Walking Direction Specification

The basic walking motion is rolled up into the walking direction. For as long as you press 'a', 
the insect will walk forward with in a fairly natural looking way. 
If it wanders out of frame it will reset on the oppiste side of the screen.

/*Control over Joints Requirements*/ 
--> 2 degrees of freedom: implemented in the front half of the 
insect's body. Can rotate left and right or up and down.
Insect's head can also be moved left and right. Engaging
the animation will reset the values of both the head and 
the front half of the body. 
--> limitations on how far both the head and the front half 
of the insect can rotate have also been put in place. 
--> Other than that, The legs are controlled by using the animation controls

/*Coloring*/
--> With the use of shaders, the different parts of the 
insect of distinguishable

/*Hidden Surface Removal*/
--> Implemented with the use of Back Face culling

/*Mouse Functions*/
--> Implemented in the use of zooming out or in on the insect. 

/*View Change and Control*/
--> In reshape(), z-varibale of the modelmatrix is translated. 

//All other requirements are met, as can be seen in the /*Camera Controls*/
and /*Motor Function Controls*/ section