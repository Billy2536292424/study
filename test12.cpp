#include <iostream>
 using namespace std;
 class Box
 {
 public:
 	void get_value();
 	float volume();
 	void display();
 public:
 	float length;
 	float width;
 
 		float height;
 
 };
 void Box::get_value()
 {
 	cout<<"please input length,width,height:";
 	cin>>length;
 	cin>>width;
 	cin>>height;
 
 }
 float Box::display()
 {
 	return (length*width*height);
 }
 void Box::display()
 {
 	cout<<volume();
 	int main()
 	{
 		Box box1,box2,box3;
 		box1.get_value();
 		cout<<"volume of box1 is";
 		box1.display();
 		box2.get_value();
 		cout<<"volume of box2 is";
 		box2.display();
 		box3.get_value();
 		cout<<"volume of box3 is";
 		box3.display();
 		return 0;
 	}
 }
