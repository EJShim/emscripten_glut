#include <iostream>


#ifdef __EMSCRIPTEN__
   #define GL_GLEXT_PROTOTYPES   
   #include <emscripten/emscripten.h>
   #include <GL/glut.h>
#else
   #ifdef _WIN32
      #include <Windows.h>
   #endif
   #include <GL/freeglut.h>
#endif

#include <vtkSmartPointer.h>
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkCamera.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkOpenGLRenderer.h>
#include <vtkOpenGLRenderWindow.h>

vtkSmartPointer<vtkOpenGLRenderer> ren = vtkSmartPointer<vtkOpenGLRenderer>::New();
vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();

void Reshape( int width, int height )
{ 	 
  renWin->SetSize( width, height );
} 	 

void Draw()
{ 	
  renWin->Render();
  ren->GetActiveCamera()->Azimuth( 1 );
  glutPostRedisplay();
}




int main(int argc, char *argv[])
{
   std::cout << "main()" << std::endl;

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutCreateWindow("VTK GLUT Example");
   glutReshapeFunc(Reshape);
   glutDisplayFunc(Draw);

   vtkSmartPointer<vtkConeSource> cone = vtkSmartPointer<vtkConeSource>::New();

   vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
   mapper->SetInputConnection(cone->GetOutputPort());

   vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
   actor->SetMapper(mapper);

   ren->AddActor(actor);
   renWin->AddRenderer(ren);

   renWin->InitializeFromCurrentContext();

   #ifndef __EMSCRIPTEN__
      glutMainLoop();
   #endif
   

   return 0;
}
