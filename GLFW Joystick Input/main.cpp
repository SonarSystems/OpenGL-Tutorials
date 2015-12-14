#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL );
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize( window, &screenWidth, &screenHeight );

    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, screenWidth, screenHeight ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment
    
    
    
    
    
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Render OpenGL here
        
        
        
        
        int present = glfwJoystickPresent( GLFW_JOYSTICK_1 );
        //std::cout << present << std::endl;
        
        if ( 1 == present )
        {
            int axesCount;
            const float *axes = glfwGetJoystickAxes( GLFW_JOYSTICK_1, &axesCount );
            //std::cout << count << std::endl;
        
            /*
             std::cout << "Left Stick X Axis: " << axes[0] << std::endl; // tested with PS4 controller connected via micro USB cable
            std::cout << "Left Stick Y Axis: " << axes[1] << std::endl; // tested with PS4 controller connected via micro USB cable
            std::cout << "Right Stick X Axis: " << axes[2] << std::endl; // tested with PS4 controller connected via micro USB cable
            std::cout << "Right Stick Y Axis: " << axes[3] << std::endl; // tested with PS4 controller connected via micro USB cable
            std::cout << "Left Trigger/L2: " << axes[4] << std::endl; // tested with PS4 controller connected via micro USB cable
            std::cout << "Right Trigger/R2: " << axes[5] << std::endl; // tested with PS4 controller connected via micro USB cable
            */
            
            int buttonCount;
            const unsigned char *buttons = glfwGetJoystickButtons( GLFW_JOYSTICK_1, &buttonCount );
            if ( GLFW_PRESS == buttons[1] )
            {
                //std::cout << "Pressed" << std::endl;
            }
            else if ( GLFW_RELEASE == buttons[0] )
            {
                //std::cout << "Released" << std::endl;
            }
            
            const char *name = glfwGetJoystickName( GLFW_JOYSTICK_1 );
            //std::cout << name << std::endl;
        }
        
        
        
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}

