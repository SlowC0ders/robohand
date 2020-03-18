#include "ros/ros.h"
#include "arm/detector.h" // input message
#include "arm/converter.h" // output message
#include "wintospace.h"

globConv inputData;

arm::converter *read(globConv *in) {

	float Ax1, Ay1, Bx1, By1, Cx1, Cy1, Dx1, Dy1, objwinX, objwinY, Ax2, Ay2, Bx2, By2, Cx2, Cy2, Dx2, Dy2, objsX, objsY, x0, Yw0, Xw0; /*in-out, objs = nedeed space crd */
	float y0, x1, y1, Xw, Yw, Ys, Xs, p, q, p1, q1; /*helpful */
  
  Ax1 = in->one.x;
  Ay1 = in->one.y;
  Bx1 = in->two.x;
  By1 = in->two.y;
  Cx1 = in->three.x;
  Cy1 = in->three.y;
  Dx1 = in->four.x;
  Dy1 = in->four.y;

	//if (objsX == objwinX || objsY == objwinY) {
		objsX = objsY = -1;
		//objwinX = objwinY= -500;
	//}
	
	do {
		Yw0 = 0, Xw0 = 0;
		x0 = Ax1;
		y0 = Ay1;
		x1 = Dx1;
		y1 = Dy1;
		p = Cx1 - x0; q = Cy1 - y0;
		p1 = Bx1 - x1; q1 = By1 - y1;
		Xw = (x0*q*p1 - x1 * q1*p - y0 * p*p1 + y1 * p*p1) / (q*p1 - q1 * p); /* found point of WIN  intersection (center)*/
		Xw = (int)Xw; // minus rochnost'
		Yw = (y0*p*q1 - y1 * p1*q - x0 * q*q1 + x1 * q*q1) / (p*q1 - p1 * q);
		Yw = (int)Yw; // minus rochnost'

		x0 = Ax2;
		y0 = Ay2;
		x1 = Dx2,
		y1 = Dy2;
		p = Cx2 - x0; q = Cy2 - y0;
		p1 = Bx2 - x1; q1 = By2 - y1;
		Xs = (x0*q*p1 - x1 * q1*p - y0 * p*p1 + y1 * p*p1) / (q*p1 - q1 * p); /* found point of SPACE intersection (center) */
		Ys = (y0*p*q1 - y1 * p1*q - x0 * q*q1 + x1 * q*q1) / (p*q1 - p1 * q);
		Ys = (int)Ys; Xs = (int)Xs; // minus rochnost'
n:		 if (Xw == objwinX) {
			if (Yw == objwinY) {  /*gave Xs, Ys for object*/
				objsX = Xs;
				objsY = Ys;
        arm::converter tmp;
        tmp.object.x = objsX;
        tmp.object.y = objsY;
				return &tmp;
			}
			else {
			if (Yw0==0){
				Yw0 = Yw + allowerr;/* +max value*/
				Yw -= allowerr; 
			}
		  		//Yw -= allowerr;
		  		while (Yw != Yw0){
		 			Yw += koef;
		  			goto n;
		 		}
		 		Yw = Yw0 - allowerr; /*not found*/
		 	}
		 	}
		 else {
	if (Xw0 == 0) {
		Xw0 = Xw + allowerr; /* +max value*/
		Xw -= allowerr;
	}
	 			while (Xw != Xw0) {
	 			Xw += koef;
	 			goto n;
	 			}
	 	Xw = Xw0 - allowerr; /*not found*/
		}


		 int n = 0, tmp, t2; float EF, mass[8]; // counter+helpful val;
		 do {
			 //p = ((Ay1 - By1) * (Cx1 - Dx1)); // p = ((Ay1 - By1) / (Cy1 - Dy1));
			// q = ((Bx1 - Ax1) * (Cy1 - Dy1)); //  q = ((Bx1 - Ax1) / (Cx1 - Dx1));
			 if ((tmp = (Bx1 - Ax1)*(Dy1 - Cy1) - (Dx1 - Cx1)*(By1 - Ay1)) == 0){

				 x0 = Xw;
				 y0 = Yw;
				 x1 = Dx1;
				 y1 = Dy1;
				 p = Bx1 - Ax1; q = By1 - Ay1; //
				 p1 = Ax1 - x1; q1 = Ay1 - y1;
				  float Xwad = (x0*q*p1 - x1 * q1*p - y0 * p*p1 + y1 * p*p1) / (q*p1 - q1 * p); /* found point of WIN  intersection paraleli and AD*/
				  float Ywad = (y0*p*q1 - y1 * p1*q - x0 * q*q1 + x1 * q*q1) / (p*q1 - p1 * q);
				 Xwad = (int)Xwad; Ywad = (int)Ywad;// minus rochnost' / in 2d iteration AD~~AB

				 x0 = Xw;
				 y0 = Yw;
				 x1 = Bx1;
				 y1 = By1;
				 p = Bx1 - Ax1; q = By1 - Ay1; //
				 p1 = Cx1 - x1; q1 = Cy1 - y1;
				 float Xwbc = (x0*q*p1 - x1 * q1*p - y0 * p*p1 + y1 * p*p1) / (q*p1 - q1 * p); /* found point of WIN  intersection paraleli and BC*/
				 float Ywbc = (y0*p*q1 - y1 * p1*q - x0 * q*q1 + x1 * q*q1) / (p*q1 - p1 * q);
				 Xwbc = (int)Xwbc; Ywbc = (int)Ywbc; // minus rochnost' AD~~CD

				 mass[n] = Xwbc;				 
				 mass[n + 1] = Ywbc;
				 mass[n + 2] = Xwad; //BC AD firstly
				 mass[n + 3] = Ywad;// after that goto AB~CD; mass=bc,ad,dc,ab (x,y)

				 // break;
			 }
			 else {
				 t2 = (Cx1 - Ax1)*(By1 - Ay1) - (Bx1 - Ax1)*(Cy1 - Ay1) / tmp;
				 /*x0 = Ax1;
				 y0 = Ay1;
				 x1 = Cx1;
				 y1 = Cy1;
				 p = Bx1 - x0; q = By1 - y0;
				 p1 = Dx1 - x1; q1 = Dy1 - y1;
				 ? proverka poteri tochnosti, pri potere drobim koord*/
				float Xwsh = Cx1 + (Dx1 - Cx1)*t2;
				float Ywsh = Cy1 + (Dy1 - Cy1)*t2;// float Xwsh = (x0*q*p1 - x1 * q1*p - y0 * p*p1 + y1 * p*p1) / (q*p1 - q1 * p); /* point of the shozdenie (gorizont front) AB CD*/
				 // float Ywsh = (y0*p*q1 - y1 * p1*q - x0 * q*q1 + x1 * q*q1) / (p*q1 - p1 * q);

				 x0 = Xwsh;
				 y0 = Ywsh;
				 x1 = Bx1;
				 y1 = By1;
				 p = Xw - x0; q = Yw - y0;
				 p1 = Cx1 - x1; q1 = Cy1 - y1;
				 float Xwbc = (x0*q*p1 - x1 * q1*p - y0 * p*p1 + y1 * p*p1) / (q*p1 - q1 * p); /* point of the peresechenie Bsh and BC*/
				 float Ywbc = (y0*p*q1 - y1 * p1*q - x0 * q*q1 + x1 * q*q1) / (p*q1 - p1 * q);

				 x0 = Xwsh;
				 y0 = Ywsh;
				 x1 = Ax1;
				 y1 = Ay1;
				 p = Xw - x0; q = Yw - y0;
				 p1 = Dx1 - x1; q1 = Dy1 - y1;
				 float Xwad = (x0*q*p1 - x1 * q1*p - y0 * p*p1 + y1 * p*p1) / (q*p1 - q1 * p); /* point of the peresechenie Bsh and AD*/
				 float Ywad = (y0*p*q1 - y1 * p1*q - x0 * q*q1 + x1 * q*q1) / (p*q1 - p1 * q);
				 mass[n] = Xwbc;
				 mass[n + 1] = Ywbc;
				 mass[n + 2] = Xwad;
				 mass[n + 3] = Ywad;// goto AB~CD; 
			 } 
			 EF = Ax1; Ax1 = Bx1; Bx1 = Cx1; Cx1 = Dx1; Dx1 = EF;
			 EF = Ay1; Ay1 = By1; By1 = Cy1; Cy1 = Dy1; Dy1 = EF; //reverse for cd + ba
			 n += 4;
		 } while (n == 4); // mass = bc, ad,
		 EF = Ax1; Ax1 = Cx1; Cx1 = EF; EF = Dx1; Dx1 = Bx1; Bx1 = EF; /*came back to first values for quad*/
		 EF = Ay1; Ay1 = Cy1; Cy1 = EF; EF = Dy1; Dy1 = By1; By1 = EF;
		 if (objwinY <= Yw) //change quad
		 {
			 if (objwinX <= Xw){ //2d chetvert' (start counting from right-top point)
				 // Ax Ay = ok
				 Bx1 = mass[6]; By1 = mass[7];
				 Dx1 = mass[2]; Dy1 = mass[3];
				 Bx2 = (Bx2 + Ax2) / 2;
				 Cx1 = Xw; Cy1 = Yw;
				 Cx2 = (Cx2 + Dx2) / 2; Cy2 = (Cy2 + By2) / 2;
				 Dy2 = (Ay2 + Dy2) / 2;
				 // By2 Dx2= (const)
			 }
			 else { //1st chetvert'
				 Dx1 = Xw; Dy1 = Yw;
				 Ax1 = mass[6]; Ay1 = mass[7];
				 Ax2 = (Ax2 + Bx2) / 2;
				 Cx1 = mass[0]; Cy1 = mass[1];
				 Cy2 = (Cy2 + By2) / 2;
				 Dy2 = (Ay2 + Dy2) / 2; Dx2 = (Dx2 + Cx2) / 2;
				// Cx2 = const;
				// Bx By ok
				 //Ay2= const
			 }
		 }
		 else {
			 if (objwinX >= Xw) { //4d
			 //D const
				 Ax1 = Xw; Ay1 = Yw;
				 // float push1 = Ay2, push2 = By2;
				  //Bx2 = (Ax2 + Dx2) / 2; 
				 By2 = (By2 + Cy2) / 2;
				 Bx1 = mass[0];  By1 = mass[1];
				 Dx1 = mass[4]; Dy1 = mass[5];
				 //Cx1 Cy1 Cx2 Cy2 Dy2 const
				 //Ax1 = mass[2]; Ay1 = mass[3];
				 Ax2 = (Ax2 + Bx2) / 2;
				 Ay2 = (Ay2 + Dy2) / 2;
				 Dx2 = (Dx2 + Cx2) / 2;
			 }
			 else { //3d
				 Ax1 = mass[2]; Ay1 = mass[3];
				Bx1 = Xw; By1 = Yw;
				 // float push1 = Ay2, push2 = By2;
				
				Bx2 = (Ax2 + Bx2) / 2; By2 = (Ay2 + Dy2) / 2;
				 Ay2 = (Ay2 + Dy2) / 2; // Ax2 const
				 // D const
				 Cx1 = mass[4];
				 Cy1 = mass[5];
				 Cx2 = (Ax2 + Bx2) / 2;
			 }
		 }/*new coords for iteration*/

		}while (objsY != Ys && objsX != Xs);
		return NULL;
}

int AreSame(float a, float b)
{
	int l = fabs(a - b) < EPSILON;
	return l;
}


void chatterCallback(const arm::detector::ConstPtr& msg)
{
  inputData = *msg;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "converter"); // initialise node

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<arm::converter>("conv_chatter", 1000); // initialise topic for third step programm (angles_converter.cpp)
  ros::Subscriber sub = n.subscribe("det_chatter", 1000, chatterCallback); // subscribe on detector chatter

  ros::Rate loop_rate(10); // establish 10hz loop rate

  while (ros::ok()) // cycle for sending messages
  {
    arm::converter *tmp = NULL;
    if (NULL != (arm::converter *tmp = read(&inputData))) {
      arm::converter msg = *tmp; // create message
    }
    chatter_pub.publish(msg); // send message

    ros::spinOnce();

    loop_rate.sleep(); // time balancer
  }

  ros::spin();

  return 0;
}
