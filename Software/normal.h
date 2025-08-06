//---------------------------------------------------------------------------

#ifndef normalH
#define normalH
//---------------------------------------------------------------------------
class normal
{
private:	// User declarations
        float X,Y,Z;
        float PX,PY,PZ;

public:         // User declarations
        normal();
        normal(float x,float y,float z,float px,float py,float pz);
        normal(float azi, float elev, float px,float py,float pz);
        ~normal();
        void normalizar();
        void SetCoords(float x, float y, float z);
        void SetPto(float px, float py, float pz);
        void SetPto(float *p);
        float GetCoords(int index);
        float GetPto(int index);
};
//---------------------------------------------------------------------------
#endif
