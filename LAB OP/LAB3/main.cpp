#include "Window.h"
#include "DialogWindow.h"
#include "DocumentWindow.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    const int N = 2018;
    Window* prozori[N];

    for (int i = 0; i < 1009; i++)
        prozori[i] = new DialogWindow();

    for (int i = 1009; i < N; i++)
        prozori[i] = new DocumentWindow();

    
    cout << "Unesi title i state za svaki prozor:\n";
    for (int i = 0; i < N; i++)
    {
        prozori[i]->read(cin);
    }

 //Test open / close za SVE prozore
 for (int i = 0; i < N; i++) {
     prozori[i]->open();
     prozori[i]->draw(cout);
     prozori[i]->close();
     prozori[i]->draw(cout);
 }

 //Test confirm / cancel za DialogWindow
 for (int i = 0; i < 1009; i++) {
     DialogWindow* dw = dynamic_cast<DialogWindow*>(prozori[i]);
     if (dw) {
         dw->open();
         dw->draw(cout);

         dw->confirm();
         dw->draw(cout);

         dw->open();
         dw->cancel();
         dw->draw(cout);
     }
 }


 for (int i = 0; i < N - 1; i++) 
 {
     for (int j = 0; j < N - 1 - i; j++)
     {
         if (prozori[j]->getTitle() > prozori[j + 1]->getTitle())
         {
             Window* tmp = prozori[j];
             prozori[j] = prozori[j + 1];
             prozori[j + 1] = tmp;
         }
     }
 }


  
    ofstream izlaz("prozori.txt");
    for (int i = 0; i < 2018; i++) {
        prozori[i]->draw(izlaz);
    }

 
    for (int i = 0; i < 2018; i++) {
        delete prozori[i];
    }

    return 0;
}

