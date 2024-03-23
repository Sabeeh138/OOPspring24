/*
Name: Muhammad Sabeeh
id: 23k-0002
Purpose: Image pixel data initializer with random values
*/

#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

class image {
    private:
        int width;
        int height;
        int* image_data;

    public:
        //parameterized constructor
        image(int awidth, int aheight, const int* imgData) : width(awidth), height(aheight) {
            //DMA for a array to store pixel data 
			image_data = new int[width * height];
			//populating the array with pixel data
            for (int i = 0; i < width * height; i++) {
                image_data[i] = imgData[i];
            }
        }

        //copy constructor
        image(const image& other/*passing another object as argument*/) : width(other.width), height(other.height) {
            image_data = new int[width * height];
            for (int i = 0; i < width * height; i++) {
                image_data[i] = other.image_data[i];
            }
        }

        //destructor
        ~image() {
            delete[] image_data;
        }

        //display function
        void display() const {
            cout<<"image Data:\n";
            //diplaying image pixel data
		    for (int i=0;i<height;i++) {
                for (int j=0;j<width; j++) {
                    cout<<image_data[i * width + j] << " ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        //add pixel data in places where pixel value is less then or equal to zero with random values between 1 and 255
        void updateData() {
        	//this function will generate random numbers to populate the array with DIFFERENT numbers each time the program is run based on the time as the seed of the function
            srand(time(NULL));
            for (int i = 0; i < width * height;i++) {
                if (image_data[i] <= 0) {
                	//makes sure random value is between 1 and 255
                    image_data[i]=rand() % 255 + 1;
                }
            }
        }
};

int main() {
	cout<<"Muhammad Sabeeh\n23k-0002\n\n"<<endl;
	

    int imgdata[6] = {1, -2, 3, -4, 5, 6};

    image original(2, 3, imgdata);

    //create a copy of the original image
    image copy(original);

    //show the original and copied images
    cout<<"Original image:\n";
    original.display();

    cout<<"Copied image:\n";
    copy.display();

    //alter data and display again
    original.updateData();
    copy.updateData();

    cout << "after updating data:\n";
    cout << "Original Image:\n";
    original.display();

    cout << "copied Image:\n";
    copy.display();

    return 0;
