//---------------------------------------------------------------------------

#ifndef planoH
#define planoH

#include "normal.h"
#include "elemplano.h"
//---------------------------------------------------------------------------
class plano
{
private:	// User declarations
        float TamX,TamY;
        normal Normal;
        elemplano **Plano;
public:         // User declarations
        plano();
        plano(float tamx,float tamy);
        ~plano();
        void Rotar(normal Norm, float Angle);
        normal GetNormal();
        elemplano GetElemPlano(int i, int j);
        
};
//---------------------------------------------------------------------------
#endif
