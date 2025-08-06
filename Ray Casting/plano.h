//---------------------------------------------------------------------------

#ifndef planoH
#define planoH

#include "normal.h"
#include "voxel.h"
#include "elemplano.h"
//---------------------------------------------------------------------------
class plano
{
private:	// User declarations
        float TamX,TamY;
        normal Normal;
        elemplano **Plano;
        BYTE *LinePtr;
public:         // User declarations
        plano();
        plano(float tamx,float tamy);
        ~plano();
        void Rotar(normal Norm, float Angle);
        void Rotar(float azi, float elev, float tilt);
        void Trasladar(float x, float y, float z);
        //falta borrar el plano, se superponen!!!! dsps q hago mas de 1 muestra
        void Trasladar(normal Norm);
        normal GetNormal();
        elemplano GetElemPlano(int i, int j);
        void CargarPlano(voxel *Vox);
        void Mostrar(TImage *Image);
        void Borrar();
        void Restore();
        void RotarXYZ(float AngX, float AngY, float AngZ);
        void VerPlano(voxel *Vox, float Azi, float Elev, float Tilt);
        void TrasladarXYZ(float X, float Y, float Z);
        
};
//---------------------------------------------------------------------------
#endif
