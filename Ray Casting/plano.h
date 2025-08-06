//---------------------------------------------------------------------------

#ifndef planoH
#define planoH

#include <vcl.h>
#include <math.h>
#include <stdio.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class plano
{
private:	// User declarations
        float PX,PY,PZ;
        float NX,NY,NZ;

public:         // User declarations


        plano();
        plano(float,float,float,float,float,float);
        ~plano();
        void Rotar(int eje,int ang);
        void Graficar(TImage *,TImage *,TImage *);
        void BorrarImages(TImage * Image1, TImage * Image2, TImage * Image3);
};


#endif
